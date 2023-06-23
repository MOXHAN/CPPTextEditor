//
// Created by maximhansen on 30.05.2023.
//

#include <QPushButton>
#include <QMessageBox>
#include "FileDocker.h"
#include "handlerlib/DocumentHandler.h"
#include "handlerlib/FileHandler.h"

FileDocker::FileDocker(MainWindow *parent, EditorWidget *editorWidget) : QDockWidget(parent){

    //set editorWidget
    this->editorWidget = editorWidget;
    //create toolbar
    fileBar = new QToolBar {this};
    //create first + button
    addButton();

}

void FileDocker::createNewDoc() {

    //tell user to save
    // Create a message box
    QMessageBox saveDialog;
    saveDialog.setText("You need to save the current file to open another one");
    // Set the buttons
    saveDialog.addButton("Save", QMessageBox::AcceptRole);
    saveDialog.addButton("Cancel  ", QMessageBox::RejectRole);
    // Execute the message box and capture the clicked button
    int buttonClicked {saveDialog.exec()};

    // Check which button was clicked
    if (buttonClicked == QMessageBox::AcceptRole) {
        //save current doc to file
        FileHandler::handleSave(editorWidget);
        //create key for map ("document 1", because current docCount is 0)
        std::string key {"document " + std::to_string(DocumentHandler::getDocumentCount() + 1)};
        //add new doc to map
        DocumentHandler::addDocumentToMap(key, FileHandler::getPathLastFile());
        //clear current doc to "create new doc"
        editorWidget->document()->clear();
    } else if (buttonClicked == QMessageBox::RejectRole) {

    }
};

void FileDocker::addButton() {

    //create action/button for given document
    QAction *button {new QAction("+", this)};

    //connect button to open new document
    connect(button, &QAction::triggered, this, [&] () {
        //call func to create new doc
        createNewDoc();
        //add Button linked to doc
        addDocButton();
        //add new button for next doc
        addButton();
    });
    //connect button to slot for deleting the button
    connect(button, &QAction::triggered, this, &FileDocker::handleActionDelete);
    //add button to toolbar
    fileBar->addAction(button);

    //add modified toolbar widget back to docker widget
    setWidget(fileBar);
};

void FileDocker::addDocButton() {

    //text for button dependend on current amount of docs
    QString buttonText {"document " + QString::fromStdString(std::to_string(DocumentHandler::getDocumentCount()))};
    //create action/button for given document
    QAction *button {new QAction(buttonText, this)};
    //get path of file to load
    std::string path {DocumentHandler::getDocumentPathFromMap("document " + std::to_string(DocumentHandler::getDocumentCount()))};

    connect(button, &QAction::triggered, this, [this, path] () {
        //load file
        FileHandler::handleLoad(editorWidget, path);
    });

    fileBar->addAction(button);
    setWidget(fileBar);
};

void FileDocker::handleActionDelete() {

    //get sender (action/button)
    QAction* action = qobject_cast<QAction*>(sender());
    //remove action/button from my filebar
    fileBar->removeAction(action);

}