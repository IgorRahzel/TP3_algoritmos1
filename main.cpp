#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "loja.hpp"
#include <fstream> //REMOVER REMOVER  R E M O V E R
int main() {
  
int numTests;
int numMaterial;
int price;
loja store;
fstream file; //REMOVER REMOVER  R E M O V E R
file.open("saida.txt",ios::out); //REMOVER REMOVER  R E M O V E R
cin >> numTests;

while(numTests > 0){
  cin >> numMaterial;
  vector<int> vec;
  store.setNumItens(numMaterial);
  for(int i = 0; i < numMaterial; i++){
    cin >> price;
    vec.push_back(price);
  }
  store.setPriceVector(vec);
  store.initializeMDOVector();
  file << store.OPT() << endl;
  numTests--;
}

  return(0);
}
