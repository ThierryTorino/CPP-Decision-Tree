# 🌳 Binary Tree em C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Finalizado-success?style=for-the-badge)

Este projeto é uma implementação em C++ de uma **Árvore Binária (Binary Tree)** desenvolvida para disciplina de Estrutura de Dados. O programa lê a estrutura da árvore (como arquivos `.tree`), constrói os nós dinamicamente na memória e realiza travessias e buscas de forma recursiva.

---

## ⚙️ Funcionalidades

* **Construção Dinâmica:** Inserção de nós pai, filho à esquerda e filho à direita utilizando ponteiros.
* **Sistema de Busca:** Algoritmo recursivo (`search`) para encontrar nós específicos dentro da árvore.
* **Travessia em Pré-Ordem (Pre-Order):** Mapeia a árvore exibindo o nome do nó, a quantidade de filhos e a sua classificação hierárquica:
  * `E` - Possui apenas filho à Esquerda.
  * `D` - Possui apenas filho à Direita.
  * `ED` - Possui filhos em ambos os lados.
  * `F` - É um nó Folha (sem filhos).
* **Tratamento de Nós Vazios:** O sistema reconhece a string `"X"` como indicador de ausência de nó, evitando alocações desnecessárias.
* **Gerenciamento de Memória:** Destrutor otimizado (`clear()`) que varre a árvore deletando os ponteiros e liberando a memória corretamente.

---

## 📂 Estrutura dos Arquivos

Os arquivos do projeto estão organizados da seguinte forma:

```text
📦 Raiz do Projeto
 ┣ 📂 .vscode/           # Configurações do ambiente
 ┣ 📜 BT.h               # Header file: Definição da classe binaryTree e seus métodos
 ┣ 📜 BT.cpp             # Lógica e implementação dos métodos da árvore
 ┣ 📜 driver.cpp         # Função main() que executa e testa a estrutura
 ┣ 📜 driver.exe         # Executável compilado (Windows)
 ┗ 📜 exemplo1.tree      # Arquivo de exemplo contendo os dados para popular a árvore
