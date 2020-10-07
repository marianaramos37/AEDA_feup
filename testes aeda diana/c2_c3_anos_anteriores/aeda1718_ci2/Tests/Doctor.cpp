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
    queue<Patient> patientsD = d.getPatients();
    if(patients.size() == patientsD.size()){
        if(medicalSpecialty == d.getMedicalSpecialty())
            return codeM < d.getCode();
        return medicalSpecialty < d.getMedicalSpecialty();
    }
    return patients.size()<patientsD.size();
}

bool Doctor::operator ==(const Doctor & d) const{
    return d.getCode() == codeM;
}


void Doctor::moveToFront(unsigned codP1) {
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
}

