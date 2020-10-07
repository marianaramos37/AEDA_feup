/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//

void FEUPConsulting::addAvailability(Student* s, string e, unsigned c) {
    Expertize exp=expertizes.find(Expertize(e,c));
    if(!(exp==Expertize("",0))){
        expertizes.remove(exp);
        exp.addConsultant(s);
        expertizes.insert(exp);
    }
    else{
        Expertize newexp(e,c);
        newexp.addConsultant(s);
        expertizes.insert(newexp);
    }
}

vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	vector<Student*> temp;
	BSTItrIn<Expertize> it(expertizes);
    vector<Student*>::iterator its;
	while(!it.isAtEnd()) {
        if(it.retrieve().getCost() == project->getCost() && it.retrieve().getName() == project->getExpertize()) {
            for (its = it.retrieve().getConsultants().begin(); its != it.retrieve().getConsultants().end(); its++) {
                if ((*its)->getCurrentProject() == "") {
                    temp.push_back(*its);
                }
            }
        }
        it.advance();
    }
	return temp;

}


bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
    vector<Student*> studentsVec = getCandidateStudents(project); // so estudantes que estao disponiveis
    vector<Student*>::iterator itS = studentsVec.begin();
    while(itS!=studentsVec.end()){
        if((*itS)->getName()==student->getName()){
            if(project->getConsultant()==NULL){ // se o projeto nao tiver ninguem associado
                project->setConsultant(student);
                student->addProject(project->getTitle());
                return true;
            }
        }
        itS++;
    }
	return false;

}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {
    StudentPtr s(student);
    students.insert(s);
}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	StudentPtr s(student);
	HashTabStudentPtr::iterator it=students.find(s);
	if(it!=students.end()){
	    students.erase(it);
	    s.setEMail(newEMail);
	    students.insert(s);
	}


}


//
// TODO: Part III - Priority Queue
//

void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {
    vector<Student>::const_iterator it;
    for(it = candidates.begin(); it != candidates.end(); it++){
        vector<string> projects = it->getPastProjects();
        if(projects.size() >= min){
            activeStudents.push(*it);
        }
    }
}


int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {
	//TODO:
	return 0;

}





















