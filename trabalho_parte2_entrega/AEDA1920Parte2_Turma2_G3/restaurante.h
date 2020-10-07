#ifndef PROJETOAEDA_RESTAURANTE_H
#define PROJETOAEDA_RESTAURANTE_H

#include "auxiliares.h"

#include <string>
#include <vector>

using namespace std;

/*
 * CLASSES:
 *
 * RESTAURANTE
 *
 * */
///\brief Class Restaurante representa um restaurante atraves do seu nome, da sua Morada, do seu menu(vetor de pratos) e conjunto de tipos de culinária.
class Restaurante{
    ///\brief O nome do Restaurante.
    string nome;
    ///\brief A morada do Restaurante.
    Morada morada;
    ///\brief O conjunto de tipos de culinária do Restaurante.
    vector<string> tipos_de_culinaria;
    ///\brief O menu/conjunto de pratos do Restaurante.
    vector<Prato> pratos;
public:
    ///\brief Construtor da classe Restaurante.
    Restaurante();
    ///\brief Destrutor da classe Restaurante.
    virtual ~Restaurante();

    /* METODOS GET E SET */
    const Morada &getMorada() const;
    const string &getNome() const;
    void setNome(const string &nome);
    void setMorada(const Morada &morada);
    const vector<string> &getTiposDeCulinaria() const;
    void setTiposDeCulinaria(const vector<string> &tiposDeCulinaria);
    const vector<Prato> &getPratos() const;
    void setPratos(const vector<Prato> &pratos);

    ///\brief Lê o ficheiro dos pratos.txt, que contem um conjunto de objetos da classe Prato.
    void pratos_readfile();

    ///\brief Ordena um vetor de Restaurantes por Zona/Concelho a que pertence, organizando-o.
    ///\param v: Vetor com objetos da Classe Restaurante.
    ///\return Retorna um vetor com objetos da classe Restaurante.
    vector<Restaurante> sortRestaurantesPorZona(vector<Restaurante> v);

    ///\brief Ordena um vetor de Restaurantes por Tipo de Culinaria, organizando-o.
    ///\param v: Vetor com objetos da Classe Restaurante.
    ///\return Retorna um vetor com objetos da classe Restaurante.
    vector<Restaurante> sortRestaurantesPorComida(vector<Restaurante> v);

    vector<Restaurante> sortRestaurantesPorNome(vector<Restaurante> v);

    ///\brief Operador menor usado para fazer sort(), ordenar, um vetor de Restaurantes.
    ///\param a: Objeto da Classe Restaurante.
    ///\return Verdadeiro ou falso consoante o operador.
    bool operator< (Restaurante a);
};

#endif //PROJETOAEDA_RESTAURANTE_H
