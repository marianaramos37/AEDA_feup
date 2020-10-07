/*
 * Doctor.cpp
 */

#include "Doctor.h"


Patient::Patient(unsigned codP, string mS): codeP(codP), medicalSpecialty(mS)
{}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS): codeM(codM), medicalSpecialty(mS)
{}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1): codeM(codM), medicalSpecialty(mS), patients(patients1)
{}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	}
	else throw PatientInexistent();
}

bool Doctor::operator <(const Doctor & d) const{

    if(patients.size()<d.getPatients().size()){
        return true;
    }
    else if(patients.size()==d.getPatients().size()){
        if(medicalSpecialty<d.getMedicalSpecialty()){
            return true;
        }
        else if(medicalSpecialty==d.getMedicalSpecialty()){
            if(codeM<d.getCode()){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;

/*
    queue<Patient> patientsD = d.getPatients();
    if(patients.size() == patientsD.size()){
        if(medicalSpecialty == d.getMedicalSpecialty())
            return codeM < d.getCode();
        return medicalSpecialty < d.getMedicalSpecialty();
    }
    return patients.size()<patientsD.size();
     */
}

bool Doctor::operator ==(const Doctor & d) const{
    return d.getCode() == codeM;
}


void Doctor::moveToFront(unsigned codP1) {
    queue<Patient> aux={};
    Patient p;
    bool existe=false;
    int size1=patients.size();
    for(int i=0; i<size1; i++){
        if(patients.front().getCode()==codP1){
            p=patients.front();
            patients.pop();
            existe=true;
        }
        else{
            aux.push(patients.front());
            patients.pop();
        }
    }
    int size2=aux.size();
    if(existe){
        patients.push(p);
    }
    for(int i=0; i<size2; i++){
        patients.push(aux.front());
        aux.pop();
    }

    /*
    queue<Patient> pats= patients;
    queue<Patient>res;
    while(!pats.empty()){
        Patient p = pats.front();
        if(p.getCode() == codP1){
            res.push(p);
            break;
        }
        pats.pop();
    }
    while(!patients.empty()){
        Patient p = patients.front();
        if(p.getCode() != codP1)
           res.push(patients.front());
        patients.pop();
    }

    patients = res;
     */
}

