//
// Created by maximhansen on 16.05.2023.
//

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

    //Create editorWidget
    EditorWidget *editorWidget = new EditorWidget(this);
    //Set Central Widget of MainWindow to editorWidget
    this->setCentralWidget(editorWidget);

    //Setup Menubar
    //menuBar() returns MainWindows menubar, addMenu adds a Menu item
    QMenu *Menu = menuBar()->addMenu(tr("&Menu"));
    //Creates Dropdown Menu Item
    QAction *fileQuit= new QAction("Quit", this);
    //connect Signals and Slots
    connect(fileQuit, &QAction::triggered, this, [&](){
        this->close();
    });
    //Add Dropdown Menu item to Menu Item
    Menu->addAction(fileQuit);

    //Setup Toolbar
    //create toolbar
    QToolBar *toolbar = new QToolBar("Toolbar", this);
    //Create Underline Button for toolbar
    QAction *underline = new QAction("U", this);
    //Connect Signals and Slots
    connect(underline, &QAction::triggered, this, [&] () {
        QTextCursor cursor = editorWidget->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFontUnderline(!format.fontUnderline());
        cursor.setCharFormat(format);
        editorWidget->setTextCursor(cursor);
    });
    //Add Button to toolbar
    toolbar->addAction(underline);
    //Add toolbar to MainWindow
    this->addToolBar(toolbar);

};