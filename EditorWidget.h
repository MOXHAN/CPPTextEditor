//
// Created by maximhansen on 16.05.2023.
//

#ifndef CPPTEXTEDITOR_EDITORWIDGET_H
#define CPPTEXTEDITOR_EDITORWIDGET_H

#include <QMainWindow>
#include <QTextEdit>

class EditorWidget : public QTextEdit {

public:
    explicit EditorWidget(QMainWindow *parent);

protected:

private:

};


#endif //CPPTEXTEDITOR_EDITORWIDGET_H
