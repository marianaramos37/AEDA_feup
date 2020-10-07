#include "ClubeVideo.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Filme& umFilme) {
	os << umFilme.titulo << " " << umFilme.emprestimos;
	return os;
}

ostream& operator<<(ostream& os, const PedidoCliente& pc) {
	os << "Cliente " << pc.nome << " em espera para " << pc.titulo << endl;
	return os;
}

ostream& operator<<(ostream& os, const Cliente& c1) {
	os << c1.nome << " tem " << c1.filmesEmprestados.size() << " filmes!\n";
	return os;
}


//
// Incluir abaixo a implementa��o das suas fun��es
//
bool ClubeVideo::existeCliente(string umNome) const{
    vector<Cliente>::const_iterator it;
    for(it= clientes.begin(); it!= clientes.end(); it++){
        if(it->getNome() == umNome) return true;
    }
    return false;
}

bool ClubeVideo::existeFilme(string umTitulo) const{
    vector<Filme>::const_iterator it;
    for(it = filmes.begin(); it!= filmes.end(); it++){
        if(it->getTitulo() == umTitulo) return true;
    }
    vector<Cliente>::const_iterator it1;
    for(it1= clientes.begin(); it1!= clientes.end(); it1++){
        stack<Filme> filmesEmprestados = it1->getFilmesEmprestados();
        while(!filmesEmprestados.empty()){
            if(filmesEmprestados.top().getTitulo() == umTitulo) return true;
            filmesEmprestados.pop();
        }
    }
    return false;
}

string ClubeVideo::imprimirFilmes() const{
    string result="";
    vector<Filme> filmesNaoRepetidos;
    vector<Filme>::const_iterator it;
    ostringstream os;
    bool repetido;

    for(it = filmes.begin(); it!= filmes.end(); it++){
        repetido=false;
        for(unsigned int i=0;i< filmesNaoRepetidos.size(); i++){
            if(*it == filmesNaoRepetidos[i]){
                repetido=true;
                break;
            }
        }
        if(!repetido){
            filmesNaoRepetidos.push_back(*it);
            os << *it << "\n";
        }
    }
    vector<Cliente>::const_iterator it1;
    for(it1= clientes.begin(); it1!= clientes.end(); it1++){
        stack<Filme> filmesEmprestados = it1->getFilmesEmprestados();
        while(!filmesEmprestados.empty()){
            repetido=false;
            for(unsigned int i=0;i< filmesNaoRepetidos.size(); i++){
                if(filmesEmprestados.top() == filmesNaoRepetidos[i]){
                    repetido=true;
                    break;
                }
            }
            if(!repetido){
                filmesNaoRepetidos.push_back(filmesEmprestados.top());
                os << filmesEmprestados.top() << "\n";
            }
            filmesEmprestados.pop();
        }
    }

    return os.str();
}

bool Filme::operator <(const Filme & f1) const{
    return titulo < f1.getTitulo();
}

list<string> ClubeVideo::titulosDisponiveis() const{
    string result="";
    list<string> filmesNaoRepetidos;
    vector<Filme>::const_iterator it;
    list<string>::const_iterator lIt;
    ostringstream os;
    bool repetido;

    for(it = filmes.begin(); it!= filmes.end(); it++){
        repetido=false;
        for(lIt =  filmesNaoRepetidos.begin(); lIt!=  filmesNaoRepetidos.end(); lIt++){
            if(*it == *lIt){
                repetido=true;
                break;
            }
        }
        if(!repetido)
            filmesNaoRepetidos.push_back(it->getTitulo());
    }

    filmesNaoRepetidos.sort();
    return filmesNaoRepetidos;
}

bool ClubeVideo::tituloDisponivel(string umTitulo) const{
    vector<Filme>::const_iterator it;
    for(it = filmes.begin(); it!= filmes.end(); it++){
        if(it->getTitulo() == umTitulo) return true;
    }
    return false;
}

string ClubeVideo::imprimirListaDeEspera() const{
    queue<PedidoCliente> listaEspera = pedidos;
    vector<string> tmp;

    while(!listaEspera.empty()){
        ostringstream os;
        os << listaEspera.front().getTituloFilme() << "\n";
        string filmeInfo = os.str();
        tmp.push_back(filmeInfo);
        os.clear();
        listaEspera.pop();
    }

    sort(tmp.begin(), tmp.end());
    string result="";
    for(size_t i=0; i<tmp.size(); i++){
        result+=tmp[i];
    }

    return result;
}

void ClubeVideo::alugar(string umNome, string umTitulo){
    if(existeFilme(umTitulo)){
        Cliente c(umNome);
        Filme f(umTitulo);
        if(existeCliente(umNome)){
            vector<Cliente>::iterator it = find(clientes.begin(), clientes.end(), c);
            if(tituloDisponivel(umTitulo)){
                vector<Filme>::iterator it1 = find(filmes.begin(), filmes.end(), f);
                it->addFilme(*it1);
                filmes.erase(it1);
            }
            else{
                PedidoCliente pc(umNome,umTitulo);
                pedidos.push(pc);
            }
        }
        else{
            if(tituloDisponivel(umTitulo)){
                vector<Filme>::iterator it1 = find(filmes.begin(), filmes.end(), f);
                c.addFilme(*it1);
                filmes.erase(it1);
                clientes.push_back(c);
            }
            else{
                PedidoCliente pc(umNome,umTitulo);
                pedidos.push(pc);
                clientes.push_back(c);
            }
        }
    }
    else{
       throw FilmeInexistente(umTitulo);
    }
}

void ClubeVideo::devolver(string umNome, string umTitulo){
    Cliente c(umNome);
    Filme f(umTitulo);

    vector<Cliente>::iterator it = find(clientes.begin(), clientes.end(), c);
    it->removeFilme(umTitulo);

    queue<PedidoCliente> pedidosCopy;
    bool found=false;
    while(!pedidos.empty()){
        if(pedidos.front().getTituloFilme() == umTitulo && !found){
            Cliente c1(pedidos.front().getNomeCliente());
            vector<Cliente>::iterator it1 = find(clientes.begin(), clientes.end(),c1);
            it1->addFilme(umTitulo);
            found=true;
        }
        else
            pedidosCopy.push(pedidos.front());
        pedidos.pop();
    }
    pedidos = pedidosCopy;

    if(!found){
        filmes.push_back(f);
    }

}