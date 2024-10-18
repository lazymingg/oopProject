#include <iostream>
#include <fstream>
#include "include/SVGParser.h"
using namespace std;

int main()
{
    //nothing here yet :D
    SVGParser parser;
    parser.loadFile("testCase/sample.svg");
    parser.print();
    return 0;
}
