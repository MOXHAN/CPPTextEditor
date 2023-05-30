//
// Created by maximhansen on 30.05.2023.
//

#include "FileDocker.h"
#include "EditorWidget.h"

FileDocker::FileDocker(MainWindow *parent) : QDockWidget(parent){

    //create toolbar
    fileBar = new QToolBar {this};

    //create buttons/actions
    QAction *plusButton {new QAction("+", this)};
    //connect actions with slots
    connect(plusButton, &QAction::triggered, this, ),

    //add buttons to toolbar
    fileBar->addAction(plusButton);

    //add toolbar widget to docker widget
    setWidget(fileBar);

}

void FileDocker::addButton() {

    //create action/button for given document

    //connect button to open given document

    //add button to toolbar

    //add modified toolbar widget back to docker widget
    setWidget(fileBar);

}