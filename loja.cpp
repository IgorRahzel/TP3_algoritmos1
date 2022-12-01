#include "loja.hpp"

loja::loja(){

}

void loja::setVecPrices(vector<int> vec){
    vec_prices = vec;
}

void loja::initializeLeftAndRight(int numMaterial){
    left.clear();
    right.clear();

    left.resize(numMaterial,0);
    right.resize(numMaterial,0);
}

void loja::setNumMaterial(int n){
    numMaterial = n;
}

int loja::MAX(){
    int max = 0;
    for(int i = 0; i < numMaterial; i++){
        if(left[i] + right[i] > max){
            max = left[i] + right[i];
        }
    }
    return max + 1;
}

int loja::findOptimal(){
    for(int i = numMaterial - 2; i >= 0; i--){
        for(int j = i+1 ; j < numMaterial; j++){
            if(vec_prices[i] > vec_prices[j] && right[i] < right[j] + 1){//tentar colocar == depois ao inves de right[j] + 1
                right[i] = 1 + right[j];
            }
            else if(vec_prices[i] < vec_prices[j] && left[i] < left[j] + 1){//tentar colocar == depois ao inves de right[j] + 1
                left[i] = 1 + left[j];
            }
        }
    }
    return MAX();
}