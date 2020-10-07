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

///\brief Class Morada representa uma morada atraves da sua rua, localidade e numero.
class Morada{
    ///\brief A rua da morada;
    string rua;
    ///\brief A localidade da morada;
    string localidade;
    ///\brief O numero da porta da morada;
    string numero;
public:
    ///\brief Construtor da classe Morada.
    Morada();

    ///\brief Constroi uma instância de Morada recebendo uma string estruturada com o seu conteúdo.
    Morada(string morada);

    ///\brief Constroi uma instância de Morada recebendo uma a rua, o numero e a localidade.
    ///\param rua: A rua da morada;
    ///\param numero: O número da porta da morada;
    ///\param rua: A localidade da morada;
    Morada(string rua, string numero, string localidade);

    ///\brief Destrutor da classe morada.
    virtual ~Morada();

    /* METODOS GET E SET */
    const string &getRua() const;
    void setRua(const string &rua);
    const string &getLocalidade() const;
    void setLocalidade(const string &localidade);
    string getNumero() const;
    void setNumero(string numero);
};

///\brief Class Prato representa um prato atraves do seu nome, tipo de culinária e o respetivo preço.
class Prato{
    ///\brief O nome do prato.
    string nome;
    ///\brief O tipo de culinaria do prato.
    string tipo_de_culinaria;
    ///\brief O preço do prato.
    double preco;

public:
    ///\brief Construtor da classe Prato.
    Prato();
    ///\brief Destrutor da classe Prato.
    virtual ~Prato();

    /* METODOS GET E SET */
    const string &getNome() const;
    void setNome(const string &nome);
    const string &getTipoDeCulinaria() const;
    void setTipoDeCulinaria(const string &tipoDeCulinaria);
    double getPreco() const;
    void setPreco(double preco);

    ///\brief Lê o ficheiro dos pratos.txt, guardando-os num vetor com objetos "Prato".
    ///\return Retorna um vetor com objetos da classe Prato.
    vector<Prato> pratos_readfile();
};

///\brief Class Data representa uma data atraves do dia, mes e ano.
class Data{
    ///\brief O dia da Data.
    int dia;
    ///\brief O mês da Data.
    int mes;
    ///\brief O ano da Data.
    int ano;

public:
    ///\brief Construtor da Classe Data.
    Data();
    ///\brief Constroi uma instância de Data recebendo uma string estruturada com o seu conteudo.
    ///\param d: A string estruturada com o conteudo da morada.
    Data(string d);
    ///\brief Destrutor da Classe Data.
    virtual ~Data();

    /* METODOS GET E SET */
    int getDia() const;
    void setDia(int dia);
    int getMes() const;
    void setMes(int mes);
    int getAno() const;
    void setAno(int ano);
};

///\brief Class Veiculo representa um veículo atraves da sua marca, do seu tipo e a sua data de aquisição.
class Veiculo {
    string marca, tipo, data_de_aquisicao, matricula;
    int km, numEntregas;
    bool precisaArranjo;

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

    string getMatricula() const;

    void setMatricula(string &matricula);

    int getKm() const;

    void setKm(int km);

    int getNumEntregas() const;

    void setNumEntregas(int numEntregas);

    bool isPrecisaArranjo() const;

    void setPrecisaArranjo(bool precisaArranjo);

    bool operator<(const Veiculo &v) const;
};
#endif //PROJETOAEDA_AUXILIARES_H