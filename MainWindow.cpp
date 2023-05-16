//
// Created by maximhansen on 16.05.2023.
//

#include <QMenuBar>
#include "MainWindow.h"
#include "EditorWidget.h"

//Close window when window is exited
void MainWindow::on_actionExit_triggered(){
    this->close();
};

//ctor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    //Set MainWindow title
    this->setWindowTitle("Aplha Editor");

    //Pointer to menubar, parent is this class
    QMenuBar *menubar {new QMenuBar(this)};
    //edit MenuBar here

    //Set Menubar of MainWindow to menubar
    this->setMenuBar(menubar);

    //Create editorWidget
    EditorWidget *editorWidget = new EditorWidget(this);
    //Set Central Widget of MainWindow to editorWidget
    this->setCentralWidget(editorWidget);

};