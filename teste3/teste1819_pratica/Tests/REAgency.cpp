#include "REAgency.h"

REAgency::REAgency(): catalogItems(PropertyTypeItem("", "","", 0)) {
	//do nothing!
}

REAgency::REAgency(vector<Property*> properties): catalogItems(PropertyTypeItem("", "","", 0)) {
	this->properties = properties;
}

void REAgency::addProperty(Property* property) {
	this->properties.push_back(property);
}

void REAgency::addProperties(vector<Property*> properties) {
	this->properties = properties;
}

vector<Property*> REAgency::getProperties() const{
	return this->properties;
}

PropertyTypeItem REAgency::getTypeItem(string address, string postalCode, string typology) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getAddress() == address && it.retrieve().getPostalCode() == postalCode && it.retrieve().getTypology() == typology) {
			PropertyTypeItem pti(it.retrieve().getAddress(), it.retrieve().getPostalCode(), it.retrieve().getTypology(), 0);
			pti.setItems(it.retrieve().getItems());
			return pti;
		}
		it.advance();
	}
	return itemNotFound;
}

void REAgency::addTypeItem(Property* property) {
	PropertyTypeItem itemNotFound("", "","", 0);
	PropertyTypeItem pti(property->getAddress(), property->getPostalCode(), property->getTypology(), property->	getPrice());
	PropertyTypeItem ptiX = catalogItems.find(pti);
	if(ptiX == itemNotFound) {
		pti.addItems(property);
		this->catalogItems.insert(pti);
	}
	else {
		this->catalogItems.remove(ptiX);
		ptiX.addItems(property);
		this->catalogItems.insert(ptiX);
	}
	properties.push_back(property);
}

BST<PropertyTypeItem> REAgency::getTypeItems() const {
	return this->catalogItems;
}

vector<ClientRecord> REAgency::getClientRecords() const {
	vector<ClientRecord> records;
	HashTabClientRecord::const_iterator it1 = this->listingRecords.begin();
	HashTabClientRecord::const_iterator it2 = this->listingRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void REAgency::setClientRecords(vector<ClientRecord>& crs) {
	for(unsigned int i = 0; i < crs.size(); i++) {
		listingRecords.insert(crs[i]);
	}

}

priority_queue<Client> REAgency::getClientProfiles() const {
	return clientProfiles;
}
void REAgency::setClientProfiles(priority_queue<Client>& profiles) {
	clientProfiles = profiles;
}

//
// TODO: Part I   - BST
//
void REAgency::generateCatalog() {
    vector<Property*>::const_iterator it;
    PropertyTypeItem notFound("","","",0);

    for(it = properties.begin(); it != properties.end(); it++){
        PropertyTypeItem p((*it)->getAddress(),(*it)->getPostalCode(),(*it)->getTypology(), 0);
        PropertyTypeItem foundOrNot = catalogItems.find(p);

        if(foundOrNot == notFound){//não encontrou adiciona novo tipo de propriedade
            p.addItems(*it);
            catalogItems.insert(p);
        }
        else{//já existe esse tipo de propriedade
            //se queremos encontrar um elemento temos que encontrar guardar remover mudar e voltar a inserir
            p=foundOrNot;
            catalogItems.remove(foundOrNot);
            p.addItems(*it);
            catalogItems.insert(p);
        }
    }
}

vector<Property*> REAgency::getAvailableProperties(Property* property) const {
    vector<Property*> temp;
    BSTItrIn<PropertyTypeItem> it(catalogItems);
    while(!it.isAtEnd()) {
        Property p(it.retrieve().getAddress(), "", it.retrieve().getPostalCode(), it.retrieve().getTypology(),
                   it.retrieve().getMaxPrice());
        if (p == *property) {
            vector<Property *>::const_iterator pIt;
            vector<Property *> pVec = it.retrieve().getItems();
            for (pIt = pVec.begin(); pIt != pVec.end(); pIt++) {
                if ((*pIt)->getReservation() == tuple<Client *, int>())
                    temp.push_back(*pIt);
            }
        }
        it.advance();
    }
    return temp;
}

bool REAgency::reservePropertyFromCatalog(Property* property, Client* client, int percentage) {
    vector<Property*>::const_iterator it;
    BSTItrIn<PropertyTypeItem> itPTI(catalogItems);
    PropertyTypeItem p(property->getAddress(),property->getPostalCode(),property->getTypology(),property->getPrice());
    while(!itPTI.isAtEnd()){
        if(itPTI.retrieve() == p){
            vector<Property*> properties = itPTI.retrieve().getItems();
            for(it=properties.begin(); it!=properties.end();it++){
                if(*(*it) == *property && (*it)->getReservation()==tuple<Client*,int>()){
                    catalogItems.remove(p);
                    client->addVisiting(p.getPostalCode(),p.getTypology(),p.getTypology(),to_string(p.getMaxPrice()));
                    (*it)->setReservation(tuple<Client*,int>(client,p.getMaxPrice()-p.getMaxPrice()*percentage/100.0));
                    p.setItems(properties);
                    catalogItems.insert(p);
                    return true;
                }
            }
        }
        itPTI.advance();
    }

    return false;
	return false;
}

//
// TODO: Part II  - Hash Table
//
void REAgency::addClientRecord(Client* client) {
    ClientRecord cr(client);
	listingRecords.insert(cr);

}

void REAgency::deleteClients() {
    unordered_set<ClientRecord, clientRecordHash, clientRecordHash>::iterator it=listingRecords.begin();
    while(it!=listingRecords.end()){
        if(it->getClientPointer()->getVisitedProperties().empty() && get<0>((*it).getClientPointer()->getVisiting()).empty()){
            it = listingRecords.erase(it);
        }
        else it++;
    }
}

//
// TODO: Part III - Priority Queue
//
void REAgency::addBestClientProfiles(const vector<Client>candidates, int min) {
	//TODO: F

}

vector<Property*> REAgency::suggestProperties() {
	//TODO: G
	vector<Property*> tempProperties;

	return tempProperties;
}
