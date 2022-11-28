#ifndef LOJA_H
#define LOJA_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct sequences{
    int sequenceSize = 1;
    list<int> seq;
};

class loja{
    private:
        int numItens;
        vector<int> prices; 
        vector<sequences> mdo; //maximum decreasing order

    public:
        loja();
        void setNumItens(int a);
        void setPriceVector(vector<int> vec);
        void initializeMDOVector();
        int OPT();
};


#endif