/*
 * Article.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include "Article.h"
#include <cmath>

using namespace std;

Article::Article(long cli, long bc) : client(cli), barCode(bc) {
	this->present = false;
	this->deliverHome = false;
	this->presentNumber = 0;
	this->arrivalNumber = 0;
};

Article::Article(const Article & a): client(a.getClient()), barCode(a.getBarCode()){
    this->present = a.getPresent();
    this->deliverHome = a.getDeliverHome();
    this->presentNumber = a.getPresentNumber();
    this->arrivalNumber = a.getArrivalNumber();
}

long Article::getClient() const {
	return client;
}

long Article::getBarCode() const {
	return barCode;
}

bool Article::getPresent() const {
	return present;
}

void Article::setPresent(bool present) {
	this->present = present;
}

bool Article::getDeliverHome() const {
	return deliverHome;
}

void Article::setDeliverHome(bool deliverHome) {
	this->deliverHome = deliverHome;
}

int Article::getPresentNumber() const {
	return presentNumber;
}

void Article::setPresentNumber(int presentNumber) {
	this->presentNumber = presentNumber;
}

int Article::getArrivalNumber() const {
	return arrivalNumber;
}

void Article::setArrivalNumber(int arrivalNumber) {
	this->arrivalNumber = arrivalNumber;
}

bool Article::operator <(const Article & a) const{
    if(deliverHome == true && a.getDeliverHome()==false){
        return false;
    }
    else if(deliverHome == false && a.getDeliverHome()==true){
        return true;
    }
    else if(deliverHome == false && a.getDeliverHome()==false){
        if(abs(presentNumber-a.getPresentNumber())>2) return presentNumber<a.getPresentNumber();
        else return arrivalNumber < a.getArrivalNumber();
    }
    else return arrivalNumber < a.getArrivalNumber();
}