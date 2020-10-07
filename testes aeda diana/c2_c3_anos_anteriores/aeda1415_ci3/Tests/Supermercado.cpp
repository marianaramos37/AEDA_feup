/*
 * Supermercado.cpp
 *
 * Created on: Dec 3, 2014
 *
 */

#include "Supermercado.h"
#include <iostream>

//A ser implementado pelo estudante!

//a)
int Cliente::numeroItens() const{
    int n=0;
    list<Cesto>::const_iterator it;
    for(it=cestos.begin(); it!=cestos.end(); it++){
        if(!it->empty())
            n+= it->getItens().size();
    }
    return n;
}

int Cliente::valorItens() const{
    int n=0;
    list<Cesto>::const_iterator it;
    for(it=cestos.begin(); it!=cestos.end(); it++){
        if(!it->empty()){
            stack<Item> items = it->getItens();
            while(!items.empty()){
                n+= items.top().preco;
                items.pop();
            }
        }
    }
    return n;
}

int Cliente::trocarItem(Item& novoItem){
    int n=0;
    list<Cesto>::iterator it;
    for(it=cestos.begin(); it!=cestos.end(); it++){
        if(!it->empty()){
            stack<Item> items;
            while(!it->empty()){
                if(it->topItem().produto == novoItem.produto){
                    items.push(novoItem);
                    n++;
                }
                items.push(it->topItem());
                it->popItem();
            }
            it->getItens() = items;
        }
    }
    return n;
}

bool Item::operator <(const Item & i) const{
    return peso < i.peso;
}

void Cliente::organizarCestos(){
    list<Cesto>::iterator it;
    vector<Item>::reverse_iterator rit;
    for(it=cestos.begin(); it!=cestos.end(); it++){ //corre a lista de cestos
        if(!it->empty()){ //se o cesto não estiver vazio
            vector<Item> items;  //cria um vetor para usar sort
            while(!it->empty()){
                items.push_back(it->topItem());
                it->popItem();
            }
            sort(items.begin(), items.end());
            for(rit = items.rbegin(); rit != items.rend(); rit++){
                it->pushItem(*rit);
            }
        }
    }
}

bool ordenarPorTipo(const Item & i1, const Item & i2){
    return i1.tipo < i2.tipo;
}

vector<string> Cliente::contarItensPorTipo(){
    list<Cesto>::iterator it;
    vector<string> resultado;
    vector<Item> produtos;
    string tipo,res;
    int n;

    //coloca todos os artigos no mesmo vector
    for(it=cestos.begin(); it!=cestos.end(); it++){
        stack<Item> items = it->getItens();
        while(!items.empty()){
            produtos.push_back(items.top());
            items.pop();
        }
    }
    sort(produtos.begin(), produtos.end(), ordenarPorTipo); //ordena o vetor de items por tipo

    for(size_t i=0; i< produtos.size(); i++){
        if(i==0) tipo =produtos[i].tipo;
        else{
            if(produtos[i].tipo == tipo)
                n++;
            else{
                res= tipo+" "+to_string(n);
                resultado.push_back(res);
                n=1;
                tipo =produtos[i].tipo;
            }
        }
    }
    res= tipo+" "+to_string(n);
    resultado.push_back(res);
    return resultado;

}

int Cesto::novoItem(const Item& umItem){
    stack<Item> itensCopy = itens;
    int p=0,v=0;

    while(!itensCopy.empty()){
        p+=itensCopy.top().peso;
        v+=itensCopy.top().volume;
        itensCopy.pop();
    }
    if(p + umItem.peso <= max_peso && v + umItem.volume <= max_volume)
        itens.push(umItem);
    else return 0;

    return itens.size();
}

int Cliente::novoItem(const Item& umItem){
    list<Cesto>::iterator it;
    bool novoCesto = true;
    for(it=cestos.begin(); it!= cestos.end(); it++){
        if(it->novoItem(umItem) != 0){
            novoCesto = false;
            break;
        }
    }
    if(novoCesto){
        Cesto c;
        c.pushItem(umItem);
        cestos.push_back(c);
    }
    return cestos.size();
}

int Supermercado::novoCliente(Cliente& umCliente){
    if(umCliente.getIdade()>= 65){
        if(filaNormal.size() >= filaPrioritaria.size())
            filaPrioritaria.push(umCliente);
        else filaNormal.push(umCliente);
    }
    else
        filaNormal.push(umCliente);

    int espera = filaPrioritaria.size() + filaNormal.size();
    return espera;
}

Cliente Supermercado::sairDaFila(string umNomeDeCliente){
    queue<Cliente> tmp;
    bool found=false;
    Cliente c;


    while (!filaPrioritaria.empty()) {
        if (filaPrioritaria.front().getNome() != umNomeDeCliente) {
            tmp.push(filaPrioritaria.front());
        } else {
            found = true;
            c = filaPrioritaria.front();
        }
        filaPrioritaria.pop();
    }
    filaPrioritaria = tmp;
    if (found) return c;



    queue<Cliente> tmp2;
    while(!filaNormal.empty()){
        if(filaNormal.front().getNome() != umNomeDeCliente){
            tmp2.push(filaNormal.front());
        }
        else{
            found = true;
            c = filaNormal.front();
        }
        filaNormal.pop();
    }
    filaNormal = tmp2;
    if(found) return c;


    throw ClienteInexistente(umNomeDeCliente);
}