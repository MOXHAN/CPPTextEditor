//
// Created by maximhansen on 31.05.2023.
//

#ifndef CPPTEXTEDITOR_DOCUMENTHANDLER_H
#define CPPTEXTEDITOR_DOCUMENTHANDLER_H

#include <unordered_map>
#include <string>
#include <QTextDocument>


class DocumentHandler {


public:

    void addDocumentToMap(std::string key);
    QTextDocument* getDocumentFromMap(std::string key);
    int getDocumentCount();

private:

    std::unordered_map<std::string, QTextDocument *> documentMap;
    int documentCount {0};

};


#endif //CPPTEXTEDITOR_DOCUMENTHANDLER_H
