//
// Created by maximhansen on 16.05.2023.
//

#ifndef ALPHA_EDITOR_MAINWINDOW_H
#define ALPHA_EDITOR_MAINWINDOW_H

#include <QMainWindow>

#include "EditorWidget.h"

class MainWindow : public QMainWindow {

Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    EditorWidget* getEditorWidget(){return editorWidget;};

private slots:
    void on_actionExit_triggered();

private:
    void setupToolBar();
    void setupMenuBar();
    EditorWidget *editorWidget;

};


#endif //ALPHA_EDITOR_MAINWINDOW_H