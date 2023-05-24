//
// Created by maximhansen on 24.05.2023.
//

#include "FileHandler.h"
#include <fstream>
#include <string>

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
    QString qstring;
    //read in data
    readFromFile >> data;
    //convert std to q string
    qstring.fromStdString(data);
    //write qstring to document
    document->setPlainText(qstring);
    //set document to Editor
    editorWidget->setDocument(document);
}