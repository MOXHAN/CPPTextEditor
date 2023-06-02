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

    static void addDocumentToMap(std::string key);
    static void addDocumentToMap(std::string key, std::string path);
    static std::string getDocumentPathFromMap(std::string key);
    static int getDocumentCount();

private:

    static std::unordered_map<std::string, std::string> documentPathMap;

};


#endif //CPPTEXTEDITOR_DOCUMENTHANDLER_H
