//
// Created by maximhansen on 16.05.2023.
//

#include <QApplication>
#include <QWindow>


#include "MainWindow.h"
#include "StartPopup.h"

int main(int argc, char *argv[]) {

    //Create Application
    QApplication a(argc, argv);
    //Create Window
    MainWindow w;

    //Design window
    w.resize(550,550);
    w.setToolTip("QWidget");

    StartPopup startPopup(&w);
    startPopup.exec();

    //Show window
    w.show();

    //Starts main loop
    return a.exec();
}

