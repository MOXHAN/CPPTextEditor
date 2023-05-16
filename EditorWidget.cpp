//
// Created by maximhansen on 16.05.2023.
//

#include "EditorWidget.h"

//ctor
EditorWidget::EditorWidget(QMainWindow *parent) : QWidget(parent){


    //Set FocusPolicy, so that the Widget gets keyboard focus, when clicked
    //on or when tab pressed
    this->setFocusPolicy(Qt::StrongFocus);

    //set font with setFont()

    installEventFilter(this);

};

//this function filters the Return key, as Qt treats this as event, not keyevent
bool EditorWidget::eventFilter(QObject* object, QEvent* event){

    if(event->type() == QEvent::KeyPress){
        //cast event to keyevent
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        //if its return key
        if(keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return){
            keyPressEvent(keyEvent);
        }
        //ignore if not return key
        return true;
    }
    //rekursiver Aufruf
    return QWidget::eventFilter(object, event);
}

void EditorWidget::keyPressEvent(QKeyEvent *event){

    //Abfangen Return key
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        textBuffer += "\n";
        update();
    }
    //Abfangen backspace
    else if(event->key() == Qt::Key_Backspace){
        //remove last character in textBuffer
        textBuffer = textBuffer.remove(textBuffer.size()-1,1);
        //call repaintEvent
        update();
        //Use Base implementation for default cases
        QWidget::keyPressEvent(event);
    }
    //Allle anderen Tasten
    else {
        //Add pressed character to String in current line
        textBuffer.append(event->text());
        //call repaintEvent to print the entered letter/character
        update();
        //Use Base implementation for default cases
        QWidget::keyPressEvent(event);
    }

};

void EditorWidget::paintEvent(QPaintEvent *event) {

    //Call base implementation for safety
    QWidget::paintEvent(event);

    //Parse tetBuffer into multiple Strings
    QStringList lines = textBuffer.split("\n");

    //Start coordinates
    int x {10};
    int y {10};

    //Own implementation
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    QSize size {this->size()};
    //Draw each string representing a new line
    for(auto &line : lines){
        painter.drawText(QRect(x, y, size.width() - 20, size.height() - 20), Qt::AlignCenter, line);
        y += painter.fontMetrics().height();
    }


}