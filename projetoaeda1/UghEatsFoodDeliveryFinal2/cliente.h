#ifndef PROJETOAEDA_CLIENTE_H
#define PROJETOAEDA_CLIENTE_H

#include "auxiliares.h"
#include "empresa.h"

#include <string>
#include <vector>

using namespace std;


/*
 * CLASSES:
 *
 * CLIENTE
 *
 * */

class Cliente{
    Morada morada;
    string name, nif;
    Base base;

public:
    Cliente();
    virtual ~Cliente();

    /* METODOS GET E SET */
    const Morada &getMorada() const;
    void setMorada(const Morada &morada);
    const string &getName() const;
    void setName(const string &name);
    string getNif() const;
    void setNif(string nif);
    Base & getBase();
    void setBase(const Base &base);

};


#endif //PROJETOAEDA_CLIENTE_H
