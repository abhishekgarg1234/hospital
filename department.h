#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<string>
#include"linklist.h"
#include"staff.h"
using namespace std;

class department{
	llperson supportStaffs;
	llperson doctors;
	llperson patients;
	string dName;
	int depId;
	int staffCount;
	int dCount;
	int sStaffCount;
	int patientCount;
public:
	department(string ,int );
	void addSupportStaff(string , string ,int);
	void addDoctor(string , string ,int);
	int getId();
	void displayStaff();
	void displayPatient();
	string getName();
	int getStaffCount();
	int getDocCount();
	int getSstaffCount();
	void transferSupportStaff(department &);
	void transferStaff(department &);
	void addPatient(int,int,string,string,int);
	void releasePatient(int );
};


#endif