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


};


#endif //CPPTEXTEDITOR_TOOLHANDLER_H
