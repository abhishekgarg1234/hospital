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
	int getId();
	int getStaffCount();
	int getDocCount();
	int getSstaffCount();
	string getName();
	
	void addSupportStaff(string , string ,int,int);
	void addDoctor(string , string ,int,int);
	void addPatient(int,int,string,string,int,int);
	
	//void transferSupportStaff(department &);
	void transferStaff(department &);
	void transferDoc(department &, int, int);
	
	void releasePatient(int );
	void releaseDoctor(int);
	void supportStaffResigns(int );

	void displayStaff();
	void displayPatient();
};


#endif