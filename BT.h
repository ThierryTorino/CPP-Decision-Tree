#ifndef BT_H
#define BT_H
#include <string>
using namespace std;
typedef string treeEntry;

class binaryTree
{
public:
    binaryTree();
    ~binaryTree();
    bool full();
    bool empty();
    void clear();
    void preOrder();
    void insert(string pai, string fLeft, string fRight);
    void search();

private:
    struct treeNode;
    typedef treeNode *treePointer;
    struct treeNode
    {
        treeEntry entry;
        treePointer leftNode, rightNode;
    };
    treePointer root;
    treePointer search(treePointer t, string x);
    void preOrder(treePointer t, int &totalNodes, int &folhas);
    void clear(treePointer t);
};

#endif