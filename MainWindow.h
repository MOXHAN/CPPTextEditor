//
// Created by maximhansen on 16.05.2023.
//

#ifndef ALPHA_EDITOR_MAINWINDOW_H
#define ALPHA_EDITOR_MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QTextCharFormat>
#include <QTextEdit>

class MainWindow : public QMainWindow {

Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_actionExit_triggered();

private:

};


#endif //ALPHA_EDITOR_MAINWINDOW_H