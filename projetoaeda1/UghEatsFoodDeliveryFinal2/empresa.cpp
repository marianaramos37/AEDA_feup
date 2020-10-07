#include "iostream"
#include "empresa.h"
#include "cliente.h"
#include "auxiliares.h"
#include <fstream>
using namespace std;
//CLASSE ENCOMENDA

Encomenda::Encomenda(){}

Encomenda::~Encomenda() {

}

const string &Encomenda::getRestauranteNome() const {
    return restauranteNome;
}

void Encomenda::setRestauranteNome(const string &restaurante) {
    Encomenda::restauranteNome = restaurante;
}

const Data &Encomenda::getData() const {
    return data;
}

void Encomenda::setData(const Data &data) {
    Encomenda::data = data;
}

string &Encomenda::getEntregadorNome(){
    return entregadorNome;
}

void Encomenda::setEntregadorNome( const string e) {
    Encomenda::entregadorNome = e;
}


const string &Encomenda::getHora() const {
    return hora;
}

void Encomenda::setHora(const string &hora) {
    Encomenda::hora = hora;
}

string &Encomenda::getPratosNome() {
    return pratosNome;
}

void Encomenda::setPratosNome(string &pratos) {
    Encomenda::pratosNome = pratos;
}

bool Encomenda::isEntrega() const {
    return entrega;
}

void Encomenda::setEntrega(bool entrega) {
    Encomenda::entrega = entrega;
}

bool Encomenda::isSucesso() const {
    return sucesso;
}

void Encomenda::setSucesso(bool sucesso) {
    Encomenda::sucesso = sucesso;
}
string Encomenda::getClienteNome (){
    return clienteNome;
}
void Encomenda::setClienteNome(string c){
    clienteNome=c;
}
double Encomenda::getPreco(){
    return preco;
}
void Encomenda::setPreco(double p){
    preco=p;
}


//CLASSE FUNCIONARIO

Funcionario::Funcionario() {}
Funcionario::~Funcionario() {

}
const string &Funcionario::getNome() const {
    return nome;
}
void Funcionario::setNome(const string &nome) {
    Funcionario::nome = nome;
}
const Data &Funcionario::getData() const {
    return data;
}
void Funcionario::setData(const Data &data) {
    Funcionario::data = data;
}
string Funcionario::getNif() const {
    return nif;
}
void Funcionario::setNif(string n) {
    nif = n;
}
int Funcionario::getSalario() const {
    return salario;
}
void Funcionario::setSalario(int salario) {
    Funcionario::salario = salario;
}
const string Funcionario::getFuncao() const{string a; return a;}
void Funcionario::setFuncao(const string &funcao){return;}
const Veiculo Funcionario::getVeiculoAlocado() const{Veiculo v; return v;}
void Funcionario::setVeiculoAlocado(const Veiculo &veiculoAlocado){return;}
vector<Encomenda> Funcionario::getEncomFeitas() {vector<Encomenda> v; return v;}
void Funcionario::setEncomFeitas(const vector<Encomenda> &encomFeitas){return;}
bool Funcionario::isDisponivel() const{return true;}
void Funcionario::setDisponivel(bool disponivel){return;}
void Funcionario::setTipoDeFuncionario(string t){
    tipoDeFuncionario=t;
}
string Funcionario::getTipoDeFuncionario(){
    return tipoDeFuncionario;
}


//CLASSE ADMINISTRADORES

Administrador::Administrador() {}
Administrador::~Administrador() {

}
const string Administrador::getFuncao() const {
    return funcao;
}
void Administrador::setFuncao(const string &f) {
    funcao = f;
}


//CLASSE ENTREGADORES
Entregador::Entregador(){}
Entregador::~Entregador() {

}
const Veiculo Entregador::getVeiculoAlocado() const {
    return veiculo_alocado;
}
void Entregador::setVeiculoAlocado(const Veiculo &veiculoAlocado) {
    veiculo_alocado = veiculoAlocado;
}
vector<Encomenda> Entregador::getEncomFeitas(){
    return encom_feitas;
}
void Entregador::setEncomFeitas(const vector<Encomenda> &encomFeitas) {
    encom_feitas = encomFeitas;
}
bool Entregador::isDisponivel() const {
    return disponivel;
}
void Entregador::setDisponivel(bool disponivel) {
    Entregador::disponivel = disponivel;
}

//CLASSE BASE

Base::Base(){}

Base::Base(string base_filename) {
    ifstream infile;
    infile.open(base_filename);

    string r;
    getline(infile, r);
    this->morada.setRua(r);
    string l;
    getline(infile, l);
    this->morada.setLocalidade(l);
    string n;
    getline(infile, n);
    this->morada.setNumero(n);
    getline(infile, this->conselho);
    getline(infile, this->coordenadaGPS);
    getline(infile, this->gerente);
    getline(infile,clientes_filename);
    getline(infile, restaurantes_filename);
    getline(infile, funcionarios_filename );

    infile.close();
}

Base::~Base() {

}

const Morada &Base::getMorada() const {
    return morada;
}

const string &Base::getConselho() const {
    return conselho;
}

const string &Base::getCoordenadaGps() const {
    return coordenadaGPS;
}

const string &Base::getGerente() const {
    return gerente;
}

vector<Cliente> Base::getClientes() {
    return clientes;
}


vector<Restaurante> Base::getRestaurantes(){

    return restaurantes;
}

 vector<Funcionario*> Base::getFuncionarios() {
    return funcionarios;
}

void Base::setMorada(const Morada &morada) {
    Base::morada = morada;
}

void Base::setConselho(const string &conselho) {
    Base::conselho = conselho;
}

void Base::setCoordenadaGps(const string &coordenadaGps) {
    coordenadaGPS = coordenadaGps;
}

void Base::setGerente(const string &gerente) {
    Base::gerente = gerente;
}

void Base::setClientes(vector<Cliente> &cs) {
  for(int i=0; i<cs.size(); i++){
      clientes.push_back(cs[i]);
  }
}

void Base::setRestaurantes(vector<Restaurante> &restaurantes) {
    Base::restaurantes = restaurantes;
}

void Base::setFuncionarios(const vector<Funcionario*> &funcionarios) {
    Base::funcionarios = funcionarios;
}
string Base::getFuncionariosFileName(){
    return funcionarios_filename;
}
string Base::getClientesFileName(){
    return clientes_filename;
}
vector <Cliente> Base::getListaNegra(){
    return listaNegra;
}
void Base::getListaNegra(vector <Cliente> l){
    listaNegra=l;
}

void Base::clientes_readfile(){
    Cliente c;
    vector<string> cliente_info;
    ifstream infile;
    string line;
    infile.open(clientes_filename);
    while(getline(infile,line)){
        if(line==":::::"){
            c.setName(cliente_info[0]);
            c.setNif(cliente_info[1]);
            c.setMorada(Morada(cliente_info[2]));
            c.setBase(Base(cliente_info[3]+".txt"));
            clientes.push_back(c);
            cliente_info.clear();
        }else{
            cliente_info.push_back(line);
        }
    }
    c.setName(cliente_info[0]);
    c.setNif(cliente_info[1]);
    c.setMorada(Morada(cliente_info[2]));
    c.setBase(Base(cliente_info[3]+".txt"));
    clientes.push_back(c);
    cliente_info.clear();
    return;
}

void Base::restaurantes_readfile(){
    Restaurante r;
    vector<string> restaurante_info;
    string culinaria, pratos;
    vector<string> c,p;
    string temp="";
    ifstream infile;
    string line;
    infile.open(restaurantes_filename);
    while(getline(infile,line)){
        if(line==":::::"){
            r.setNome(restaurante_info[0]);
            r.setMorada(Morada(restaurante_info[1]));
            r.setTiposDeCulinaria(tiposculinaria(restaurante_info[2]));
            r.pratos_readfile();
            restaurantes.push_back(r);
            restaurante_info.clear();
        }else{
            restaurante_info.push_back(line);
        }
    }
    r.setNome(restaurante_info[0]);
    r.setMorada(Morada(restaurante_info[1]));
    r.setTiposDeCulinaria(tiposculinaria(restaurante_info[2]));
    r.pratos_readfile();
    restaurantes.push_back(r);
    restaurante_info.clear();
    return;
}

void Base::funcionarios_readfile(){
    Data d;
    Veiculo v;
    vector<string> funcionario_info;
    ifstream infile;
    string line,veiculo;
    string temp="";
    infile.open(funcionarios_filename);
    while(getline(infile,line)) {
        if (line == ":::::") {
            if(funcionario_info[0]=="Entregador") {
                Entregador *e = new Entregador();
                e->setTipoDeFuncionario(funcionario_info[0]);
                e->setNome(funcionario_info[1]);
                e->setNif(funcionario_info[2]);
                e->setData(Data(funcionario_info[3]));
                e->setSalario(stoi(funcionario_info[4]));
                e->setVeiculoAlocado(Veiculo(funcionario_info[5]));
                e->setDisponivel(stoi(funcionario_info[6]));
                funcionarios.push_back(e);
                funcionario_info.clear();
            }
            else if(funcionario_info[0]=="Administrador") {
                Administrador *a= new Administrador;
                a->setTipoDeFuncionario(funcionario_info[0]);
                a->setNome(funcionario_info[1]);
                a->setNif(funcionario_info[2]);
                a->setData(Data(funcionario_info[3]));
                a->setSalario(stoi(funcionario_info[4]));
                a->setFuncao(funcionario_info[5]);
                funcionarios.push_back(a);
                funcionario_info.clear();
            }
        } else {
            funcionario_info.push_back(line);
        }
    }
    if(funcionario_info[0]=="Entregador") {
        Entregador *e = new Entregador();
        e->setTipoDeFuncionario(funcionario_info[0]);
        e->setNome(funcionario_info[1]);
        e->setNif(funcionario_info[2]);
        e->setData(Data(funcionario_info[3]));
        e->setSalario(stoi(funcionario_info[4]));
        e->setVeiculoAlocado(Veiculo(funcionario_info[5]));
        e->setDisponivel(stoi(funcionario_info[6]));
        funcionarios.push_back(e);
        funcionario_info.clear();
    }
    else if(funcionario_info[0]=="Administrador") {
        Administrador *a= new Administrador;
        a->setTipoDeFuncionario(funcionario_info[0]);
        a->setNome(funcionario_info[1]);
        a->setNif(funcionario_info[2]);
        a->setData(Data(funcionario_info[3]));
        a->setSalario(stoi(funcionario_info[4]));
        a->setFuncao(funcionario_info[5]);
        funcionarios.push_back(a);
        funcionario_info.clear();
    }
    return;
}

void Base::listaNegra_readfile(){
    Cliente c;
    vector<string> cliente_info;
    ifstream infile;
    string line;
    infile.open("listanegra.txt");
    while(getline(infile,line)){
        if(line==":::::"){
            c.setName(cliente_info[0]);
            c.setNif(cliente_info[1]);
            c.setMorada(Morada(cliente_info[2]));
            c.setBase(Base(cliente_info[3]+".txt"));
            listaNegra.push_back(c);
            cliente_info.clear();
        }else{
            cliente_info.push_back(line);
        }
    }
    c.setName(cliente_info[0]);
    c.setNif(cliente_info[1]);
    c.setMorada(Morada(cliente_info[2]));
    c.setBase(Base(cliente_info[3]+".txt"));
    listaNegra.push_back(c);
    cliente_info.clear();
    return;
}

void Base::addCliente() {
    Cliente c;
    Morada m;
    ofstream file;
    string nome,nif,rua,con,num,base, morada;
    int a;
    bool aceite= true;
    cin.ignore();
    cout<<"Nome:"<<endl;
    getline(cin,nome);
    c.setName(nome);
    cout<<"Nif:"<<endl;
    cin>>nif;
    //cin.ignore();
    while(nif.size()>9 || nif.size()<9){
        cout<<"Nif invalido. Volte a inserir:"<<endl;
        cin>>nif;
    }
    bool existe=false;
    for(int i=0;i<clientes.size();i++){
        if(clientes[i].getNif()==nif){
            existe=true;
        }
    }
    listaNegra_readfile();
    for(int i=0; i<listaNegra.size(); i++){
        if(listaNegra[i].getNif()==nif){
            throw ClienteNaListaNegra(clientes[i]);
        }
    }
    while (existe == true) {
        cout << "Ja temos um cliente registado com este nif" << endl;
        cout << "Tente Novamente!" << endl;
        cout << "Nif:" << endl;
        cin >> nif;
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i].getNif() == nif) {
                existe = true;
                break;
            } else existe = false;
        }
    }
    c.setNif(nif);
    cin.ignore();
    cout << "Rua:" << endl;
    getline(cin, rua);
    //cin.ignore();
    cout << "Conselho:" << endl;

    if (conselho == "Porto") {
        cout << "{1} - Porto" << endl;
        cout << "{2} - Matosinhos " << endl;
        cout << "{3} - Vila Nova de Gaia" << endl;
        cout << "{4} - Maia" << endl;
        cout << "{5} - Gondomar" << endl;
        cout << "{0} - Outros" << endl;
        cin >> a;

        switch (a) {
            case 0:
                con = "0";
                break;
            case 1:
                con = "Porto";
                break;
            case 2:
                con = "Matosinhos";
                break;
            case 3:
                con = "Vila Nova de Gaia";
                break;
            case 4:
                con = "Maia";
                break;
            case 5:
                con = "Gondomar";
                break;
            default:
                con = "1";
        }
    }
    if (conselho == "Lisboa") {
        cout << "{1} - Lisboa" << endl;
        cout << "{2} - Oeiras " << endl;
        cout << "{3} - Amadora" << endl;
        cout << "{4} - Odivelas" << endl;
        cout << "{5} - Loures" << endl;
        cout << "{0} - Outro" << endl;
        cin >> a;

        switch (a) {
            case 0:
                con = "0";
                break;
            case 1:
                con = "Lisboa";
                break;
            case 2:
                con = "Oeiras";
                break;
            case 3:
                con = "Amadora";
                break;
            case 4:
                con = "Odivelas";
                break;
            case 5:
                con = "Loures";
                break;
            default:
                con = "1";
        }
    }
    if (conselho == "Faro") {
        cout << "{1} - Faro" << endl;
        cout << "{2} - Loule" << endl;
        cout << "{3} - Olhao" << endl;
        cout << "{4} - Sao Bras de Alportel" << endl;
        cout << "{0} - Outro" << endl;
        cin >> a;

        switch (a) {
            case 0:
                con = "0";
                break;
            case 1:
                con = "Faro";
                break;
            case 2:
                con = "Loule";
                break;
            case 3:
                con = "Olhao";
                break;
            case 4:
                con = "Sao Bras de Alportel";
                break;
            default:
                con = "1";

        }
    }
    if (con != "0" && con != "1") {
        cout << "Numero:" << endl;
        cin >> num;
        morada = rua + ", " + con + ", " + num;
        m = Morada(morada);
        c.setMorada(m);
        clientes.push_back(c);
        cout << "O cliente " << c.getName() << " foi registado com sucesso! " << endl;
        cout << "Obrigada por escolher Ugh Eats Delivery!" << endl;
        file.open(clientes_filename);
        for (int i = 0; i < clientes.size() - 1; i++) {
            file << clientes[i].getName() << endl;
            file << clientes[i].getNif() << endl;
            file << clientes[i].getMorada().getRua() + ", " + clientes[i].getMorada().getLocalidade() + ", " +
                    clientes[i].getMorada().getNumero() << endl;
            file << conselho << endl;
            file << ":::::" << endl;
        }
        file << clientes[clientes.size() - 1].getName() << endl;
        file << clientes[clientes.size() - 1].getNif() << endl;
        file << clientes[clientes.size() - 1].getMorada().getRua() + ", " +
                clientes[clientes.size() - 1].getMorada().getLocalidade() + ", " +
                clientes[clientes.size() - 1].getMorada().getNumero() << endl;
        file << conselho << endl;
    } else if (con == "1") {
        cout << "Opcao Invalida";
    } else {
        cout << "Lamentamos, mas a Ugh Eats ainda nao entraga noutros concelhos" << endl;
    }
}
void Base::removeCliente(Cliente c){
    Base b=c.getBase();
    ofstream file;
    clientes_readfile();
    for(int i=0; i<clientes.size();i++){
        if(clientes[i].getNif()==c.getNif()){
            clientes.erase(clientes.begin()+i);
        }
    }
    file.open(b.clientes_filename);
    for (int i = 0; i < clientes.size()-1; i++) {

        file << clientes[i].getName() << endl;

        file << clientes[i].getNif() << endl;

        file << clientes[i].getMorada().getRua() + ", " + clientes[i].getMorada().getLocalidade() + ", " +clientes[i].getMorada().getNumero() << endl;

        file << conselho << endl;

        file << ":::::" << endl;
    }
    file << clientes[clientes.size()-1].getName() << endl;

    file << clientes[clientes.size()-1].getNif() << endl;

    file << clientes[clientes.size()-1].getMorada().getRua() + ", " + clientes[clientes.size()-1].getMorada().getLocalidade() + ", " +clientes[clientes.size()-1].getMorada().getNumero() << endl;

    file << conselho << endl;

    file.close();
}
void Base::addRestaurante(){
    Restaurante r;
    Morada m;
    ofstream file;
    string nome,rua,con,num,base, morada, culi;
    int a,b;
    vector<string> culinaria;
    cin.ignore();
    cout<<"Nome:"<<endl;
    getline(cin,nome);
    r.setNome(nome);
    cout<< "Rua:"<<endl;
    getline(cin,rua);
    //cin.ignore();
    cout<<"Concelho:"<<endl;
    if(conselho=="Porto") {
        cout << "{1} - Porto" << endl;
        cout << "{2} - Matosinhos " << endl;
        cout << "{3} - Vila Nova de Gaia" << endl;
        cout << "{4} - Maia" << endl;
        cout << "{5} - Gondomar" << endl;
        cin>>a;

        switch(a){
            case 1: con="Porto"; break;
            case 2: con="Matosinhos"; break;
            case 3: con="Vila Nova de Gaia"; break;
            case 4: con="Maia"; break;
            case 5:con="Gondomar";break;
            default:  con="1";
        }
    }
    if(conselho=="Lisboa") {
        cout << "{1} - Lisboa" << endl;
        cout << "{2} - Oeiras " << endl;
        cout << "{3} - Amadora" << endl;
        cout << "{4} - Odivelas" << endl;
        cout << "{5} - Loures" << endl;
        cin>>a;

        switch(a) {
            case 1: con = "Lisboa";break;
            case 2: con = "Oeiras";break;
            case 3: con = "Amadora";break;
            case 4: con = "Odivelas";break;
            case 5: con = "Loures";break;
            default:  con="1";
        }
    }
    if(conselho=="Faro") {
        cout << "{1} - Faro" << endl;
        cout << "{2} - Loule" << endl;
        cout << "{3} - Olhao" << endl;
        cout << "{4} - Sao Bras de Alportel" << endl;
        cin>>a;

        switch(a){
            case 1: con="Faro"; break;
            case 2: con="Loule"; break;
            case 3: con="Olhao"; break;
            case 4: con="Sao Bras de Alportel"; break;
            default:  con="1";

        }
    }
    if(con!="0" && con!="1") {
        cout << "Numero:" << endl;
        cin >> num;
        morada = rua + ", " + con + ", " + num;
        m = Morada(morada);
        r.setMorada(m);
        cout << "Culinaria:" << endl;
        cout << "{1} - Portuguesa"<< endl;
        cout << "{2} - Italiana" << endl;
        cout << "{3} - Chinesa" << endl;
        cout << "{4} - Japonesa" << endl;
        cout<< "{0} - Outro"<<endl;
        cin >> b;
        switch(b) {
            case 0:
                culi="0";
                break;
            case 1:
                culi = "Portuguesa";
                break;
            case 2:
                culi = "Italiana";
                break;
            case 3:
                culi = "Chinesa";
                break;
            case 4:
                culi = "Japonesa";
                break;
            default:
                culi = "1";
        }
        if(culi!="1" && culi!="0") {
            culinaria.push_back(culi);
            r.setTiposDeCulinaria(culinaria);
            restaurantes.push_back(r);
            cout << "O restaurante "<<r.getNome()<<" foi adicionado com sucesso! " << endl;
            cout<<"O restaurante "<<r.getNome()<<" ja se encontra disponivel para receber emcomendas! "<<endl;
            file.open(restaurantes_filename);
            for (int i = 0; i < restaurantes.size() - 1; i++) {
                file << restaurantes[i].getNome() << endl;
                file << restaurantes[i].getMorada().getRua() + ", " + restaurantes[i].getMorada().getLocalidade() +
                        ", " +
                        restaurantes[i].getMorada().getNumero() << endl;
                file << restaurantes[i].getTiposDeCulinaria()[0] << endl;
                file << conselho << endl;
                file << ":::::" << endl;
            }
            file << restaurantes[restaurantes.size() - 1].getNome() << endl;
            file << restaurantes[restaurantes.size() - 1].getMorada().getRua() + ", " +
                    restaurantes[restaurantes.size() - 1].getMorada().getLocalidade() + ", " +
                    restaurantes[restaurantes.size() - 1].getMorada().getNumero() << endl;
            file << restaurantes[restaurantes.size() - 1].getTiposDeCulinaria()[0] << endl;
            file << conselho << endl;
        }
        else if(culi=="1"){
            cout<<"Opcao Invalida";
        }
        else if(culi=="0"){
            cout<<"Lamentamos, mas a Ugh Eats nao permite restaurantes com outros tipos de culinaria "<<endl;
        }
    }



}
void Base::removeRestaurante(Restaurante r) {
    ofstream file;
    for(int i=0;i<restaurantes.size();i++){
        if(restaurantes[i].getNome()==r.getNome()){
            restaurantes.erase(restaurantes.begin()+i);
        }
    }
    file.open(restaurantes_filename);
    for (int i = 0; i < restaurantes.size()-1; i++) {
        file << restaurantes[i].getNome() << endl;
        file << restaurantes[i].getMorada().getRua() + ", " + restaurantes[i].getMorada().getLocalidade() + ", " +restaurantes[i].getMorada().getNumero() << endl;
        file << restaurantes[i].getTiposDeCulinaria()[0] << endl;
        file<<"pratos.txt"<<endl;
        file << ":::::" << endl;
    }
    file << restaurantes[restaurantes.size()-1].getNome() << endl;
    file << restaurantes[restaurantes.size()-1].getMorada().getRua() + ", " +restaurantes[restaurantes.size()-1].getMorada().getLocalidade() + ", " +restaurantes[restaurantes.size()-1].getMorada().getNumero() << endl;
    file << restaurantes[restaurantes.size()-1].getTiposDeCulinaria()[0] << endl;
    file<<"pratos.txt"<<endl;
    file.close();
}
void Base::addAdmin(){
    Administrador a;
    Data d;
    ofstream file;
    string nome,nif,dia,mes,ano,salario,funcao, data;
    int b;
    cin.ignore();
    cout<<"Nome:"<<endl;
    getline(cin,nome);
    a.setNome(nome);
    cout<<"Nif:"<<endl;
    cin>>nif;
    //cin.ignore();
    while(nif.size()>9 || nif.size()<9){
        cout<<"Nif invalido. Volte a inserir:"<<endl;
        cin>>nif;
    }
    bool existe=false;
    for(int i=0;i<funcionarios.size();i++){
        if(funcionarios[i]->getNif()==nif){
            existe=true;
        }
    }
    while(existe==true){
        cout<<"Ja temos um funcionario registado com este nif" <<endl;
        cout<< "Tente Novamente!"<<endl;
        cout<<"Nif:"<<endl;
        cin>>nif;
        for(int i=0;i<funcionarios.size();i++){
            if(funcionarios[i]->getNif()==nif){
                existe=true;
                break;
            }else existe=false;

        }
    }
    a.setNif(nif);
    //cin.ignore();
    cout<<"Data de nascimento:"<<endl;
    cout<<"Dia:"<<endl;
    cin>>dia;
    cout<<"Mes:"<<endl;
    cin>>mes;
    cout<<"Ano:"<<endl;
    cin>>ano;
    data=dia+"/"+mes+"/"+ano;
    d=Data(data);
    a.setData(d);
    cout<<"Salario:"<<endl;
    cin>>salario;
    a.setSalario(stoi(salario));
    cout<<"Cargo:"<<endl;
    cin>>funcao;
    a.setFuncao(funcao);
    funcionarios.push_back(&a);
    cout << "O administrador "<<a.getNome()<<" foi adicionado com sucesso! " << endl;
    file.open(funcionarios_filename, ios::app);
    file << ":::::" << endl;
    file<<"Administrador"<<endl;
    file << a.getNome() << endl;
    file << a.getNif()<<endl;
    file << to_string(a.getData().getDia())+"/"+to_string(a.getData().getMes())+"/"+to_string(a.getData().getAno()) << endl;
    file <<to_string(a.getSalario())<< endl;
    file<<a.getFuncao()<<endl;


}
void Base::addEntreg() {
    Entregador a;
    Data d;
    Veiculo v;
    ofstream file;
    string nome,nif,dia,mes,ano,salario,marca, tipo, diav, data,mesv, anov,datav, veiculo, disp;
    int b;
    cin.ignore();
    cout<<"Nome:"<<endl;
    getline(cin,nome);
    a.setNome(nome);
    cout<<"Nif:"<<endl;
    cin>>nif;
    //cin.ignore();
    while(nif.size()>9 || nif.size()<9){
        cout<<"Nif invalido. Volte a inserir:"<<endl;
        cin>>nif;
    }
    bool existe=false;
    for(int i=0;i<funcionarios.size();i++){
        if(funcionarios[i]->getNif()==nif){
            existe=true;
        }
    }
    while(existe==true){
        cout<<"Ja temos um funcionario registado com este nif" <<endl;
        cout<< "Tente Novamente!"<<endl;
        cout<<"Nif:"<<endl;
        cin>>nif;
        for(int i=0;i<funcionarios.size();i++){
            if(funcionarios[i]->getNif()==nif){
                existe=true;
                break;
            }else existe=false;

        }
    }
    a.setNif(nif);
    //cin.ignore();
    cout<<"Data de nascimento:"<<endl;
    cout<<"Dia:"<<endl;
    cin>>dia;
    cout<<"Mes:"<<endl;
    cin>>mes;
    cout<<"Ano:"<<endl;
    cin>>ano;
    data=dia+"/"+mes+"/"+ano;
    d=Data(data);
    a.setData(d);
    cout<<"Salario:"<<endl;
    cin>>salario;
    a.setSalario(stoi(salario));
    cout<<"Marca do veiculo alocado:"<<endl;
    cin.ignore();
    getline(cin,marca);
    v.setMarca(marca);
    cout<<"Modelo do veiculo:"<<endl;
    getline(cin,tipo);
    v.setTipo(tipo);
    cout<<"Dia de aquisicao :"<<endl;
    cin>>dia;
    cout<<"Mes de aquisicao :"<<endl;
    cin>>mes;
    cout<<"Ano de aquisicao :"<<endl;
    cin>>ano;
    datav=dia+"/"+mes+"/"+ano;
    v.setDataDeAquisicao(datav);
    a.setVeiculoAlocado(v);
    a.setDisponivel(1);
    funcionarios.push_back(&a);
    cout << "O entregador "<<a.getNome()<<" foi adicionado com sucesso! " << endl;
    file.open(funcionarios_filename, ios::app);
    file << ":::::" << endl;
    file<<"Entregador"<<endl;
    file << a.getNome() << endl;
    file << a.getNif()<<endl;
    file << to_string(a.getData().getDia())+"/"+to_string(a.getData().getMes())+"/"+to_string(a.getData().getAno()) << endl;
    file <<to_string(a.getSalario())<< endl;
    file<<a.getVeiculoAlocado().getMarca()+" ,"+a.getVeiculoAlocado().getTipo()+" ,"+a.getVeiculoAlocado().getDataDeAquisicao()<<endl;
    file<<to_string(a.isDisponivel())<<endl;
}
void Base::removeAdmin(Funcionario f) {
    bool a=false;
    funcionarios_readfile();
    for(int i=0; i<funcionarios.size();i++){
        if(funcionarios[i]->getNif()==f.getNif()){
            if(funcionarios[i]->getTipoDeFuncionario()=="Administrador"){
                funcionarios.erase(funcionarios.begin()+i);
                a=true;
            }else{
                a=false;
            }
        }
    }
    if(a==true) {
        ofstream file;
        file.open(funcionarios_filename);
        for (int i = 0; i < funcionarios.size() - 1; i++) {
            if (funcionarios[i]->getTipoDeFuncionario() == "Administrador") {
                file << "Administrador" << endl;
                file << funcionarios[i]->getNome() << endl;
                file << funcionarios[i]->getNif() << endl;
                file << to_string(funcionarios[i]->getData().getDia()) + "/" +
                        to_string(funcionarios[i]->getData().getMes()) + "/" +
                        to_string(funcionarios[i]->getData().getAno()) << endl;
                file << to_string(funcionarios[i]->getSalario()) << endl;
                file <<funcionarios[i]->getFuncao() << endl;
                file << ":::::" << endl;
            } else if (funcionarios[i]->getTipoDeFuncionario() == "Entregador") {
                file << "Entregador" << endl;
                file << funcionarios[i]->getNome() << endl;
                file << funcionarios[i]->getNif() << endl;
                file << to_string(funcionarios[i]->getData().getDia()) + "/" +
                        to_string(funcionarios[i]->getData().getMes()) + "/" +
                        to_string(funcionarios[i]->getData().getAno()) << endl;
                file << to_string(funcionarios[i]->getSalario()) << endl;
                file << funcionarios[i]->getVeiculoAlocado().getMarca() + ", " +
                        funcionarios[i]->getVeiculoAlocado().getTipo() + ", " +
                        funcionarios[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                if (funcionarios[i]->isDisponivel()) {
                    file << "0" << endl;
                } else {
                    file << "1" << endl;
                }

                file << ":::::" << endl;
            }
        }
        if (funcionarios[funcionarios.size() - 1]->getTipoDeFuncionario() == "Administrador") {
            file << "Administrador" << endl;
            file << funcionarios[funcionarios.size() - 1]->getNome() << endl;
            file << funcionarios[funcionarios.size() - 1]->getNif() << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getData().getDia()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getMes()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getAno()) << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getSalario()) << endl;
            file << funcionarios[funcionarios.size() - 1]->getFuncao() << endl;
        } else if (funcionarios[funcionarios.size() - 1]->getTipoDeFuncionario() == "Entregador") {
            file << "Entregador" << endl;
            file << funcionarios[funcionarios.size() - 1]->getNome() << endl;
            file << funcionarios[funcionarios.size() - 1]->getNif() << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getData().getDia()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getMes()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getAno()) << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getSalario()) << endl;
            file << funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                    funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                    funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getDataDeAquisicao() << endl;
            if (funcionarios[funcionarios.size() - 1]->isDisponivel()) {
                file << "0" << endl;
            } else {
                file << "1" << endl;
            }

        }
        cout<<"O funcionario "<<f.getNome()<<" foi removido com sucesso!"<<endl;
    }else{
        cout<<"O nif que selecionou nao pertence a nunhum administrador!"<<endl;
    }
}
void Base::removeEntreg(Funcionario f) {
    bool a;
    funcionarios_readfile();
    for(int i=0; i<funcionarios.size();i++){
        if(funcionarios[i]->getNif()==f.getNif()){
            if(funcionarios[i]->getTipoDeFuncionario()=="Entregador"){
                funcionarios.erase(funcionarios.begin()+i);
                a=true;
            }else{
                a=false;
            }
        }
    }
    if(a==true) {
        ofstream file;
        file.open(funcionarios_filename);
        for (int i = 0; i < funcionarios.size() - 1; i++) {
            if (funcionarios[i]->getTipoDeFuncionario() == "Administrador") {
                file << "Administrador" << endl;
                file << funcionarios[i]->getNome() << endl;
                file << funcionarios[i]->getNif() << endl;
                file << to_string(funcionarios[i]->getData().getDia()) + "/" +
                        to_string(funcionarios[i]->getData().getMes()) + "/" +
                        to_string(funcionarios[i]->getData().getAno()) << endl;
                file << to_string(funcionarios[i]->getSalario()) << endl;
                file << funcionarios[i]->getFuncao() << endl;
                file << ":::::" << endl;
            } else if (funcionarios[i]->getTipoDeFuncionario() == "Entregador") {
                file << "Entregador" << endl;
                file << funcionarios[i]->getNome() << endl;
                file << funcionarios[i]->getNif() << endl;
                file << to_string(funcionarios[i]->getData().getDia()) + "/" +
                        to_string(funcionarios[i]->getData().getMes()) + "/" +
                        to_string(funcionarios[i]->getData().getAno()) << endl;
                file << to_string(funcionarios[i]->getSalario()) << endl;
                file << funcionarios[i]->getVeiculoAlocado().getMarca() + ", " +
                        funcionarios[i]->getVeiculoAlocado().getTipo() + ", " +
                        funcionarios[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                if (funcionarios[i]->isDisponivel()) {
                    file << "0" << endl;
                } else {
                    file << "1" << endl;
                }

                file << ":::::" << endl;
            }
        }
        if (funcionarios[funcionarios.size() - 1]->getTipoDeFuncionario() == "Administrador") {
            file << "Administrador" << endl;
            file << funcionarios[funcionarios.size() - 1]->getNome() << endl;
            file << funcionarios[funcionarios.size() - 1]->getNif() << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getData().getDia()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getMes()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getAno()) << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getSalario()) << endl;
            file << funcionarios[funcionarios.size() - 1]->getFuncao() << endl;
        } else if (funcionarios[funcionarios.size() - 1]->getTipoDeFuncionario() == "Entregador") {
            file << "Entregador" << endl;
            file << funcionarios[funcionarios.size() - 1]->getNome() << endl;
            file << funcionarios[funcionarios.size() - 1]->getNif() << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getData().getDia()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getMes()) + "/" +
                    to_string(funcionarios[funcionarios.size() - 1]->getData().getAno()) << endl;
            file << to_string(funcionarios[funcionarios.size() - 1]->getSalario()) << endl;
            file << funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                    funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                    funcionarios[funcionarios.size() - 1]->getVeiculoAlocado().getDataDeAquisicao() << endl;
            if (funcionarios[funcionarios.size() - 1]->isDisponivel()) {
                file << "0" << endl;
            } else {
                file << "1" << endl;
            }

        }
        cout<<"O funcionario "<<f.getNome()<<" foi removido com sucesso!"<<endl;
    }else{
        cout<<"O nif que selecionou nao pertence a nunhum entergador!"<<endl;
    }
}


//CLASSE EMPRESA

Empresa::Empresa() {}

Empresa::~Empresa() {

}

const vector<Base> &Empresa::getBases() const {
    return bases;
}

void Empresa::setBases(const vector<Base> &bases) {
    Empresa::bases = bases;
}
vector<Encomenda> Empresa::getEncomendas (){
    return encomendas;
}
void Empresa::setEncomendas(vector<Encomenda> e){
    encomendas=e;
}
void Empresa::encomendas_readfile(){
    Encomenda e;
    vector<string> encomenda_info;
    ifstream infile;
    string line;
    infile.open("entregas.txt");
    while(getline(infile,line)){
        if(line==":::::"){
            e.setRestauranteNome(encomenda_info[0]);
            e.setData(Data(encomenda_info[1]));
            e.setEntregadorNome(encomenda_info[2]);
            e.setHora(encomenda_info[3]);
            e.setPratosNome(encomenda_info[4]);
            e.setEntrega(stoi(encomenda_info[5]));
            e.setSucesso(stoi(encomenda_info[6]));
            e.setClienteNome(encomenda_info[7]);
            e.setPreco(stod(encomenda_info[8]));
            encomendas.push_back(e);
            encomenda_info.clear();
        }else{
            encomenda_info.push_back(line);
        }
    }
    e.setRestauranteNome(encomenda_info[0]);
    e.setData(Data(encomenda_info[1]));
    e.setEntregadorNome(encomenda_info[2]);
    e.setHora(encomenda_info[3]);
    e.setPratosNome(encomenda_info[4]);
    e.setEntrega(stoi(encomenda_info[5]));
    e.setSucesso(stoi(encomenda_info[6]));
    e.setClienteNome(encomenda_info[7]);
    e.setPreco(stod(encomenda_info[8]));
    encomendas.push_back(e);
    encomenda_info.clear();
    return;
}

