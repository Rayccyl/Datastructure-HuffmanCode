#include<iostream>
#include <fstream>
#include "HuffmanCode.h"
HuffmanTree InitHuffmanTree(HuffmanTree HT, int n) {
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];
    for (int i = 0; i <= m; ++i) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].weight = 0;
        HT[i].itemChar = '\0';
    }
    return HT;
}

void Write(HuffmanTree HT, int m) {
    int out = 0;
    std::ofstream outFile("HFMTREE", std::ios::out | std::ios::binary);
    if (!outFile) {
        std::cout << "failed to open the file" << std::endl;
        exit(1);
    }
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char *>(&HT[0]), (m + 1) * sizeof(HTNode));

        outFile.close();

        std::cout << "Huffman tree data written to HFMTREE" << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing!" << std::endl;
    }
}

void Min2(HuffmanTree HT, int *s1, int *s2, int m) {
    int minweight = 10000;
    for (int i = 1; i <= m; i++) {
        if (HT[i].weight < minweight && HT[i].parent == 0) {
            minweight = HT[i].weight;
            *s1 = i;
        }
    }
    minweight = 10000;
    for (int i = 1; i <= m; i++) {
        if (HT[i].weight < minweight && HT[i].parent == 0 && i != *s1) {
            minweight = HT[i].weight;
            *s2 = i;
        }
    }
}

HuffmanTree SetCharAndWeight(HuffmanTree HT, int n) {
    int m = 2 * n - 1;
    int s1, s2;
    if (n <= 1) return nullptr;
    HT[0].rchild = 2 * n - 1;
    std::cout << "Attention:weight can only be int\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << "please enter in the char and its weight\n";
        std::cin >> HT[i].itemChar;
        std::cin >> HT[i].weight;
    }
    for (int i = n + 1; i <= m; i++) {
        Min2(HT, &s1, &s2, i - 1);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    return HT;
}

int I() {
    std::cout << "please enter in the size of the character set\n";
    std::cin >> n;

//    n为编码字符的种数 即哈夫曼树的叶子节点数
    int m = 2 * n - 1;
//    为HT分配空间
    HT = InitHuffmanTree(HT, n);
//    引导用户手输权值 并生成哈夫曼树 （结构体数组形式）
    HT = SetCharAndWeight(HT, n);

//    写入外存
    Write(HT, m);
    return n;
}