/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double total=0.0;
	for (int i=0; i<this->accounts.size();i++){
	    if (this->accounts[i]->getCodH()==cod1)
	        total+=this->accounts[i]->getWithdraw();
	}
	return total;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res={};
	for (int i=0; i<bankOfficers.size(); i++){
	    if(bankOfficers[i].getName()==name) {
            res=bankOfficers[i].getAccounts();
            bankOfficers.erase(bankOfficers.begin()+i);
            break;
        }
	}
	return res;
}


// a alterar


const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    for (int i=0;i<bankOfficers.size();i++) {
        if (bankOfficers[i].getName() == name) {
            bankOfficers[i].addAccount(ac);
            return bankOfficers[i];
        }
    }
    throw NoBankOfficerException(name);
}


// a alterar
void Bank::sortAccounts() {
    for(unsigned int j=accounts.size()-1; j>0; j--) {
        bool troca = false;
        for (unsigned int i = 0; i < j; i++) {
            if (accounts[i + 1]->getBalance() < accounts[i]->getBalance()) {
                swap(accounts[i], accounts[i + 1]);
                troca = true;
            }
            if (accounts[i+1]->getBalance() == accounts[i]->getBalance())
            {
                if (accounts[i + 1] ->getCodIBAN() < accounts[i]->getCodIBAN())
                {
                    swap(accounts[i], accounts[i + 1]);
                    troca = true;
                }
            }

        }
        if (!troca) return;
    }
}

