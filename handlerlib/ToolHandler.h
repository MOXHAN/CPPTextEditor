//
// Created by maximhansen on 20.05.2023.
//

#ifndef CPPTEXTEDITOR_TOOLHANDLER_H
#define CPPTEXTEDITOR_TOOLHANDLER_H

#include <QTextEdit>
#include <QAction>

class ToolHandler : public QObject{

    Q_OBJECT

public slots:

    static void handleUnderline(QTextEdit *editorWidget, QAction *underline);
    static void handleBold(QTextEdit *editorWidget, QAction *bold);
    static void handleItalic(QTextEdit *editorWidget, QAction *italic);
    static void handleMarker(QTextEdit *editorWidget, QAction *marker);
    static void handleSearch(QTextEdit *editorWidget);
    static void handleDump(QString text, QTextEdit *editorWidget);
    static void handleUndo(QTextEdit *editorWidget);

private:
    static QString lastFoundString;
    static QTextCursor lastFoundStringCursor;

    template <typename T>
    static void print(const T& text);

};


#endif //CPPTEXTEDITOR_TOOLHANDLER_H
