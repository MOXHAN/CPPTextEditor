//
// Created by maximhansen on 31.05.2023.
//

#include "DocumentHandler.h"

std::unordered_map<std::string, QTextDocument *> DocumentHandler::documentMap;

void DocumentHandler::addDocumentToMap(std::string key) {

    //create new document
    QTextDocument *document {new QTextDocument};
    //add given doc and name as pair to unordered map
    DocumentHandler::documentMap[key] = document;

}

void DocumentHandler::addDocumentToMap(std::string key, QTextDocument *document) {

    //add given doc and name as pair to unordered map
    DocumentHandler::documentMap[key] = document;

}

QTextDocument *DocumentHandler::getDocumentFromMap(std::string key) {

    return DocumentHandler::documentMap[key];

}

int DocumentHandler::getDocumentCount() {

    return DocumentHandler::documentMap.size();

}