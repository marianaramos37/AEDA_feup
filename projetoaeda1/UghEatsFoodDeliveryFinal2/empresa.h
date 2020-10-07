#ifndef PROJETOAEDA_EMPRESA_H
#define PROJETOAEDA_EMPRESA_H

#include "restaurante.h"
#include <iostream>
using namespace std;

/*
 * CLASSES:
 *
 * BASE
 * ENCOMENDA
 * FUNCIONARIOS
 * ADMINISTRADORES
 * ENTREGADORES
 * EMPRESA
 *
 * */
class Cliente;
class Restaurante;
class Funcionario;
class Entregador;

/* Excecao */
class ClienteNaListaNegra{
public:
    Cliente* cliente;
    ClienteNaListaNegra(Cliente &c){ cliente=&c;}
    friend ostream & operator<<(ostream &out, const ClienteNaListaNegra &c){
        out << "Devido a pagamentos em atraso nao se pode registar."<<endl;
        return out;
    }
};
class FuncionarioInexistente{
public:
    Funcionario* funcionario;
    FuncionarioInexistente(Funcionario &f){ funcionario=&f;}
    friend ostream & operator<<(ostream &out, const FuncionarioInexistente &f){
        out << "Esse funcionario nao e nosso trabalhador!"<<endl;
        return out;
    }
};
class RestauranteInexistente{
public:
    Restaurante* restaurante;
    RestauranteInexistente(Restaurante &r){
        restaurante=&r;
    }
    friend ostream & operator<<(ostream &out, const RestauranteInexistente &r){
        out << "Esse restaurante nao pertence a nossa cadeia de fornecedores!"<<endl;
        return out;
    }
};

class Encomenda{
    string restauranteNome;
    Data data;
    string entregadorNome;
    string hora;
    string pratosNome;
    bool entrega; //dentro ou fora
    bool sucesso;
    string clienteNome;
    double preco;
public:
    Encomenda();
    virtual ~Encomenda();

    /* METODOS GET E SET */
    const string &getRestauranteNome() const;
    void setRestauranteNome(const string &restaurante);
    const Data &getData() const;
    void setData(const Data &data);
    string &getEntregadorNome() ;
    void setEntregadorNome(const string entregador);
    const string &getHora() const;
    void setHora(const string &hora);
    string &getPratosNome();
    void setPratosNome(string &pratos);
    bool isEntrega() const;
    void setEntrega(bool entrega);
    bool isSucesso() const;
    void setSucesso(bool sucesso);
    string getClienteNome ();
    void setClienteNome(string c);
    double getPreco();
    void setPreco(double p);

};

class Funcionario{
    string nome, nif ;
    Data data;
    int salario;
    string tipoDeFuncionario;
public:
    Funcionario();
    virtual ~Funcionario();

    /* METODOS GET E SET */
    virtual const string &getNome() const;
    virtual void setNome(const string &nome);
    virtual const Data &getData() const;
    virtual void setData(const Data &data);
    virtual string getNif() const;
    virtual void setNif(string nif);
    virtual int getSalario() const;
    virtual void setSalario(int salario);
    virtual const string getFuncao() const;
    virtual void setFuncao(const string &funcao);
    virtual const Veiculo getVeiculoAlocado() const;
    virtual void setVeiculoAlocado(const Veiculo &veiculoAlocado);
    virtual vector<Encomenda> getEncomFeitas();
    virtual void setEncomFeitas(const vector<Encomenda> &encomFeitas);
    virtual bool isDisponivel() const;
    virtual void setDisponivel(bool disponivel);
    void setTipoDeFuncionario(string t);
    string getTipoDeFuncionario();
};

class Administrador: public Funcionario{
    string funcao;
public:
    Administrador();
    virtual ~Administrador();

    /* METODOS GET E SET */
    const string getFuncao() const;
    void setFuncao(const string &funcao);
};

class Entregador: public Funcionario{
    Veiculo veiculo_alocado;
    vector<Encomenda> encom_feitas;
    bool disponivel;
public:
    Entregador();
    virtual ~Entregador();

    /* METODOS GET E SET */
    const Veiculo getVeiculoAlocado() const;
    void setVeiculoAlocado(const Veiculo &veiculoAlocado);
    vector<Encomenda> getEncomFeitas();
    void setEncomFeitas(const vector<Encomenda> &encomFeitas);
    bool isDisponivel() const;
    void setDisponivel(bool disponivel);
};

class Base{
    Morada morada;
    string conselho, coordenadaGPS, gerente, clientes_filename,restaurantes_filename, funcionarios_filename ;
    vector <Cliente> clientes;
    vector <Cliente> listaNegra;
    vector <Restaurante> restaurantes;
    vector <Funcionario*> funcionarios;
public:
    Base();
    Base(string base);
    virtual ~Base();
    /* METODOS GET E SET */
    const Morada &getMorada() const;
    void setMorada(const Morada &morada);
    const string &getConselho() const;
    void setConselho(const string &conselho);
    const string &getCoordenadaGps() const;
    void setCoordenadaGps(const string &coordenadaGps);
    const string &getGerente() const;
    void setGerente(const string &gerente);
    vector<Cliente> getClientes() ;
    void setClientes(vector<Cliente> &clientes);
    vector<Restaurante> getRestaurantes() ;
    void setRestaurantes( vector<Restaurante> &restaurantes);
    vector<Funcionario*> getFuncionarios() ;
    void setFuncionarios(const vector<Funcionario*> &funcionarios);
    string getFuncionariosFileName();
    string getClientesFileName();
    vector <Cliente> getListaNegra();
    void getListaNegra(vector <Cliente> l);
    /* READ FILES */
    void clientes_readfile();
    void funcionarios_readfile();
    void restaurantes_readfile();
    void listaNegra_readfile();
    /* ADD */
    void addCliente();
    void addRestaurante();
    void addAdmin();
    void addEntreg();
    /* REMOVE */
    void removeCliente(Cliente c);
    void removeRestaurante(Restaurante r);
    void removeFuncionario(Funcionario f);
    void removeAdmin(Funcionario f);
    void removeEntreg(Funcionario f);
};


class Empresa{
    vector<Base> bases;
    vector <Encomenda> encomendas;
public:
    Empresa();
    virtual ~Empresa();

    /* METODOS GET E SET */
    const vector<Base> &getBases() const;
    void setBases(const vector<Base> &bases);
    vector<Encomenda> getEncomendas ();
    void setEncomendas(vector<Encomenda>);

    /* READ FILES */
    void encomendas_readfile();

};

#endif //PROJETOAEDA_EMPRESA_H
