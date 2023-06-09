//
// Created by maximhansen on 08.06.2023.
//

#include "TableHandler.h"
#include <QTextTable>

void TableHandler::createTable(QTextEdit *editorWidget) {

    //get current doc in editorWidget and "save it"
    QTextCursor cursor {editorWidget->textCursor()};
    //create Table
    cursor.insertTable(1,1);
    //set cursor back to editorWidget
    editorWidget->setTextCursor(cursor);

};

void TableHandler::addRow(QTextEdit *editorWidget) {

    //get current doc in editorWidget and "save it"
    QTextCursor cursor {editorWidget->textCursor()};
    //get current table
    QTextTable *table {cursor.currentTable()};
    //insert Row
    table->insertRows(1,1);
    //set cursor back to editorWidget
    editorWidget->setTextCursor(cursor);

};

void TableHandler::addCol(QTextEdit *editorWidget) {

    //get current doc in editorWidget and "save it"
    QTextCursor cursor {editorWidget->textCursor()};
    //get current table
    QTextTable *table {cursor.currentTable()};
    //insert Row
    table->insertColumns(1,1);
    //set cursor back to editorWidget
    editorWidget->setTextCursor(cursor);

}