// CSimpleList - Implementacao Simples de Lista Ligada
#include <iostream>
#include <string>

using namespace std;

class CNode{ 
private: 
    int d_data;   
    CNode *d_next; 
public:
    CNode(int data, CNode *next){ d_data=data; d_next=next; }
    void setData(int data) { d_data=data; }
    void setNext(CNode *next) { d_next=next; }
    int data() const { return d_data;}
    CNode *next() const { return d_next;}
    void print() const { cout << d_data << " ";}
};

class CSimpleList {
private: 
	 CNode *first; 
public:
    CSimpleList() { first=0; }
    ~CSimpleList() { 
        CNode *aux=first;
        CNode *cur;
        while(aux!=0) {
            cur = aux;
            aux = aux->next();
            delete cur;
        }
    }
    bool empty() const { return (first==0); }
    string toStr() const {
    	stringstream oss;
    	CNode *aux=first;
        while(aux!=0) { oss << aux->data() << " "; aux=aux->next(); }
        return oss.str();
     }
    void print() const {   
        CNode *aux=first;
        cout << "List: ";
        while(aux!=0) { aux->print(); aux=aux->next(); }
        cout << endl;
    }
	CNode *find(int elem) { 
      CNode *aux = first;
      while(aux!=0 && aux->data()!=elem) aux=aux->next();
      if(aux!=0) return aux;
      else { cerr << "Elem is not in list\n"; return 0;}
  	}
	void insert_head(int elem){ 
      CNode *res = new CNode(elem, first);
      first = res;
	}
	void insert_end(int elem){ 
      CNode *node, *aux;
      node = new CNode(elem,0); 
      aux = first;
      if(aux==0) first=node;
      else { 
          while(aux->next()!=0) aux = aux->next();
          aux->setNext(node);
      }
	}	
	void insert_sort(int elem) { 
    	CNode *prev, *node, *aux;
    	node = new CNode(elem,0); prev = 0; aux = first;
    	while(aux!=0 && aux->data()<elem) { prev = aux; aux = aux->next();}
    	node->setNext(aux);
    	if(prev==NULL) first=node; else prev->setNext(node);
  	}
	void intercalar(const CSimpleList &lst) //Grupo 2 c)
	{
        CNode *a = first; //guarda endereço do primeiro elem da lista A
        CNode *b = lst.first; //guarda endereço do primeiro elem da lista B
        while(a!=0){ //enquanto nao chegamos ao fim da lista A (o no end() é identificado com 0)
            if(b!=0){ //se a lista B nao tiver chegado ao fim
                //adicionamos novo nó à lista A, com conteudo do proximo elem de B (se existir)
                CNode *newNode = new CNode(b->data(), a->next());
                a->setNext(newNode);

                //avancamos para o proximo no que estava originalmente na lista A
                a=a->next();
                a=a->next();
                b=b->next(); //proximo elem da lista B
            }
            else break;
        }

	}
	int zipar() //Grupo 2 d)
	{
        int cnt=0;
		CNode *atual=first;
		CNode *anterior =nullptr;
		while(atual!=first){
		    //se for o primeiro elemento nao faz nada (passa para o segundo) para os restantes compara com o anterior
		    if(atual!=first){
                if(anterior->data()==atual->data()){
                    anterior->setNext(atual->next());//o anterior passa a apontar para depois do atual
                    // o atual deixou de existir e queremos avaliar o elemento que estava depois dele
                    atual=anterior;  // entao guardamos o anterior pois na proxima iteraçao vamos avancar para o aseguir a ele
                    cnt++;
                }
                else{
                    anterior=atual; // o atual passa a ser o anterior da proxima iteraçao
                }
                atual=atual->next();
		    }
		    else{
		        anterior=atual;
                atual=atual->next();
		    }
		}
		return cnt;
	}
}; 

