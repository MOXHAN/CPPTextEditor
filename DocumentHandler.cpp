//
// Created by maximhansen on 31.05.2023.
//

#include <iostream>
#include "DocumentHandler.h"
#include "FileHandler.h"

//Define map
std::unordered_map<std::string, std::string> DocumentHandler::documentPathMap;

void DocumentHandler::addDocumentToMap(std::string key) {

    //create new document
    //FileHandler::handleSave()
    //add given doc and name as pair to unordered map
    //DocumentHandler::documentPathMap[key] = path;
    //Log
    std::cout<<"DOC-LOG: added document " << key << " to map." << std::endl;

}

void DocumentHandler::addDocumentToMap(std::string key, std::string path) {

    //add given doc and name as pair to unordered map
    DocumentHandler::documentPathMap[key] = path;
    //Log
    std::cout<<"DOC-LOG: added document path " << path << " to map." << std::endl;
}

std::string DocumentHandler::getDocumentPathFromMap(std::string key) {

    return DocumentHandler::documentPathMap[key];

}

int DocumentHandler::getDocumentCount() {

    return DocumentHandler::documentPathMap.size();

}