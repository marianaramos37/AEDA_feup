#include <iostream>
#include "restaurante.h"
#include "cliente.h"
#include "auxiliares.h"
#include "empresa.h"
#include "fstream"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>

void mainmenu();

void cliente();

void funcionario();

void gestao();

void login();

void eliminarRegisto(Cliente c);

void registo();

void informacaoCliente();

void procurarRestaurante(Cliente c);

void fazerEncomenda(Restaurante r,Cliente c);

void addRest();

void removeRest();

void addFunc();

void removeFunc();

void verFunc();

using namespace std;




int main() {

    mainmenu();
    return 0;

}
void mainmenu(){
    bool exit = false;
    while(!exit) {
        int option;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Selecione uma opcao: \n";
        cout << "{1} - Sou cliente \n";
        cout << "{2} - Sou funcionario \n";
        cout << "{3} - Gestao \n";  //economia, adicionar e remover restaurantes
        cout << "{0} - Sair\n";
        //
        cin >> option;


        switch (option) {
            case 1:
                cliente();
                break;
            case 2:
                funcionario();
                break;
            case 3:
                gestao();
                break;
            case 0:
                cout << "Obrigado por escolher a UghEats Food Delivery. \n";
                exit = true;
                break;
            default:
                cout << "Opcao Invalida!\n";
        }
    }
}

void cliente(){
    bool exit=false;
    while (!exit) {
        int op;
        cout << "Selecionou -Cliente-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Selecione uma opcao: \n";
        cout << "{1} - Log in \n";
        cout << "{2} - Registo \n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;

        switch (op) {
            case 1:
                login();
                break;
            case 2:
                registo();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Opcao Invalida! \n";
                cliente();
        }
    }
}

void informacaoCliente(Cliente c){
    bool exit=false;
    int op;
    while(!exit) {
        int op;
        cout << endl;
        cout << "Selecionou -Ver a sua informacao- " << endl;
        cout << "Nome: \t" << c.getName() << endl;
        cout << "Nif: \t" << c.getNif() << endl;
        cout << "Morada: " << c.getMorada().getRua() << ", " << c.getMorada().getLocalidade() << ", "
             << c.getMorada().getNumero() << endl;
        cout << "Base: \t" << c.getBase().getConselho() << endl << endl;
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;
        switch(op){
            case 0:
                exit = true;
                break;
            default:
                cout<<"Opcao Invalida!\n";
        }
    }
}

void login() {
    bool exit=false;
    while(!exit) {
        int op, base, op1;
        string nif;
        cout << "Selecionou -LogIn-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "A que base pertence? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cin >> base;
        cout << "Coloque o seu NIF:\n";
        cin >> nif;
        /*verificaçao do nif*/
        bool existe = false;
        Cliente c;
        if (base == 1) {
            Base b("porto.txt");
            b.clientes_readfile();
            for (int i = 0; i < b.getClientes().size(); i++) {
                if (b.getClientes()[i].getNif() == nif) {
                    existe = true;
                    c = b.getClientes()[i];
                }
            }
        } else if (base == 2) {
            Base b("lisboa.txt");
            b.clientes_readfile();
            for (int i = 0; i < b.getClientes().size(); i++) {
                if (b.getClientes()[i].getNif() == nif) {
                    existe = true;
                    c = b.getClientes()[i];
                }
            }
        } else if (base == 3) {
            Base b("faro.txt");
            b.clientes_readfile();
            for (int i = 0; i < b.getClientes().size(); i++) {
                if (b.getClientes()[i].getNif() == nif) {
                    existe = true;
                    c = b.getClientes()[i];
                }
            }
        }
        else {
            cout << "Opcao Invalida!" << endl;
        }
        if (existe == true) {
            cout << "Ola " << c.getName() << ".\nBem vindo/a a UghEats Food Delivery!\n\n";
            cout << "Selecione uma opcao: \n";
            cout << "{1} - Fazer uma encomenda\n";
            cout << "{2} - Ver a minha informacao\n";
            cout << "{3} - Eliminar registo\n";
            cout << "Prima {0} para voltar atras!\n";

            cin >> op;
            switch (op) {
                case 1:
                    procurarRestaurante(c);
                    break;
                case 2:
                    informacaoCliente(c);
                    break;
                case 3:
                    eliminarRegisto(c);
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    cout << "Opcao Invalida!\n";
            }
        } else {
            do {
                cout << "Nao esta registado na nossa plataforma!" << endl;
                cout << "{1} - Registar\n";
                cout << "{2} - Tentar login novamente\n";
                cout << "Prima {0} para voltar atras!\n";

                cin >> op1;
                switch (op1) {
                    case 1:
                        registo();
                        break;
                    case 2:
                        login();
                        break;
                    case 0:
                        exit = true;
                        break;
                    default:
                        cout << "Opcao Invalida \n";
                }
            } while (op1 != 1 && op1 != 2 && !exit);
        }

    }
}

void eliminarRegisto(Cliente c){
    Base b= c.getBase();
    b.removeCliente(c);
    cout<<"Ja nao e cliente da Ugh Eats Delivery!"<<endl;

}


void registo(){

    cout << "Selecionou -Registo-\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                         UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "A que base se quer registar? \n";
    cout << "{1} - Porto\n";
    cout << "{2} - Lisboa\n";
    cout << "{3} - Faro\n";
    string base;
    cin >> base;
    Base b;
    if (base == "1") {
        b = Base("porto.txt");
    }
    if (base == "2") {
        b = Base("lisboa.txt");
    }
    if (base == "3") {
        b = Base("faro.txt");
    }
    b.clientes_readfile();
    b.addCliente();
    cout << endl;
    cout << "Selecione uma opcao: " << endl;
    cout << "{1} - Login\n";
    cout << "Prima {0} para voltar atras!\n";
    string n;
    cin >> n;
    if (n == "1") {
        login();
    }
    if (n == "0") {
        exit;
    } else {
        cout << "Opcao Invalida!";
    }

}

void procurarRestaurante(Cliente c){
    bool exit=false;
    while(!exit) {
        int op, op1, op2, op3, op4;
        cout << "Procurar restaurantes por: \n";
        cout << "{1} - Zona Geografica \n";
        cout << "{2} - Ordem Alfabetica \n";
        cout << "{3} - Tipo de Culinaria\n";
        cout << "{4} - Intervalo de Preco\n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;
        c.getBase().restaurantes_readfile();
        if (op == 1) {
            vector<Restaurante> ord = c.getBase().getRestaurantes()[0].sortRestaurantesPorZona(
                    c.getBase().getRestaurantes());
            cout << "Restaurantes disponiveis na sua base - " << c.getBase().getConselho() << ":" << endl;
            for (int i = 0; i < ord.size(); i++) {
                if (ord[i].getMorada().getLocalidade() == "Porto") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Porto" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Matosinhos") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Matosinhos" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Vila Nova de Gaia") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Vila Nova de Gaia" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Maia") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Maia" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Gondomar") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Gondomar" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Loures") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Loures" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Lisboa") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Lisboa" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Amadora") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Amadora" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Faro") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Faro" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Loule") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Loule" << endl;
                }
                if (ord[i].getMorada().getLocalidade() == "Sao Bras de Alportel") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - concelho : Sao Bras de Alportel" << endl;
                }
            }
            cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
            cin >> op1;
            fazerEncomenda(ord[op1], c);
        }
        if (op == 2) {

            vector<Restaurante> nomesRest = {};
            for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                nomesRest.push_back(c.getBase().getRestaurantes()[i]);
                sort(nomesRest.begin(), nomesRest.end());
            }
            for (int i = 0; i < nomesRest.size(); i++) {
                cout << "{" << i << "} - " << nomesRest[i].getNome() << endl;
            }
            cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
            cin >> op2;

            fazerEncomenda(nomesRest[op2], c);
        }
        if (op == 3) {
            vector<Restaurante> ord = c.getBase().getRestaurantes()[0].sortRestaurantesPorComida(
                    c.getBase().getRestaurantes());
            cout << "Restaurantes disponiveis na sua base - " << c.getBase().getConselho() << ":" << endl;
            for (int i = 0; i < ord.size(); i++) {
                if (ord[i].getTiposDeCulinaria()[0] == "Portuguesa") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Portuguesa" << endl;
                }
                if (ord[i].getTiposDeCulinaria()[0] == "Italiana") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Italiana" << endl;
                }
                if (ord[i].getTiposDeCulinaria()[0] == "Chinesa") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Chinesa" << endl;
                }
                if (ord[i].getTiposDeCulinaria()[0] == "Japonesa") {
                    cout << "{" << i << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Japonesa" << endl;
                }
            }
            cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
            cin >> op1;
            fazerEncomenda(c.getBase().getRestaurantes()[op1], c);
        }
        if (op == 4) {
            int counter = 1;
            cout << "Selecione o intervalo de precos que pretende pesquisar" << endl;
            cout << "{1} - 0 a 4.99 euros\n";
            cout << "{2} - 5 a 9.99 euros\n";
            cout << "{3} - 10 a 14.99 euros\n";
            cout << "{4} - 15 a 19.99 euros\n";
            cout << "{5} - 20 a 25 euros\n";
            cin >> op3;

            switch (op3) {
                case 1:
                    for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                        for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                            //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                            if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                                c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                                if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() > 0 &&
                                    c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 4.99) {
                                    cout << "{" << i << "} - " << c.getBase().getRestaurantes()[i].getNome()
                                         << " - Prato: "
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getNome() << " - Preco: "
                                         << fixed << setprecision(2)
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() << endl;
                                }
                            }
                        }
                    }
                    cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
                    cin >> op4;
                    fazerEncomenda(c.getBase().getRestaurantes()[op4], c);
                    break;
                case 2:
                    for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                        for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                            //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                            if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                                c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                                if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 5 &&
                                    c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 9.99) {
                                    cout << "{" << i << "} - " << c.getBase().getRestaurantes()[i].getNome()
                                         << " - Prato: "
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getNome() << " - Preco: "
                                         << fixed << setprecision(2)
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() << endl;
                                }
                            }
                        }
                    }
                    cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
                    cin >> op4;
                    fazerEncomenda(c.getBase().getRestaurantes()[op4], c);
                    break;
                case 3:
                    for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                        for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                            //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                            if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                                c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                                if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 10 &&
                                    c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 14.99) {
                                    cout << "{" << i << "} - " << c.getBase().getRestaurantes()[i].getNome()
                                         << " - Prato: "
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getNome() << " - Preco: "
                                         << fixed << setprecision(2)
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() << endl;
                                }
                            }
                        }
                    }
                    cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
                    cin >> op4;
                    fazerEncomenda(c.getBase().getRestaurantes()[op4], c);
                    break;
                case 4:
                    for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                        for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                            //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                            if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                                c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                                if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 15 &&
                                    c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 19.99) {
                                    cout << "{" << i << "} - " << c.getBase().getRestaurantes()[i].getNome()
                                         << " - Prato: "
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getNome() << " - Preco: "
                                         << fixed << setprecision(2)
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() << endl;
                                }
                            }
                        }
                    }
                    cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
                    cin >> op4;
                    fazerEncomenda(c.getBase().getRestaurantes()[op4], c);
                    break;
                case 5:
                    for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                        for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                            //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                            if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                                c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                                if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 20 &&
                                    c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 25) {
                                    cout << "{" << i << "} - " << c.getBase().getRestaurantes()[i].getNome()
                                         << " - Prato: "
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getNome() << " - Preco: "
                                         << fixed << setprecision(2)
                                         << c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() << endl;
                                }
                            }
                        }
                    }
                    cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
                    cin >> op4;
                    fazerEncomenda(c.getBase().getRestaurantes()[op4], c);
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
            }
        }
        if (op == 0) {
            exit = true;
            break;
        } else {
            cout << "Opcao Invalida" << endl;
        }
    }
}

void fazerEncomenda(Restaurante r,Cliente c){
    Encomenda e;
    e.setRestauranteNome(r.getNome());
    e.setClienteNome(c.getName());

    int op;
    char op1;
    cout << "Selecionou -Fazer uma encomenda- Restaurante: "<<r.getNome()<<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                         UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    vector<Prato> encomendas;
    do {
        cout << "Menu: " << endl;
        for (int i = 0; i < r.getPratos().size(); i++) {
            cout << "{" << i << "} - " << r.getPratos()[i].getNome() << " - Preco: " << r.getPratos()[i].getPreco()
                 << endl;
        }
        cout << "Selecione o prato que pretende encomendar" << endl;
        cin >> op;
        encomendas.push_back(r.getPratos()[op]);
        cout << "Deseja encomendar outro prato? s/n" << endl;
        cin >> op1;
    }while(op1!='n');
    string stringDePratos;
    for(int i=0; i<encomendas.size()-1; i++){
        stringDePratos+=encomendas[i].getNome()+", ";
    }
    stringDePratos+=encomendas[encomendas.size()-1].getNome();
    e.setPratosNome(stringDePratos);
    cout<<"A verificar se existem entregadores disponiveis perto de si..."<<endl;
    c.getBase().funcionarios_readfile();
    bool existe=false;
    Funcionario *f=new Entregador;
    for(int i=0; i<c.getBase().getFuncionarios().size(); i++) {
        if(c.getBase().getFuncionarios()[i]->isDisponivel()){
            existe=true;
            f=c.getBase().getFuncionarios()[i];
            c.getBase().getFuncionarios()[i]->setDisponivel(false);
            break;
        }
    }
    ofstream file;
    file.open(c.getBase().getFuncionariosFileName());
    for (int i = 0; i < c.getBase().getFuncionarios().size()-1; i++) {
        if(c.getBase().getFuncionarios()[i]->getTipoDeFuncionario()=="Administrador") {
            file << "Administrador" << endl;
            file << c.getBase().getFuncionarios()[i]->getNome() << endl;
            file << c.getBase().getFuncionarios()[i]->getNif() << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
            file << c.getBase().getFuncionarios()[i]->getFuncao() << endl;
            file << ":::::" << endl;
        }else if(c.getBase().getFuncionarios()[i]->getTipoDeFuncionario()=="Entregador"){
            file << "Entregador" << endl;
            file << c.getBase().getFuncionarios()[i]->getNome() << endl;
            file << c.getBase().getFuncionarios()[i]->getNif() << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
            file << c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMarca()+", "+c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getTipo()+", "+c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
            if(c.getBase().getFuncionarios()[i]->isDisponivel()){
                file<<"1"<<endl;
            }else{
                file<<"0"<<endl;
            }

            file << ":::::" << endl;
        }
    }
    if(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getTipoDeFuncionario()=="Administrador") {
        file << "Administrador" << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNome() << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNif() << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getDia()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getMes()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getAno()) << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getSalario()) << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getFuncao() << endl;
    }else if(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getTipoDeFuncionario()=="Entregador"){
        file << "Entregador" << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNome() << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNif() << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getDia()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getMes()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getAno()) << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getSalario()) << endl;
        file <<c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getMarca()+", "+c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getTipo()+", "+c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getDataDeAquisicao() << endl;
        if(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->isDisponivel()){
            file<<"1"<<endl;
        }else{
            file<<"0"<<endl;
        }
    }
    if(existe){
        e.setEntregadorNome(f->getNome());
        cout<<"A sua encomenda foi efetuada com sucesso!"<<endl;
        cout<<endl;
        cout<<"DADOS DA ENTREGA"<<endl;
        cout<<"Produtos encomendados: ";
        for(int i=0; i<encomendas.size(); i++){
            cout<<encomendas[i].getNome()<<endl;
        }
        cout<<"Entregador: "<< f->getNome()<<", "<< f->getNif()<<endl;
        cout<<"Meio de transporte utilizado: "<<f->getVeiculoAlocado().getTipo()<< ", "<<f->getVeiculoAlocado().getMarca()<< ", "<<f->getVeiculoAlocado().getDataDeAquisicao()<<endl;
        //Hora
        chrono::system_clock::time_point  time_now =chrono::system_clock::now();
        time_now += std::chrono::minutes(15);
        time_t c_time_format = std::chrono::system_clock::to_time_t(time_now);
        string str_time =ctime(& c_time_format);
        cout<<"Data exata de entrega prevista: " << str_time<<endl;
        string stringData;
        string stringHora;
        string mess;
        string dias;
        string anos;
        stringHora+=str_time[11];
        stringHora+=str_time[12];
        stringHora+=str_time[13];
        stringHora+=str_time[14];
        stringHora+=str_time[15];
        mess+=str_time[4];
        mess+=str_time[5];
        mess+=str_time[6];
        dias+=str_time[8];
        dias+=str_time[9];
        anos+=str_time[20];
        anos+=str_time[21];
        anos+=str_time[22];
        anos+=str_time[23];
        int ano=stoi(anos);
        int mes;
        if(mess=="Nov"){
            mes=11;
        }
        else if (mess=="Dez"){
            mes=12;
        }
        else if (mess=="Jan"){
            mes = 01;
        }
        int dia=stoi(dias);
        Data d;
        d.setAno(ano); d.setDia(dia); d.setMes(mes);
        e.setData(d);
        e.setHora(stringHora);
        double preco=0.0;
        for(int i=0; i<encomendas.size(); i++){
            preco+=encomendas[i].getPreco();
        }
        if(r.getMorada().getLocalidade()=="Porto"||r.getMorada().getLocalidade()=="Lisboa"||r.getMorada().getLocalidade()=="Faro"){
            e.setEntrega(true);
            preco+=3.0;
            cout<<"Preco: "<<fixed<<setprecision(2) <<preco<<" euros - Foi acrescida uma taxa de entrega de 3 euros.";
        }
        else{
            e.setEntrega(false);
            preco+=5.0;
            cout<<"Preco: "<<fixed<<setprecision(2) <<preco<<" euros - Foi acrescida uma taxa de entrega de 5 euros por se localizar num concelho vizinho.";
        }
        e.setPreco(preco);
        srand(time(NULL));
        int r = (double)rand()/(9000 + 1) * (9999-1000);
        int m;
        cout<<setw(10)<< " "<< "MENSAGEM: "<<r<<endl;
        cout<<"Introduza o codigo de pagamento enviado por mensagem."<<endl;

        int a=3;
        while(a!=0 && m!=r) {
            cin>>m;
            if (m == r) {
                e.setSucesso(true);
                cout << "O pagamento foi efetuado com sucesso" << endl;
                break;
            } else {
                cout << "Codigo errado, tem " << a-1 << " tentativas." << endl;
                a--;
                cout << "Introduza o codigo de pagamento enviado por mensagem." << endl;
            }
        }
        if(m!=r){
            cout<<"Foi removido da nossa plataforma por ter pagamentos em atraso. Nao se podera registar novamente."<<endl;
            ofstream file;
            file.open("listanegra.txt", ios::app);
            file<<":::::"<<endl;
            file << c.getName() << endl;
            file << c.getNif() << endl;
            file << c.getMorada().getRua() + ", " + c.getMorada().getLocalidade() + ", " +c.getMorada().getNumero() << endl;
            file << c.getBase().getConselho()<<endl;
            c.getBase().removeCliente(c);
            c.getBase().listaNegra_readfile();
        }
        Empresa empresa;
        ofstream file;
        file.open("entregas.txt",ios::app);
        file<<endl;
        file << ":::::" << endl;
        file << e.getRestauranteNome() << endl;
        file <<e.getData().getDia() <<"/"<< e.getData().getMes()<<"/"<<e.getData().getAno()<<endl;
        file << e.getEntregadorNome()<<endl;
        file << e.getHora()<<endl;
        file << e.getPratosNome()<<endl;
        if(e.isEntrega()){
            file<<1<<endl;
        }
        if(!e.isEntrega()){
            file<<0<<endl;
        }
        if(e.isSucesso()==true){
            file<<1<<endl;
        }
        if(!e.isSucesso()==true){
            file<<0<<endl;
        }
        file << e.getClienteNome()<<endl;
        file << e.getPreco();
        empresa.encomendas_readfile();

    }
    else{
        cout<<"De momento nao existem entregadores disponiveis. Por favor tente de novo dentro de uns minutos."<<endl;
    }
}

void funcionario() {
    bool exit=false;
    while(!exit) {
        int op;
        cout << "Selecionou -Funcionario-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        cout << "Selecione uma opcao\n";
        cout << "{1} - Sou administrador \n"; //ver e mexer -adicionar/remover funcionarios
        cout << "{2} - Sou entregador \n"; //ver lista de encomendas
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;
        string pass;
        switch(op) {
            case 0:
                exit = true;
                break;
        }
        if(!exit) {
            if (op == 1) {
                cout << "Introduza palavra-passe:";
                cin >> pass;
                if (pass == "0000") {
                    cout << "{1} - Ver lista de funcionarios \n"; //ver e mexer -adicionar/remover funcionarios
                    cout << "{2} - Adicionar funcionarios \n";
                    cout << "{3} - Remover funcionarios\n";
                    int op1;
                    cin >> op1;
                    switch (op1) {
                        case 1:
                            verFunc();
                            break;
                        case 2:
                            addFunc();
                            break;
                        case 3:
                            removeFunc();
                            break;
                        default:
                            cout << "Opcao Invalida!" << endl;

                    }
                }
            }
            //case 2: //listaEncomendas(); break;
            if (op == 3) {
                removeRest();
            } else cout << "Opcao Invalida \n";
        }
    }
}

//a alterar
void gestao(){
    bool exit=false;
    while(!exit) {
        int op;
        Base b;
        Restaurante r;
        cout << "Selecionou -Gestao-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Selecione uma opcao: \n";
        cout << "{1} - Economia \n";
        cout << "{2} - Adicionar um restaurante \n";
        cout << "{3} - Remover um restaurante\n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;
        switch (op) {
            //case 1: economia(); break;
            case 2:
                addRest();
                break;
            case 3:
                removeRest();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Opcao Invalida \n";
        }
    }
}
void addRest(){
    bool exit=false;
    while(!exit) {
        cout << "Selecionou -Adicionar um restaurante-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "A que base se quer registar? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "Prima {0} para voltar atras!\n";
        string base;
        cin >> base;
        Base b;
        if (base == "1") {
            b = Base("porto.txt");
        }
        if (base == "2") {
            b = Base("lisboa.txt");
        }
        if (base == "3") {
            b = Base("faro.txt");
        }
        if (base == "4") {
            exit = true;
            break;
        }
        else{
            cout<<"Opcao Invalida!"<<endl;
        }

        b.restaurantes_readfile();
        b.addRestaurante();

    }

}
void removeRest() {
    bool exit=false;
    while(!exit) {
        if (exit) break;
        bool existe = false;
        Base b;
        int base;
        string nome;
        Restaurante r;
        cout << "Selecionou -Remover Restaurante-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "A que base pertence o restaurante que pretende remover? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> base;
        switch(base){
            case 0:
                exit = true;
                break;
        }
        cout << "Nome do restaurante:\n";
        cin >> nome;
        if(base==1) {
            b = Base("porto.txt");
            b.restaurantes_readfile();
            for (int i = 0; i < b.getRestaurantes().size(); i++) {
                if (b.getRestaurantes()[i].getNome() == nome) {
                    existe = true;
                    r = b.getRestaurantes()[i];
                }
            }
        }
        if(base==2) {
            b = Base("lisboa.txt");
            b.restaurantes_readfile();
            for (int i = 0; i < b.getRestaurantes().size(); i++) {
                if (b.getRestaurantes()[i].getNome() == nome) {
                    existe = true;
                    r = b.getRestaurantes()[i];
                }
            }
        }
        if(base==3) {
            b = Base("faro.txt");
            b.restaurantes_readfile();
            for (int i = 0; i < b.getRestaurantes().size(); i++) {
                if (b.getRestaurantes()[i].getNome() == nome) {
                    existe = true;
                    r = b.getRestaurantes()[i];
                }
            }
        }

        else if(base!=1 && base!=2 && base!=3 && base!=0){
            cout << "Opcao Invalida" << endl;
        }
        if(exit){
            break;
        }


        if (existe == true && !exit) {
            b.removeRestaurante(r);
            cout<<"O restaurante "<<r.getNome()<<" foi removido da nossa plataforma com sucesso!"<<endl;
            exit=true;
        } else {
            cout << "Esse restaurante nao pertence a nossa cadeia de fornecedores!" << endl;
        }
    }
}
void addFunc(){
    bool exit=false;
    while(!exit) {
        cout << "Selecionou -Adicionar um funcionario-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "A que base adicionar o funcionario? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "Prima {0} para valtar atras!\n";
        int base;
        cin >> base;
        Base b;
        switch (base) {
            case 1:
                b = Base("porto.txt");
                break;
            case 2:
                b = Base("lisboa.txt");
                break;
            case 3:
                b = Base("faro.txt");
                break;
            case 0:
                exit = true;
                break;
            default: cout << "Opcao Invalida!\n";
        }
        if (exit){
            break;
        }
        cout << "Pretende adicionar:" << endl;
        cout << "{1} - Administrador" << endl;
        cout << "{2} - Entregador" << endl;
        cout << "Prima {0} para valtar atras!\n";
        int op1;
        cin >> op1;
        switch (op1) {
            case 1:
                b.addAdmin();
                break;
            case 2:
                b.addEntreg();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
        b.funcionarios_readfile();
    }
}
void removeFunc(){
    bool exit=false;
    while(!exit) {
        int base;
        string nif;
        Funcionario f;
        cout << "Selecionou -Remover Funcionario-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                          UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "A que base pertence o funcionario que pretende remover? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> base;
        switch(base){
            case 0:
                exit=true;
                break;
        }
        if(!exit) {
            cout << "Pretende remover:" << endl;
            cout << "{1} - Administrador" << endl;
            cout << "{2} - Entregador" << endl;

            int op1;
            cin >> op1;
            cout << "Nif do funcionario que pertende remover:\n";
            cin >> nif;
            bool existe = false;
            Base b;
            if (base == 1) {
                b = Base("porto.txt");
                b.funcionarios_readfile();
                for (int i = 0; i < b.getFuncionarios().size(); i++) {
                    if (b.getFuncionarios()[i]->getNif() == nif) {
                        existe = true;
                        f = *b.getFuncionarios()[i];
                    }
                }
            } else if (base == 2) {
                b = Base("lisboa.txt");
                b.funcionarios_readfile();
                for (int i = 0; i < b.getFuncionarios().size(); i++) {
                    if (b.getFuncionarios()[i]->getNif() == nif) {
                        existe = true;
                        f = *b.getFuncionarios()[i];
                    }
                }
            } else if (base == 3) {
                b = Base("faro.txt");
                b.funcionarios_readfile();
                for (int i = 0; i < b.getFuncionarios().size(); i++) {
                    if (b.getFuncionarios()[i]->getNif() == nif) {
                        existe = true;
                        f = *b.getFuncionarios()[i];
                    }
                }
            } else cout << "Opcao Invalida" << endl;
            if (existe == true) {
                switch (op1) {
                    case 1 :
                        b.restaurantes_readfile();
                        b.removeAdmin(f);
                        break;
                    case 2:
                        b.funcionarios_readfile();
                        b.removeEntreg(f);
                        break;
                }
            } else {
                cout << "Esse funcionario nao e nosso trabalhador!" << endl;
            }
        }
    }
}
void verFunc(){
    bool exit= false;
    while(!exit) {
        cout << "Selecionou -Ver funcionarios-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Ver funcionarios da base: \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "{4} - Todas\n";
        cout << "Prima {0} para voltar atras!\n";
        int base;
        cin >> base;
        switch (base) {
            case 0:
                exit = true;
                break;
        }
        Base b, c, d;
        vector<Funcionario> v;
        if (base == 1) {
            b = Base("porto.txt");
            b.funcionarios_readfile();
            for (int i = 0; i < b.getFuncionarios().size(); i++) {
                if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (b.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }
        }
        if (base == 2) {
            b = Base("lisboa.txt");
            b.funcionarios_readfile();
            for (int i = 0; i < b.getFuncionarios().size(); i++) {
                if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (b.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }
        }
        if (base == 3) {
            b = Base("faro.txt");
            b.funcionarios_readfile();
            for (int i = 0; i < b.getFuncionarios().size(); i++) {
                if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (b.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }
        }
        if (base == 4) {
            b = Base("porto.txt");
            c = Base("lisboa.txt");
            d = Base("faro.txt");
            cout << "Funcionarios Porto:" << endl;
            cout << endl;
            b.funcionarios_readfile();
            for (int i = 0; i < b.getFuncionarios().size(); i++) {
                if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << "Entregador" << endl;
                    cout << b.getFuncionarios()[i]->getNome() << endl;
                    cout << b.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    cout << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (b.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }
            cout << endl;
            c.funcionarios_readfile();
            cout << "Funcionarios Lisboa:" << endl;
            cout << endl;
            for (int i = 0; i < c.getFuncionarios().size(); i++) {
                if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << "Administrador" << endl;
                    cout << c.getFuncionarios()[i]->getNome() << endl;
                    cout << c.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(c.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(c.getFuncionarios()[i]->getSalario()) << endl;
                    cout << c.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << "Entregador" << endl;
                    cout << c.getFuncionarios()[i]->getNome() << endl;
                    cout << c.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(c.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(c.getFuncionarios()[i]->getSalario()) << endl;
                    cout << c.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            c.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            c.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (c.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }
            cout << endl;
            d.funcionarios_readfile();
            cout << "Funcionarios Faro:" << endl;
            cout << endl;
            for (int i = 0; i < d.getFuncionarios().size(); i++) {
                if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    cout << "Administrador" << endl;
                    cout << d.getFuncionarios()[i]->getNome() << endl;
                    cout << d.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(d.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(d.getFuncionarios()[i]->getSalario()) << endl;
                    cout << d.getFuncionarios()[i]->getFuncao() << endl;
                    cout << ":::::" << endl;
                } else if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    cout << "Entregador" << endl;
                    cout << d.getFuncionarios()[i]->getNome() << endl;
                    cout << d.getFuncionarios()[i]->getNif() << endl;
                    cout << to_string(d.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getAno()) << endl;
                    cout << to_string(d.getFuncionarios()[i]->getSalario()) << endl;
                    cout << d.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                            d.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                            d.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() << endl;
                    if (d.getFuncionarios()[i]->isDisponivel()) {
                        cout << "0" << endl;
                    } else {
                        cout << "1" << endl;
                    }

                    cout << ":::::" << endl;
                }
            }

        }

    }
}