//
// Created by maximhansen on 21.05.2023.
//

#ifndef CPPTEXTEDITOR_LINENUMBERAREA_H
#define CPPTEXTEDITOR_LINENUMBERAREA_H


#include <QWidget>

#include "EditorWidget.h"

class LineNumberArea : public QWidget
{
Q_OBJECT

public:
    LineNumberArea(QTextEdit *editor);

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTextEdit *editorWidget;
};


#endif //CPPTEXTEDITOR_LINENUMBERAREA_H