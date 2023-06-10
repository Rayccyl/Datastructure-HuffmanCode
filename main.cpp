#include <iostream>
#include "HuffmanCode.h"
CharCodeMap *CCM = nullptr;
HuffmanTree HT = nullptr;
int n = 0;
void showOptions() {
    system("cls");
    std::cout << "Welcome to WCGL's HuffmanCode System" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Program Function Menu" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "I: Initialize Huffman Tree" << std::endl;
    std::cout << "E: Encode Text File" << std::endl;
    std::cout << "D: Decode Encoded File" << std::endl;
    std::cout << "P: Print Encoded File" << std::endl;
    std::cout << "T: Print Huffman Tree" << std::endl;
    std::cout << "Q: Quit the Program" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Please select an operation (enter the corresponding letter):";
}

int main() {
    char c;
    int n = 0;
    showOptions();
    std::cout << std::endl;
    do {
        std::cin >> c;
        switch (c) {
            case 'I':
                n=I();
                showOptions();
                std::cout << "Initialized\n";
                break;
            case 'E':
                if(E()){
                    showOptions();
                    std::cout << "Encoded\n";
                }
                break;
            case 'D':
                if(D()){
                    showOptions();
                    std::cout << "Decoded\n";
                }
                break;
            case 'P':
                showOptions();
                std::cout << std::endl;
                P();
                break;
            case 'T':
                showOptions();
                std::cout << std::endl;
                T();
                break;
            case 'Q':
                return 0;
            default:
                showOptions();
                std::cout << "\nthere are no such a choice!\n";
                break;
        }
    } while (true);

}
