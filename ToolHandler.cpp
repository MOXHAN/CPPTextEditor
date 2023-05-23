//
// Created by maximhansen on 20.05.2023.
//

#include "ToolHandler.h"

void ToolHandler::handleUnderline(QTextEdit *editorWidget, QAction *underline) {

    //Receive current cursor - format and font
    QTextCursor cursor = editorWidget->textCursor();
    QTextCharFormat format = cursor.charFormat();
    QFont font = format.font();

    //Set font to underline/not underline depending on current state
    font.setUnderline(!font.underline());
    format.setFont(font);
    cursor.setCharFormat(format);
    //Add Cursor back to editor
    editorWidget->setTextCursor(cursor);

    //Set button checked/unchecked
    underline->setChecked(font.underline());
}

void ToolHandler::handleBold(QTextEdit *editorWidget, QAction *bold) {

    //Receive current cursor - format and font
    QTextCursor cursor = editorWidget->textCursor();
    QTextCharFormat format = cursor.charFormat();
    QFont font = format.font();

    //Set font to bold/not bold depending on current state
    font.setBold(!font.bold());
    format.setFont(font);
    cursor.setCharFormat(format);
    //Add Cursor back to editor
    editorWidget->setTextCursor(cursor);

    //Set button checked/unchecked
    bold->setChecked(font.bold());
}

void ToolHandler::handleItalic(QTextEdit *editorWidget, QAction *italic) {

    //Receive current cursor - format and font
    QTextCursor cursor {editorWidget->textCursor()};
    QTextCharFormat format {cursor.charFormat()};
    QFont font = format.font();

    //Set font to italic/not italic depending on current state
    font.setItalic(!font.italic());
    format.setFont(font);
    cursor.setCharFormat(format);
    //Add Cursor back to editor
    editorWidget->setTextCursor(cursor);

    //Set button checked/unchecked
    italic->setChecked(font.italic());
}

void ToolHandler::handleMarker(QTextEdit *editorWidget, QAction *marker) {

    //get current color
    QColor color = editorWidget->textColor();

    if(marker->isChecked()){
        //Change rgb value
        color.setNamedColor("yellow");
        //Set backgroundcolor to changed color
        editorWidget->setTextBackgroundColor(color);
    } else {
        //Change rgb value to white
        color.setNamedColor("white");
        //Set backgroundcolor to changed color
        editorWidget->setTextBackgroundColor(color);
    }
}