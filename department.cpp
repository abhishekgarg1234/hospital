#include<string>
#include<iostream>
#include"department.h"
#include"doctor.h"
#include"staff.h"
#include"patient.h"

using namespace std;

department::department(string s,int id){
	staffCount=0;
	dCount=0;
	sStaffCount=0;
	patientCount=0;
	dName=s;
	depId=id;
}

string department::getName(){
	return dName;
}

int department::getStaffCount(){
	return staffCount;
}

int department::getDocCount(){
	return dCount;
}

int department::getSstaffCount(){
	return sStaffCount;
}

int department::getId(){
	return depId;
}

void department::addSupportStaff(string stafftype, string name, int sid, int ag) {
	if (stafftype == "nurse") {
		staff *s = new nurse(name, sid, ag);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else if (stafftype == "cleaner") {
		staff *s = new cleaner(name, sid, ag);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else if (stafftype == "frontOffice") {
		staff *s = new frontOffice(name, sid, ag);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else {
		cout << "wrong staff type" << endl;
		staffCount--;
	}
	staffCount++;
}

void department::addDoctor(string stafftype, string name, int sid, int ag) {
	if (stafftype == "surgeon") {
		staff *s = new surgeon(name, sid, ag);
		doctors.addNode(s);
		dCount++;
	}
	else if (stafftype == "radiologist") {
		staff *s = new radiologist(name, sid, ag);
		doctors.addNode(s);
		dCount++;
	}
	else if (stafftype == "oncologist") {
		staff *s = new oncologist(name, sid, ag);
		doctors.addNode(s);
		dCount++;
	}
	else if (stafftype == "paediatrician") {
		staff *s = new paediatrician(name, sid, ag);
		doctors.addNode(s);
		dCount++;
	}
	else {
		cout << "wrong doctor type" << endl;
		staffCount--;
	}
	staffCount++;
}

void department::addPatient(int did, int pid, string pname, string illness, int bedno, int ag) {
	patient *s = new patient(pid, pname, illness, bedno, did, ag);
	patients.addNode(s);
	patientCount++;
}

void department::transferStaff(department &d){
	supportStaffs= supportStaffs + d.supportStaffs;
	sStaffCount+=d.sStaffCount;
	staffCount += d.sStaffCount;
}

void department::transferDoc(department &d, int docId1, int docId2){
	person *p1=doctors.getPerson(docId1);
	doctor *p=((doctor *)p1);
	if(surgeon * ptr = dynamic_cast<surgeon *>(p)){
		d.addDoctor("surgeon", p->getName(),docId2,p->getAge());
	}
	else if(radiologist * ptr = dynamic_cast<radiologist *>(p)){
		d.addDoctor("radiologist", p->getName(),docId2,p->getAge());
	}
	else if(oncologist * ptr = dynamic_cast<oncologist *>(p)){
		d.addDoctor("oncologist", p->getName(),docId2,p->getAge());
   
	}
	else if(paediatrician * ptr = dynamic_cast<paediatrician *>(p)){
		d.addDoctor("paediatrician", p->getName(),docId2,p->getAge());
   
	}
	else{
		cout<<"Not exist";
	}
}

void department::releasePatient(int pid){
	patients.deletePerson(pid);
	patientCount--;
	//person * p = patients.getPerson(pid);
	//cout<<"\n"<<((patient *)p)->getBedNo();
}

void department::supportStaffResigns(int sid){
	supportStaffs.deletePerson(sid);
	sStaffCount--;
	staffCount--;
}

void department::releaseDoctor(int docId){
		doctors.deletePerson(docId);
		dCount--;
}

void department::displayStaff() {
	cout << "DOCTORS::" << endl;
	this->doctors.dispList();
	cout << "SUPPORT STAFF::" << endl;
	this->supportStaffs.dispList();
}

void department::displayPatient() {
	cout << "PATIENTS::" << endl;
	this->patients.dispList();
}