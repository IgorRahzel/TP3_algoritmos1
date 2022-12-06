#ifndef LOJA_H
#define LOJA_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>

using namespace std;

class loja{
    private:
        int numMaterial; //numero de rolos do caso de teste
        vector<int> left; //maximo de rolos que podem ser colocados na esquerda de left[i]
        vector<int> right; //maximo de rolos que podem ser colocados na direita de right[i]
        vector<int> vec_prices; //vetor contendo os preços dos rolos

    public:
        loja();
        void setVecPrices(vector<int> vec);
        void setNumMaterial(int n);
        void initializeLeftAndRight(int numMaterial);
        int findOptimal();
        int MAX();
};


#endif