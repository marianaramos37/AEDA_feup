#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
    return (numeros.find(num) != numeros.end());
}

//a alterar
void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    int total = 0;
    auto it = valores.begin();
    while (total <n){
        if (numeros.find(*it) == numeros.end()) { // se numero nao existe no vetor numeros
            numeros.insert(*it);
            total++;
        }
        it++;
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt &sorteio) const
{
    int cnt=0;
    tabHInt::const_iterator it;
    for(it=sorteio.begin(); it!=sorteio.end(); it++){
        if(contem(*it)){
            cnt++;
        }
    }
    return cnt;
}





