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

    //create file outstream
    std::ofstream writeToFile {"data.txt"};
    //write contents to txt file
    writeToFile << document->toPlainText().toStdString();
    //close outstream
    writeToFile.close();

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

    //read in data
    //readFromFile >> data;
    //convert std to q string
    QString qstring = QString::fromStdString(data);
    //write qstring to document
    document->setPlainText(qstring);
    //set document to Editor
    editorWidget->setDocument(document);
}