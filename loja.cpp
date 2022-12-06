#include "loja.hpp"

//construtor da classe
loja::loja(){

}

//registra os preços dos rolos
void loja::setVecPrices(vector<int> vec){
    vec_prices = vec;
}

//inicializa os vectors left and right 
//com tamanho igual ao numero de rolos
//do caso teste e entradas igual a zero
void loja::initializeLeftAndRight(int numMaterial){
    //limpa vectors para proximos testes
    left.clear(); 
    right.clear();

    left.resize(numMaterial,0);
    right.resize(numMaterial,0);
}

//registra o numero de rolos
void loja::setNumMaterial(int n){
    numMaterial = n;
}

//retorna o valor maximo de rolos que
//podem ser colocados em ordem decrescente
int loja::MAX(){
    int max = 0;
    for(int i = 0; i < numMaterial; i++){
        if(left[i] + right[i] > max){
            max = left[i] + right[i];
        }
    }
    return max + 1;
}

//Determina número máximo de valores
//que podem ser inseridos a esquerda e direita
//de um numero vec_prices[i]
int loja::findOptimal(){
    for(int i = numMaterial - 2; i >= 0; i--){
        for(int j = i+1 ; j < numMaterial; j++){
            //determina maximo de numeros a direita
            if(vec_prices[i] > vec_prices[j] && right[i] < right[j] + 1){
                right[i] = 1 + right[j];
            }
            //determina maximo de numeros a esquerda
            else if(vec_prices[i] < vec_prices[j] && left[i] < left[j] + 1){
                left[i] = 1 + left[j];
            }
        }
    }
    return MAX();
}