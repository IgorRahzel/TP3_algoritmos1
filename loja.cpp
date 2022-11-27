#include "loja.hpp"

loja::loja(){

}

void loja::setNumItens(int a){
    this->numItens = a+1;
}

void loja::insertPrice(int price){
    materialPrice.push_back(price);
}

void loja::initilizeMatrix(){
    Matrix = new listAux*[numItens];
    for(int i = 0; i < numItens; i++){
        Matrix[i] = new listAux[numItens];
    }
}

list<int> loja::insere(int index, list<int> v){
    int siz = v.size() - 1;
    if(materialPrice[index] > v.front()){
        v.push_front(materialPrice[index]);
    }
    else if(materialPrice[index] < v.back()){
        v.push_back(materialPrice[index]);
    }
    
}

int loja::OPT(int k,int size){
    k++;
    size++;
    for(int i = 0; i < k; i++){
        Matrix[0][i].prices.push_back(0);
        Matrix[i][0].prices.push_back(0);
    }

    for(int i = 1; i < k; i++){
        for(int j = 1; j < size; j++){
            //caso não foi inserido nenhum rolo na prateleira
            if(i==1){
                Matrix[i][j].prices.push_back(materialPrice[0]);
            }
            else if(materialPrice[i] < Matrix[i][j].prices.front() && materialPrice[i] < Matrix[i][j].prices.back()){
                Matrix[i][j].prices = Matrix[i-1][j].prices;
            }
            else
                Matrix[i][j].prices = max(insere(i,Matrix[i-1][j-1].prices));
        }
    }
}
