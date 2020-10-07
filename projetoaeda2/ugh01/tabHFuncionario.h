//
// Created by Mariana Ramos on 02/01/2020.
//

#ifndef UGHEATS_FOOD_DELIVERY_TABHFUNCIONARIO_H
#define UGHEATS_FOOD_DELIVERY_TABHFUNCIONARIO_H

#include <unordered_set>

class Funcionario;

class funcionarioHash{
public:
    int operator() (const Funcionario* f) const;
};
class funcionarioEq{
public:
    bool operator() (const Funcionario* f1,const Funcionario* f2) const;
};

typedef unordered_set<Funcionario*, funcionarioHash, funcionarioEq> tabHFuncionario;

#endif //UGHEATS_FOOD_DELIVERY_TABHFUNCIONARIO_H
