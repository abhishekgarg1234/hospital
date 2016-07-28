#ifndef HOSPITAL_H
#define HOSPITAL_H

#include<string>
#include"department.h"
using namespace std;

class hospital{
	int aCode;
	int nOfDep;
	int hId;
	string hName;
	department *dep[10];
	
public:
	hospital();
	hospital(int a,string s,int);
	
	void addDepartment(department &);

	void addNewDepartment(string ,int);
	void addNewSupportStaff(int,string,string,int);
	void addNewDoctor(int,string,string,int);
	bool compareHospital(hospital &);
	void tranferDep(int,hospital &,int );
	void addNewPatient(int,int,string,string,int);
	int getId();

	//void addDepartment(hospital &,string &);

	void displayDepartments();
	friend ostream & operator <<(ostream &,hospital &);
	void deleteDepartment(int);
	int getNoDep();
	int getAcode();
	 ~hospital();
};

/*

class qualification{

};

class docQualification : public qualification{

};

class supportStaffQualification : public qualification{

};





*/

#endif