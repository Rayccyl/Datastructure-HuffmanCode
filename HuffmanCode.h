//
// Created by 23689 on 2023/6/10.
//

#ifndef HUFFMANTREELOCAL_HUFFMANCODE_H
#define HUFFMANTREELOCAL_HUFFMANCODE_H

int I();
bool E();
bool D();
void T();
void P();
typedef struct HTNode {
    int weight;
    char itemChar;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef struct CharCodeMap {
    char theChar='\0';
    std::string code;
} CharCodeMap;
extern CharCodeMap *CCM;
extern int n;
extern HuffmanTree HT;
CharCodeMap* CreatMap(int n,HuffmanTree HT);
HuffmanTree Read(int& n,HuffmanTree HT);
bool Trans(CharCodeMap* map, int n);
HuffmanTree Read(int& n,HuffmanTree HT);
#endif //HUFFMANTREELOCAL_HUFFMANCODE_H
