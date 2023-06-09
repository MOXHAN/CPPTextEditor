//
// Created by maximhansen on 08.06.2023.
//

#ifndef CPPTEXTEDITOR_TABLEHANDLER_H
#define CPPTEXTEDITOR_TABLEHANDLER_H


#include <QTextEdit>

class TableHandler {

public:

    TableHandler() = delete;

    static void createTable(QTextEdit *editorWidget);
    static void addRow(QTextEdit *editorWidget);
    static void addCol(QTextEdit *editorWidget);

};


#endif //CPPTEXTEDITOR_TABLEHANDLER_H
