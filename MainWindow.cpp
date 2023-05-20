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
    setWindowTitle("Aplha Editor");

    //Create editorWidget
    EditorWidget *editorWidget = new EditorWidget(this);
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
    //Turn it inot checkable button
    underline->setCheckable(true);
    //Add Button to toolbar
    toolbar->addAction(underline);

    //Connect Signals and Slots
    connect(underline, &QAction::triggered, this, [editorWidget, underline] () {

        //Receive current cursor - format and font
        QTextCursor cursor = editorWidget->textCursor();
        QTextCharFormat format = cursor.charFormat();
        QFont font = format.font();

        //Set font to underline/not underline depending on current state
        font.setUnderline(!font.underline());
        format.setFont(font);
        cursor.setCharFormat(format);
        //Add Cursor back to editor
        editorWidget->setTextCursor(cursor);

        //Set button checked/unchecked
        underline->setChecked(font.underline());
    });

};