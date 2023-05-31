//
// Created by maximhansen on 31.05.2023.
//

#include "DocumentHandler.h"


void DocumentHandler::addDocumentToMap(std::string key) {

    //create new document
    QTextDocument *document {new QTextDocument};
    //add given doc and name as pair to unordered map
    documentMap[key] = document;
    documentCount++;

}

QTextDocument *DocumentHandler::getDocumentFromMap(std::string key) {

    return documentMap[key];

}

int DocumentHandler::getDocumentCount() {

    return documentCount;

}