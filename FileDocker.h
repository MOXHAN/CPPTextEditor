//
// Created by maximhansen on 30.05.2023.
//

#ifndef CPPTEXTEDITOR_FILEDOCKER_H
#define CPPTEXTEDITOR_FILEDOCKER_H

#include <QDockWidget>
#include "MainWindow.h"
#include "DocumentHandler.h"


class FileDocker : public QDockWidget{

public:
    explicit FileDocker(MainWindow *parent);

    void addButton();

private:
    QToolBar *fileBar;
    DocumentHandler documentHandler;

};


#endif //CPPTEXTEDITOR_FILEDOCKER_H
