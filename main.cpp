#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "loja.hpp"

int main() {
  
int numTests;
int numMaterial;
int price;
loja store;

cin >> numTests;

while(numTests > 0){
  cin >> numMaterial;
  store.setNumItens(numMaterial);
  for(int i = 0; i < numMaterial; i++){
    cin >> price;
    store.insertPrice(price);
  }
  store.initilizeMatrix();


  numTests--;
}

  return(0);
}
