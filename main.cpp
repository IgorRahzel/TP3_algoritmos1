#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "loja.hpp"

int main() {
  
  int numTests; //numero de casos de teste
  int numMaterial; //quantidade de rolos
  int price; // preço dos rolo

  loja store;

  cin >> numTests;

  while(numTests > 0){

    cin >> numMaterial;

    vector<int> vec; //armazena os preços de cada rolo
    store.setNumMaterial(numMaterial);

    for(int i = 0; i < numMaterial; i++){
      cin >> price;
      vec.push_back(price); //adiciona preço do rolo no vector vec
    }
    store.setVecPrices(vec);
    store.initializeLeftAndRight(numMaterial);
    cout << store.findOptimal() << endl;
    numTests--;
  }
  return(0);
}
