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
///\brief Class Cliente representa um cliente atraves da sua Morada, nome, nif e Base pertencente.
class Cliente{
    ///\brief A morada do Cliente.
    Morada morada;
    ///\brief O nome do Cliente.
    string name;
    ///\brief O nif do Cliente.
    string nif;
    ///\brief A base a que o Cliente pertence.
    Base base;

public:
    ///\brief Construtor da classe Cliente.
    Cliente();
    ///\brief Destrutor da classe Cliente.
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
