//
// Created by maximhansen on 29.05.2023.
//

#include "PopUpWindow.h"
#include "handlerlib/FileHandler.h"
#include <QAction>
#include <QPushButton>
#include <iostream>
#include <QVBoxLayout>
#include <QFileDialog>

//ctor popup for load on start
PopUpWindow::PopUpWindow(MainWindow *parent) : QDialog(parent){

    setWindowTitle("Popup Window");
    setFixedSize(300, 200);

    QPushButton *loadButton {new QPushButton("Open most recent file?", this)};

    connect(loadButton, &QPushButton::clicked, this, [&] (){
        FileHandler::loadLast(parent->getEditorWidget());
        accept();
    });

    //create Layout, add widget to layout, add layout to popup
    QVBoxLayout* layout {new QVBoxLayout(this)};
    layout->addWidget(loadButton);
    setLayout(layout);

};

//ctor popup for save on close
PopUpWindow::PopUpWindow(MainWindow *parent, QTextDocument *document) : QDialog(parent) {

    setWindowTitle("Popup Window");
    setFixedSize(300, 200);

    QPushButton *saveButton {new QPushButton("Save this file?", this)};

    connect(saveButton, &QPushButton::clicked, this, [&] (){
        QString fileName = QFileDialog::getSaveFileName(parent,
                                                        tr("Open Textfile"), "/home", tr("Text Files (*.txt)"));
        FileHandler::handleSave(parent->getEditorWidget());
        accept();
    });

    //create Layout, add widget to layout, add layout to popup
    QVBoxLayout* layout {new QVBoxLayout(this)};
    layout->addWidget(saveButton);
    setLayout(layout);
}