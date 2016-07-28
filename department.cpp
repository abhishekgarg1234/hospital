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

void department::addSupportStaff(string stafftype, string name,int sid){
	if(stafftype=="nurse"){
		staff *s= new nurse(name,sid);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else if(stafftype=="cleaner"){
		staff *s= new cleaner(name,sid);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else if(stafftype=="frontOffice"){
		staff *s= new frontOffice(name,sid);
		supportStaffs.addNode(s);
		sStaffCount++;
	}
	else{
		cout<<"wrong staff type"<<endl;
	}
	staffCount++;
}

void department::addDoctor(string stafftype, string name,int sid){
	
	if(stafftype=="surgeon"){
		staff *s= new surgeon(name,sid);
		doctors.addNode(s);
		dCount++;
	}
	else if(stafftype=="radiologist"){
		staff *s= new radiologist(name,sid);
		doctors.addNode(s);
		dCount++;
	}
	else if(stafftype=="oncologist"){
		staff *s= new oncologist(name,sid);
		doctors.addNode(s);
		dCount++;
	}
	else if(stafftype=="paediatrician"){
		staff *s= new paediatrician(name,sid);
		doctors.addNode(s);
		dCount++;
	}
	else{
		cout<<"wrong doctor type"<<endl;
	}
	staffCount++;
}

void department::displayStaff(){
	cout << "DOCTORS::" << endl;
	this->doctors.dispList();
	cout << "SUPPORT STAFF::" << endl;
	this->supportStaffs.dispList();
}

void department::displayPatient(){
	cout<<"PATIENTS::"<<endl;
	this->patients.dispList();
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
void department::transferSupportStaff(department &d)
{
	supportStaffs= supportStaffs + d.supportStaffs;
}

void department::transferStaff(department &d){
	supportStaffs= supportStaffs + d.supportStaffs;
	sStaffCount+=d.sStaffCount;
	staffCount += d.sStaffCount;
}

void department::addPatient(int did,int pid,string pname,string illness,int bedno){
	patient *s= new patient(pid,pname,illness,bedno,did);
	patients.addNode(s);
	patientCount++;

}
