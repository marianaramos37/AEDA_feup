/*
 * Restaurant.cpp
 *
 *  Created on: 17/11/2015
 *      Author: hlc
 */

#include "Restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant() { }

Restaurant::Restaurant(vector< stack<Dish*> >* cl, queue<Dish*>* di, list<Dish*>* dr) {
	if(cl != NULL) clean = *cl;
	if(di != NULL) dirty = *di;
	if(dr != NULL) drying = *dr;
}

void Restaurant::addTable(unsigned int n_places) {
	tables.push_back(Table(n_places));
}

void Restaurant::addTable(Table& t) {
	tables.push_back(t);
}

const Table& Restaurant::getTable(vector<Table>::size_type idx) const {
	return tables[idx];
}

/**
 * Gets the clean dishes stack for a given collection and type.
 * If there is none, adds and returns an empty stack.
 */
stack<Dish*>& Restaurant::getCleanDishStack(string collection, TypeOfDish type) {

	for(vector< stack<Dish*> >::iterator it = clean.begin(); it != clean.end(); ++it) {
		if((*it).empty() || ((*it).top()->getCollection() == collection && (*it).top()->getType() == type)) {
			return *it;
		}
	}

	stack<Dish*> st;
	clean.push_back(st);
	return clean.back();
}

const queue<Dish*>& Restaurant::getDirty() const {
	return dirty;
}

const list<Dish*>& Restaurant::getDrying() const {
	return drying;
}

/**
 * Adds a number of dishes of a collection/type to the respective clean stack.
 */
void Restaurant::addDishes(unsigned int n, string collection, TypeOfDish type) {
    while(n>0){
        Dish* d= new Dish(collection,type);
        getCleanDishStack(collection,type).push(d);
        n--;
    }
}

/**
 * Washes a dish, getting if from the dirty queue and putting it in the wet list.
 * Returns the washed dish.
 */
Dish* Restaurant::washDish() {
    Dish* d;
    if(!dirty.empty()){
        d = dirty.front();
        dirty.pop();
        drying.push_back(d);
    }

	return d;
}

/**
 * Clears a table, placing all dishes that are on it in the dirty queue.
 */
void Restaurant::clearTable(vector<Table>::size_type idx) {
    if(tables.size() >idx){
        vector<Dish*> dishes = tables[idx].clear();
        for(size_t i=0; i< dishes.size(); i++){
            dirty.push(dishes[i]);
        }
    }
}

/**
 * Stores in the respective clean stack all drying dishes of a given collection and type.
 */
void Restaurant::storeDryDishes(string collection, TypeOfDish type) {
    list<Dish*>::iterator it;
    vector<Dish*> dishesToBeStored;

    for(it=drying.begin(); it!= drying.end();it++){
        if((*it)->getType() == type && (*it)->getCollection() == collection){
            dishesToBeStored.push_back(*it);
            it=drying.erase(it);
            it--;
        }
    }

    addDishes(dishesToBeStored.size(),collection,type);
}

/**
 * Puts Plates of a given collection in a table.
 * Throws TableNotReadyException when the table is not empty.
 * Throws NotEnoughDishesException when there are not enough clean plates of the collection.
 */
void Restaurant::setupTable(vector<Table>::size_type idx, string collection) {
    if(tables.size() > idx){
        for(size_t i=0; i<tables[idx].getPlaces().size(); i++){
            if(!tables[idx].getPlaces()[i].empty()) throw TableNotReadyException();
        }
        if(tables[idx].getPlaces().size() > getCleanDishStack(collection,Plate).size()) throw NotEnoughDishesException();

        vector<Dish*> dishes;
        for(unsigned int i = 0; i < tables[idx].size(); i++){
            dishes.push_back(getCleanDishStack(collection,Plate).top());
            getCleanDishStack(collection,Plate).pop();
        }
        tables[idx].putOn(dishes);
    }
}

bool sortDishes(const Dish * d1, const Dish * d2){
    return *d1<(*d2);
}

/**
 * Picks the dry dishes and groups them.
 * Returns the grouped dishes.
 */
list<Dish*> Restaurant::pickupAndGroupDryDishes() {
	list<Dish*> dry_grouped = drying;
	if(!drying.empty()) drying.clear();
	dry_grouped.sort(sortDishes);
	return dry_grouped;
}

/**
 * Stores grouped dishes in the respective clean stacks.
 * Returns the number of stacks that have been updated.
 */
int Restaurant::storeGroupedDishes(list<Dish*> grouped_dishes) {

    int n = 0;
    list<Dish*>::iterator it;
    Dish * d;

    for(it = grouped_dishes.begin(); it!= grouped_dishes.end();it++){
        if(it==grouped_dishes.begin()){
            d= *it;
            n++;
        }
        else{
            if((*it)->getType() != d->getType() || (*it)->getCollection() != d->getCollection()){
                d=*it;
                n++;
            }
        }
        getCleanDishStack((*it)->getCollection(),(*it)->getType()).push(*it);
    }
	return n;
}

