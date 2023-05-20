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