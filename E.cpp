#include <fstream>
#include <iostream>
#include "HuffmanCode.h"

HuffmanTree Read(int& n,HuffmanTree HT) {
    std::ifstream inputFile("HFMTREE", std::ios::binary);
    if (!inputFile.is_open()){
        std::cout<<"HuffmanTree uncreated yet,please select I option first to creat it\n";
        return nullptr;
    }
    // 获取文件大小
    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    // 计算数组元素个数
    n = static_cast<int>(fileSize / (5*sizeof(HuffmanTree)));

    // 创建动态数组
    HT = new HTNode[2*n];

    // 从文件读取数据
    inputFile.read(reinterpret_cast<char*>(HT), fileSize);
    inputFile.close();

    return HT;
}
std::string HFMcodeS(HuffmanTree HT,int i){
    std::string toreturn;
    while(HT[i].parent!=0){
        if(HT[HT[i].parent].lchild==i) toreturn='0'+toreturn;
        if(HT[HT[i].parent].rchild==i) toreturn='1'+toreturn;
        i=HT[i].parent;
    }
    return toreturn;
}
CharCodeMap* CreatMap(int n,HuffmanTree HT){
    CharCodeMap *theMap;
    theMap = new CharCodeMap[n + 1];
    for (int i = 1; i <= n; ++i) {
        theMap[i].theChar=HT[i].itemChar;
        theMap[i].code=HFMcodeS(HT,i);
    }
    return theMap;
}
std::string search(char tosearch,CharCodeMap* map,int n){
    for (int i = 1; i <=n ; ++i) {
        if(map[i].theChar==tosearch) return map[i].code;
    }
    std::cout << tosearch<<" is not found in the map,please init it again\n";
    return "";
}
bool Trans(CharCodeMap* map,int n){
    std::ifstream from("TOBETRAN", std::ios::in);
    std::ofstream to("CODEFILE",std::ios::out);
    if (! from.is_open()) {
        std::cout << "File TOBETRAN failed to be opened.May be you didn't creat it,please check\n";
        return false;
    }
    if(!to.is_open()){
        std::cout << "File CODEFILE failed to be opened";
        return false;
    }
    char ch;
    std::string temp;
    while (from.get(ch)) {

        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            if(temp=search(ch,map,n),temp=="")return false;
            to << temp ;
        }
    }
    from.close();
    to.close();
    return true;
}
bool E(){
    if(HT== nullptr)HT=Read(n,HT);
    if(HT== nullptr)return false;
    if(CCM== nullptr)CCM= CreatMap(n,HT);
    if(!Trans(CCM,n)) return false;
    std::cout << "Encoded\n";
    return true;
}


