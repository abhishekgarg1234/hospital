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

void hospital::addDepartment(department &d){

	for(int i=0;i<nOfDep;i++){
		if(d.getName()==dep[i]->getName()){
			cout<<"Department already present";
			return;
		}
	}
	
	dep[nOfDep]=&d;
	nOfDep++;
}


void hospital::addNewSupportStaff(int did,string stafftype,string name,int ssid){

for(int i=0;i<nOfDep;i++){
		if(did==dep[i]->getId()){
			dep[i]->addSupportStaff(stafftype,name,ssid);
		}
	}
return;
}

void hospital::addNewDoctor(int did,string stafftype,string name,int ssid){

for(int i=0;i<nOfDep;i++){
		if(did==dep[i]->getId()){
			dep[i]->addDoctor(stafftype,name,ssid);
		}
	}
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



int hospital::getId(){
	return hId;
}
//
//void hospital::addDepartment(string hosp,string depart){
//	for(int i=0;i<nOfDep;i++){
//		if(d.getName()==dep[i]->getName()){
//			cout<<"Department already present";
//			return;
//		}
//	}
//		
//	dep[nOfDep]=&d;
//	nOfDep++;
//}

void hospital::displayDepartments(){
	for(int i=0;i<nOfDep;i++){
		cout<<"\nDepartment "<<i<<" : "<< dep[i]->getName()<<endl;
		cout<<"staff count : "<<dep[i]->getStaffCount()<<endl;
		cout<<"number of doctors: "<<dep[i]->getDocCount()<<endl;
		cout<<"number of support staff: "<<dep[i]->getSstaffCount()<<endl;
		dep[i]->displayStaff();
		dep[i]->displayPatient();
	}
}

ostream & operator <<(ostream &o,hospital &s){
	o<<endl<<"HOSPITAL :: "<<s.hName<<endl;
	o<<"Number of departments : "<<s.nOfDep<<endl;
	s.displayDepartments();
	return o;
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
void hospital::tranferDep(int did1,hospital &h2,int did2){
	department *d1=NULL;
	department *d2=NULL;
	for(int i=0;i<nOfDep;i++){
		if(did1==dep[i]->getId()){
			d1=dep[i];
		}
	}
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

int hospital::getAcode(){
		return aCode;
	}


int hospital::getNoDep(){
	return nOfDep;
}

void hospital::addNewPatient(int did,int pid,string pname,string illness,int bedno){
	for(int i=0;i<nOfDep;i++){
		if(did==dep[i]->getId()){
			dep[i]->addPatient(did,pid,pname,illness,bedno);
		}
	}

}

void hospital::releasePatient(int did, int pid)
{
	for (int i = 0; i<nOfDep; i++) {
		if (this->dep[i]->getId() == did) {
			dep[i]->releasePatient(pid);
		}
	}
}

hospital::~hospital()
{
	cout << "destructor called"<<endl;
}