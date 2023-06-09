//
// Created by maximhansen on 21.05.2023.
//

#ifndef CPPTEXTEDITOR_EDITORWIDGET_H
#define CPPTEXTEDITOR_EDITORWIDGET_H


#include <QTextEdit>
#include <QPaintEvent>
#include <QRectF>


class EditorWidget : public QTextEdit
{
Q_OBJECT

public:
    //ctor
    explicit EditorWidget(QWidget *parent = 0);

    int getFirstVisibleBlockId();
    void lineNumberAreaPaintEvent(QPaintEvent *event);

    int lineNumberAreaWidth;

public slots:

    void resizeEvent(QResizeEvent *e);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private slots:

    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea();

private:

    QWidget *lineNumberArea;

};


#endif //CPPTEXTEDITOR_EDITORWIDGET_H
