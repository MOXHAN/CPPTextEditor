//
// Created by maximhansen on 24.05.2023.
//

#ifndef CPPTEXTEDITOR_FILEHANDLER_H
#define CPPTEXTEDITOR_FILEHANDLER_H


#include <QObject>
#include <QTextDocument>
#include "EditorWidget.h"

class FileHandler : public QObject{

    Q_OBJECT

public:
    static void handleSave(EditorWidget *editorWidget, QTextDocument *document);
    static void handleLoad(EditorWidget *editorWidget);
    static void handleLoad(EditorWidget *editorWidget, std::string path);
    static void loadLast(EditorWidget *editorWidget);
    static void savePathLast(std::string path);

private:

    static std::string getPathLastFile();

};


#endif //CPPTEXTEDITOR_FILEHANDLER_H
