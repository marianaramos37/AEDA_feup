#ifndef PARQUE_H_
#define PARQUE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class InfoCartao {
public:
	string nome;
	bool presente;
	int frequencia;
	bool operator < (const InfoCartao &ic1) const{
	    if (frequencia>ic1.frequencia)
	        return true;
	    else if (frequencia< ic1.frequencia)
	        return false;
	    else
	        return (nome<ic1.nome);
	}
	bool operator == (const InfoCartao &ic1) const{
        if (frequencia==ic1.frequencia)
            return true;
        else if (frequencia!= ic1.frequencia)
            return false;
        else
            return (nome==ic1.nome);
	}
};

class ClienteNaoExistente{
public:
    string nome;
    ClienteNaoExistente(const string &n) {
        nome = n;
    }
    string getNome()const{
        return nome;
    }

};

class PosicaoNaoExistente{
    int valor;
public:
    PosicaoNaoExistente(int p): valor(p) {}
    int getValor() const { return valor; }
};


class ParqueEstacionamento {
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	unsigned int numClientes;
	const unsigned int numMaximoClientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli);
	~ParqueEstacionamento();
	vector<InfoCartao> getClientes() const;
	bool adicionaCliente(const string & nome);
	bool retiraCliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	unsigned int getNumLugares() const;
	unsigned int getNumLugaresOcupados() const;
	int posicaoCliente(const string & nome) const;
	friend ostream & operator<<(ostream & os, const ParqueEstacionamento & pe);
	int getFrequencia(const string &nome) const;
	InfoCartao getClienteAtPos(vector<InfoCartao>::size_type p) const;
	void ordenaClientesPorFrequencia();
	void ordenaClientesPorNome();
	vector<string> clientesGamaUso(int n1, int n2);
};

#endif /*PARQUE_H_*/
