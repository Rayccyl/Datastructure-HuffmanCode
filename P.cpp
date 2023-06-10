#include <fstream>
#include <iostream>
#include "HuffmanCode.h"

void printHuffmanCode(std::ostream& out){
    std::ifstream in("CODEFILE");
    if (!in) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }
    if (in.peek() == std::ifstream::traits_type::eof()) {
        if(CCM== nullptr)CCM= CreatMap(n,HT);
        if(!Trans(CCM,n))return;
    }
    const int maxCharsPerLine = 50;
    std::string line;
    int charCount = 0;

    while (std::getline(in, line)) {
        for (char c : line) {
            out << c;
            charCount++;
            if (charCount == maxCharsPerLine) {
                out << std::endl;
                charCount = 0;
            }
        }
    }
    out << std::endl;

    in.close();
}
void P(){
    if(HT== nullptr)HT=Read(n,HT);
    if(HT== nullptr){
        return;
    }
    printHuffmanCode(std::cout);
    std::ofstream out("CODEPRIN");
    printHuffmanCode(out);
    out.close();
}