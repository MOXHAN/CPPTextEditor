//
// Created by maximhansen on 31.05.2023.
//

#include <iostream>
#include "DocumentHandler.h"

//Define map
std::unordered_map<std::string, std::string> DocumentHandler::documentPathMap;

void DocumentHandler::addDocumentToMap(const std::string &key, const std::string &path) {

    //add given doc and name as pair to unordered map
    DocumentHandler::documentPathMap[key] = path;
    //Log
    std::cout<<"DOC-LOG: added document path " << path << " to map." << std::endl;
    std::cout<<"DOC-LOG: current map: " <<std::endl;
    for(auto &i : documentPathMap){
        std::cout << "  key: " << i.first << "val: " << i.second << std::endl;
    }
}

std::string DocumentHandler::getDocumentPathFromMap(const std::string &key) {

    std::cout << "DOC-LOG: Trying to get path for key: " << key << std::endl;
    return DocumentHandler::documentPathMap.at(key);

}

int DocumentHandler::getDocumentCount() {

    return DocumentHandler::documentPathMap.size();

}