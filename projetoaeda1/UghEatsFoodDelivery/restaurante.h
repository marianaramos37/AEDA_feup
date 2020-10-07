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

class Restaurante{
    string nome;
    Morada morada;
    vector<string> tipos_de_culinaria;
    vector<Prato> pratos;
public:
    Restaurante();
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

    void pratos_readfile();

    vector<Restaurante> sortRestaurantesPorZona(vector<Restaurante> v);
    vector<Restaurante> sortRestaurantesPorComida(vector<Restaurante> v);
    vector<Restaurante> sortRestaurantesPorNome(vector<Restaurante> v);

    bool operator< (Restaurante a);
};

#endif //PROJETOAEDA_RESTAURANTE_H
