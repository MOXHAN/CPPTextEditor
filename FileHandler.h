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
    static void handleSave(QTextDocument *document);
    static void handleLoad(EditorWidget *editorWidget);

};


#endif //CPPTEXTEDITOR_FILEHANDLER_H
