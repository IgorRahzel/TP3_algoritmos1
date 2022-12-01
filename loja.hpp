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
        int numMaterial;
        vector<int> left;
        vector<int> right;
        vector<int> vec_prices;

    public:
        loja();
        void setVecPrices(vector<int> vec);
        void setNumMaterial(int n);
        void initializeLeftAndRight(int numMaterial);
        int findOptimal();
        int MAX();
};


#endif