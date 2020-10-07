#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */


// excecao NoRepetido
template <class N>
class NoRepetido{
public:
    N info;
    NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
    N info;
    NoInexistente(N inf) {
        info = inf;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }


template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
    N info;
    vector< Aresta<N,A> > arestas;
    No(N inf) {
        info = inf;
    }
};

template <class N, class A>
class Aresta {
public:
    A valor;
    No<N,A> *destino;
    Aresta(No<N,A> *dest, A val) {
        valor = val;
        destino = dest;
    }
};

//excecao ArestaRepetida

template <class N>
class ArestaRepetida
{
public:
    N inicio;
    N destino;
    ArestaRepetida(N inic, N dest) {
        inicio=inic;
        destino=dest; }
};


template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &aresta)
{
    out << "Aresta repetida: " << aresta.inicio << " , " << aresta.destino;
    return out;
}

// excecao ArestaInexistente
template <class N>
class ArestaInexistente {
public:
    N inicio, fim;
    ArestaInexistente(N s, N e) {
        inicio = s;
        fim = e;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ni)
{ out << "Aresta inexistente: "<< ni.inicio <<" , "<< ni.fim; return out; }

template <class N, class A>
class Grafo {
    vector< No<N,A> *> nos;
public:
    Grafo(){};
    ~Grafo(){
        /*//com iteradores
 * vector < No<N,A> * >::iterator it = nos.begin();
 * for(;it != nos.end(); it++)
 * {
 * 		delete *it;
 * }
 */ //vai dar erro por causa do template de dados não definidos, portanto devemos escrever typename antes da declaração do iterador
        for(size_t i=0; i < nos.size(); i++)
        {
            delete nos[i];
        }
    };
    Grafo & inserirNo(const N &dados){
        for (int i=0; i<nos.size(); i++){
            if (nos[i]->info==dados){
                throw NoRepetido<N>(dados);
            }
        }
        No<N,A> *a = new No<N,A>(dados);
        nos.push_back(a);
        return *this;
    }
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val) {
       bool found =false;
       typename vector<No<N,A>*>::iterator it_fim;
       for(typename vector<No<N,A>*>::iterator it = nos.begin(); it != nos.end(); it++)
           if((*it)->info==fim)
           {
               it_fim=it;
               found = true;
           }
       if (!found)
           throw NoInexistente<N>(fim);
       found=false;
       Aresta<N,A> a= Aresta<N,A>(*it_fim, val);
        for(typename vector<No<N,A>*>::iterator it = nos.begin(); it != nos.end(); it++)
            if((*it)->info==inicio)
            {
                for (typename vector<Aresta<N, A>>::iterator it_a = (*it)->arestas.begin(); it_a != (*it)->arestas.end(); it_a++){
                    if ((*it_a).destino->info == fim)
                        throw ArestaRepetida<N>(inicio, fim);
                }
                (*it)->arestas.push_back(a);
                found=true;
            }
        if(!found)
            throw NoInexistente<N>(inicio);
        return *this;

    }
    Grafo & eliminarAresta(const N &inicio, const N &fim){
        for(int i=0;i<nos.size();++i)
            if(nos.at(i)->info==inicio)
            {
                for(int j=0;j<nos.at(i)->arestas.size();++j)
                    if(nos.at(i)->arestas.at(j).destino->info==fim)
                    {
                        nos.at(i)->arestas.erase(nos.at(i)->arestas.begin()+i);
                        return *this;
                    }
                throw ArestaInexistente<N>(inicio,fim);
            }

        throw NoInexistente<N>(inicio);
    }
    A & valorAresta(const N &inicio, const N &fim){
        for(int i=0;i<nos.size();++i)
            if(nos.at(i)->info==inicio)
            {
                for(int j=0;j<nos.at(i)->arestas.size();++j)
                    if(nos.at(i)->arestas.at(j).destino->info==fim)
                        return nos.at(i)->arestas.at(j).valor;

                throw ArestaInexistente<N>(inicio,fim);
            }
        throw NoInexistente<N>(inicio);
    }
    int numArestas(void) const{
        int a=0;
        for (int i=0; i<nos.size(); i++){
            for (int j=0; j< nos[i]->arestas.size();i++){
                a+=1;
            }
        }
        return a;
    };
    int numNos(void) const{
        return nos.size();
    };
    void imprimir(std::ostream &os) const{
        for(int i=0;i<nos.size();++i)
        {
            os << "( " << nos.at(i)->info;
            for(int j=0;j<nos.at(i)->arestas.size();++j)
                os << "[ " << nos.at(i)->arestas.at(j).destino->info << " " << nos.at(i)->arestas.at(j).valor << "] ";
            os << ") ";
        }
    }
};

template <class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);



