#include "Property.h"

Property::Property(string addr, string owner, string pc, string typo, int prc):
	address(addr), ownerName(owner), postalCode(pc), typology(typo), price(prc) {

}

string Property::getAddress() const {
	return this->address;
}

string Property::getOwnerName() const {
	return this->ownerName;
}

string Property::getPostalCode() const {
	return this->postalCode;
}

string Property::getTypology() const {
	return this->typology;
}

int Property::getPrice() const {
	return this->price;
}

tuple<Client*, int> Property::getReservation() const {
	return this->reservation;
}

void Property::setReservation(tuple<Client*, int> reserv) {
	this->reservation = reserv;
}

bool Property::operator==(const Property &pti1) const{
    return address==pti1.getAddress() && postalCode==pti1.getPostalCode() && typology==pti1.getTypology();
}