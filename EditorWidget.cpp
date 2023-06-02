//
// Created by maximhansen on 21.05.2023.
//

#include "EditorWidget.h"
#include "LineNumberArea.h"
#include "handlerlib/DocumentHandler.h"

EditorWidget::EditorWidget(QWidget *parent) : QTextEdit(parent){

    // Line numbers
    lineNumberArea = new LineNumberArea(this);

    //connect "scrolled up/down" with updateLineNumberArea (writing new number)
    connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateLineNumberArea/*_2*/(int)));
    //connect textChanged signal with updateLineNumberArea
    connect(this, SIGNAL(textChanged()), this, SLOT(updateLineNumberArea()));
    //connect cursor pos change with updateLineNumberArea
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(updateLineNumberArea()));

    //init width for 4 digits
    lineNumberAreaWidth = 13 +  fontMetrics().width(QLatin1Char('9')) * (4);
    setViewportMargins(lineNumberAreaWidth, 0, 0, 0);

    //Horizontal Scroll instead of Linewrap
    setLineWrapMode(NoWrap);
    //Enable Undo/Redo
    setUndoRedoEnabled(true);
    document()->setUndoRedoEnabled(true);

    //Add original document to DocumentHandler map
    //DocumentHandler::addDocumentToMap("document 1", document());

}

void EditorWidget::updateLineNumberArea(QRectF /*rect_f*/)
{
    EditorWidget::updateLineNumberArea();
}
void EditorWidget::updateLineNumberArea(int /*slider_pos*/)
{
    EditorWidget::updateLineNumberArea();
}
void EditorWidget::updateLineNumberArea()
{
    /*
     * When the signal is emitted, the sliderPosition has been adjusted according to the action,
     * but the value has not yet been propagated (meaning the valueChanged() signal was not yet emitted),
     * and the visual display has not been updated. In slots connected to this signal you can thus safely
     * adjust any action by calling setSliderPosition() yourself, based on both the action and the
     * slider's value.
     */
    // Make sure the sliderPosition triggers one last time the valueChanged() signal with the actual value !!!!
    this->verticalScrollBar()->setSliderPosition(this->verticalScrollBar()->sliderPosition());

    // Since "QTextEdit" does not have an "updateRequest(...)" signal, we chose
    // to grab the information from "sliderPosition()" and "contentsRect()".
    // See the necessary connections used (Class constructor implementation part).

    QRect rect =  this->contentsRect();
    lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    int dy = this->verticalScrollBar()->sliderPosition();
    if (dy > -1) {
        lineNumberArea->scroll(0, dy);
    }

    //Adjust slider to always see the number of the currently being edited line...
    int first_block_id = getFirstVisibleBlockId();
    if (first_block_id == 0 || this->textCursor().block().blockNumber() == first_block_id-1)
        this->verticalScrollBar()->setSliderPosition(dy-this->document()->documentMargin());
}


void EditorWidget::resizeEvent(QResizeEvent *e)
{
    QTextEdit::resizeEvent(e);

    QRect cr = this->contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth, cr.height()));
}


int EditorWidget::getFirstVisibleBlockId()
{
    // Detect the first block for which bounding rect - once translated
    // in absolute coordinated - is contained by the editor's text area

    // Costly way of doing but since "blockBoundingGeometry(...)" doesn't
    // exists for "QTextEdit"...

    QTextCursor curs = QTextCursor(this->document());
    curs.movePosition(QTextCursor::Start);
    for(int i=0; i < this->document()->blockCount(); ++i)
    {
        QTextBlock block = curs.block();

        QRect r1 = this->viewport()->geometry();
        QRect r2 = this->document()->documentLayout()->blockBoundingRect(block).translated(
                this->viewport()->geometry().x(), this->viewport()->geometry().y() - (
                        this->verticalScrollBar()->sliderPosition()
                ) ).toRect();

        if (r1.contains(r2, true)) { return i; }

        curs.movePosition(QTextCursor::NextBlock);
    }

    return 0;
}

void EditorWidget::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    this->verticalScrollBar()->setSliderPosition(this->verticalScrollBar()->sliderPosition());

    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    int blockNumber = this->getFirstVisibleBlockId();

    QTextBlock block = this->document()->findBlockByNumber(blockNumber);
    QTextBlock prev_block = (blockNumber > 0) ? this->document()->findBlockByNumber(blockNumber-1) : block;
    int translate_y = (blockNumber > 0) ? -this->verticalScrollBar()->sliderPosition() : 0;

    int top = this->viewport()->geometry().top();

    // Adjust text position according to the previous "non entirely visible" block
    // if applicable. Also takes in consideration the document's margin offset.
    int additional_margin;
    if (blockNumber == 0)
        // Simply adjust to document's margin
        additional_margin = (int) this->document()->documentMargin() -1 - this->verticalScrollBar()->sliderPosition();
    else
        // Getting the height of the visible part of the previous "non entirely visible" block
        additional_margin = (int) this->document()->documentLayout()->blockBoundingRect(prev_block)
                .translated(0, translate_y).intersected(this->viewport()->geometry()).height();

    // Shift the starting point
    top += additional_margin;

    int bottom = top + (int) this->document()->documentLayout()->blockBoundingRect(block).height();

    QColor col_1(90, 255, 30);      // Current line (custom green)
    QColor col_0(120, 120, 120);    // Other lines  (custom darkgrey)

    // Draw the numbers
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen("Black");
            painter.drawText(-5, top,
                             lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) this->document()->documentLayout()->blockBoundingRect(block).height();
        ++blockNumber;
    }

}

void EditorWidget::paintEvent(QPaintEvent *event) {

    //get ID of current block
    int currentBlockID = textCursor().blockNumber();
    //get current block
    QTextCursor currentCursor {textCursor()};

    QTextBlock block;
    QTextBlockFormat blockFormat;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    //iterate through all blocks
    for(int i=0; i<document()->blockCount(); i++){
        //get block
        block = document()->findBlockByNumber(i);
        //get format of current block
        blockFormat = block.blockFormat();

        //Only set background yellow if block is current block
        if(i == currentBlockID){
            brush.setColor("lightgray");
        } else {
            //Set default brush
            brush.setColor("white");
        }
        //set Background of Blocks Format to the brush
        blockFormat.setBackground(brush);
        //get cursor for according block
        QTextCursor cursor(block);
        //Set format to cursor and cursor to widget
        cursor.setBlockFormat(blockFormat);
        setTextCursor(cursor);
    }
    //Set cursor back to recent position
    setTextCursor(currentCursor);

    //call Paint Event of super class to insure right behaviour
    QTextEdit::paintEvent(event);
}