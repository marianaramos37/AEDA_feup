#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1){
    veiculos.push_back(v1);
}
int Frota::numVeiculos() const{
    return veiculos.size();
}
int Frota::menorAno() const{
    if (veiculos.size()==0){return 0;}
    int a=veiculos[0]->getAno();
    for (int i=1;i<veiculos.size();i++){
        if((*veiculos[i]).getAno()<a){ //*veiculos[i].getAno ==== veiculos[i]->getAno
            a=veiculos[i]->getAno();
        }
    }
    return a;
}


ostream & operator<<(ostream & o, const Frota & f)
{
    vector<Veiculo *>::const_iterator it=f.veiculos.begin();
    while(it!=f.veiculos.end()) {
        (*it)->info();
        it++;
    }
    return o;
}

vector<Veiculo *> Frota::operator () (int anoM) const{
    vector<Veiculo*> a;
    for(int i=0; i<veiculos.size();i++){
        if(veiculos[i]->getAno()==anoM){
            a.push_back(veiculos[i]);
        }
    }
    return a;
}