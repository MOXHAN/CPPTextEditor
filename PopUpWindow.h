//
// Created by maximhansen on 29.05.2023.
//

#ifndef CPPTEXTEDITOR_POPUPWINDOW_H
#define CPPTEXTEDITOR_POPUPWINDOW_H

#include <QDialog>
#include "MainWindow.h"

class PopUpWindow : public QDialog{

public:
    explicit PopUpWindow(MainWindow *parent);
    PopUpWindow(MainWindow *parent, QTextDocument *document);

};


#endif //CPPTEXTEDITOR_POPUPWINDOW_H
