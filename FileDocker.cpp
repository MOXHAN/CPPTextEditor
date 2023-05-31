//
// Created by maximhansen on 30.05.2023.
//

#include "FileDocker.h"
#include "EditorWidget.h"

FileDocker::FileDocker(QWidget *parent) : QDockWidget(parent){

    //create toolbar
    fileBar = new QToolBar {this};

    //create buttons/actions
    QAction *plusButton {new QAction("+", this)};
    //connect actions with slots
    connect(plusButton, &QAction::triggered, this, [&] () {
        DocumentHandler::addDocumentToMap("document2");
        //Setzen des Documents im Editor Widget
        //editorWidget->setDocument(DocumentHandler::documentMap[key];
    });

    //add buttons to toolbar
    fileBar->addAction(plusButton);

    //add toolbar widget to docker widget
    setWidget(fileBar);

}

void FileDocker::addButton() {

    //create action/button for given document
    QAction *button {new QAction("+", this)};

    //create key
    std::string key {"document " + std::to_string(DocumentHandler::getDocumentCount())};

    //connect button to open new document
    connect(button, &QAction::triggered, this, [&] () {
        DocumentHandler::addDocumentToMap(key);
        //Setzen des Documents im Editor Widget
        //editorWidget->setDocument(DocumentHandler::documentMap[key];
    });
    //add button to toolbar
    fileBar->addAction(button);

    //add modified toolbar widget back to docker widget
    setWidget(fileBar);

}