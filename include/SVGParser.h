#ifndef _SVG_PARSER_H_
#define _SVG_PARSER_H_

#include <string>
#include <iostream>
#include <fstream>
#include "..\extendLib\rapid_xml\rapidxml.hpp"


using namespace rapidxml;
using namespace std;

class SVGParser
{
    private:
        string filename;
        xml_document<> doc;
        xml_node<> *root_node;
        char *buffer;
    public:
        SVGParser();
        ~SVGParser();
        void loadFile(const string &filename);
        void print();
};


#endif