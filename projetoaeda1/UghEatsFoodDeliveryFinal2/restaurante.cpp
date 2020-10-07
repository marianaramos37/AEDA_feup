#include "restaurante.h"
#include "fstream"
#include "vector"
#include "iostream"
using namespace std;
//CLASSE RESTAURANTE

Restaurante::Restaurante() {}

Restaurante::~Restaurante() {

}

const string &Restaurante::getNome() const {
    return nome;
}

void Restaurante::setNome(const string &nome) {
    Restaurante::nome = nome;
}

const Morada &Restaurante::getMorada() const {
    return morada;
}

void Restaurante::setMorada(const Morada &morada) {
    Restaurante::morada = morada;
}

const vector<string> &Restaurante::getTiposDeCulinaria() const {
    return tipos_de_culinaria;
}

void Restaurante::setTiposDeCulinaria(const vector<string> &tiposDeCulinaria) {
    tipos_de_culinaria = tiposDeCulinaria;
}

const vector<Prato> &Restaurante::getPratos() const {
    return pratos;
}

void Restaurante::setPratos(const vector<Prato> &pratos) {
    Restaurante::pratos = pratos;
}

void Restaurante::pratos_readfile(){
    Prato p;
    vector<string> prato_info;
    ifstream infile;
    string line;
    infile.open("pratos.txt");
    this->pratos.clear();
    while(getline(infile,line)){
        if(line==":::::"){
            p.setNome(prato_info[0]);
            p.setTipoDeCulinaria(prato_info[1]);
            p.setPreco(stod(prato_info[2]));
            if (p.getTipoDeCulinaria() == this->tipos_de_culinaria[0]) {
                this->pratos.push_back(p);
            }
            prato_info.clear();
        }else{
            prato_info.push_back(line);
        }
    }
    p.setNome(prato_info[0]);
    p.setTipoDeCulinaria(prato_info[1]);
    p.setPreco(stod(prato_info[2]));
    if (p.getTipoDeCulinaria() == this->tipos_de_culinaria[0]) {
        this->pratos.push_back(p);
    }
    prato_info.clear();
    return;
}

bool Restaurante::operator< (Restaurante a){
    if(nome<a.getNome())
        return true;
    return false;
}

vector<Restaurante> Restaurante::sortRestaurantesPorZona(vector<Restaurante> v){
    vector<Restaurante> res;
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Porto")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Matosinhos")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Vila Nova de Gaia")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Maia")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Gondarem")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Lisboa")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Amadora")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Loures")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Faro")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Loule")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getMorada().getLocalidade()=="Sao Bras de Alportel")
            res.push_back(v[i]);
    }
    return res;
}

vector<Restaurante> Restaurante::sortRestaurantesPorComida(vector<Restaurante> v){
    vector<Restaurante> res;
    for(int i=0; i<v.size(); i++){
        if(v[i].getTiposDeCulinaria()[0]=="Portuguesa")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getTiposDeCulinaria()[0]=="Italiana")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getTiposDeCulinaria()[0]=="Chinesa")
            res.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].getTiposDeCulinaria()[0]=="Japonesa")
            res.push_back(v[i]);
    }
    return res;
}

vector<Restaurante> Restaurante::sortRestaurantesPorNome(vector<Restaurante> v) {
}