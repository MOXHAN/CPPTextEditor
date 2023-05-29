//
// Created by maximhansen on 29.05.2023.
//

#include "StartPopup.h"
#include "FileHandler.h"
#include <QAction>
#include <QPushButton>
#include <iostream>
#include <QVBoxLayout>

StartPopup::StartPopup(MainWindow *parent) : QDialog(parent){

    setWindowTitle("Popup Window");
    setFixedSize(300, 200);

    QPushButton *loadButton {new QPushButton("Open most recent file?", this)};

    connect(loadButton, &QPushButton::clicked, this, [&] (){
        FileHandler::loadLast(parent->editorWidget);
        accept();
    });

    //create Layout, add widget to layout, add layout to popup
    QVBoxLayout* layout {new QVBoxLayout(this)};
    layout->addWidget(loadButton);
    setLayout(layout);

};

