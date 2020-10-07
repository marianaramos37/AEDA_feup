#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"
#include "algorithm"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
bool CKart::operator <(const CKart & ckart) const{
    return numero < ckart.getNumero();
}

bool CKart::operator ==(const CKart & ckart) const{
    return numero == ckart.getNumero();
}

//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts()
{
	vector<CKart> vord;
	for(unsigned int i= 0; i< pistasG.size(); i++){
	    vector<CKart> karts= pistasG[i].getFrotaActual();
	    for(unsigned int j=0; j<karts.size(); j++){
	        if(find(vord.begin(), vord.end(),karts[j]) == vord.end())
                vord.push_back(karts[j]);
	    }
	}

	sort(vord.begin(), vord.end());
	return vord;
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    int res=0;
    vector<CKart>::iterator it1;

    for(unsigned int i= 0; i< pistasG.size(); i++){
        vector<CKart>avariados = pistasG[i].getKartsAvariados();
        for(it1=avariados.begin(); it1!= avariados.end(); it1++ ){
            if((*it1).getCilindrada() == cilind)
                res++;
        //desncessário - já há uma função para isto
        /*vector<CKart> karts= pistasG[i].getFrotaActual();
        for(it1=karts.begin(); it1!= karts.end(); it1++ ){
            if((*it1).getAvariado() && (*it1).getCilindrada() == cilind)
                res++;
        }*/
        }
    }
    return res;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    while(!kartsLinhaPartida.empty()){
        kartsLinhaPartida.pop();
    }

    int n=0;
    for(size_t i=0; i< frotaKartsPista.size(); i++){
        if(n>=numeroKarts)
            break;
        if(cilind == frotaKartsPista[i].getCilindrada()){
            kartsLinhaPartida.push(frotaKartsPista[i]);
            n++;
        }
    }

    if(n<numeroKarts)return false;
    return true;
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    while(!kartsLinhaPartida.empty()){
        CKart c = kartsLinhaPartida.front();
        if(!c.getAvariado()){
            kartsEmProva.push_back(kartsLinhaPartida.front());
            kartsLinhaPartida.pop();
        }
        else{
            kartsLinhaPartida.pop();
        }
    }
    return kartsEmProva.size();
}
