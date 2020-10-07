#include <iostream>
#include "restaurante.h"
#include "cliente.h"
#include "auxiliares.h"
#include "empresa.h"
#include "BST.h"
#include "fstream"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <queue>

///\brief Apresenta o menu inicial.
void mainmenu();

///\brief Apresenta o menu "cliente" levando às respetivas funcionalidades - login e registo;
void cliente();

///\brief Apresenta o menu "funcionário" levando às respetivas funcionalidades - Administrador e Entregador
void funcionario();

///\brief Apresenta o menu "gestão" levando às respetivas funcionalidades. - Economia, adicionar e remover restaurante, ver diversas informaçoes e lista de encomendas.
void gestao();

///\brief Apresenta o menu "login" levando às respetivas funcionalidades.
void login();

///\brief Elimina o registo de um cliente terminando o programa.
void eliminarRegisto(Cliente c);

///\brief Apresenta o menu "registo" levando às respetivas funcionalidades.
void registo();

///\brief Apresenta a informação de um cliente.
void informacaoCliente();

///\brief Apresenta o menu "Procurar Restaurante" que permite ver uma lista de restaurantes ordenados de diferentes formas.
void procurarRestaurante(Cliente c);

///\brief Realiza uma encomenda.
void fazerEncomenda(Restaurante r,Cliente c);

///\brief Adiciona restaurantes a uma base.
void addRest();

///\brief Remove restaurantes de uma base.
void removeRest();

///\brief Adiciona funcionários a uma base.
void addFunc();

///\brief Remove Funcionários de uma base.
void removeFunc();

///\brief Apresenta de forma organizada a informação de um funcionário.
void verFunc();

///\brief Apresenta de forma organizada a informação de um Restaurante.
void verRest();

///\brief Apresenta de forma organizada a informação de um Cliente.
void verClientes();

///\brief Apresenta de forma organizada a informação das Encomendas Realizadas.
void verEncomendas();

///\brief Apresenta de forma organizada a informação dos Veiculos.
void verVeiculos();

///\brief Vê, para a base do funcionário fornecido como parametro, qual é o técnico mais perto de estar disponível para arranjar o veículo.
///\param f: O funcionário que precisa do veiculo reparado.
void verListaDisponibilidade(Funcionario* f);

///\brief Apresenta a informação relacionada à economia/lucro da empresa. Podem ser procuradas por Base, Restaurante, ou Entregador
void economia();

///\brief Apresenta a informação relacionada à economia/lucro da empresa,
void listaEncomendas(Funcionario &f);

void procurarRestaurante(Cliente c);

using namespace std;


int main() {

    mainmenu();
    return 0;

}
void mainmenu(){
    bool exit = false;
    while(!exit) {
        char option;
        do{
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
                case '1':
                    cliente();
                    break;
                case '2':
                    funcionario();
                    break;
                case '3':
                    gestao();
                    break;
                case '0':
                    cout << "Obrigado por escolher a UghEats Food Delivery. \n";
                    exit = true;
                    break;
                default:
                    cout << "Opcao Invalida!\n";
            }
        }while(!isdigit(option));
    }
} //cin verified
void cliente() {
    bool exit = false;
    while (!exit) {
        char op;
        do {
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
                case '1':
                    login();
                    break;
                case '2':
                    registo();
                    break;
                case '0':
                    exit = true;
                    break;
                default:
                    cout << "Opcao Invalida! \n";
            }
        } while (!isdigit((op)));
    }
}
void informacaoCliente(Cliente c){

        char op;
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
            case '0':
                exit;
                break;
            default:
                cout<<"Opcao Invalida!\n";
        }
}
void login() {
    bool exit=false;
    while(!exit) {
        int op, op1;
        char base;
        bool existe = false;
        Cliente c;
        string nif;
        do{
            cin.clear();
            cout << "Selecionou -LogIn-\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            cout << "                          UghEats Food Delivery                                    ";
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "A que base pertence? \n";
            cout << "{1} - Porto\n";
            cout << "{2} - Lisboa\n";
            cout << "{3} - Faro\n";
            cin >> base;
            if (base == '1') {
                break;
            } else if (base == '2') {
                break;
            } else if (base == '3') {
                break;
            } else {
                cout << "Opcao Invalida!" << endl;
            }
        }while(!isdigit(base)||base!='1'||base!='2'||base!='3');

        cout << "Coloque o seu NIF:\n";
        cin >> nif;
        while(nif.size()>9 || nif.size()<9){
            cout<<"Nif invalido. Volte a inserir:"<<endl;
            cin>>nif;
        }
        /*verificaçao do nif*/
        if (base == '1') {
            Base b("porto.txt");
            b.clientes_readfile();
            for (int i = 0; i < b.getClientes().size(); i++) {
                if (b.getClientes()[i].getNif() == nif) {
                    existe = true;
                    c = b.getClientes()[i];
                }
            }
        } else if (base == '2') {
            Base b("lisboa.txt");
            b.clientes_readfile();
            for (int i = 0; i < b.getClientes().size(); i++) {
                if (b.getClientes()[i].getNif() == nif) {
                    existe = true;
                    c = b.getClientes()[i];
                }
            }
        } else if (base == '3') {
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
                cin >> op1;
                if (std::cin.fail()) // has a previous extraction failed?
                {
                    // yep, so let's handle the failure
                    std::cin.clear(); // put us back in 'normal' operation mode
                    std::cin.ignore(32767,'\n'); // and remove the bad input
                }
                switch (op1) {
                    case 1:
                        registo();
                        break;
                    case 2:
                        login();
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
    exit(0);
}
void registo(){
    cout << "Selecionou -Registo-\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                         UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    char base;
    do{
        cout << "A que base se quer registar? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cin >> base;
        if (base == '1') {
            break;
        } else if (base == '2') {
            break;
        } else if (base == '3') {
            break;
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    }while(!isdigit(base)||base!='1'||base!='2'||base!='3');
    Base b;
    if (base == '1') {
        b = Base("porto.txt");
    }
    if (base == '2') {
        b = Base("lisboa.txt");
    }
    if (base == '3') {
        b = Base("faro.txt");
    }
    b.clientes_readfile();
    try{
        b.addCliente();
    }catch(ClienteNaListaNegra &e){
        cerr<<e<<endl;
        system("pause");
    }
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
void procurarRestaurante(Cliente c) {

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
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Porto" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Matosinhos") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Matosinhos" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Vila Nova de Gaia") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Vila Nova de Gaia" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Maia") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Maia" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Gondomar") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Gondomar" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Loures") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Loures" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Lisboa") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Lisboa" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Amadora") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Amadora" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Faro") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Faro" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Loule") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Loule" << endl;
            }
            if (ord[i].getMorada().getLocalidade() == "Sao Bras de Alportel") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - concelho : Sao Bras de Alportel" << endl;
            }
        }
        cout << "Selecione o restaurante pelo qual pertende encomendar: " << endl;
        cin >> op1;
        fazerEncomenda(ord[op1 - 1], c);
    }
    else if (op == 2) {

        vector<Restaurante> nomesRest = {};
        cout << "Restaurantes disponiveis na sua base - " << c.getBase().getConselho() << ": " << endl;
        for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
            nomesRest.push_back(c.getBase().getRestaurantes()[i]);
            sort(nomesRest.begin(), nomesRest.end());
        }
        for (int i = 0; i < nomesRest.size(); i++) {
            cout << "{" << i + 1 << "} - " << nomesRest[i].getNome() << endl;
        }
        cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
        cin >> op2;

        fazerEncomenda(nomesRest[op2 - 1], c);
    }
    else if (op == 3) {
        vector<Restaurante> ord = c.getBase().getRestaurantes()[0].sortRestaurantesPorComida(
                c.getBase().getRestaurantes());
        cout << "Restaurantes disponiveis na sua base - " << c.getBase().getConselho() << ":" << endl;
        for (int i = 0; i < ord.size(); i++) {
            if (ord[i].getTiposDeCulinaria()[0] == "Portuguesa") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Portuguesa" << endl;
            }
            if (ord[i].getTiposDeCulinaria()[0] == "Italiana") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Italiana" << endl;
            }
            if (ord[i].getTiposDeCulinaria()[0] == "Chinesa") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Chinesa" << endl;
            }
            if (ord[i].getTiposDeCulinaria()[0] == "Japonesa") {
                cout << "{" << i + 1 << "} - " << ord[i].getNome() << " - Tipo de Culinaria : Japonesa" << endl;
            }
        }
        cout << "Selecione o restaurante pelo qual pertende encomendar" << endl;
        cin >> op1;
        fazerEncomenda(ord[op1 - 1], c);
    }
    else if (op == 4) {
        int counter = 1;
        cout << "Selecione o intervalo de precos que pretende pesquisar" << endl;
        cout << "{1} - 0 a 4.99 euros\n";
        cout << "{2} - 5 a 9.99 euros\n";
        cout << "{3} - 10 a 14.99 euros\n";
        cout << "{4} - 15 a 19.99 euros\n";
        cout << "{5} - 20 a 25 euros\n";
        cin >> op3;
        cout << "Restaurantes disponiveis na sua base - " << c.getBase().getConselho() << ":" << endl;
        switch (op3) {
            case 1:
                for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                    for (int j = 0; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                        if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                            c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                            if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() > 0 &&
                                c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 4.99) {
                                cout << "{" << i + 1 << "} - " << c.getBase().getRestaurantes()[i].getNome()
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

                fazerEncomenda(c.getBase().getRestaurantes()[op4 - 1], c);
                break;


            case 2:
                for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                    for (int j = 0; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                        if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                            c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                            if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 5 &&
                                c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 9.99) {
                                cout << "{" << i + 1 << "} - " << c.getBase().getRestaurantes()[i].getNome()
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

                fazerEncomenda(c.getBase().getRestaurantes()[op4 - 1], c);
                break;

            case 3:
                for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                    for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                        //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                        if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                            c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                            if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 10 &&
                                c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 14.99) {
                                cout << "{" << i + 1 << "} - " << c.getBase().getRestaurantes()[i].getNome()
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

                fazerEncomenda(c.getBase().getRestaurantes()[op4 - 1], c);
                break;

            case 4:
                for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                    for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                        //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                        if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                            c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                            if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 15 &&
                                c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 19.99) {
                                cout << "{" << i + 1 << "} - " << c.getBase().getRestaurantes()[i].getNome()
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

                fazerEncomenda(c.getBase().getRestaurantes()[op4 - 1], c);
                break;

            case 5:
                for (int i = 0; i < c.getBase().getRestaurantes().size(); i++) {
                    for (int j = i; j < c.getBase().getRestaurantes()[i].getPratos().size(); j++) {
                        //cout << c.getBase().getRestaurantes()[i].getPratos()[j].getNome()<< endl;
                        if (c.getBase().getRestaurantes()[i].getTiposDeCulinaria()[0] ==
                            c.getBase().getRestaurantes()[i].getPratos()[j].getTipoDeCulinaria()) {
                            if (c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() >= 20 &&
                                c.getBase().getRestaurantes()[i].getPratos()[j].getPreco() <= 25) {
                                cout << "{" << i + 1 << "} - " << c.getBase().getRestaurantes()[i].getNome()
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

                fazerEncomenda(c.getBase().getRestaurantes()[op4 - 1], c);
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    }
    else if (op == 0) {
        exit;

    } else {
        cout << "Opcao Invalida!" << endl;
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
            cout << "{" << i + 1 << "} - " << r.getPratos()[i].getNome() << fixed << setprecision(2) << " - Preco: " << r.getPratos()[i].getPreco()
                 << endl;
        }
        cout << "Selecione o prato que pretende encomendar" << endl;
        cin >> op;
        encomendas.push_back(r.getPratos()[op-1]);
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
        if(c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
            if (c.getBase().getFuncionarios()[i]->isDisponivel()) {
                existe = true;
                f = c.getBase().getFuncionarios()[i];
                //c.getBase().getFuncionarios()[i]->setDisponivel(false);
                break;
            }
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
            if(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo()==true) {
                file << c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                        to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                        to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                        "1" << endl;
            }else{
                file << c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                        c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                        to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                        to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                        "0" << endl;

            }

            if(c.getBase().getFuncionarios()[i]->isDisponivel()){
                file<<"1"<<endl;
            }else{
                file<<"0"<<endl;
            }

            file << ":::::" << endl;
        }
        else if (c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
            file << c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() << endl;
            file << c.getBase().getFuncionarios()[i]->getNome() << endl;
            file << c.getBase().getFuncionarios()[i]->getNif() << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                    to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
            file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
            file << c.getBase().getFuncionarios()[i]->getDisponibilidade() << endl;
            file << c.getBase().getFuncionarios()[i]->getManutencoes() << endl;
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
        if(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().isPrecisaArranjo()==true) {
            file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getMarca() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getTipo() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getMatricula() + ", " +
                    to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getKm()) + ", " +
                    to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                    "1" << endl;
        }else{
            file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getMarca() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getTipo() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                    c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getMatricula() + ", " +
                    to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getKm()) + ", " +
                    to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                    "0" << endl;

        }
        if(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->isDisponivel()){
            file<<"1"<<endl;
        }else{
            file<<"0"<<endl;
        }

    }
    else if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getTipoDeFuncionario() == "Tecnico") {
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getTipoDeFuncionario() << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNome() << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getNif() << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getDia()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getMes()) + "/" +
                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getData().getAno()) << endl;
        file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getSalario()) << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getDisponibilidade() << endl;
        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size()-1]->getManutencoes() << endl;
    }
    if(existe){
        e.setEntregadorNome(f->getNome());
        cout<<endl;
        cout<<"DADOS DA ENTREGA"<<endl;
        cout<<"Produtos encomendados: " << endl;
        for(int i=0; i<encomendas.size(); i++){
            cout<< "\t\t\t" << encomendas[i].getNome() << " - Preco: " << fixed << setprecision(2) << encomendas[i].getPreco() << endl;
        }
        cout<<"Entregador: "<< f->getNome() << endl;
        cout<<"Meio de transporte utilizado: "<<f->getVeiculoAlocado().getMarca()<< ", "<<f->getVeiculoAlocado().getTipo()<< ", "<<f->getVeiculoAlocado().getMatricula()<<endl;
        //Hora
        chrono::system_clock::time_point  time_now =chrono::system_clock::now();
        time_now += std::chrono::minutes(30);
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
        d.setAno(ano);
        d.setDia(dia);
        d.setMes(mes);
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
        int cod = (double)rand()/(9000 + 1) * (9999-1000);
        int m;
        cout<<setw(7)<< " "<< "MENSAGEM: "<<cod<<endl;
        cout<<"Introduza o codigo de pagamento enviado por mensagem."<<endl;

        int a=3;
        while(a!=0 && m!=cod) {
            cin>>m;
            if (m == cod) {
                e.setSucesso(true);
                cout << "O pagamento foi efetuado com sucesso" << endl;
                cout << "O seu pedido esta a ser preparado!" << endl;
                for (int i = 0; i < c.getBase().getFuncionarios().size(); i++) {
                    if (c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        if (c.getBase().getFuncionarios()[i]->getNome() == e.getEntregadorNome()) {

                            c.getBase().getFuncionarios()[i]->setDisponivel(false);
                            int num = c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas() + 1;
                            Veiculo v = c.getBase().getFuncionarios()[i]->getVeiculoAlocado();
                            v.setNumEntregas(num);
                            if (c.getMorada().getLocalidade() == r.getMorada().getLocalidade()) {
                                int num1 = 1 + (rand() % 10);
                                int km = c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm() + num1;
                                v.setKm(km);
                            } else {
                                int num1 = 1 + (rand() % 40);
                                int km = c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm() + num1;
                                v.setKm(km);
                            }

                            break;
                        }
                    }
                }
                ofstream file;
                file.open(c.getBase().getFuncionariosFileName());
                for (int i = 0; i < c.getBase().getFuncionarios().size() - 1; i++) {
                    if (c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                        file << "Administrador" << endl;
                        file << c.getBase().getFuncionarios()[i]->getNome() << endl;
                        file << c.getBase().getFuncionarios()[i]->getNif() << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
                        file << c.getBase().getFuncionarios()[i]->getFuncao() << endl;
                        file << ":::::" << endl;
                    } else if (c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        file << "Entregador" << endl;
                        file << c.getBase().getFuncionarios()[i]->getNome() << endl;
                        file << c.getBase().getFuncionarios()[i]->getNif() << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
                        if (c.getBase().getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                            file << c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                    to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                    to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) +
                                    ", " +
                                    "1" << endl;
                        } else {
                            file << c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                    c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                    to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                    to_string(c.getBase().getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) +
                                    ", " +
                                    "0" << endl;

                        }

                        if (c.getBase().getFuncionarios()[i]->isDisponivel()) {
                            file << "1" << endl;
                        } else {
                            file << "0" << endl;
                        }

                        file << ":::::" << endl;
                    } else if (c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                        file << c.getBase().getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                        file << c.getBase().getFuncionarios()[i]->getNome() << endl;
                        file << c.getBase().getFuncionarios()[i]->getNif() << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getData().getDia()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getMes()) + "/" +
                                to_string(c.getBase().getFuncionarios()[i]->getData().getAno()) << endl;
                        file << to_string(c.getBase().getFuncionarios()[i]->getSalario()) << endl;
                        file << c.getBase().getFuncionarios()[i]->getDisponibilidade() << endl;
                        file << c.getBase().getFuncionarios()[i]->getManutencoes() << endl;
                        file << ":::::" << endl;
                    }
                }
                if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getTipoDeFuncionario() ==
                    "Administrador") {
                    file << "Administrador" << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNome() << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNif() << endl;
                    file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getDia()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getMes()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getAno()) << endl;
                    file << to_string(
                            c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getSalario())
                         << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getFuncao()
                         << endl;
                } else if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                         1]->getTipoDeFuncionario() == "Entregador") {
                    file << "Entregador" << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNome() << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNif() << endl;
                    file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getDia()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getMes()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getAno()) << endl;
                    file << to_string(
                            c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getSalario())
                         << endl;
                    if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                      1]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getMarca() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getTipo() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                        1]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                        1]->getVeiculoAlocado().getNumEntregas()) +
                                ", " +
                                "1" << endl;
                    } else {
                        file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getMarca() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getTipo() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                              1]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                        1]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                        1]->getVeiculoAlocado().getNumEntregas()) +
                                ", " +
                                "0" << endl;

                    }
                    if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->isDisponivel()) {
                        file << "1" << endl;
                    } else {
                        file << "0" << endl;
                    }

                } else if (c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                         1]->getTipoDeFuncionario() == "Tecnico") {
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                          1]->getTipoDeFuncionario() << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNome() << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getNif() << endl;
                    file << to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getDia()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getMes()) + "/" +
                            to_string(c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                                    1]->getData().getAno()) << endl;
                    file << to_string(
                            c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getSalario())
                         << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() -
                                                          1]->getDisponibilidade() << endl;
                    file << c.getBase().getFuncionarios()[c.getBase().getFuncionarios().size() - 1]->getManutencoes()
                         << endl;
                }

                break;
            } else {
                cout << "Codigo errado, tem " << a-1 << " tentativas." << endl;
                a--;
                cout << "Introduza o codigo de pagamento enviado por mensagem." << endl;
            }
        }
        if(m!=cod){
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
            exit(0);
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
        else if(!e.isEntrega()){
            file<<0<<endl;
        }
        if(e.isSucesso()==true){
            file<<1<<endl;
        }
        else if(!e.isSucesso()==true){
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
    bool exit2=false;
    while(!exit) {
        char op;
        bool existe = false;
        string nif;
        cout << "Selecionou -Funcionario-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        do{
            cout << "Selecione uma opcao\n";
            cout << "{1} - Sou administrador \n"; //ver e mexer -adicionar/remover funcionarios
            cout << "{2} - Sou entregador \n"; //ver lista de encomendas
            cout << "Prima {0} para voltar atras!\n";
            cin >> op;
        }while(!isdigit(op)||(op!='1'&&op!='0'&&op!='2'));
        string pass;
        switch (op) {
            case '0':
                exit = true;
                break;
        }
        if (!exit) {
            if (op == '1') {
                cout << "Introduza palavra-passe:";
                cin >> pass;
                if (pass == "0000") {
                    char op1;
                    do{
                        cout<<"Selecione uma opcao:"<<endl<<endl;
                        cout << "{1} - Ver lista de funcionarios \n"; //ver e mexer -adicionar/remover funcionarios
                        cout << "{2} - Contratar funcionarios \n";
                        cout << "{3} - Despedir funcionarios\n";
                        cout << "{4} - Adicionar restaurante\n";
                        cout << "{5} - Eliminar restaurante\n";
                        cin >> op1;
                    }while(!isdigit(op1)||(op1!='1'&&op1!='2'&&op1!='3'&&op1!='4'&&op1!='5'));
                    switch (op1) {
                        case '1':
                            verFunc();
                            break;
                        case '2':
                            addFunc();
                            break;
                        case '3':
                            try {
                                removeFunc();
                            } catch (FuncionarioInexistente &e) {
                                cerr << e << endl;
                            }
                            break;
                        case '4':
                            addRest();
                            break;
                        case '5':
                            try{
                                removeRest();
                            }catch(RestauranteInexistente &e){
                                cerr<<e<<endl;
                            }
                            system("pause");
                            break;
                        default:
                            cout << "Opcao Invalida!" << endl;
                    }
                }
                system("pause");
            } else if (op == '2') {
                cout << "Coloque o seu NIF:\n";
                cin >> nif;

                Funcionario *fun;
                Base p = Base("porto.txt");
                Base l = Base("lisboa.txt");
                Base f = Base("faro.txt");
                p.funcionarios_readfile();
                l.funcionarios_readfile();
                f.funcionarios_readfile();
                for (int i = 0; i < p.getFuncionarios().size(); i++) {

                    if (p.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        if (p.getFuncionarios()[i]->getNif() == nif) {
                            existe = true;
                            fun = p.getFuncionarios()[i];
                        }
                    }
                }
                for (int i = 0; i < l.getFuncionarios().size(); i++) {
                    if (l.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        if (l.getFuncionarios()[i]->getNif() == nif) {
                            existe = true;
                            fun = l.getFuncionarios()[i];
                        }
                    }
                }
                for (int i = 0; i < f.getFuncionarios().size(); i++) {
                    if (f.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        if (f.getFuncionarios()[i]->getNif() == nif) {
                            existe = true;
                            fun = f.getFuncionarios()[i];
                        }
                    }
                }
                if (existe) {
                    char op1;
                    do{
                        cout<<"Selecione uma opcao:"<<endl<<endl;
                        cout << "{1} - Ver lista de encomendas \n"; //ver e mexer -adicionar/remover funcionarios
                        cout << "{2} - Enviar veiculo para revisao \n";
                        cin >> op1;
                    }while(!isdigit(op1)||(op1!='1'&&op1!='2'));
                    switch (op1) {
                        case '1':
                            listaEncomendas(*fun);
                            break;
                        case '2':
                            verListaDisponibilidade(fun);
                            break;

                        default:
                            cout << "Opcao Invalida!" << endl;
                    }

                } else {
                    cout << "Nao temos nenhum entregador com esse nif!" << endl;
                    system("pause");
                }
            }
            else {
                cout << "Opcao Invalida!\n";
                system("pause");
            }
        }
    }
}

/****************/

void gestao() {

    int op;
    Base b;
    string pass;
    Restaurante r;
    cout << "Selecionou -Gestao-\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                          UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Introduza a palavra-passe:";
    cin >> pass;
    if (pass == "0000") {
        cout << "Selecione uma opcao: \n";
        cout << "{1} - Economia \n";
        cout << "{2} - Ver lista de funcionarios\n";
        cout << "{3} - Ver lista de restaurante\n";
        cout << "{4} - Ver lista de cliente\n";
        cout << "{5} - Ver lista de encomendas\n";
        cout << "{6} - Ver lista de veiculos\n";
        cout << "Prima {0} para voltar atras!\n";
        cin >> op;
        switch (op) {
            case 1:
                economia();
                break;
            case 0:
                exit;
                break;
            case 2:
                verFunc();
                break;
            case 3:
                verRest();
                break;
            case 4:
                verClientes();
                break;
            case 5:
                verEncomendas();
                break;
            case 6:
                verVeiculos();
                break;
            default:
                cout << "Opcao Invalida \n";
                system("pause");
        }
    }

}
void addRest(){
    bool exit=false;
    while(!exit) {
        if(exit) break;
        cout << "Selecionou -Adicionar um restaurante-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Em que base pretende registar o restaurante? \n";
        cout << "{1} - Porto\n";
        cout << "{2} - Lisboa\n";
        cout << "{3} - Faro\n";
        cout << "Prima {0} para voltar atras!\n";
        int base;
        cin >> base;
        Base b;
        switch(base){
            case 0:
                exit=true;
                break;
        }
        if(!exit) {
            if (base == 1) {
                b = Base("porto.txt");
            }
            else if (base == 2) {
                b = Base("lisboa.txt");
            }
            else if (base == 3) {
                b = Base("faro.txt");
            } else {
                cout << "Opcao Invalida!" << endl;
                system("pause");
            }
            b.restaurantes_readfile();
            b.addRestaurante();
            system("pause");
        }


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
            system("pause");
            exit=true;
        } else {
            throw RestauranteInexistente(r);
        }
    }
}
void addFunc() {
    cout << "Selecionou -Adicionar um funcionario-\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                         UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "A que base quer adicionar o funcionario? \n";
    cout << "{1} - Porto\n";
    cout << "{2} - Lisboa\n";
    cout << "{3} - Faro\n";
    cout << "Prima {0} para valtar atras!\n";
    int base;
    cin >> base;

    Base b;
    switch (base) {
        case 0:
            exit;
            break;
    }
    if (base == 1) b = Base("porto.txt");
    else if (base == 2) b = Base("lisboa.txt");
    else if (base == 3) b = Base("faro.txt");
    else cout << "Opcao Invalida!\n";
    cout << "Pretende adicionar:" << endl;
    cout << "{1} - Administrador" << endl;
    cout << "{2} - Entregador" << endl;
    cout << "{3} - Tecnico" << endl;
    int op1;
    cin >> op1;
    switch (op1) {
        case 0:
            exit;
            break;
    }

    if (op1 == 1) {
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        b.addAdmin();
    }
    else if (op1 == 2) {
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        b.addEntreg();
    }
    else if (op1 == 3) {
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        b.addTecnico();
    }
    else{
        cout << "Opcao invalida!" << endl;
        system("pause");

    }


}
void removeFunc(){
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
            exit;
            break;
    }
    cout << "Pretende remover:" << endl;
    cout << "{1} - Administrador" << endl;
    cout << "{2} - Entregador" << endl;
    cout << "{3} - Tecnico" <<endl;
    int op1;
    cin >> op1;

    bool existe = false;
    Base b;
    if (base == 1) {
        b = Base("porto.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        if(op1==1) {
            cout<<"\t Listagem de administradores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
                if (b.getFuncionariosTodos()[i]->getTipoDeFuncionario() == "Administrador") {
                    bool atual = false;
                    for (int j = 0; j < b.getFuncionarios().size(); j++) {
                        if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                            atual = true;
                            break;
                        }
                    }
                    if (!atual) {
                        cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    } else {
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    }
                }
            }
        }
        else if(op1==2){
            cout<<"\t Listagem de entregadores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Entregador"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        else if(op1==3){
            cout<<"\t Listagem de tecnicos atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Tecnico"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        cin.clear();
        cout<<endl;
        cout << "Nif do funcionario que pertende remover:\n";
        cin >> nif;
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getNif() == nif) {
                existe = true;
                f = *b.getFuncionarios()[i];
            }
        }
    } else if (base == 2) {
        b = Base("lisboa.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        if(op1==1) {
            cout<<"\t Listagem de administradores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
                if (b.getFuncionariosTodos()[i]->getTipoDeFuncionario() == "Administrador") {
                    bool atual = false;
                    for (int j = 0; j < b.getFuncionarios().size(); j++) {
                        if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                            atual = true;
                            break;
                        }
                    }
                    if (!atual) {
                        cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    } else {
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    }
                }
            }
        }
        else if(op1==2){
            cout<<"\t Listagem de entregadores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Entregador"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        else if(op1==3){
            cout<<"\t Listagem de tecnicos atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Tecnico"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        cin.clear();
        cout<<endl;
        cout << "Nif do funcionario que pertende remover:\n";
        cin >> nif;
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getNif() == nif) {
                existe = true;
                f = *b.getFuncionarios()[i];
            }
        }
    } else if (base == 3) {
        b = Base("faro.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        if(op1==1) {
            cout<<"\t Listagem de administradores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
                if (b.getFuncionariosTodos()[i]->getTipoDeFuncionario() == "Administrador") {
                    bool atual = false;
                    for (int j = 0; j < b.getFuncionarios().size(); j++) {
                        if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                            atual = true;
                            break;
                        }
                    }
                    if (!atual) {
                        cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    } else {
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "
                             << b.getFuncionariosTodos()[i]->getNif() << endl;
                    }
                }
            }
        }
        else if(op1==2){
            cout<<"\t Listagem de entregadores atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Entregador"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        else if(op1==3){
            cout<<"\t Listagem de tecnicos atuais:\t";
            cout<<"Listagem de funcionarios antigos:"<<endl;
            for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Tecnico"){
                    bool atual=false;
                    for(int j=0; j<b.getFuncionarios().size(); j++){
                        if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                            atual=true;
                            break;
                        }
                    }
                    if(!atual){
                        cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                    else{
                        cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                    }
                }
            }
        }
        cin.clear();
        cout<<endl;
        cout << "Nif do funcionario que pertende remover:\n";
        cin >> nif;
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
                b.removeAdmin(f);
                cout<<endl;
                cout<<"\t\t\t\tListagens atualizadas: "<<endl;
                cout<<endl;
                cout<<"\t Listagem de administradores atuais:\t";
                cout<<"Listagem de funcionarios antigos:"<<endl;
                for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                    if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Administrador"){
                        bool atual=false;
                        for(int j=0; j<b.getFuncionarios().size(); j++){
                            if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                                atual=true;
                                break;
                            }
                        }
                        if(!atual){
                            cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                        else{
                            cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                    }
                }
                cout<<endl;
                system("pause");
                break;
            case 2:
                b.removeEntreg(&f);
                cout<<endl;
                cout<<"\t\t\t\tListagens atualizadas: "<<endl;
                cout<<endl;
                cout<<"\t Listagem de administradores atuais:\t";
                cout<<"Listagem de funcionarios antigos:"<<endl;
                for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                    if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Entregador"){
                        bool atual=false;
                        for(int j=0; j<b.getFuncionarios().size(); j++){
                            if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                                atual=true;
                                break;
                            }
                        }
                        if(!atual){
                            cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                        else{
                            cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                    }
                }
                cout<<endl;
                system("pause");
                break;
            case 3:
                b.removeTecnico(f);
                cout<<endl;
                cout<<"\t\t\t\tListagens atualizadas: "<<endl;
                cout<<endl;
                cout<<"\t Listagem de tecnicos atuais:\t";
                cout<<"Listagem de funcionarios antigos:"<<endl;
                for(int i=0;i<b.getFuncionariosTodos().size(); i++){
                    if(b.getFuncionariosTodos()[i]->getTipoDeFuncionario()=="Tecnico"){
                        bool atual=false;
                        for(int j=0; j<b.getFuncionarios().size(); j++){
                            if(b.getFuncionariosTodos()[i]->getNif()==b.getFuncionarios()[j]->getNif()){
                                atual=true;
                                break;
                            }
                        }
                        if(!atual){
                            cout<<"\t\t\t\t\t\t"<<"   " <<b.getFuncionariosTodos()[i]->getNome()<<" - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                        else{
                            cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " - "<<b.getFuncionariosTodos()[i]->getNif()<<endl;
                        }
                    }
                }
                cout<<endl;
                system("pause");
                break;
        }

    }else {
        throw FuncionarioInexistente(f);
    }


}
void verFunc() {

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
            exit;
            break;
    }

    Base b, c, d;
    vector<Funcionario> v;
    if (base == 1) {
        b = Base("porto.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        cout << "\t Listagem de funcionarios atuais:\t";
        cout << "Listagem de funcionarios antigos:" << endl;
        for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
            bool atual = false;
            for (int j = 0; j < b.getFuncionarios().size(); j++) {
                if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                    atual = true;
                    break;
                }
            }
            if (!atual) {
                cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            }
        }
        cout << endl << "\t\tListagem detalhada de todos os funcionarios da base do Porto: " << endl;
        cout << endl;
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tFuncao: \t\t" << b.getFuncionarios()[i]->getFuncao() << endl;
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tVeiculo " << endl;
                cout << "\t\t\tMarca: \t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() << endl;
                cout << "\t\t\tTipo:\t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() << endl;
                cout << "\t\t\tData de Aquisisao:\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao()
                     << endl;
                cout << "\t\t\tMatricula:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() << endl;
                cout << "\t\t\tKilometros:\t\t" << to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getKm()) << endl;
                cout << "\t\t\tNr de entregas:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()
                     << endl;
                if (b.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo()) {
                    cout << "\t\t\tVeiculo precisa de revisao tecnica" << endl;
                } else {
                    cout << "\t\t\tVeiculo nao precisa de revisao tecnica" << endl;
                }
                if (b.getFuncionarios()[i]->isDisponivel()) {
                    cout << "\t\t\tEntregador disponivel de momento" << endl;
                } else {
                    cout << "\t\t\tEntregador nao disponivel de momento" << endl;
                }
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tDisponivel daqui a: \t" << to_string(b.getFuncionarios()[i]->getDisponibilidade())
                     << endl;
                cout << "\t\t\tNr de manutencoes: \t" << to_string(b.getFuncionarios()[i]->getManutencoes()) << endl;
                cout << "\t\t\t_____________________________________" << endl;
            }
        }
        system("pause");
    } else if (base == 2) {
        b = Base("lisboa.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        cout << "\t Listagem de funcionarios atuais:\t";
        cout << "Listagem de funcionarios antigos:" << endl;
        for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
            bool atual = false;
            for (int j = 0; j < b.getFuncionarios().size(); j++) {
                if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                    atual = true;
                    break;
                }
            }
            if (!atual) {
                cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            }
        }
        cout << endl << "\t\tListagem detalhada de todos os funcionarios da base de Lisboa\t\t\t" << endl;
        cout << endl;
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tFuncao: \t\t" << b.getFuncionarios()[i]->getFuncao() << endl;
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tVeiculo " << endl;
                cout << "\t\t\tMarca:\t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() << endl;
                cout << "\t\t\tTipo:\t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() << endl;
                cout << "\t\t\tData de Aquisisao:\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao()
                     << endl;
                cout << "\t\t\tMatricula:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() << endl;
                cout << "\t\t\tKilometros:\t\t" << to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getKm()) << endl;
                cout << "\t\t\tNr de entregas:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()
                     << endl;
                if (b.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo()) {
                    cout << "\t\t\tVeiculo precisa de revisao tecnica" << endl;
                } else {
                    cout << "\t\t\tVeiculo nao precisa de revisao tecnica" << endl;
                }
                if (b.getFuncionarios()[i]->isDisponivel()) {
                    cout << "\t\t\tEntregador disponivel de momento" << endl;
                } else {
                    cout << "\t\t\tEntregador nao disponivel de momento" << endl;
                }
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tDisponivel daqui a: \t" << to_string(b.getFuncionarios()[i]->getDisponibilidade())
                     << endl;
                cout << "\t\t\tNr de manutencoes: \t" << to_string(b.getFuncionarios()[i]->getManutencoes()) << endl;
                cout << "\t\t\t_____________________________________" << endl;
            }
        }
        system("pause");
    } else if (base == 3) {
        b = Base("faro.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        cout << "\t Listagem de funcionarios atuais:\t";
        cout << "Listagem de funcionarios antigos:" << endl;
        for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
            bool atual = false;
            for (int j = 0; j < b.getFuncionarios().size(); j++) {
                if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                    atual = true;
                    break;
                }
            }
            if (!atual) {
                cout << "\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            }
        }
        cout << endl << "\t\tListagem detalhada de todos os funcionarios da base de Faro\t\t\t" << endl;
        cout << endl;
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tFuncao: \t\t" << b.getFuncionarios()[i]->getFuncao() << endl;
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tVeiculo " << endl;
                cout << "\t\t\tMarca:\t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() << endl;
                cout << "\t\t\tTipo:\t\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() << endl;
                cout << "\t\t\tData de Aquisisao:\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao()
                     << endl;
                cout << "\t\t\tMatricula:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() << endl;
                cout << "\t\t\tKilometros:\t\t" << to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getKm()) << endl;
                cout << "\t\t\tNr de entregas:\t\t" << b.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()
                     << endl;
                if (b.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo()) {
                    cout << "\t\t\tVeiculo precisa de revisao tecnica" << endl;
                } else {
                    cout << "\t\t\tVeiculo nao precisa de revisao tecnica" << endl;
                }
                if (b.getFuncionarios()[i]->isDisponivel()) {
                    cout << "\t\t\tEntregador disponivel de momento" << endl;
                } else {
                    cout << "\t\t\tEntregador nao disponivel de momento" << endl;
                }
                cout << "\t\t\t_____________________________________" << endl;
            } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                cout << "\t\t\tNome: \t\t\t" << b.getFuncionarios()[i]->getNome() << endl;
                cout << "\t\t\tCargo: \t\t\t" << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                cout << "\t\t\tNIF: \t\t\t" << b.getFuncionarios()[i]->getNif() << endl;
                cout << "\t\t\tData de Nascimento: \t"
                     << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                cout << "\t\t\tSalario: \t\t" << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                cout << "\t\t\tDisponivel daqui a: \t" << to_string(b.getFuncionarios()[i]->getDisponibilidade())
                     << endl;
                cout << "\t\t\tNr de manutencoes: \t" << to_string(b.getFuncionarios()[i]->getManutencoes()) << endl;
                cout << "\t\t\t_____________________________________" << endl;
            }
        }
        system("pause");
    } else if (base == 4) {
        b = Base("porto.txt");
        c = Base("lisboa.txt");
        d = Base("faro.txt");
        b.funcionarios_readfile();
        b.setFuncionariosTodos(b.getFuncionarios());
        b.funcionariosAntigos_readfile();
        c.funcionarios_readfile();
        c.setFuncionariosTodos(c.getFuncionarios());
        c.funcionariosAntigos_readfile();
        d.funcionarios_readfile();
        d.setFuncionariosTodos(d.getFuncionarios());
        d.funcionariosAntigos_readfile();
        cout << "\t Listagem de funcionarios atuais:\t";
        cout << "Listagem de funcionarios antigos:" << endl;
        cout << endl;
        cout << "\t\t\t\t\tPORTO" << endl;
        for (int i = 0; i < b.getFuncionariosTodos().size(); i++) {
            bool atual = false;
            for (int j = 0; j < b.getFuncionarios().size(); j++) {
                if (b.getFuncionariosTodos()[i]->getNif() == b.getFuncionarios()[j]->getNif()) {
                    atual = true;
                    break;
                }
            }
            if (!atual) {
                cout << "\t\t\t\t\t\t" << "   " << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << b.getFuncionariosTodos()[i]->getNome() << " : "
                     << b.getFuncionariosTodos()[i]->getTipoDeFuncionario()<< endl;
            }
        }
        cout << endl;
        cout << "\t\t\t\t\tLISBOA" << endl;
        for (int i = 0; i < c.getFuncionariosTodos().size(); i++) {
            bool atual1 = false;
            for (int j = 0; j < c.getFuncionarios().size(); j++) {
                if (c.getFuncionariosTodos()[i]->getNif() == c.getFuncionarios()[j]->getNif()) {
                    atual1 = true;
                    break;
                }
            }
            if (!atual1) {
                cout << "\t\t\t\t\t\t" << "   " << c.getFuncionariosTodos()[i]->getNome() << " : "
                     << c.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << c.getFuncionariosTodos()[i]->getNome() << " : "
                     << c.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            }
        }
        cout << endl;
        cout << "\t\t\t\t\tFARO" << endl;
        for (int i = 0; i < d.getFuncionariosTodos().size(); i++) {
            bool atual2 = false;
            for (int j = 0; j < d.getFuncionarios().size(); j++) {
                if (d.getFuncionariosTodos()[i]->getNif() == d.getFuncionarios()[j]->getNif()) {
                    atual2 = true;
                    break;
                }
            }
            if (!atual2) {
                cout << "\t\t\t\t\t\t" << "   " << d.getFuncionariosTodos()[i]->getNome() << " : "
                     << d.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            } else {
                cout << "\t\t" << d.getFuncionariosTodos()[i]->getNome() << " : "
                     << d.getFuncionariosTodos()[i]->getTipoDeFuncionario() << endl;
            }
        }
        cout << endl << "Para ver listagem detalhada de cada funcionario selecione ver funcionarios da base pertendida"
             << endl;

        system("pause");

    } else {
        cout << "Opcao Invalida!" << endl;
        system("pause");
    }
}
void verRest() {

    cout << "Selecionou -Ver restaurantes-\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "                         UghEats Food Delivery                                    ";
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Ver restaurantes da base: \n";
    cout << "{1} - Porto\n";
    cout << "{2} - Lisboa\n";
    cout << "{3} - Faro\n";
    cout << "{4} - Todas\n";
    cout << "Prima {0} para voltar atras!\n";
    int base;
    cin >> base;
    switch (base) {
        case 0:
            exit;
            break;
    }
    Base b, c, d;
    if (base == 1) {
        b = Base("porto.txt");
        cout << "  Restaurantes Porto" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        b.restaurantes_readfile();
        for (int i = 0; i < b.getRestaurantes().size(); i++) {
            b.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << b.getRestaurantes()[i].getNome() << endl;
            cout << "Morada: \t" << b.getRestaurantes()[i].getMorada().getRua() << ", "
                 << b.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << b.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "Culinaria: \t" << b.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < b.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << b.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << b.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }

        system("pause");

    } else if (base == 2) {
        b = Base("lisboa.txt");
        b.restaurantes_readfile();
        cout << "  Restaurantes Lisboa" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        for (int i = 0; i < b.getRestaurantes().size(); i++) {
            b.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << b.getRestaurantes()[i].getNome() << endl;
            cout << "Morada: \t" << b.getRestaurantes()[i].getMorada().getRua() << ", "
                 << b.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << b.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "Culinaria: \t" << b.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < b.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << b.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << b.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }
        system("pause");

    } else if (base == 3) {
        b = Base("faro.txt");
        b.restaurantes_readfile();
        cout << "   Restaurantes Faro" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        for (int i = 0; i < b.getRestaurantes().size(); i++) {
            b.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << b.getRestaurantes()[i].getNome() << endl;
            cout << "Morada: \t" << b.getRestaurantes()[i].getMorada().getRua() << ", "
                 << b.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << b.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "Culinaria: \t" << b.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < b.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << b.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << b.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }
        system("pause");

    } else if (base == 4) {
        b = Base("porto.txt");
        c = Base("lisboa.txt");
        d = Base("faro.txt");
        cout << "   Restaurantes Porto" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        b.restaurantes_readfile();
        for (int i = 0; i < b.getRestaurantes().size(); i++) {
            b.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << b.getRestaurantes()[i].getNome() << endl;
            cout << "Morada: \t" << b.getRestaurantes()[i].getMorada().getRua() << ", "
                 << b.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << b.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "TCulinaria: \t" << b.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < b.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << b.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << b.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }
        cout << endl;
        cout << "  Restaurantes Lisboa" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        c.restaurantes_readfile();
        for (int i = 0; i < c.getRestaurantes().size(); i++) {
            c.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << c.getRestaurantes()[i].getNome() << endl;
            cout << "Morada:\t" << c.getRestaurantes()[i].getMorada().getRua() << ", "
                 << c.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << c.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "Culinaria: \t" << c.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < c.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << c.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << c.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }

        cout << endl;
        cout << "   Restaurantes Faro" << endl;
        cout << "_______________________" << endl;
        cout << endl;
        d.restaurantes_readfile();
        for (int i = 0; i < d.getRestaurantes().size(); i++) {
            d.getRestaurantes()[i].pratos_readfile();
            cout << "Nome: \t\t" << d.getRestaurantes()[i].getNome() << endl;
            cout << "Morada: \t" << d.getRestaurantes()[i].getMorada().getRua() << ", "
                 << d.getRestaurantes()[i].getMorada().getLocalidade() << ", "
                 << d.getRestaurantes()[i].getMorada().getNumero() << endl;
            cout << "Culinaria: \t" << d.getRestaurantes()[i].getTiposDeCulinaria()[0] << endl;
            cout << "MENU:" << endl;
            for (int j = 0; j < d.getRestaurantes()[i].getPratos().size(); j++) {
                cout << "\t\t" << d.getRestaurantes()[i].getPratos()[j].getNome() << " - "
                     << fixed << setprecision(2) << d.getRestaurantes()[i].getPratos()[j].getPreco() << " euros"
                     << endl;
            }
            cout << ":::::" << endl;

        }
        system("pause");

    } else {
        cout << "Opcao Invalida!" << endl;
        system("pause");
    }


}
void verClientes() {
    bool exit=false;
    while(!exit) {
        cout << "Selecionou -Ver clientes-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Ver clientes da base: \n";
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
        if (!exit) {
            Base b, c, d;
            vector<Cliente> cli;
            if (base == 1) {
                b = Base("porto.txt");
                b.clientes_readfile();
                cout << "     Clientes Porto" << endl;
                cout << "_____________________" << endl;
                for (int i = 0; i < b.getClientes().size(); i++) {
                    cout << "Nome:\t" << b.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << b.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << b.getClientes()[i].getMorada().getRua() << ", "
                         << b.getClientes()[i].getMorada().getLocalidade() << ", "
                         << b.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << b.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                system("pause");
            }
            if (base == 2) {
                b = Base("lisboa.txt");
                b.clientes_readfile();
                cout << "    Clientes Lisboa" << endl;
                cout << "_____________________" << endl;
                for (int i = 0; i < b.getClientes().size(); i++) {
                    cout << "Nome:\t" << b.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << b.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << b.getClientes()[i].getMorada().getRua() << ", "
                         << b.getClientes()[i].getMorada().getLocalidade() << ", "
                         << b.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << b.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                system("pause");
            }
            if (base == 3) {
                b = Base("faro.txt");
                b.clientes_readfile();
                cout << "     Clientes Faro" << endl;
                cout << "_____________________" << endl;
                for (int i = 0; i < b.getClientes().size(); i++) {
                    cout << "Nome:\t" << b.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << b.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << b.getClientes()[i].getMorada().getRua() << ", "
                         << b.getClientes()[i].getMorada().getLocalidade() << ", "
                         << b.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << b.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                system("pause");
            }
            if (base == 4) {
                b = Base("porto.txt");
                c = Base("lisboa.txt");
                d = Base("faro.txt");
                cout << "     Clientes Porto" << endl;
                cout << "_____________________" << endl;
                cout << endl;
                b.clientes_readfile();
                for (int i = 0; i < b.getClientes().size(); i++) {
                    cout << "Nome:\t" << b.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << b.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << b.getClientes()[i].getMorada().getRua() << ", "
                         << b.getClientes()[i].getMorada().getLocalidade() << ", "
                         << b.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << b.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                cout << endl;
                c.clientes_readfile();
                cout << "    Clientes Lisboa" << endl;
                cout << "_____________________" << endl;
                cout << endl;
                for (int i = 0; i < c.getClientes().size(); i++) {
                    cout << "Nome:\t" << c.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << c.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << c.getClientes()[i].getMorada().getRua() << ", "
                         << c.getClientes()[i].getMorada().getLocalidade() << ", "
                         << c.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << c.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                cout << endl;
                d.clientes_readfile();
                cout << "     Clientes Faro" << endl;
                cout << "_____________________" << endl;
                cout << endl;
                for (int i = 0; i < d.getClientes().size(); i++) {
                    cout << "Nome:\t" << d.getClientes()[i].getName() << endl;
                    cout << "Nif:\t" << d.getClientes()[i].getNif() << endl;
                    cout << "Morada:\t" << d.getClientes()[i].getMorada().getRua() << ", "
                         << d.getClientes()[i].getMorada().getLocalidade() << ", "
                         << d.getClientes()[i].getMorada().getNumero() << endl;
                    cout << "Base:\t" << d.getClientes()[i].getBase().getConselho() << endl;
                    cout << ":::::" << endl;
                }
                system("pause");


                if (base != 1 && base != 2 && base != 3 && base != 4 && base != 0) {
                    cout << "Opcao Invalida!" << endl;
                    system("pause");
                }

            }
        }
    }
}
void verEncomendas() {

    Empresa e;
    e.encomendas_readfile();
    vector<Encomenda> encom = e.getEncomendas();
    bool exit = false;
    bool exit2 = false;
    int base, op;
    while (!exit) {
        cout << "Selecionou -Ver encomendas-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "{1} - Por base\n";
        cout << "{2} - Por restaurante\n";
        cout << "{3} - Por entregador\n";
        cout << "{4} - Todas\n";
        cout << "Prima {0} para voltar atras!\n";
        int op;
        cin >> op;
        switch (op) {
            case 0:
                exit;
                break;
        }
        if (!exit) {
            Base b, p, l, f;

            //POR BASE
            if (op == 1) {
                cout << "Ver encomendas da base: \n";
                cout << "{1} - Porto\n";
                cout << "{2} - Lisboa\n";
                cout << "{3} - Faro\n";
                cout << "{4} - Todas\n";
                cout << "Prima {0} para voltar atras!\n";
                cin >> base;
                switch (op) {
                    case 0:
                        exit2 = true;
                        break;
                }
                if (!exit2) {
                    if (base == 1) {
                        b = Base("porto.txt");
                        e.encomendas_readfile();
                        b.restaurantes_readfile();
                        cout << "    Encomendas Porto" << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {

                            for (int j = 0; j < b.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == b.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        system("pause");
                    } else if (base == 2) {
                        b = Base("lisboa.txt");
                        e.encomendas_readfile();
                        b.restaurantes_readfile();
                        cout << "    Encomendas Lisboa" << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {

                            for (int j = 0; j < b.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == b.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        system("pause");
                    } else if (base == 3) {
                        b = Base("faro.txt");
                        e.encomendas_readfile();
                        b.restaurantes_readfile();
                        cout << "     Encomendas Faro     " << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {

                            for (int j = 0; j < b.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == b.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        system("pause");
                    } else if (base == 4) {
                        p = Base("porto.txt");
                        l = Base("lisboa.txt");
                        f = Base("faro.txt");

                        e.encomendas_readfile();
                        p.restaurantes_readfile();
                        l.restaurantes_readfile();
                        f.restaurantes_readfile();
                        cout << "    Encomendas Porto" << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {
                            for (int j = 0; j < p.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == p.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        cout << "    Encomendas Lisboa" << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {
                            for (int j = 0; j < l.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == l.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        cout << "    Encomendas Faro" << endl;
                        cout << "_________________________" << endl;
                        for (int i = 0; i < encom.size(); i++) {
                            for (int j = 0; j < f.getRestaurantes().size(); j++) {
                                if (encom[i].getRestauranteNome() == f.getRestaurantes()[j].getNome()) {
                                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                         << encom[i].getData().getMes() << "/"
                                         << encom[i].getData().getAno() << endl;
                                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                                    if (!encom[i].isSucesso()) { //isSucesso = 0
                                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                                    if (!encom[i].isEntrega()) { //sem sucesso
                                        srand(time(0));
                                        string razoesInsucesso[4] = {"Restaurante fechado!",
                                                                     "Problema de transporte!",
                                                                     "Aplicacao em atualizacao!",
                                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                        vector<string> random;
                                        for (int i = 0; i < 3; i++) {
                                            random.push_back(razoesInsucesso[rand() % 4]);
                                        }
                                        cout << random[0] << endl;
                                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                                    cout << ":::::" << endl;
                                }
                            }
                        }
                        system("pause");
                    }
                }
            }
                //POR RESTAURANTE
            else if (op == 2) {
                vector<Restaurante> nomesRest = {};
                p = Base("porto.txt");
                l = Base("lisboa.txt");
                f = Base("faro.txt");

                //e.encomendas_readfile();
                p.restaurantes_readfile();
                l.restaurantes_readfile();
                f.restaurantes_readfile();
                for (int i = 0; i < p.getRestaurantes().size(); i++) {
                    nomesRest.push_back(p.getRestaurantes()[i]);
                }
                for (int j = 0; j < l.getRestaurantes().size(); j++) {
                    nomesRest.push_back(l.getRestaurantes()[j]);
                }
                for (int k = 0; k < f.getRestaurantes().size(); k++) {
                    nomesRest.push_back(f.getRestaurantes()[k]);
                }
                sort(nomesRest.begin(), nomesRest.end());


                for (int j = 0; j < nomesRest.size(); j++) {
                    for (int i = 0; i < encom.size(); i++) {
                        if (encom[i].getRestauranteNome() == nomesRest[j].getNome()) {
                            cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                            cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                 << encom[i].getData().getMes() << "/"
                                 << encom[i].getData().getAno() << endl;
                            cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                            cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                            cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                            if (!encom[i].isSucesso()) { //isSucesso = 0
                                cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                            } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                            if (!encom[i].isEntrega()) { //sem sucesso
                                srand(time(0));
                                string razoesInsucesso[4] = {"Restaurante fechado!", "Problema de transporte!",
                                                             "Aplicacao em atualizacao!",
                                                             "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                vector<string> random;
                                for (int i = 0; i < 3; i++) {
                                    random.push_back(razoesInsucesso[rand() % 4]);
                                }
                                cout << random[0] << endl;
                            } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                            cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                            cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                            cout << ":::::" << endl;
                        }
                    }
                }
                system("pause");
            }


                //POR ENTREGADOR
            else if (op == 3) {
                vector<string> nomesEntreg = {};
                p = Base("porto.txt");
                l = Base("lisboa.txt");
                f = Base("faro.txt");

                //e.encomendas_readfile();
                p.funcionarios_readfile();
                l.funcionarios_readfile();
                f.funcionarios_readfile();
                for (int i = 0; i < p.getFuncionarios().size(); i++) {
                    if (p.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                        nomesEntreg.push_back(p.getFuncionarios()[i]->getNome());
                    }
                }
                for (int j = 0; j < l.getFuncionarios().size(); j++) {
                    if (l.getFuncionarios()[j]->getTipoDeFuncionario() == "Entregador") {
                        nomesEntreg.push_back(l.getFuncionarios()[j]->getNome());
                    }
                }
                for (int k = 0; k < f.getFuncionarios().size(); k++) {
                    if (f.getFuncionarios()[k]->getTipoDeFuncionario() == "Entregador") {
                        nomesEntreg.push_back(f.getFuncionarios()[k]->getNome());
                    }
                }

                sort(nomesEntreg.begin(), nomesEntreg.end());


                for (int j = 0; j < nomesEntreg.size(); j++) {
                    for (int i = 0; i < encom.size(); i++) {
                        if (encom[i].getEntregadorNome() == nomesEntreg[j]) {
                            cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                            cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                                 << encom[i].getData().getMes() << "/"
                                 << encom[i].getData().getAno() << endl;
                            cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                            cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                            cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                            if (!encom[i].isSucesso()) { //isSucesso = 0
                                cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                            } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                            if (!encom[i].isEntrega()) { //sem sucesso
                                srand(time(0));
                                string razoesInsucesso[4] = {"Restaurante fechado!", "Problema de transporte!",
                                                             "Aplicacao em atualizacao!",
                                                             "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                                vector<string> random;
                                for (int i = 0; i < 3; i++) {
                                    random.push_back(razoesInsucesso[rand() % 4]);
                                }
                                cout << random[0] << endl;
                            } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                            cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                            cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                            cout << ":::::" << endl;
                        }
                    }
                }
                system("pause");
            }

                //TODAS
            else if (op == 4) {
                for (int i = 0; i < encom.size(); i++) {
                    cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                    cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                         << encom[i].getData().getMes() << "/"
                         << encom[i].getData().getAno() << endl;
                    cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                    cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                    cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;

                    if (!encom[i].isSucesso()) { //isSucesso = 0
                        cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                    } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                    if (!encom[i].isEntrega()) { //sem sucesso
                        srand(time(0));
                        string razoesInsucesso[4] = {"Restaurante fechado!", "Problema de transporte!",
                                                     "Aplicacao em atualizacao!",
                                                     "Todos os estregadores estao ocupados!\nTente novamente dentro de momentos"};

                        vector<string> random;
                        for (int i = 0; i < 3; i++) {
                            random.push_back(razoesInsucesso[rand() % 4]);
                        }
                        cout << random[0] << endl;
                    } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                    cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                    cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                    cout << ":::::" << endl;
                }

                system("pause");
            } else { cout << "Opcao Invalida!\n"; }
        }
    }


}
void verVeiculos(){
    bool exit=false;
    while(!exit) {
        cout << "Selecionou -Ver veiculos-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        Base b, c, d;
        vector<Cliente> cli;
        Empresa e;
        b = Base("porto.txt");
        c = Base("lisboa.txt");
        d = Base("faro.txt");

        vector<Veiculo> v;

        b.funcionarios_readfile();
        for (int i = 0; i < b.getFuncionarios().size(); i++) {
            if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                v.push_back(b.getFuncionarios()[i]->getVeiculoAlocado());
            }
        }
        c.funcionarios_readfile();
        for (int i = 0; i < c.getFuncionarios().size(); i++) {
            if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                v.push_back(c.getFuncionarios()[i]->getVeiculoAlocado());
            }
        }
        d.funcionarios_readfile();
        for (int i = 0; i < d.getFuncionarios().size(); i++) {

            if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                v.push_back(d.getFuncionarios()[i]->getVeiculoAlocado());
            }
        }
        for(int i =0; i<v.size();i++){

            e.addVeiculo(v[i]);
        }
        for (int i=0; i<e.verVeiculo().size();i++){
            cout << "Marca:\t\t\t" << e.verVeiculo()[i].getMarca() << endl;
            cout << "Modelo:\t\t\t" << e.verVeiculo()[i].getTipo() << endl;
            cout << "Data de Aquisicao:\t" <<e.verVeiculo()[i].getDataDeAquisicao()
                 << endl;
            cout << "Matricula:\t\t" << e.verVeiculo()[i].getMatricula() << endl;
            cout << "Kilometros percorridos:\t" << to_string(e.verVeiculo()[i].getKm()) << endl;
            cout << "Nr de entregas:\t\t" << to_string(e.verVeiculo()[i].getNumEntregas()) << endl;
            if (e.verVeiculo()[i].isPrecisaArranjo()) {
                cout << "Veiculo precisa de revisao tecnica!" << endl;
            } else {
                cout << "Veiculo nao precisa de revisao tecnica!" << endl;
            }
            cout << ":::::" << endl;
        }
        cout << endl;
        system("pause");

    }
}
void verListaDisponibilidade(Funcionario* f){
   /* chrono::system_clock::time_point  time_now =chrono::system_clock::now();
    chrono::system_clock::time_point  time_after_repair =chrono::system_clock::now() + std::chrono::hours(4);
    time_t c_time_format = std::chrono::system_clock::to_time_t(time_now);
    time_t c_time_format_after = std::chrono::system_clock::to_time_t(time_after_repair);
    string str_time =ctime(& c_time_format);
    string str_time_after =ctime(& c_time_format_after);

    string stringHora;
    stringHora+=str_time[11];
    stringHora+=str_time[12];
    stringHora+=str_time[13];
    stringHora+=str_time[14];
    stringHora+=str_time[15];
    string stringHora_after;
    stringHora_after+=str_time_after[11];
    stringHora_after+=str_time_after[12];
    stringHora_after+=str_time_after[13];
    stringHora_after+=str_time_after[14];
    stringHora_after+=str_time_after[15];*/

    vector<Funcionario*> tecporto, teclisboa, tecfaro;
    vector<Funcionario*> tecorganizado;
    Funcionario* tecnico;
    Base b, c, d;
    Empresa e;
    bool porto=false, lisboa=false, faro=false;
    b = Base("porto.txt");
    c = Base("lisboa.txt");
    d = Base("faro.txt");
    b.funcionarios_readfile();
    for (int i = 0; i < b.getFuncionarios().size(); i++) {

        for (int j = 0; j < b.getFuncionarios().size(); j++) {
            if (b.getFuncionarios()[j]->getTipoDeFuncionario() == "Tecnico") {
                tecporto.push_back(b.getFuncionarios()[j]);
            }
        }
        if (b.getFuncionarios()[i]->getNif() == f->getNif()) {
            porto = true;
            for (int k= 0; k < tecporto.size(); k++) {
                b.addTecnicoToFila(tecporto[k]);

            }

            cout << "O tecnico com disponibilidade mais proxima e " << b.getTecnicoFila().top()->getNome()
                 << ", que estara disponivel daqui a " << b.getTecnicoFila().top()->getDisponibilidade() << " horas"
                 << endl;

            b.getTecnicoFila().top()->setDisponibilidade(b.getTecnicoFila().top()->getDisponibilidade() + 4);

            b.getTecnicoFila().top()->setManutencoes(b.getTecnicoFila().top()->getManutencoes() + 1);
            f->setDisponivel(false);
            Veiculo v = f->getVeiculoAlocado();
            v.setPrecisaArranjo(false);

        }

        goto ficheirosporto;
    }
    c.funcionarios_readfile();
    for (int i = 0; i < c.getFuncionarios().size(); i++) {

        for (int j = 0; j < b.getFuncionarios().size(); j++) {

            if (c.getFuncionarios()[j]->getTipoDeFuncionario() == "Tecnico") {
                teclisboa.push_back(c.getFuncionarios()[j]);

            }
        }

        if (c.getFuncionarios()[i]->getNif() == f->getNif()) {
            lisboa = true;
            for (int k= 0; k < teclisboa.size(); k++) {
                c.addTecnicoToFila(teclisboa[k]);

            }

            cout << "O tecnico com disponibilidade mais proxima e " << c.getTecnicoFila().top()->getNome()
                 << ", que estara disponivel daqui a " << c.getTecnicoFila().top()->getDisponibilidade() << " horas"
                 << endl;

            c.getTecnicoFila().top()->setDisponibilidade(c.getTecnicoFila().top()->getDisponibilidade() + 4);

            c.getTecnicoFila().top()->setManutencoes(c.getTecnicoFila().top()->getManutencoes() + 1);
            f->setDisponivel(false);
            Veiculo v = f->getVeiculoAlocado();
            v.setPrecisaArranjo(false);
        }
        goto ficheiroslisboa;
    }
    d.funcionarios_readfile();
    for (int i = 0; i < d.getFuncionarios().size(); i++) {

        for (int j = 0; j <d.getFuncionarios().size(); j++) {
            if (d.getFuncionarios()[j]->getTipoDeFuncionario() == "Tecnico") {
                tecfaro.push_back(d.getFuncionarios()[j]);
            }
        }
        if (d.getFuncionarios()[i]->getNif() == f->getNif()) {
            faro = true;
            for (int k= 0; k < tecfaro.size(); k++) {
                d.addTecnicoToFila(tecfaro[k]);

            }

            cout << "O tecnico com disponibilidade mais proxima e " << d.getTecnicoFila().top()->getNome()
                 << ", que estara disponivel daqui a " << d.getTecnicoFila().top()->getDisponibilidade() << " horas"
                 << endl;

            d.getTecnicoFila().top()->setDisponibilidade(d.getTecnicoFila().top()->getDisponibilidade() + 4);

            d.getTecnicoFila().top()->setManutencoes(d.getTecnicoFila().top()->getManutencoes() + 1);
            f->setDisponivel(false);
            Veiculo v = f->getVeiculoAlocado();
            v.setPrecisaArranjo(false);
        }
        goto ficheirosfaro;
    }


    if(porto) {
        ficheirosporto:
        ofstream file;

            file.open("funcionariosPorto.txt");
            for (int i = 0; i < b.getFuncionarios().size() - 1; i++) {
                if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    file << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << b.getFuncionarios()[i]->getNome() << endl;
                    file << b.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    file << b.getFuncionarios()[i]->getFuncao() << endl;
                    file << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    file << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << b.getFuncionarios()[i]->getNome() << endl;
                    file << b.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    if (b.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                        file << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "1" << endl;
                    } else {
                        file << b.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                b.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(b.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "0" << endl;

                    }
                    if (b.getFuncionarios()[i]->isDisponivel()) {
                        file << "1" << endl;
                    } else {
                        file << "0" << endl;
                    }

                    file << ":::::" << endl;
                } else if (b.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                    file << b.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << b.getFuncionarios()[i]->getNome() << endl;
                    file << b.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(b.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(b.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(b.getFuncionarios()[i]->getSalario()) << endl;
                    file << b.getFuncionarios()[i]->getDisponibilidade() << endl;
                    file << b.getFuncionarios()[i]->getManutencoes() << endl;
                    file << ":::::" << endl;
                }
            }
            if (b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Administrador") {
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNome() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getSalario()) << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getFuncao() << endl;
            } else if (b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Entregador") {
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNome() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getSalario()) << endl;
                if (b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                    file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(b.getFuncionarios()[b.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "1" << endl;
                } else {
                    file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                            b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(b.getFuncionarios()[b.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "0" << endl;

                }
                if (b.getFuncionarios()[b.getFuncionarios().size() - 1]->isDisponivel()) {
                    file << "1" << endl;
                } else {
                    file << "0" << endl;
                }

            } else if (b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Tecnico") {
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNome() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(b.getFuncionarios()[b.getFuncionarios().size() - 1]->getSalario()) << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getDisponibilidade() << endl;
                file << b.getFuncionarios()[b.getFuncionarios().size() - 1]->getManutencoes() << endl;
            }
            file.close();

    }
    else if(lisboa) {
        ficheiroslisboa:
            ofstream file;
            file.open("funcionariosLisboa.txt");
            for (int i = 0; i < c.getFuncionarios().size() - 1; i++) {
                if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    file << c.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << c.getFuncionarios()[i]->getNome() << endl;
                    file << c.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(c.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(c.getFuncionarios()[i]->getSalario()) << endl;
                    file << c.getFuncionarios()[i]->getFuncao() << endl;
                    file << ":::::" << endl;
                } else if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    file << c.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << c.getFuncionarios()[i]->getNome() << endl;
                    file << c.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(c.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(c.getFuncionarios()[i]->getSalario()) << endl;
                    if (c.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                        file << c.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(c.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(c.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "1" << endl;
                    } else {
                        file << c.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                                c.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(c.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(c.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "0" << endl;

                    }
                    if (c.getFuncionarios()[i]->isDisponivel()) {
                        file << "1" << endl;
                    } else {
                        file << "0" << endl;
                    }

                    file << ":::::" << endl;
                } else if (c.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                    file << c.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file << c.getFuncionarios()[i]->getNome() << endl;
                    file << c.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(c.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(c.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(c.getFuncionarios()[i]->getSalario()) << endl;
                    file << c.getFuncionarios()[i]->getDisponibilidade() << endl;
                    file << c.getFuncionarios()[i]->getManutencoes() << endl;
                    file << ":::::" << endl;
                }
            }
            if (c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Administrador") {
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNome() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getSalario()) << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getFuncao() << endl;
            } else if (c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Entregador") {
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNome() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getSalario()) << endl;
                if (c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                    file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(c.getFuncionarios()[c.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "1" << endl;
                } else {
                    file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                            c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(c.getFuncionarios()[c.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "0" << endl;

                }
                if (c.getFuncionarios()[c.getFuncionarios().size() - 1]->isDisponivel()) {
                    file << "1" << endl;
                } else {
                    file << "0" << endl;
                }

            } else if (c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Tecnico") {
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNome() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(c.getFuncionarios()[c.getFuncionarios().size() - 1]->getSalario()) << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getDisponibilidade() << endl;
                file << c.getFuncionarios()[c.getFuncionarios().size() - 1]->getManutencoes() << endl;
            }
            file.close();

    }
    else if(faro) {
        ficheirosfaro:
            ofstream file;
            file.open("funcionariosFaro.txt");
            for (int i = 0; i <d.getFuncionarios().size() - 1; i++) {
                if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Administrador") {
                    file <<d.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file <<d.getFuncionarios()[i]->getNome() << endl;
                    file <<d.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(d.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(d.getFuncionarios()[i]->getSalario()) << endl;
                    file <<d.getFuncionarios()[i]->getFuncao() << endl;
                    file << ":::::" << endl;
                } else if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Entregador") {
                    file <<d.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file <<d.getFuncionarios()[i]->getNome() << endl;
                    file <<d.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(d.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(d.getFuncionarios()[i]->getSalario()) << endl;
                    if (d.getFuncionarios()[i]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                        file <<d.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(d.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(d.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "1" << endl;
                    } else {
                        file <<d.getFuncionarios()[i]->getVeiculoAlocado().getMarca() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getTipo() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getDataDeAquisicao() + ", " +
                               d.getFuncionarios()[i]->getVeiculoAlocado().getMatricula() + ", " +
                                to_string(d.getFuncionarios()[i]->getVeiculoAlocado().getKm()) + ", " +
                                to_string(d.getFuncionarios()[i]->getVeiculoAlocado().getNumEntregas()) + ", " +
                                "0" << endl;

                    }
                    if (d.getFuncionarios()[i]->isDisponivel()) {
                        file << "1" << endl;
                    } else {
                        file << "0" << endl;
                    }

                    file << ":::::" << endl;
                } else if (d.getFuncionarios()[i]->getTipoDeFuncionario() == "Tecnico") {
                    file <<d.getFuncionarios()[i]->getTipoDeFuncionario() << endl;
                    file <<d.getFuncionarios()[i]->getNome() << endl;
                    file <<d.getFuncionarios()[i]->getNif() << endl;
                    file << to_string(d.getFuncionarios()[i]->getData().getDia()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getMes()) + "/" +
                            to_string(d.getFuncionarios()[i]->getData().getAno()) << endl;
                    file << to_string(d.getFuncionarios()[i]->getSalario()) << endl;
                    file <<d.getFuncionarios()[i]->getDisponibilidade() << endl;
                    file <<d.getFuncionarios()[i]->getManutencoes() << endl;
                    file << ":::::" << endl;
                }
            }
            if (d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Administrador") {
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNome() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getSalario()) << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getFuncao() << endl;
            } else if (d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Entregador") {
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNome() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getSalario()) << endl;
                if (d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().isPrecisaArranjo() == true) {
                    file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(d.getFuncionarios()[d.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "1" << endl;
                } else {
                    file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getMarca() + ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getTipo() + ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getDataDeAquisicao() +
                            ", " +
                           d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getMatricula() + ", " +
                            to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getVeiculoAlocado().getKm()) +
                            ", " +
                            to_string(d.getFuncionarios()[d.getFuncionarios().size() -
                                                          1]->getVeiculoAlocado().getNumEntregas()) + ", " +
                            "0" << endl;

                }
                if (d.getFuncionarios()[d.getFuncionarios().size() - 1]->isDisponivel()) {
                    file << "1" << endl;
                } else {
                    file << "0" << endl;
                }

            } else if (d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() == "Tecnico") {
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getTipoDeFuncionario() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNome() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getNif() << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getDia()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getMes()) + "/" +
                        to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getData().getAno()) << endl;
                file << to_string(d.getFuncionarios()[d.getFuncionarios().size() - 1]->getSalario()) << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getDisponibilidade() << endl;
                file <<d.getFuncionarios()[d.getFuncionarios().size() - 1]->getManutencoes() << endl;
            }
            file.close();

    }



}
void economia(){
    bool exit=false;
    bool exit2=false;
    while(!exit) {

        cout << "Selecionou -Economia-\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "                         UghEats Food Delivery                                    ";
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Ver lucro da empresa por: \n";
        cout << "{1} - Base\n";
        cout << "{2} - Cliente\n";
        cout << "{3} - Restaurante\n";
        cout << "{4} - Mes\n";
        cout << "{5} - Geral\n";
        cout << "Prima {0} para voltar atras!\n";
        int op;
        cin >> op;
        switch (op) {
            case 0:
                exit = true;
                break;
        }
        if (!exit) {
            if (op == 1) {
                cout << "Selecionou -Ver lucro da empresa por base-\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "                         UghEats Food Delivery                                    ";
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Ver lucro da base: \n";
                cout << "{1} - Porto\n";
                cout << "{2} - Lisboa\n";
                cout << "{3} - Faro\n";
                cout << "Prima {0} para voltar atras!\n";
                int op2;
                cin >> op2;
                switch (op2) {
                    case 0:
                        exit2 = true;
                        break;
                }
                double soma = 0.0;
                if (!exit2) {
                    if (op2 == 1) {
                        double soma = 0.0;
                        Base b;
                        Empresa e;
                        e.encomendas_readfile();
                        b = Base("porto.txt");
                        cout << "Lucro da base do Porto: " << endl;
                        b.restaurantes_readfile();

                        for (int i = 0; i < b.getRestaurantes().size(); i++) {
                            for (int j = i; j < e.getEncomendas().size(); j++) {
                                if (b.getRestaurantes()[i].getNome() == e.getEncomendas()[j].getRestauranteNome()) {
                                    soma += e.getEncomendas()[j].getPreco();
                                }
                            }
                        }
                        cout << soma << endl;
                    } else if (op2 == 2) {
                        Base b;
                        Empresa e;
                        e.encomendas_readfile();
                        b = Base("lisboa.txt");
                        cout << "Lucro da base de Lisboa: " << endl;
                        cout << endl;
                        b.restaurantes_readfile();

                        for (int i = 0; i < b.getRestaurantes().size(); i++) {
                            for (int j = i; i < e.getEncomendas().size(); j++) {
                                if (b.getRestaurantes()[i].getNome() == e.getEncomendas()[j].getRestauranteNome()) {
                                    soma += e.getEncomendas()[j].getPreco();

                                }
                            }

                        }
                        cout << soma << endl;
                    } else if (op2 == 3) {
                        Base b;
                        Empresa e;
                        e.encomendas_readfile();
                        b = Base("faro.txt");
                        cout << "Lucro da base de Faro: " << endl;
                        cout << endl;
                        b.restaurantes_readfile();

                        for (int i = 0; i < b.getRestaurantes().size(); i++) {
                            for (int j = i; i < e.getEncomendas().size(); j++) {
                                if (b.getRestaurantes()[i].getNome() == e.getEncomendas()[j].getRestauranteNome()) {
                                    soma += e.getEncomendas()[j].getPreco();


                                }
                            }

                        }
                        cout << soma << endl;
                    }
                    system("pause");
                }

            } else if (op == 2) {
                cout << "Selecionou -Ver lucro da empresa por cliente-\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "                         UghEats Food Delivery                                    ";
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Clientes que ja efetuaram uma ou mais encomendas:" << endl;
                Empresa e;
                e.encomendas_readfile();
                vector<string> n;
                for (int j = 0; j < e.getEncomendas().size() ; j++) {
                    cout << "{" << j + 1 << "} - " << e.getEncomendas()[j].getClienteNome() << endl;
                }

                cout << "Prima {0} para voltar atras!" << endl;
                int op2;
                cin >> op2;
                switch (op2) {
                    case 0:
                        exit2 = true;
                        break;
                }
                double soma = 0.0;
                if (!exit2) {
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[op2 - 1].getClienteNome() == e.getEncomendas()[j].getClienteNome()) {
                            soma += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "O/A cliente " << e.getEncomendas()[op2 - 1].getClienteNome() << " gastou um total de "
                         << soma << " euros." << endl;
                    cout << "Prima {0} para voltar atras!" << endl;
                    system("pause");
                }
            } else if (op == 3) {
                cout << "Selecionou -Ver lucro da empresa por restaurante-\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "                         UghEats Food Delivery                                    ";
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Restaurantes com encomendas realizadas:" << endl;
                Empresa e;
                e.encomendas_readfile();
                for (int j = 0; j < e.getEncomendas().size(); j++) {
                    cout << "{" << j + 1 << "} - " << e.getEncomendas()[j].getRestauranteNome() << endl;
                }
                cout << "Prima {0} para voltar atras!" << endl;
                int op2;
                cin >> op2;
                switch (op2) {
                    case 0:
                        exit2 = true;
                        break;
                }
                double soma = 0.0;
                if (!exit2) {
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[op2 - 1].getRestauranteNome() ==
                            e.getEncomendas()[j].getRestauranteNome()) {
                            soma += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "O restaurante " << e.getEncomendas()[op2 - 1].getRestauranteNome()
                         << " fez um total de " << soma << " euros em encomendas." << endl;
                    system("pause");
                }


            } else if (op == 4) {
                cout << "Selecionou -Ver lucro da empresa por mes-\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "                         UghEats Food Delivery                                    ";
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                int op2;
                double somaj = 0.0;
                double somaf = 0.0;
                double somam = 0.0;
                double somaa = 0.0;
                double somamai = 0.0;
                double somajun = 0.0;
                double somajul = 0.0;
                double somaag = 0.0;
                double somas = 0.0;
                double somao = 0.0;
                double soman = 0.0;
                double somad = 0.0;
                if (!exit2) {
                    Empresa e;
                    e.encomendas_readfile();

                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 1) {
                            somaj += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de janeiro, fez-se um total de " << somaj << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 2) {
                            somaf += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de janeiro, fez-se um total de " << somaf << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 3) {
                            somam += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de marco, fez-se um total de " << somam << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 4) {
                            somaa += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de abril, fez-se um total de " << somaa << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 5) {
                            somamai += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de maio, fez-se um total de " << somamai << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 6) {
                            somajun += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de junho, fez-se um total de " << somajun << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 7) {
                            somajul += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de julho, fez-se um total de " << somajul << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 8) {
                            somaag += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de agosto, fez-se um total de " << somaag << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 9) {
                            somas += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de setembro, fez-se um total de " << somas << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 10) {
                            somao += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de outubro, fez-se um total de " << somao << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 11) {
                            soman += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de novembro, fez-se um total de " << soman << " euros em encomendas." << endl;
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        if (e.getEncomendas()[j].getData().getMes() == 12) {
                            somad += e.getEncomendas()[j].getPreco();
                        }
                    }
                    cout << "No mes de dezembro, fez-se um total de " << somad << " euros em encomendas." << endl;
                    system("pause");
                }


            } else if (op == 5) {
                cout << "Selecionou -Ver lucro geral da empresa-\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "                         UghEats Food Delivery                                    ";
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                if (!exit2) {
                    double soma = 0.0;
                    Empresa e;
                    e.encomendas_readfile();
                    for (int j = 0; j < e.getEncomendas().size(); j++) {
                        soma += e.getEncomendas()[j].getPreco();
                    }
                    cout << "A empresa obteve ate hoje um total de " << soma << " euros em encomendas."<<endl;
                    system("pause");
                }
            } else cout << "Opcao Invalida!" << endl;

        }
    }
}
void listaEncomendas(Funcionario &fun) {
    Empresa e;
    bool existe = false;
    e.encomendas_readfile();
    vector<Encomenda> encom = e.getEncomendas();
    if (fun.getTipoDeFuncionario() == "Entregador") {
        cout << "Bem vindo " << fun.getNome() << endl << endl;
        for (int i = 0; i < encom.size(); i++) {
            if (fun.getNome() == encom[i].getEntregadorNome()) {
                existe = true;
                cout << "Nome do Restaurante: \t" << encom[i].getRestauranteNome() << endl;
                cout << "Data de entrega: \t" << encom[i].getData().getDia() << "/"
                     << encom[i].getData().getMes() << "/"
                     << encom[i].getData().getAno() << endl;
                cout << "Nome do Entregador: \t" << encom[i].getEntregadorNome() << endl;
                cout << "Hora de entrega: \t" << encom[i].getHora() << endl;
                cout << "Pratos Encomendados: \t" << encom[i].getPratosNome() << endl;
                if (!encom[i].isSucesso()) { //isSucesso = 0
                    cout << "A entrega foi efetuada num concelho vizinho!" << endl;
                } else cout << "A entrega foi efetuada no proprio concelho!" << endl;

                if (!encom[i].isEntrega()) { //sem sucesso
                    srand(time(0));
                    string razoesInsucesso[4] = {"Restaurante fechado!", "Problema de transporte!",
                                                 "Aplicacao em atualizacao!",
                                                 "Todos os entregadores estao ocupados!\nTente novamente dentro de momentos"};

                    vector<string> random;
                    for (int i = 0; i < 3; i++) {
                        random.push_back(razoesInsucesso[rand() % 4]);
                    }
                    cout << random[0] << endl;
                } else cout << "Encomenda entregue com sucesso!\nBom Apetite!" << endl;
                cout << "Nome do Cliente: \t" << encom[i].getClienteNome() << endl;
                cout << "Valor da Encomenda: \t" << encom[i].getPreco() << " euros" << endl;
                cout << ":::::" << endl;

            }

        }
        if (!existe) {
            cout << "Ainda nao realizou nenhuma encomenda!" << endl;
        }
        system("pause");
    } else {
        cout << "Nao e entregador na nossa empresa!" << endl;
        system("pause");
    }


}
