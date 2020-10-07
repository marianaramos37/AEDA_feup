/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>

#include "BankOfficer.h"

template <class T>
unsigned int numberDifferent(const vector<T> &v1){
    vector<T> v2;
    bool a= false;
    for (int i=0; i<v1.size(); i++) {
        a=false;
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) {
                a = true;
                break;
            }
        }
        if (!a)
            v2.push_back(v1[i]);
    }
    return v2.size();
}

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
	//class NoBankOfficerException{};
};

class NoBankOfficerException {
    string name;
public:
    NoBankOfficerException(string name) {this->name = name; };
    string getName() {return name;};
};

#endif /* SRC_BANK_H_ */
