//
// Created by maximhansen on 24.05.2023.
//

#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <QDebug>
#include <QFileDialog>

void FileHandler::handleSave(QTextEdit *editorWidget) {

    QString fileName = QFileDialog::getSaveFileName(editorWidget,
                                                    tr("Open Textfile"), "/home", tr("Text Files (*.txt)"));
    //create file outstream
    std::ofstream writeToFile {fileName.toStdString()};
    //write contents to txt file
    writeToFile << editorWidget->document()->toPlainText().toStdString();
    //close outstream
    writeToFile.close();

    //write path to saved file to "pathlast.txt" to save it for next session
    savePathLast(fileName.toStdString());

    //Logging
    std::cout << "FILE-LOG: successfully saved file " << fileName.toStdString() << std::endl;

}

void FileHandler::handleLoad(QTextEdit *editorWidget){

    QString fileName = QFileDialog::getOpenFileName(editorWidget,
                                            tr("Open Textfile"), "/home", tr("Text Files (*.txt)"));
    //create file instream
    std::ifstream readFromFile {fileName.toStdString()};
    //Declare std string for read and qstring for write to document
    std::string data;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    data = ss.str();

    QTextDocument *document = editorWidget->document();
    //convert std to q string
    QString qstring = QString::fromStdString(data);
    //write qstring to document
    document->setPlainText(qstring);

    //Logging
    std::cout << "FILE-LOG: successfully loaded file " << fileName.toStdString() << std::endl;

}

void FileHandler::handleLoad(QTextEdit *editorWidget, std::string path){

    //create file instream
    std::ifstream readFromFile {path};
    //Declare std string for read and qstring for write to document
    std::string data;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    data = ss.str();

    //convert std to q string
    QString qstring = QString::fromStdString(data);
    //get document in editor
    QTextDocument *document = editorWidget->document();
    //write qstring to document
    document->setPlainText(qstring);
    //set document to Editor
    editorWidget->setDocument(document);

    //Logging
    std::cout << "FILE-LOG: successfully saved file from path " << path << std::endl;
}

std::string FileHandler::getPathLastFile() {
    //create file instream
    std::ifstream readFromFile {"pathLast.txt"};
    //Declare std string for read
    std::string path;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    path = ss.str();

    return path;
}

void FileHandler::loadLast(QTextEdit *editorWidget) {

    //receive path to last opened txt
    std::string path {getPathLastFile()};
    //load content into editorWidget
    handleLoad(editorWidget, path);

    //Logging
    std::cout << "FILE-LOG: successfully loaded previous saved file from path " << getPathLastFile << std::endl;

}

//this function saves the given string (path) into a separate txt file
//when the Popup-Dialog asking whether to open the last saved file is accepted
//the path is read from this file
void FileHandler::savePathLast(std::string path){

    //create file outstream
    std::ofstream writeToFile {"pathLast.txt"};
    //write contents to txt file
    writeToFile << path;
    //close outstream
    writeToFile.close();

    //Logging
    std::cout << "FILE-LOG: successfully saved path " << path << " as path to previously saved file" << std::endl;

}