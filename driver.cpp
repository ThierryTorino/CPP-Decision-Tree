#include "BT.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void import(binaryTree &t)
{
    // variaveis uteis
    string nomeArquivo, pai, fLeft, fRight;
    cout << "Digite o nome do arquivo .tree: ";

    getline(cin, nomeArquivo); // le o nome do arquivo
    ifstream arquivo;
    arquivo.open(nomeArquivo); // tenta abrir o arquivo
    if (!arquivo.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
        return;
    }

    while (arquivo >> pai >> fLeft >> fRight)
    {
        if (pai == "X" && fLeft == "X" && fRight == "X") // se for o caso "X""X""X" para o while
        {
            break;
        }
        t.insert(pai, fLeft, fRight); // aplica o insert no pai e nos filhos
    }
}

int main()
{
    binaryTree Arvore;
    import(Arvore);
    Arvore.preOrder();

    return 0;
}