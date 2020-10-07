#include "maquinaEmpacotar.h"
#include <sstream>
#include <algorithm>

MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


// a alterar
unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	unsigned cnt=0;
	vector<Objeto>::iterator it;
	for(it=objs.begin(); it!=objs.end(); it++){
	    if(it->getPeso()<=capacidadeCaixas){
	        objetos.push(*it);
	        it=objs.erase(it);
	        it--;
	        cnt++;
	    }
	}
	return cnt;
}

// a alterar
Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	Caixa cx;
	bool existe=false;
	vector<Caixa> aux;
	while(!caixas.empty()){
	    if(caixas.top().getCargaLivre()>=obj.getPeso()){
	        existe=true;
	        cx=caixas.top();
	        caixas.pop();
	        while(!caixas.empty()){
	            aux.push_back(caixas.top());
	            caixas.pop();
	        }
	        break;
	    }
	    else{
            aux.push_back(caixas.top());
            caixas.pop();
	    }
	}
	for(int i=0; i<aux.size(); i++){
	    caixas.push(aux[i]);
	}
	if(!existe){
	    cx=Caixa(capacidadeCaixas);
	}
	return cx;
}

// a alterar
unsigned MaquinaEmpacotar::empacotaObjetos() {
    while(!objetos.empty()){
        bool esta=false;
        Objeto obj=objetos.top();
        Caixa cx=procuraCaixa(obj);
        cx.addObjeto(obj);
        caixas.push(cx);
        objetos.pop();
    }
	return caixas.size();
}

// a alterar
string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
    HEAP_OBJS aux=objetos;
	if(!objetos.empty()){
        stringstream ss;
	    while(!aux.empty()){
            ss<<aux.top()<<endl;
            aux.pop();
        }
	    return ss.str();
	}
	return "Nao ha objetos!\n";
}

// a alterar
Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	if(caixas.empty())
        throw MaquinaSemCaixas();

    HEAP_CAIXAS aux=caixas;
    Caixa cx;
    while(!aux.empty()){
        if(aux.top().getSize()>cx.getSize()){
            cx=aux.top();
        };
        aux.pop();
    }
    return cx;

}



