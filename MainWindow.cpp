//
// Created by maximhansen on 16.05.2023.
//

#include "MainWindow.h"
#include "ToolHandler.h"


//Close window when window is exited
void MainWindow::on_actionExit_triggered(){
    this->close();
};

//ctor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    //Set MainWindow title
    setWindowTitle("Aplha Editor");

    //Create editorWidget
    QTextEdit *editorWidget = new QTextEdit(this);
    //Set Central Widget of MainWindow to editorWidget
    setCentralWidget(editorWidget);

    //Setup Menubar
    //menuBar() returns MainWindows menubar, addMenu adds a Menu item
    QMenu *Menu = menuBar()->addMenu(tr("&Menu"));
    //Creates Dropdown Menu Item
    QAction *fileQuit= new QAction("Quit", this);
    //connect Signals and Slots
    connect(fileQuit, &QAction::triggered, this, [&](){
        close();
    });
    //Add Dropdown Menu item to Menu Item
    Menu->addAction(fileQuit);

    //Setup Toolbar
    //create toolbar
    QToolBar *toolbar = addToolBar("MyToolBar");

    //Create Underline Button for toolbar
    QAction *underline = new QAction("U", this);
    //Turn it into checkable button
    underline->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(underline);

    //Connect Signals and Slots
    connect(underline, &QAction::triggered, this, [editorWidget, underline] (){
        ToolHandler::handleUnderline(editorWidget, underline);
    });
};