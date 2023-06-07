//
// Created by maximhansen on 24.05.2023.
//

#ifndef CPPTEXTEDITOR_FILEHANDLER_H
#define CPPTEXTEDITOR_FILEHANDLER_H


#include <QObject>
#include <QTextDocument>
#include <QTextEdit>

class FileHandler : public QObject{

    Q_OBJECT

public:
    static void handleSave(QTextEdit *editorWidget);
    static void handleLoad(QTextEdit *editorWidget);
    static void handleLoad(QTextEdit *editorWidget, std::string path);
    static void loadLast(QTextEdit *editorWidget);
    static void savePathLast(std::string path);
    static std::string getPathLastFile();
    static void handleExportPdf(QTextEdit *editorWidget);

private:


};


#endif //CPPTEXTEDITOR_FILEHANDLER_H
