#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a){
    marca=mc;
    mes=m;
    ano=a;
}
string Veiculo::getMarca() const{
    return marca;
}
int Veiculo::getAno() const{
    return ano;
}
int Veiculo::info() const{
    cout<<"Marca:"<<marca<<endl;
    cout<<"Mês:"<<mes<<endl;
    cout<<"Ano:"<<ano<<endl;
    return 3;
}
bool Veiculo::operator < (const Veiculo & v) const{
    if(ano<v.ano){return true;}
    if(ano==v.ano && mes<v.mes){return true;}
    else{return false;}
}



Motorizado::Motorizado(string mc, int m, int a,string c,int cil):Veiculo(mc,m,a){
    combustivel=c;
    cilindrada=cil;
}
string Motorizado::getCombustivel() const{
    return combustivel;
}
int Motorizado::info() const{
    Veiculo::info();
    cout<<"Combustivel:"<<combustivel<<endl;
    cout<<"cilindrada:"<<cilindrada<<endl;
    return 5;
}

float Motorizado::calcImposto() const{
    if(combustivel=="gasolina") {
        if (ano > 1995) {
            if (cilindrada <= 1000) { return 14.56; }
            if (cilindrada > 1000 && cilindrada <= 1300) { return 29.06; }
            if (cilindrada > 1300 && cilindrada <= 1750) { return 45.15; }
            if (cilindrada > 1750 && cilindrada <= 2600) { return 113.98; }
            if (cilindrada > 2600 && cilindrada <= 3500) { return 181.17; }
            if (cilindrada > 3500) { return 320.89; }
        } else {
            if (cilindrada <= 1000) { return 8.10; }
            if (cilindrada > 1000 && cilindrada <= 1300) { return 14.56; }
            if (cilindrada > 1300 && cilindrada <= 1750) { return 22.65; }
            if (cilindrada > 1750 && cilindrada <= 2600) { return 54.89; }
            if (cilindrada > 2600 && cilindrada <= 3500) { return 87.13; }
            if (cilindrada > 3500) { return 148.37; }
        }
    }
    else{
        if (ano > 1995) {
            if (cilindrada <= 1500) { return 14.56; }
            if (cilindrada > 1500 && cilindrada <= 2000) { return 29.06; }
            if (cilindrada > 2000&& cilindrada <= 3000) { return 45.15; }
            if (cilindrada > 3000) { return 113.98; }
        } else {
            if (cilindrada <= 1500) { return 8.10; }
            if (cilindrada > 1500 && cilindrada <= 2000) { return 14.56; }
            if (cilindrada > 2000&& cilindrada <= 3000) { return 22.65; }
            if (cilindrada > 3000) { return 54.89; }
        }
    }
}

Automovel::Automovel(string mc, int m, int a,string c, int cil):Motorizado(mc,m,a,c,cil){}

int Automovel::info() const{
    Motorizado::info();
    return 5;
}
float Automovel::calcImposto() const{
    Motorizado::calcImposto();
}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm):Motorizado(mc,m,a,c,cil){
    carga_maxima=cm;
}
int Camiao::info() const{
    Motorizado::info();
    cout<<"Carga Máxima:"<<carga_maxima<<endl;
    return 6;
}
float Camiao::calcImposto() const{
    Motorizado::calcImposto();
}


Bicicleta::Bicicleta(string mc, int m, int a,string t):Veiculo(mc,m,a){
    tipo=t;
}
int Bicicleta::info() const{
    Veiculo::info();
    cout<<"Tipo:"<<tipo<<endl;
    return 4;
}
