//
// Created by maximhansen on 21.05.2023.
//

#include "LineNumberArea.h"

LineNumberArea::LineNumberArea(QTextEdit *editor) : QWidget(editor) {
    editorWidget = editor;
}

QSize LineNumberArea::sizeHint() const {
    return QSize(((EditorWidget *)editorWidget)->lineNumberAreaWidth, 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    ((EditorWidget *)editorWidget)->lineNumberAreaPaintEvent(event);
}