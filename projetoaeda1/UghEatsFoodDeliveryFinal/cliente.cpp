#include "cliente.h"

//CLASSE CLIENTE

Cliente::Cliente(){}

Cliente::~Cliente() {
}

const Morada &Cliente::getMorada() const {
    return morada;
}

void Cliente::setMorada(const Morada &morada) {
    Cliente::morada = morada;
}

const string &Cliente::getName() const {
    return name;
}

void Cliente::setName(const string &name) {
    Cliente::name = name;
}

string Cliente::getNif() const {
    return nif;
}

void Cliente::setNif(string nif) {
    Cliente::nif = nif;
}

Base &Cliente::getBase() {
    return base;
}

void Cliente::setBase(const Base &base) {
    Cliente::base = base;
}

