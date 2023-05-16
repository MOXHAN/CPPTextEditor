//
// Created by maximhansen on 16.05.2023.
//

#ifndef CPPTEXTEDITOR_EDITORWIDGET_H
#define CPPTEXTEDITOR_EDITORWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <vector>

class EditorWidget : public QWidget {

public:
    explicit EditorWidget(QMainWindow *parent);

protected:
    //override QWidgets keyPress Eventhandler
    virtual void keyPressEvent(QKeyEvent *event) override;

    virtual void paintEvent(QPaintEvent *event) override;

private:

    QString textBuffer;
    int currentLine {0};

    bool eventFilter(QObject* object, QEvent* event);

};


#endif //CPPTEXTEDITOR_EDITORWIDGET_H
