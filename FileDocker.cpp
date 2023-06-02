//
// Created by maximhansen on 30.05.2023.
//

#include <iostream>
#include "FileDocker.h"
#include "DocumentHandler.h"

FileDocker::FileDocker(MainWindow *parent, EditorWidget *editorWidget) : QDockWidget(parent){

    //set editorWidget
    editorWidget = editorWidget;
    //create toolbar
    fileBar = new QToolBar {this};

    //create buttons/actions
    QAction *plusButton {new QAction("+", this)};
    //connect actions with slots
    connect(plusButton, &QAction::triggered, this, [&] () {
        DocumentHandler::addDocumentToMap("document 2");

        std::cout << DocumentHandler::getDocumentPathFromMap("document 2") << std::endl;

        QTextDocument *doc = editorWidget->document();
        //doc->setPlainText(DocumentHandler::getDocumentPathFromMap("document 2")->toPlainText());
        //change Button text from "+" to "document 2"
        //plusButton->setText("document 2");
        //add new button for next doc
        //addButton();
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

};