//
// Created by maximhansen on 24.05.2023.
//

#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <string>
#include <QDebug>
#include <iostream>

void FileHandler::handleSave(QTextDocument *document) {

    std::string fileName {"data.txt"};
    //create file outstream
    std::ofstream writeToFile {fileName};
    //write contents to txt file
    writeToFile << document->toPlainText().toStdString();
    //close outstream
    writeToFile.close();

    //write path to saved file to "pathlast.txt" to save it for next session
    savePathLast(fileName);

}

void FileHandler::handleLoad(EditorWidget *editorWidget){

    QTextDocument *document = editorWidget->document();
    //create file instream
    std::ifstream readFromFile {"data.txt"};
    //Declare std string for read and qstring for write to document
    std::string data;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    data = ss.str();

    //convert std to q string
    QString qstring = QString::fromStdString(data);
    //write qstring to document
    document->setPlainText(qstring);
    //set document to Editor
    editorWidget->setDocument(document);
}

void FileHandler::handleLoad(EditorWidget *editorWidget, std::string path){

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
}

std::string FileHandler::getPathLastFile() {
    //create file instream
    std::ifstream readFromFile {"lastPath.txt"};
    //Declare std string for read
    std::string path;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    path = ss.str();

    return path;
}

void FileHandler::loadLast(EditorWidget *editorWidget) {

    //receive path to last opened txt
    std::string path {getPathLastFile()};
    //load content into editorWidget
    handleLoad(editorWidget, path);

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

}