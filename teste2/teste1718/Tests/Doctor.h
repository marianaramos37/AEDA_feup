/*
 * Doctor.h
 */

#ifndef SRC_DOCTOR_H_
#define SRC_DOCTOR_H_

#include <string>
#include <queue>


using namespace std;

class Patient {
  unsigned codeP;
  string medicalSpecialty;
public:
  Patient(){codeP=0; medicalSpecialty="";};
  Patient(unsigned cod, string mS);
  string getMedicalSpecialty() const;
  unsigned getCode() const;
};


class Doctor {
  unsigned codeM;
  string medicalSpecialty;
  queue<Patient> patients;
public:
  Doctor(unsigned codM, string mS);
  Doctor(unsigned codM, string mS, queue<Patient> patients1);
  unsigned getCode() const;
  string getMedicalSpecialty() const;
  queue<Patient> getPatients() const;
  void addPatient(const Patient &p1);
  Patient removeNextPatient();
  bool operator <(const Doctor & d) const;
  bool operator ==(const Doctor & d) const;
  void moveToFront(unsigned codP1);

  class PatientInexistent {};

};


#endif /* SRC_DOCTOR_H_ */
