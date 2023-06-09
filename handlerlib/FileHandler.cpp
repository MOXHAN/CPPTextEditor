//
// Created by maximhansen on 24.05.2023.
//

#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>

std::ofstream& operator<<(std::ofstream& ofs, const QString& qstring){
    ofs << qstring.toStdString();
    return ofs;
}

void FileHandler::handleSave(QTextEdit *editorWidget) {

    QString fileName {QFileDialog::getSaveFileName(editorWidget,
                                                    tr("Open Textfile"), "/home", tr("Text Files (*.txt)"))};
    //create file outstream
    std::ofstream writeToFile {fileName.toStdString()};
    //write contents to txt file
    //writeToFile << editorWidget->document()->toPlainText().toStdString();
    QString text {editorWidget->toHtml()};
    //removing unwanted html background coloring
    text.remove(" background-color:#ffffff;");
    text.remove(" background-color:#d3d3d3;");

    writeToFile << text;
    //close outstream
    writeToFile.close();

    //write path to saved file to "pathlast.txt" to save it for next session
    savePathLast(fileName.toStdString());

    //Logging
    std::cout << "FILE-LOG: successfully saved file " << fileName.toStdString() << std::endl;

}

void FileHandler::handleLoad(QTextEdit *editorWidget){

    QString fileName {QFileDialog::getOpenFileName(editorWidget,
                                            tr("Open Textfile"), "/home", tr("Text Files (*.txt)"))};
    //create file instream
    std::ifstream readFromFile {fileName.toStdString()};
    //Declare std string for read and qstring for write to document
    std::string data;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    data = ss.str();

    QTextDocument *document {editorWidget->document()};
    //convert std to q string
    QString qstring {QString::fromStdString(data)};
    //write qstring to document
    document->setHtml(qstring);

    //Logging
    std::cout << "FILE-LOG: successfully loaded file " << fileName.toStdString() << std::endl;

}

void FileHandler::handleLoad(QTextEdit *editorWidget, const std::string &path){

    //create file instream
    std::ifstream readFromFile {path};
    //Declare std string for read and qstring for write to document
    std::string data;

    std::ostringstream ss;
    ss << readFromFile.rdbuf();
    data = ss.str();

    //convert std to q string
    QString qstring {QString::fromStdString(data)};
    //get document in editor
    QTextDocument *document {editorWidget->document()};
    //write qstring to document
    document->setHtml(qstring);

    //Logging
    std::cout << "FILE-LOG: successfully loaded file from path: " << path << std::endl;
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
    std::cout << "FILE-LOG: successfully loaded previous saved file from path: " << getPathLastFile() << std::endl;

}

//this function saves the given string (path) into a separate txt file
//when the Popup-Dialog asking whether to open the last saved file is accepted
//the path is read from this file
void FileHandler::savePathLast(const std::string &path){

    //create file outstream
    std::ofstream writeToFile {"pathLast.txt"};
    //write contents to txt file
    writeToFile << path;
    //close outstream
    writeToFile.close();

    //Logging
    std::cout << "FILE-LOG: successfully saved path " << path << " as path to previously saved file" << std::endl;

}

void FileHandler::handleExportPdf(QTextEdit *editorWidget) {

    //get name to save file as
    QString fileName {QFileDialog::getSaveFileName(editorWidget,
                                                    tr("Open Textfile"), "/home", tr("Pdf Files (*.pdf)"))};
    //get current text in editorWidget
    QString text {editorWidget->document()->toPlainText()};
    //create pdfWriter instance for file
    QPdfWriter pdfWriter(fileName);
    //set page size and orientation
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    //create painter instance, set font and write text to file
    QPainter painter(&pdfWriter);
    painter.setFont(QFont("Arial", 12));
    painter.drawText(QRectF(0, 0, pdfWriter.width(), pdfWriter.height()), text);
    //end/delete painter and delete pdf-writer
    painter.end();
    pdfWriter.deleteLater();

}