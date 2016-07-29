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
	friend ostream & operator <<(ostream &,hospital &);
	department * getDepartment(int ,int );
	int getId();
	int getNoDep();
	int getAcode();
	
	void addNewDepartment(string ,int);
	void addNewSupportStaff(int,string,string,int,int);
	void addNewDoctor(int,string,string,int,int);
	void addNewPatient(int,int,string,string,int,int);

	bool compareHospital(hospital &);
	void tranferDep(int,hospital &,int );
	void tranferDoc(int, hospital &, int, int,int);
	
	void releasePatient(int ,int );
	void releaseDoctor(int ,int );
	void supportStaffResigns(int ,int );
	void deleteDepartment(int);

	void displayDepartments();

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