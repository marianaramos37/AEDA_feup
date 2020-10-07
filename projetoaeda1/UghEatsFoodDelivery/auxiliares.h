#ifndef PROJETOAEDA_AUXILIARES_H
#define PROJETOAEDA_AUXILIARES_H

#include <string>
#include <vector>

using namespace std;

/*
 * CLASSES:
 *
 * MORADA
 * PRATO
 * DATA
 * VEICULO
 *
 * */


vector<string> tiposculinaria(string tipos);

class Morada{
    string rua, localidade;
    string numero;
public:
    Morada();
    Morada(string morada);
    Morada(string rua, string numero, string localidade);
    virtual ~Morada();

    /* METODOS GET E SET */
    const string &getRua() const;
    void setRua(const string &rua);
    const string &getLocalidade() const;
    void setLocalidade(const string &localidade);
    string getNumero() const;
    void setNumero(string numero);
};

class Prato{
    string nome, tipo_de_culinaria;
    double preco;

public:
    Prato();
    virtual ~Prato();

    /* METODOS GET E SET */
    const string &getNome() const;
    void setNome(const string &nome);
    const string &getTipoDeCulinaria() const;
    void setTipoDeCulinaria(const string &tipoDeCulinaria);
    double getPreco() const;
    void setPreco(double preco);

    vector<Prato> pratos_readfile();
};

class Data{
    int dia, mes, ano;

public:

    Data();
    Data(string d);
    virtual ~Data();

    /* METODOS GET E SET */
    int getDia() const;
    void setDia(int dia);
    int getMes() const;
    void setMes(int mes);
    int getAno() const;
    void setAno(int ano);
};

class Veiculo{
    string marca, tipo, data_de_aquisicao;

public:

    Veiculo();
    Veiculo(string v);
    virtual ~Veiculo();

    /* METODOS GET E SET */
    const string &getMarca() const;
    void setMarca(const string &marca);
    const string &getTipo() const;
    void setTipo(const string &tipo);
    const string &getDataDeAquisicao() const;
    void setDataDeAquisicao(const string &dataDeAquisicao);
};
#endif //PROJETOAEDA_AUXILIARES_H
