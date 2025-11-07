#include "BT.h"
#include <iostream>
#include <string>
using namespace std;

binaryTree::binaryTree()
{
    root = NULL;
}

binaryTree::~binaryTree()
{
    clear();
}

void binaryTree::clear()
{
    clear(root);
}

void binaryTree::clear(treePointer t)
{
    if (t == NULL)
    {
        return;
    }
    clear(t->leftNode);
    clear(t->rightNode);
    delete t;
}

bool binaryTree::empty()
{
    // retorna true caso a raiz seja 0
    return root == NULL;
}

void binaryTree::preOrder()
{
    int totalNodes = 0;
    int folhas = 0;
    preOrder(root, totalNodes, folhas);
}

void binaryTree::preOrder(treePointer t, int &totalNodes, int &folhas)
{
    // define variaveis para cada parte
    string pai = "";
    bool esq = false, dir = false;
    int count = 0;

    // se for nulo, retorna
    if (t == NULL)
    {
        return;
    }

    // se for X, não irá imprimir
    if (t->entry != "X")
    {
        // adiciona o node pai
        pai = t->entry;
        totalNodes++;

        // verifica nó da esquerda
        if (t->leftNode != NULL && t->leftNode->entry != "X")
        {
            count++;
            esq = true;
        }
        else
            esq = false;

        // verifica nó da direita
        if (t->rightNode != NULL && t->rightNode->entry != "X")
        {
            count++;
            dir = true;
        }
        else
            dir = false;

        // imprime o pai
        cout << pai << " " << count << " ";

        // verifica qual imprimir, E, D, ED ou F
        if (count == 0)
        {
            folhas++;
            cout << "F";
        }
        else if (count == 1)
        {
            if (dir == true)
            {
                cout << "D";
            }
            else
                cout << "E";
        }
        else
            cout << "ED";
        cout << "\n";

        // recursao
        preOrder(t->leftNode, totalNodes, folhas);
        preOrder(t->rightNode, totalNodes, folhas);
    }
}

binaryTree::treePointer binaryTree::search(treePointer t, string x) // recebe de onde ele vai começar a busca (root) e qual valor ele deve achar
{
    if (t == NULL)
    {
        // chgou no final da arvore / arvore está vazia
        return NULL;
    }
    if (t->entry == "X")
    {
        // achou um nó X (folha), retrona nulo
        return NULL;
    }
    if (t->entry == x)
    {
        // achou o nó que procura (retorna o endereço de memoria)
        return t;
    }
    // se nao acontecer nenhuma das 3 alternativas, usa recurção para procurar na esquerda
    treePointer ptrLeft = search(t->leftNode, x);
    if (ptrLeft != NULL)
    {
        return ptrLeft;
        // se n der certo, tenta na direita
    }
    else
    {
        // retorna ou o valor do x que esta a procura, ou o X ou nulo
        return search(t->rightNode, x);
    }
}

void binaryTree::insert(string pai, string fLeft, string fRight)
{
    if (empty())
    {
        // se a arvore estiver vazia, inicia criando uma nova
        root = new treeNode;
        root->entry = pai;

        // adiciona o nó da esquerda
        root->leftNode = new treeNode;
        root->leftNode->entry = fLeft;
        root->leftNode->leftNode = NULL;
        root->leftNode->rightNode = NULL;

        // adiciona o nó da direita
        root->rightNode = new treeNode;
        root->rightNode->entry = fRight;
        root->rightNode->leftNode = NULL;
        root->rightNode->rightNode = NULL;
    }
    else
    {
        treePointer find = search(root, pai);
        if (find != NULL) // achou o nó pai que ele esta procurando
        {
            // adicionna o nó da esquerda
            find->leftNode = new treeNode;
            find->leftNode->entry = fLeft;
            find->leftNode->leftNode = NULL;
            find->leftNode->rightNode = NULL;

            // adiciona o nó da direita
            find->rightNode = new treeNode;
            find->rightNode->entry = fRight;
            find->rightNode->leftNode = NULL;
            find->rightNode->rightNode = NULL;
        }
    }
}
