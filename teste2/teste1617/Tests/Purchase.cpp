/*
 * Purchase.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include "Purchase.h"

using namespace std;

Purchase::Purchase(long cli) : client (cli) {
}

long Purchase::getClient() const {
	return client;
}

list< stack<Article*> > Purchase::getBags() const {
	return bags;
}

/**
 * Create an Article associated with the client of this purchase.
 */
Article* Purchase::createArticle(long barCode, bool present, bool deliverHome) {
    Article *a= new Article(client, barCode);
    a->setPresent(present);
    a->setDeliverHome(deliverHome);
    return a;

    /*
	Article *a = new Article(client,barCode);
    a->setDeliverHome(deliverHome);
    a->setPresent(present);
	return a;
     */
}

/**
 * Add an Article to the bags of this purchase. A new bag is added when the last bag is full.
 */
void Purchase::putInBag(Article* article) {

    if (prev(bags.end())->size() >= BAG_SIZE) {
        std::stack<Article *> newstack;
        newstack.push(article);
        bags.push_back(newstack);
    } else {
        prev(bags.end())->push(article);
    }
}
/*
    std::list< std::stack<Article*> >::iterator it=prev(bags.end());

    if(it->size() < BAG_SIZE)
        it->push(article);
    else{
        std::stack<Article*> stackArt;
        stackArt.push(article);
        bags.push_back(stackArt);
    }
}
*/


/**
 * Pop from the bags all articles that are presents.
 * All other articles are pushed back into the bags where they were, maintaining order.
 */
vector<Article*> Purchase::popPresents() {
    vector<Article *> res;
    vector<Article *> aux;
    std::list<std::stack<Article *>>::iterator it;
    for(it=bags.begin(); it!=bags.end(); it++){
        Article *a=it->top();
        if(a->getPresent()){
            res.push_back(a);
            it->pop();
        }
        else{
            aux.push_back(a);
            it->pop();
        }
    }
    for(it=bags.begin(); it!=bags.end(); it++){
        while(it->size()<BAG_SIZE){
            for(int i=0; i<aux.size(); i++){
                it->push(aux[i]);
                aux.erase(aux.begin()+i);
            }
        }
    }


/*
	vector<Article*> presents;
    std::list< std::stack<Article*> >::iterator it;
    for(it=bags.begin(); it!= bags.end(); it++){
        std::stack<Article*> stackArt;
        while(!it->empty()){
            Article * a = it->top();
            if(a->getPresent())
                presents.push_back(a);
            else
                stackArt.push(a);
            it->pop();
        }
        while(!stackArt.empty()){
            it->push(stackArt.top());
            stackArt.pop();
        }
    }

	return presents;
*/
}

