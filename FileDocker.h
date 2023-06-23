//
// Created by maximhansen on 30.05.2023.
//

#ifndef CPPTEXTEDITOR_FILEDOCKER_H
#define CPPTEXTEDITOR_FILEDOCKER_H

#include <QDockWidget>
#include <QToolBar>
#include "MainWindow.h"
#include "EditorWidget.h"

class FileDocker : public QDockWidget{

public:
    explicit FileDocker(MainWindow *parent, EditorWidget *editorWidget);

public slots:
    void handleActionDelete();

private:
    QToolBar *fileBar;
    EditorWidget *editorWidget;

    void createNewDoc();
    void addDocButton();
    void addButton();
};


#endif //CPPTEXTEDITOR_FILEDOCKER_H
