//
// Created by maximhansen on 20.05.2023.
//

#ifndef CPPTEXTEDITOR_TOOLHANDLER_H
#define CPPTEXTEDITOR_TOOLHANDLER_H

#include <QTextEdit>
#include <QAction>
#include <QColor>

class ToolHandler : public QObject{

    Q_OBJECT

public slots:

    static void handleUnderline(QTextEdit *editorWidget, QAction *underline);
    static void handleBold(QTextEdit *editorWidget, QAction *bold);
    static void handleItalic(QTextEdit *editorWidget, QAction *italic);
    static void handleMarker(QTextEdit *editorWidget, QAction *marker);

};


#endif //CPPTEXTEDITOR_TOOLHANDLER_H
