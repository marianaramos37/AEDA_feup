#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli): lotacao(lot), numMaximoClientes(nMaxCli) {
    vagas=lotacao;
}
unsigned int ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for(int i=0;i<clientes.size();i++){
        if (nome==clientes[i].nome) {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if(clientes.size()==numMaximoClientes) return false;
    for (int i=0; i<clientes.size(); i++){
        if (clientes[i].nome==nome) return false;
    }
    InfoCartao a;
    a.nome=nome;
    a.presente= false;
    clientes.push_back(a);
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome){
    int a;
    if (vagas==0) return false;
    for (int i=0; i<clientes.size(); i++){
        if (clientes[i].nome==nome){
            if (clientes[i].presente==true) return false;
            else{
                clientes[i].presente=true;
                vagas-=1;
                return true;
            }
            a+=1;
        }
    }
    if (a==0) return false;
}

bool ParqueEstacionamento::retiraCliente(const string & nome){
    for (int i=0; i<clientes.size(); i++){
        if (clientes[i].nome==nome && clientes[i].presente==false) {
            clientes.erase(clientes.begin() + i);
            return true;
        }
    }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome){
    for (int i=0; i<clientes.size(); i++){
        if(clientes[i].nome==nome && clientes[i].presente==true){
            vagas+=1;
            clientes[i].presente=false;
            return true;
        }
    }
    return false;
}
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}
unsigned int ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}



