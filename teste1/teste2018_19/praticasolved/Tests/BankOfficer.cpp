/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int BankOfficer::current_id = 0;

BankOfficer::BankOfficer(): id(0) {}


void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar

BankOfficer::BankOfficer(string name) : id(current_id + 1){
    this->name = name;
    myAccounts = {};
    current_id++;
}

bool BankOfficer::operator> (BankOfficer& b1) {
    if (this->myAccounts.size() > b1.myAccounts.size())
        return true;
    else if (this->myAccounts.size() == b1.myAccounts.size())
        if (this->getName() > b1.getName())
            return true;
    return false;
}


