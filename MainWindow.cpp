//
// Created by maximhansen on 16.05.2023.
//

#include "MainWindow.h"
#include "ToolHandler.h"
#include "EditorWidget.h"
#include "FileHandler.h"
#include "PopUpWindow.h"
#include "FileDocker.h"
#include <iostream>
#include <QFileDialog>


//Close window when window is exited
void MainWindow::on_actionExit_triggered(){
    this->close();
};

//ctor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    //Set MainWindow title
    setWindowTitle("Aplha Editor");

    //Create editorWidget
    editorWidget = new EditorWidget(this);

    //Set Central Widget of MainWindow to editorWidget
    setCentralWidget(editorWidget);

    //Create Instance of FileDocker
    FileDocker *fileDocker = new FileDocker(this, editorWidget);
    //Set DockerWidget
    addDockWidget(Qt::TopDockWidgetArea, fileDocker);

    //Setup menuBar
    setupMenuBar();

    //Setup ToolBar
    setupToolBar();
};

void MainWindow::setupMenuBar() {

    //menuBar() returns MainWindows menubar, addMenu adds a Menu item
    QMenu *Menu = menuBar()->addMenu(tr("&Menu"));
    //Creates Dropdown Menu Items
    QAction *fileQuit {new QAction("Quit", this)};
    QAction *fileSave = new QAction("save to txt", this);
    QAction *fileLoad = new QAction("load from txt", this);

    //connect Signals and Slots
    connect(fileQuit, &QAction::triggered, this, [&](){
        PopUpWindow closePopup(this, editorWidget->document());
        closePopup.exec();
        close();
    });
    connect(fileSave, &QAction::triggered, this, [this, fileSave](){
        FileHandler::handleSave(editorWidget);
    });
    connect(fileLoad, &QAction::triggered, this, [this](){
        FileHandler::handleLoad(editorWidget);
    });
    //Add Dropdown Menu item to Menu Item
    Menu->addAction(fileQuit);
    Menu->addAction(fileSave);
    Menu->addAction(fileLoad);

}

void MainWindow::setupToolBar() {

    //create toolbar
    QToolBar *toolbar = addToolBar("MyToolBar");

    //Create Underline Button for toolbar
    QAction *underline = new QAction("U", this);
    //Turn it into checkable button
    underline->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(underline);

    //Create bold Button for toolbar
    QAction *bold = new QAction("B", this);
    //Turn it into checkable button
    bold->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(bold);

    //Create italic Button for toolbar
    QAction *italic = new QAction("K", this);
    //Turn it into checkable button
    italic->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(italic);

    //Create marker Button for toolbar
    QAction *marker = new QAction("Yellow", this);
    //Turn it into checkable button
    marker->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(marker);

    //Connect Signals and Slots
    connect(underline, &QAction::triggered, this, [this, underline] (){
        ToolHandler::handleUnderline(editorWidget, underline);
    });
    connect(bold, &QAction::triggered, this, [this, bold] (){
        ToolHandler::handleBold(editorWidget, bold);
    });
    connect(italic, &QAction::triggered, this, [this, italic] (){
        ToolHandler::handleItalic(editorWidget, italic);
    });
    connect(marker, &QAction::triggered, this, [this, marker] (){
        ToolHandler::handleMarker(editorWidget, marker);
    });
    
};