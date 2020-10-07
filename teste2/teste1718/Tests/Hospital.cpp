/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>
#include <iostream>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
    unsigned int num=0;
    list<Doctor>::const_iterator it;
    for(it=doctors.begin(); it!=doctors.end(); it++){
        if(it->getMedicalSpecialty()==medicalSpecialty){
            num+=it->getPatients().size();
        }
    }
    return num;
    /*
    int n=0;
    list<Doctor>::const_iterator it;
    for(it=doctors.begin(); it!= doctors.end(); it++){
        if(it->getMedicalSpecialty() == medicalSpecialty){
            queue<Patient> patients = it->getPatients();
            n+=patients.size();
        }
    }
	return n;
*/
}

void Hospital::sortDoctors() {
    doctors.sort();

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
    Doctor d(codM1, medicalSpecialty1);
    int num=0;
    list<Doctor>::iterator it;
    for(it=doctors.begin(); it!=doctors.end();it++ ){
        if(it->getMedicalSpecialty()==medicalSpecialty1)
            num+=1;
    }
    if(num<3){
        doctors.push_back(d);
        return true;
    }
    return false;
/*
    int n=0;
    list<Doctor>::iterator it;
    for(it=doctors.begin(); it!= doctors.end(); it++){
        if(it->getMedicalSpecialty() == medicalSpecialty1)
            n++;
    }
    if(n>=3) return false;

    Doctor d(codM1,medicalSpecialty1);
    doctors.push_back(d);
	return true;
 */
}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
    list<Doctor>::iterator it;
    for(it=doctors.begin(); it!=doctors.end(); it++){
        if(it->getCode()==codM1){
            doctors.erase(it);
            return it->getPatients();
        }
    }
    throw DoctorInexistent();

    /*
    Doctor d1(codM1, "");
    if(find(doctors.begin(), doctors.end(),d1) == doctors.end())
        throw DoctorInexistent();


	queue<Patient> p1 = find(doctors.begin(), doctors.end(),d1)->getPatients();
	doctors.erase(find(doctors.begin(), doctors.end(),d1));
	return p1;
*/
}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
    list<Doctor>::iterator it;
    list<Doctor>::iterator lessBusyDoctor=doctors.end();
    for(it=doctors.begin(); it!=doctors.end();it++){
        if(it->getMedicalSpecialty() == medicalSpecialty1){
            if(lessBusyDoctor == doctors.end())
                lessBusyDoctor = it;
            else{
                queue<Patient>p1 = lessBusyDoctor->getPatients();
                queue<Patient>p2= it->getPatients();
                if(p2.size()< p1.size()) lessBusyDoctor=it;
            }
        }
    }
	if(lessBusyDoctor == doctors.end()) return false;
	Patient patient(cod1,medicalSpecialty1);
	lessBusyDoctor->addPatient(patient);
	return true;

}



void Hospital::processPatient(unsigned codM1) {
    Patient p;
    list<Doctor>::iterator it;
    bool existe=false;
    for(it=doctors.begin(); it!=doctors.end(); it++){
        if(it->getCode()==codM1){
            if(it->getPatients().size()==0) return;
            p=it->removeNextPatient();
            existe=true;
        }
    }
    if(!existe) return;

    list<stack<Patient>>::iterator it2;
    bool sucess=false;
    for(it2 = letterTray.begin(); it2 != letterTray.end(); it2++) {
        if (it2->size() < trayCapacity) {
            it2->push(p);
            sucess=true;
            break;
        }
    }
    if(sucess==false){
        stack<Patient> newStack={};
        newStack.push(p);
        letterTray.push_back(newStack);
    }


    /*
    Doctor d(codM1,"");
	list<Doctor>::iterator dIt = find(doctors.begin(), doctors.end(), d);
	if(dIt == doctors.end())
	    return;
	queue<Patient> dPatients = dIt->getPatients();
    Patient p;
	if(!dPatients.empty())
        p = dIt->removeNextPatient();
	else
	    return;

    list<stack<Patient>>::iterator trayIt;
    bool added=false;
	for(trayIt = letterTray.begin(); trayIt != letterTray.end(); trayIt++){
	    if(trayIt->size() < trayCapacity){
	        trayIt->push(p);
	        added = true;
	        break;
	    }
	}
	if(!added){
	    stack<Patient> newStack;
	    newStack.push(p);
	    letterTray.push_back(newStack);
	}
*/
}


unsigned Hospital::removePatients(unsigned codP1) {
	list<stack<Patient>>::iterator it;
	int n=0;
	for(it=letterTray.begin(); it!= letterTray.end(); it++){
	    if(!it->empty()){
            Patient p = it->top();
            if(p.getCode() == codP1){
                it->pop();
                n++;
                if(it->empty())
                    it = letterTray.erase(it);
            }
	    }
	}
	return n;

}



