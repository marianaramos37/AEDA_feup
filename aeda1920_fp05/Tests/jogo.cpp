/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

// a implementar
Jogo::Jogo()
{
}

// a implementar
Jogo::Jogo(list<Crianca>& lc2)
{
    criancas=lc2;
}

// a implementar
void Jogo::insereCrianca(const Crianca &c1)
{
    criancas.push_back (c1);
}

// a implementar
list<Crianca> Jogo::getCriancasJogo() const
{
    return criancas;
}

// a implementar
string Jogo::escreve() const
{
    string res;
    list <Crianca>::const_iterator it;
    for (it = criancas.begin(); it!=criancas.end(); it++){
        res+=it->getNome() + " : " + to_string(it->getIdade()) + '\n' ;
    }
    return res;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    Crianca *c1 = new Crianca();
    list <Crianca>::const_iterator itinicio=criancas.begin();
    list <Crianca>::const_iterator itfim=criancas.end();
    while(criancas.size()>1) {
        int a=(numPalavras(frase)-1)%criancas.size();
        for (int i=0; i<a; i++) {
            itinicio++;
            if (itinicio == itfim) {
                itinicio=criancas.begin();
            }
        }
        itinicio=criancas.erase(itinicio); //aponta para o seguinte
        if (itinicio==criancas.end()) itinicio=criancas.begin();
        *c1=*itinicio;
    }
    return *c1;
}

// a implementar
list<Crianca>& Jogo::inverte()
{
    /*
    list<Crianca>::iterator itb=criancas.begin();
    list<Crianca>::iterator ite=criancas.end();
    ite--;
    for (int i=0; i<4; i++){
        itb=criancas.insert(itb,*ite);
        criancas.pop_back();
        itb++;
        ite--;
    }*/
    criancas.reverse();
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    list<Crianca>::iterator itb=criancas.begin();
    for (int i=0; i<criancas.size(); i++){
        if(itb->getIdade()>id){
            res.push_back(*itb);
            criancas.pop_front();
        }
        itb++;
    }
    return res;
}

// a implementar
void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    criancas=l1;
}

// a implementar
bool Jogo::operator==(Jogo& j2)
{
    if(criancas==j2.getCriancasJogo()) return true; //dá para comparar duas listas assim
	return false;
}

// a implementar
bool existe(vector<int> v, int n)
{
    for(int i=0;i<v.size();i++)
        if(n==v.at(i))
            return true;

    return false;
}
list<Crianca> Jogo::baralha() const
{
    list<Crianca> res;
    vector<int> pos;
    //int cnt=0;
    //int cnt2=0;
    list<Crianca>::const_iterator it=criancas.begin();
    while(pos.size()!=criancas.size()){
        int randNum = rand()%criancas.size();
        if(!existe(pos,randNum)){
            pos.push_back(randNum);
        }
    }
    while(res.size()!=criancas.size()){
        for(int i=0;i<pos.size();i++){
            /*if(pos.at(i)==cnt){
                while(cnt2<i){
                    it++;
                    cnt2++;
                }*/
               // cnt2=0;
                res.push_back(*it);
                it++;
                //cnt++;
                break;
            }
    }
    return res;
}
