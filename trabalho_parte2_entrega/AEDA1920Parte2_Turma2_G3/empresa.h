#ifndef PROJETOAEDA_EMPRESA_H
#define PROJETOAEDA_EMPRESA_H

#include "restaurante.h"
#include <iostream>
#include "BST.h"
#include "tabHFuncionario.h"

/*
 * CLASSES:
 *
 * BASE
 * ENCOMENDA
 * FUNCIONARIOS
 * ADMINISTRADORES * ENTREGADORES
 * EMPRESA
 *
 * */
class Cliente;
class Restaurante;
class Funcionario;
class Entregador;

typedef priority_queue<Funcionario*> HEAP_TECNICO;

/* Excecao */
///\brief Classe ClienteNaListaNegra representa uma exceção que é lançada quando um cliente pertence à Lista Negra da empresa (listanegra.txt).
class ClienteNaListaNegra{
public:
    ///\brief O Cliente pertencente à Lista Negra.
    Cliente* cliente;
    ///\brief Construtor da Classe Lista Negra.
    ClienteNaListaNegra(Cliente &c){ cliente=&c;}
    ///\brief Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const ClienteNaListaNegra &c){
        out << "Devido a pagamentos em atraso nao se pode registar."<<endl;
        return out;
    }
};
///\brief Classe FuncionarioInexistente representa uma exceção que é lançada se tenta aceder a um funcionario que não pertence à lista de funcionarios da base.
class FuncionarioInexistente{
public:
    ///\brief O Funcionario Inexistente.
    Funcionario* funcionario;
    ///\brief Construtor da Classe FuncionarioInexistente.
    FuncionarioInexistente(Funcionario &f){ funcionario=&f;}
    ///\brief Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const FuncionarioInexistente &f){
        out << "Esse funcionario nao e nosso trabalhador!"<<endl;
        return out;
    }
};
///\brief Classe RestauranteInexistente representa uma exceção que é lançada quando tenta aceder a um Restaurante que não pertence à lista de restaurantes da base.
class RestauranteInexistente{
public:
    ///\brief O Restaurante Inexistente.
    Restaurante* restaurante;
    ///\brief Construtor da Classe RestautanteInexistente.
    RestauranteInexistente(Restaurante &r){
        restaurante=&r;
    }
    ///\brief Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const RestauranteInexistente &r){
        out << "Esse restaurante nao pertence a nossa cadeia de fornecedores!"<<endl;
        return out;
    }
};

///\brief Classe Encomenda representa uma encomenda através do nome do Restauranre, Data e hora da encomenda, nome do Entregador e Cliente, lista de pratos do menu
/// encomendados, se a encomenda foi realizada com sucesso e se foi realizada dentro ou num concelho vizinho, e o preço total da encomenda.
class Encomenda{
    ///\brief O nome do Restaurante da encomenda.
    string restauranteNome;
    ///\brief A data da encomenda.
    Data data;
    ///\brief O nome do entregador da encomenda.
    string entregadorNome;
    ///\brief A hora da encomenda.
    string hora;
    ///\brief Os pratos encomendados.
    string pratosNome;
    ///\brief Booleano que representa se a encomenda foi realizada dentro ou fora.
    bool entrega; //dentro ou fora
    ///\brief Booleano que representa se a encomenda foi realizada com sucesso.
    bool sucesso;
    ///\brief O nome do Cliente que realizou a encomenda.
    string clienteNome;
    ///\brief O preço da encomenda.
    double preco;
public:
    ///\brief Construtor da classe Encomenda.
    Encomenda();
    ///\brief Destrutor da classe Encomenda.
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

///\brief Classe Funcionario representa um funcionário através do seu nome e nif, da sua Data de nascimento, do seu Salario e do seu tipo(Entregador/Administrador).
class Funcionario{
    ///\brief O nome do Funcionário.
    string nome;
    ///\brief O nif do Funcionário.
    string nif;
    ///\brief A data de nascimento do Funcionário.
    Data data;
    ///\brief O salário do Funcionário.
    int salario;
    ///\brief O tipo de Funcionário.
    string tipoDeFuncionario;


public:
    ///\brief Construtor da classe Funcionário.
    Funcionario();
    ///\brief Construtor da classe Funcionário.
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
    virtual int getDisponibilidade() const;
    virtual void setDisponibilidade(int disponibilidade);
    virtual int getManutencoes() const;
    virtual void setManutencoes(int manutencoes);
    virtual bool operator>(Funcionario* t);
    /*
    virtual HEAP_TECNICO getTecnicoFila() const;
    virtual void addTecnicoToFila(Funcionario *r);
    virtual void removeTecnicoFromFila(string nif);
*/

};

///\brief Classe Administrador representa um funcionário Administrador através das suas caracteristicas enquanto Funcionário, mais a sua função.
class Administrador: public Funcionario{
    ///\brief A função do Administrador.
    string funcao;
public:
    ///\brief Construtor da classe Administrador.
    Administrador();
    ///\brief Destrutor da classe Administrador.
    virtual ~Administrador();

    /* METODOS GET E SET */
    const string getFuncao() const;
    void setFuncao(const string &funcao);
};

///\brief Classe Entregador representa um funcionário Entregador através das suas características enquanto Funcionário, mais o seu Veículo, um vetor de
/// encomendas (classe Encomenda) feitas, e a sua disponibilidade.
class Entregador: public Funcionario{
    ///\brief O veiculo do entregador.
    Veiculo veiculo_alocado;
    ///\brief O vetor de encomendas (Classe Encomenda) feitas pelo entregador.
    vector<Encomenda> encom_feitas;
    ///\brief A sua disponibilidade.
    bool disponivel;
public:
    ///\brief Construtor da classe Entregador.
    Entregador();
    ///\brief Destrutor da classe Entregador.
    virtual ~Entregador();

    /* METODOS GET E SET */
    const Veiculo getVeiculoAlocado() const;
    void setVeiculoAlocado(const Veiculo &veiculoAlocado);
    vector<Encomenda> getEncomFeitas();
    void setEncomFeitas(const vector<Encomenda> &encomFeitas);
    bool isDisponivel() const;
    void setDisponivel(bool disponivel);
};

///\brief Classe Técnico representa um funcionário técnico através das suas características enquanto Funcionário, mais a sua disponibilidade e
/// o número de manutenções já efetuaadas.
class Tecnico:public Funcionario{
    ///brief O número de horas ate estar disponivel.
    int disponibilidade;
    ///brief O número de manutenções já efetuadas.
    int manutencoes;
    //HEAP_TECNICO tecnicos_fila;
public:
    ///\brief Construtor da classe Técnico.
    Tecnico();
    ///\brief Destrutor da classe Técnico.
    virtual ~Tecnico();

    /* METODOS GET E SET */
    int getDisponibilidade() const;
    void setDisponibilidade(int disponibilidade);
    int getManutencoes() const;
    void setManutencoes(int manutencoes);
    bool operator>(Funcionario* t);
    /*
    HEAP_TECNICO getTecnicoFila() const;
    void addTecnicoToFila(Funcionario *r);
    void removeTecnicoFromFila(string nif);
*/
    //bool vehicleToMaintenance();

};

///\brief Classe Base representa uma Base da Empresa através da sua Morada, conselho, coordenadas GPS, gerente, conjunto de Clientes, conjunto de Restaurantes
/// e o conjunto de funcionários dessa Base.
class Base{
    ///\brief A morada da Base.
    Morada morada;
    ///\brief O conselho da Base.
    string conselho;
    ///\brief As coordenadas GPS da Base.
    string coordenadaGPS;
    ///\brief O gerente da Base.
    string gerente;
    ///\brief O nome do ficheiro que contem todos os clientes da Base.
    string clientes_filename;
    ///\brief O nome do ficheiro que contem todos os restaurantes da Base.
    string restaurantes_filename;
    ///\brief O nome do ficheiro que contem todos os funcionários da Base.
    string funcionarios_filename ;
    ///\brief O conjunto dos clientes da Base.
    vector <Cliente> clientes;
    ///\brief O conjunto dos clientes pertencentes à Lista Negra da Empresa.
    vector <Cliente> listaNegra;
    ///\brief O conjunto dos restaurantes da Base.
    vector <Restaurante> restaurantes;
    ///\brief O conjunto dos funcionários da Base.
    vector <Funcionario*> funcionarios;
    ///\brief fila de prioridade de tecnicos de acordo com a sua disponibilidade.
    HEAP_TECNICO tecnicos_fila;
    ///\brief tabela de disperção com os funcionários antigos e atuais da base.
    tabHFuncionario funcionarios_tabH; //tabH


public:
    ///\brief Construtor da classe Base.
    Base();
    ///\brief Constroi uma instância de Base recebendo uma string estruturada com o seu conteudo.
    Base(string base);
    ///\brief Destrutor da classe Base.
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
    ///\brief Lê o ficheiro clientes.txt, que contém a informacao ordenada de um conjunto de clientes (Classe Cliente).
    void clientes_readfile();

    ///\brief Lê o ficheiro funcionarios<Base>.txt, que contém a informacão ordenada de um conjunto de funcionários (Classe Funcionário).
    void funcionarios_readfile();

    ///\brief Lê o ficheiro restaurante<Base>.txt, que contém a informacao ordenada de um conjunto de restaurantes (Classe Restaurante).
    void restaurantes_readfile();

    ///\brief Lê o ficheiro listanegra.txt, que contém a informacao ordenada de um conjunto de clientes (Classe Cliente).
    void listaNegra_readfile();
    ///\brief Lê o ficheiro funcionariosAntigos.txt, que contém a informacao ordenada funcionarios antigos.
    void funcionariosAntigos_readfile();
    /* ADD */
    ///\brief Adinciona um Cliente à Base.
    void addCliente();
    ///\brief Adinciona um Restaurante à Base.
    void addRestaurante();
    ///\brief Adinciona um funcionário Administrador à Base.
    void addAdmin();
    ///\brief Adinciona um funcionario Entregador à Base.
    void addEntreg();
    ///\brief Adinciona um funcionario Tecnico à Base.
    void addTecnico();
    /* REMOVE */
    ///\brief Remove um Cliente da Base.
    void removeCliente(Cliente c);
    ///\brief Remove um Restaurante da Base.
    void removeRestaurante(Restaurante r);
    ///\brief Remove um Funcionário da Base.
    void removeFuncionario(Funcionario f);
    ///\brief Remove um funcionário do tipo Administrador da Base.
    void removeAdmin(Funcionario f);
    ///\brief Remove um funcionário do tipo Entregador da Base.
    void removeEntreg(Funcionario f);
    ///\brief Remove um funcionário do tipo Tecnico da Base.
    void removeTecnico(Funcionario f);

    HEAP_TECNICO getTecnicoFila() const;

    ///\brief Adiciona um funcionário do tipo Tecnico na Fila de prioridade.
    void addTecnicoToFila(Funcionario *r);

    ///\brief Remove um funcionário do tipo Tecnico na Fila de prioridade.
    void removeTecnicoFromFila(string nif);

    vector<Funcionario*> getFuncionariosTodos();
    void setFuncionariosTodos(const vector<Funcionario* > &funcionariosv);


};

///\brief Classe Empresa representa a Empresa através do conjunto de Bases (classe Base) que tem e um conjunto de encomendas feitas à empresa desde sempre.
class Empresa{
    ///\brief O conjunto de bases (Classe Base) da Empresa.
    vector<Base> bases;
    ///\brief O conjuntor de encomendas (Classe Encomenda) da Empresa.
    vector <Encomenda> encomendas;
    BST<Veiculo> veiculos;
    //HEAP_TECNICO tecnicos_fila;

public:
    ///\brief Construtor da classe Empresa.
    Empresa(): veiculos(Veiculo()){};
    ///\brief Donstrutor da classe Empresa.
    virtual ~Empresa();

    /* METODOS GET E SET */
    const vector<Base> &getBases() const;
    void setBases(const vector<Base> &bases);
    vector<Encomenda> getEncomendas ();
    void setEncomendas(vector<Encomenda>);

    /* READ FILES */
    ///\brief Lê o ficheiro encomendas.txt, que contém a informação ordenada de um conjunto de encomendas (Classe Encomenda).
    void encomendas_readfile();
    void addVeiculo(const Veiculo& v);
    vector<Veiculo> verVeiculo();

    /*HEAP_TECNICO getTecnicoFila() const;
    void addTecnicoToFila(Funcionario *r);
    void removeTecnicoFromFila(string nif);*/
};

#endif //PROJETOAEDA_EMPRESA_H
