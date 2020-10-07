#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"

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
 
//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts()
{
    vector<CKart> vord;
    for(int i=0; i<getPistas().size(); i++){
        for(int j=0; j< getPistas()[i].getFrotaActual().size(); j++)
            vord.push_back(getPistas()[i].getFrotaActual()[j]);
    }
    for(unsigned int j=vord.size()-1; j>0; j--)
    {
        bool troca=false;
        for(unsigned int i = 0; i<j; i++)
            if(vord[i+1].getNumero() < vord[i].getNumero()) {
                swap(vord[i],vord[i+1]);
                troca = true;
            }
        if (!troca) return vord;
    }
    //return vord;
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    vector<CKart> vord;
    for(int i=0; i<getPistas().size(); i++){
        for(int j=0; j< getPistas()[i].getFrotaActual().size(); j++)
            if(getPistas()[i].getFrotaActual()[j].getAvariado() && getPistas()[i].getFrotaActual()[j].getCilindrada()==cilind)
                vord.push_back(getPistas()[i].getFrotaActual()[j]);
    }
    return vord.size();
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind) {
    int num=0;
    for(int i=0; i<frotaKartsPista.size(); i++){
        if(frotaKartsPista[i].getCilindrada()==cilind && !frotaKartsPista[i].getAvariado()) {
            kartsLinhaPartida.push(frotaKartsPista[i]);
            num++;
            if (num == numeroKarts) break;
        }
    }
    if(kartsLinhaPartida.size()==numeroKarts) return true;
    return false;
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    int size=kartsLinhaPartida.size();
    for (int i=0; i<size; i++){
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
    }
    return kartsEmProva.size();
}

