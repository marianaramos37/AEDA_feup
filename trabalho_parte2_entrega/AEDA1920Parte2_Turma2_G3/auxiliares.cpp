#include "auxiliares.h"
#include <fstream>
#include <string>


//sorts


//tipos de culinaria
vector<string> tiposculinaria(string tipos){
    vector<string> tipos_temp;
    tipos_temp.push_back(tipos);
    return tipos_temp;
}


//CLASSE MORADA
Morada::Morada() {}
Morada::Morada(string morada) {
    string temp = "";
    vector<string> morada_temp;

    for (size_t i = 0; i <= morada.length(); i++)
    {
        if (morada[i] == ',' )
        {
            i += 1;
            morada_temp.push_back(temp);
            temp = "";
        }
        else
            temp += morada[i];
    }
    morada_temp.push_back(temp);

    this->rua = morada_temp[0];
    this->localidade= morada_temp[1];
    this->numero = morada_temp[2];
}

Morada::Morada(string r, string num, string loc) {
    this->rua = r;
    this->numero = num;
    this->localidade = loc;
}

Morada::~Morada() {}

const string &Morada::getRua() const {
    return rua;
}

void Morada::setRua(const string &r) {
    rua = r;
}

const string &Morada::getLocalidade() const {
    return localidade;
}

void Morada::setLocalidade(const string &loc) {
    localidade = loc;
}

string Morada::getNumero() const {
    return numero;
}

void Morada::setNumero(string num) {
    numero = num;
}


// CLASSE PRATO

Prato::Prato() {}

Prato::~Prato() {

}

const string &Prato::getNome() const {
    return nome;
}

void Prato::setNome(const string &nome) {
    Prato::nome = nome;
}

const string &Prato::getTipoDeCulinaria() const {
    return tipo_de_culinaria;
}

void Prato::setTipoDeCulinaria(const string &tipoDeCulinaria) {
    tipo_de_culinaria = tipoDeCulinaria;
}

double Prato::getPreco() const {
    return preco;
}

void Prato::setPreco(double preco) {
    Prato::preco = preco;
}

vector<Prato> Prato::pratos_readfile() {
    Prato p;
    vector<Prato> pratos;
    vector<string> prato_info;
    ifstream infile;
    string line;
    infile.open("pratos.txt");
    while(getline(infile,line)){
        if(line==":::::"){
            p.setNome(prato_info[0]);
            p.setTipoDeCulinaria(prato_info[1]);
            p.setPreco(stod(prato_info[2]));
            pratos.push_back(p);
            prato_info.clear();
        }else{
            prato_info.push_back(line);
        }
    }
    p.setNome(prato_info[0]);
    p.setTipoDeCulinaria(prato_info[1]);
    p.setPreco(stod(prato_info[2]));
    pratos.push_back(p);
    prato_info.clear();
    return pratos;
}
//CLASSE DATA

Data::Data() {}
Data::Data(string d) {
    string temp = "";
    vector<int> data_info;
    for (size_t i = 0; i < d.length(); i++)
    {
        if (d[i] == '/')
        {
            data_info.push_back(stoi(temp));
            temp = "";
        }
        else
            temp += d[i];
    }

    data_info.push_back(stoi(temp));
    this->dia = data_info[0];
    this->mes = data_info[1];
    this->ano = data_info[2];
}

Data::~Data() {

}

int Data::getDia() const {
    return dia;
}

void Data::setDia(int dia) {
    Data::dia = dia;
}

int Data::getMes() const {
    return mes;
}

void Data::setMes(int mes) {
    Data::mes = mes;
}

int Data::getAno() const {
    return ano;
}

void Data::setAno(int ano) {
    Data::ano = ano;
}

//CLASSE VEICULO

Veiculo::Veiculo() {}
Veiculo::Veiculo(string v) {
    Data d;
    string temp=  "";
    vector<string> veiculo_temp;
    for (size_t i = 0; i <= v.length(); i++)
    {
        if (v[i] == ',' )
        {
            i += 1;
            veiculo_temp.push_back(temp);
            temp = "";
        }
        else
            temp += v[i];
    }
    veiculo_temp.push_back(temp);

    this->marca = veiculo_temp[0];
    this->tipo= veiculo_temp[1];
    this->data_de_aquisicao = veiculo_temp[2];
    this->matricula=veiculo_temp[3];
    this->km =stoi( veiculo_temp[4]);
    this->numEntregas = stoi(veiculo_temp[5]);
    if(veiculo_temp[6]=="0"){
        this->precisaArranjo=true;
    } else{
        this->precisaArranjo= false;
    }

}

Veiculo::~Veiculo() {

}

const string &Veiculo::getMarca() const {
    return marca;
}

void Veiculo::setMarca(const string &marca) {
    Veiculo::marca = marca;
}

const string &Veiculo::getTipo() const {
    return tipo;
}

void Veiculo::setTipo(const string &tipo) {
    Veiculo::tipo = tipo;
}

const string &Veiculo::getDataDeAquisicao() const {
    return data_de_aquisicao;
}

void Veiculo::setDataDeAquisicao(const string &dataDeAquisicao) {
    data_de_aquisicao = dataDeAquisicao;
}
string Veiculo::getMatricula() const {
    return matricula;
}

void Veiculo::setMatricula( string &matricula) {
    Veiculo::matricula = matricula;
}

int Veiculo::getKm() const {
    return km;
}

void Veiculo::setKm(int km) {
    Veiculo::km = km;
}

int Veiculo::getNumEntregas() const {
    return numEntregas;
}

void Veiculo::setNumEntregas(int numEntregas) {
    Veiculo::numEntregas = numEntregas;
}
bool  Veiculo::operator<(const Veiculo &v) const {
    if(numEntregas<v.getNumEntregas()){
        return true;
    }else if(numEntregas==v.getNumEntregas() && km<v.getKm()){
        return true;
    }else{
        return false;
    }
}

bool Veiculo::isPrecisaArranjo() const {
    return precisaArranjo;
}

void Veiculo::setPrecisaArranjo(bool precisaArranjo) {
    Veiculo::precisaArranjo = precisaArranjo;
}
