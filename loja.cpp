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
    mdo.resize(numItens);
}

int loja::OPT(){
    int MAX = 1;
    for(int i = 1; i < numItens; i++){
        for(int j = 0; j < i; j++){
            if(i==1){
                mdo[0].seq.push_front(prices[0]); 
            }
            else{
                if(prices[i] < mdo[j].seq.back() && mdo[i].sequenceSize < mdo[j].sequenceSize + 1){
                    mdo[i] = mdo[j];
                    mdo[i].seq.push_back(prices[i]);
                    mdo[i].sequenceSize++;
                    if(mdo[i].sequenceSize > MAX){
                        MAX = mdo[i].sequenceSize;
                    }
                }
                else if(prices[i] > mdo[j].seq.front() && mdo[i].sequenceSize < mdo[j].sequenceSize + 1){
                    mdo[i] = mdo[j];
                    mdo[i].seq.push_front(prices[i]);
                    mdo[i].sequenceSize++;
                    if(mdo[i].sequenceSize > MAX){
                        MAX = mdo[i].sequenceSize;
                    }
                }
            }
        }
    }
    return MAX;
}