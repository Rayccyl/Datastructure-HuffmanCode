#include <string>
#include <fstream>
#include <iostream>
#include "HuffmanCode.h"

char search(CharCodeMap *map, std::string tosearch, int n) {
    for (int i = 1; i <= n; ++i) {
        if (map[i].code == tosearch) return map[i].theChar;
    }
    return '\0';
}

int maxInMap(CharCodeMap *map, int n) {
    int max = map[1].code.length();
    for (int i = 1; i <= n; ++i) {
        if (max < map[i].code.length())max = map[i].code.length();
    }
    return max;
}

std::string getCode(CharCodeMap *pMap, int n, std::ifstream &inStream) {
    int maxLengthInMap = maxInMap(pMap, n);
    char perget = '/0';
    std::string get;
    char findTheChar = '/0';
//    字符串遍历 0-n for循环采取经典型
    for (int i = 0; i < maxLengthInMap; ++i) {
        inStream >> perget;
        get = get + perget;
        if (findTheChar = search(pMap, get, n))return get;
    }
//    如果for出不来 说明发生错误了
    return "";
}

int getN(HuffmanTree HT) {
    int nHT = 0;
    std::ifstream inputFile("HFMTREE", std::ios::binary);

    // 获取文件大小
    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    // 计算数组元素个数
    nHT = static_cast<int>(fileSize / (5 * sizeof(HuffmanTree)));
    return nHT;
}

bool D() {
    if (CCM == nullptr) {
        if (HT == nullptr)HT = Read(n, HT);
        if (HT== nullptr)return false;
        CCM = CreatMap(n, HT);
    }
    std::ifstream from("CODEFILE", std::ios::in);
    std::ofstream to("TEXTFILE", std::ios::out);
    if (!from.is_open()) {
        std::cerr << "File CODEFILE failed to be opened";
        return false;
    }
    if (!to.is_open()) {
        std::cerr << "File TEXTFILE failed to be opened";
        return false;
    }
    std::string code;

    while (from.peek() != EOF) {

        int maxLengthInMap = maxInMap(CCM, n);
        char perget = '/0';
        std::string get = "";
        char findTheChar = '/0';
//    字符串遍历 0-n for循环采取经典型
        for (int i = 0; i < maxLengthInMap; ++i) {
            from >> perget;
            get = get + perget;
            if (findTheChar = search(CCM, get, n)) {
                to << findTheChar;
                break;
            }
        }

//    如果for出不来 说明发生错误了

    }
    from.close();
    to.close();

    return true;
}