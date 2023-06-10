#include <sstream>
#include <fstream>
#include <iostream>
#include "HuffmanCode.h"
std::string LeafNodeToString(HTNode thenode,CharCodeMap *CCM,int n){
    std::string search(char tosearch,CharCodeMap* map,int n);
    std::stringstream ss;
    if(thenode.itemChar=='\0') return "";
    ss << thenode.itemChar << " " << thenode.weight << " " << search(thenode.itemChar,CCM,n);
    return ss.str();
}
void printHuffmanTree(HuffmanTree tree, int root, std::string prefix = "",std::ostream& out=std::cout) {
    if (root == 0) {
        return;
    }

    out << prefix;
    std::string add="    ";
    // 判断当前节点是叶子节点还是内部节点
    if (tree[root].lchild == 0 && tree[root].rchild == 0) {
        if(tree[tree[root].parent].lchild==root)out << "├──" << LeafNodeToString(tree[root],CCM,n) << std::endl;
        if(tree[tree[root].parent].rchild==root)out << "└──" << LeafNodeToString(tree[root],CCM,n) << std::endl;
    } else {
        if(tree[tree[root].parent].lchild==root){out << "├──" << tree[root].weight << std::endl;add="│   ";}
        if(tree[tree[root].parent].rchild==root) out << "└──" << tree[root].weight << std::endl;
        printHuffmanTree(tree, tree[root].lchild, prefix + add,out);
        printHuffmanTree(tree, tree[root].rchild, prefix + add,out);
    }
}
void T(){
    if(HT== nullptr)HT=Read(n,HT);
    if(HT== nullptr)return;
    CCM= CreatMap(n,HT);
    printHuffmanTree(HT,2*n-1);
    std::ofstream outputFile("TREEPRIN");
    printHuffmanTree(HT,2*n-1,"",outputFile);
}
