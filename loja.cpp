#include "loja.hpp"

loja::loja(){

}

void loja::setNumItens(int a){
    this->numItens = a;
}

void loja::setPriceVector(vector<int> vec){
    prices = vec;
}

void loja::initializeMDOVector(){
    mdo.clear();
    mdo.resize(numItens);
}

int loja::OPT(){
    int MAX = 1;
    int index_MAX = -1;
    list<int> aux;

    mdo[0].seq.push_front(prices[0]);

    for(int i = 1; i < numItens; i++){
        if(index_MAX != -1 && prices[i] < aux.back() && mdo[index_MAX].seq.back() < prices[i]){
            mdo[i].seq = aux;
            mdo[i].seq.push_back(prices[i]);
            index_MAX = i;
        }
        else if(index_MAX != -1 && prices[i] > aux.front() && mdo[index_MAX].seq.front() > prices[i]){
            mdo[i].seq = aux;
            mdo[i].seq.push_front(prices[i]);
            index_MAX = i;
        }
        else{
            for(int j = 0; j < i; j++){  
                //inserir na direita
                if(prices[i] < mdo[j].seq.back() && mdo[i].sequenceSize <= mdo[j].sequenceSize + 1){
                    mdo[i] = mdo[j];
                    mdo[i].seq.push_back(prices[i]);
                    mdo[i].sequenceSize++;
                    if(mdo[i].sequenceSize > MAX){
                        MAX = mdo[i].sequenceSize;
                        index_MAX = i;
                        aux = mdo[i].seq;
                        aux.pop_front();
                        aux.pop_back();
                    }
                }
                //inserir na esquerda
                else if(prices[i] > mdo[j].seq.front() && mdo[i].sequenceSize <= mdo[j].sequenceSize + 1){
                    mdo[i] = mdo[j];
                    mdo[i].seq.push_front(prices[i]);
                    mdo[i].sequenceSize++;
                    if(mdo[i].sequenceSize > MAX){
                        MAX = mdo[i].sequenceSize;
                        index_MAX = i;
                        aux = mdo[i].seq;
                        aux.pop_front();
                        aux.pop_back();
                    }
                }
            }
        }
    }
    return MAX;
}