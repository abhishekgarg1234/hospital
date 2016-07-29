#include<string>
#include<iostream>
#include"hospital.h"
#include"department.h"

using namespace std;

hospital::hospital(){}

hospital::hospital(int aC,string name,int id)
{
	aCode=aC;
	hName=name;
	nOfDep=0;
	hId=id;
}

ostream & operator <<(ostream &o, hospital &s) {
	o << endl << "HOSPITAL :: " << s.hName << endl;
	o << "Number of departments : " << s.nOfDep << endl;
	s.displayDepartments();
	return o;
}

department * hospital::getDepartment(int nOfDep,int did){
	cout << "hospital::getDepartment";
	for(int i=0;i<nOfDep;i++){
		if(did==dep[i]->getId()){
			cout << "found department";
			return dep[i];
		}
	}
	cout << "Department not found ";
}

int hospital::getId() {
	return hId;
}

int hospital::getNoDep() {
	return nOfDep;
}

int hospital::getAcode() {
	return aCode;
}

void hospital::addNewSupportStaff(int did,string stafftype,string name,int ssid,int ag){
	cout << "hospital::addNewSupportStaff" << endl;
	department *d;
	d=getDepartment(nOfDep,did);
	d->addSupportStaff(stafftype,name,ssid,ag);
	return;
}

void hospital::addNewDoctor(int did,string stafftype,string name,int ssid,int ag){
	department *d;
	d = getDepartment(nOfDep, did);
	d->addDoctor(stafftype, name, ssid, ag);
	return;
}

void hospital::addNewDepartment(string depname,int did){

	for(int i=0;i<nOfDep;i++){
		if(did==dep[i]->getId()){
			cout<<"Department with same id already present";
			return;
		}
	}
	department *d = new department(depname,did);
	dep[nOfDep]=d;
	nOfDep++;
}

void hospital::addNewPatient(int did, int pid, string pname, string illness, int bedno, int ag) {
	department *d;
	d = getDepartment(nOfDep, did);
	d->addPatient(did, pid, pname, illness, bedno, ag);
}

bool hospital::compareHospital(hospital &h)
{
	int doc1 = 0, doc2 = 0, st1 = 0, st2 = 0;
	for (int i = 0; i<getNoDep(); i++) {
		doc1 += dep[i]->getDocCount();
		st1 += dep[i]->getSstaffCount();
	}
	for (int i = 0; i<h.getNoDep(); i++) {
		doc2 += h.dep[i]->getDocCount();
		st2 += h.dep[i]->getSstaffCount();
	}
	cout << "doc1 " << doc1 << " doc2" << doc2 << endl;
	cout << "st1 " << st1 << " st2" << st2 << endl;
	if (doc1 == doc2 && st1 == st2) {
		return true;
	}
	return false;
}

void hospital::tranferDoc(int did1, hospital & h, int did2, int docId1, int docId2) {
	department *d1 = NULL;
	department *d2 = NULL;
	d1 = getDepartment(nOfDep, did1);
	for (int i = 0; i<h.nOfDep; i++) {
		if (did2 == h.dep[i]->getId()) {
			d2 = dep[i];
		}
	}
	d2->transferDoc(*d1, docId1, docId2);
}

void hospital::tranferDep(int did1,hospital &h2,int did2){
	department *d1=NULL;
	department *d2=NULL;

	d1 = getDepartment(nOfDep, did1);
	
	for(int i=0;i<h2.nOfDep;i++){
		if(did2==h2.dep[i]->getId()){
			d2=dep[i];
		}
	}

	d2->transferStaff(*d1);
}

void hospital::deleteDepartment(int did){
	
	for(int i=0;i<nOfDep;i++){
		if(this->dep[i]->getId() == did){
			for(;i<nOfDep;i++){
				dep[i]=dep[i+1];
			}
			dep[i]=NULL;
		}
	}
	this->nOfDep--;
}

void hospital::releasePatient(int did, int pid){
	department *d;
	d = getDepartment(nOfDep, did);
	d->releasePatient(pid);
}

void hospital::supportStaffResigns(int did,int sid){
	department *d;
	d = getDepartment(nOfDep, did);
	d->supportStaffResigns(sid);
}

void hospital::releaseDoctor(int did ,int docId){
	department *d;
	d = getDepartment(nOfDep, did);
	d->releaseDoctor(docId);
}

void hospital::displayDepartments() {
	for (int i = 0; i<nOfDep; i++) {
		cout << "\nDepartment " << i << " : " << dep[i]->getName() << endl;
		cout << "staff count : " << dep[i]->getStaffCount() << endl;
		cout << "number of doctors: " << dep[i]->getDocCount() << endl;
		cout << "number of support staff: " << dep[i]->getSstaffCount() << endl;
		dep[i]->displayStaff();
		dep[i]->displayPatient();
	}
}

hospital::~hospital(){
	cout << "destructor called"<<endl;
}