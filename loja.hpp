#ifndef LOJA_H
#define LOJA_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct listAux{
    int numElements = 0;
    list<int> prices;
};

class loja{
    private:
        listAux **Matrix;
        int numItens = 0;  //numero de rolos
        vector<int> materialPrice; //preco do material na ordem recebida

    public:
        loja();
        void insertPrice(int price);
        void  setNumItens(int a);
        void  initilizeMatrix();
        int OPT(int k,int size);
        list<int> max(list<int> v);
        list<int> insere(int index,list<int> v);
};


#endif