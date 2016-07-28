#include<iostream>
#include"hospital.h"
#include"staff.h"
#include"doctor.h"
#include"city.h"
using namespace std;

void main(){

	city delhi("delhi",4000);
	delhi.addAreaCode(100);
	delhi.addAreaCode(101);
	delhi.addAreaCode(102);
	delhi.addAreaCode(103);

	//hospitalName areacode hospitalId
	delhi.addHospital("Fortis",100,123);
	delhi.addHospital("Apollo",100,124);
	
	//areacode hospitalId,depName,depId
	delhi.addDepartment(100,123,"Radiology",12);
	delhi.addDepartment(100,124,"Pathology",13);

	//areacode, hospitalId,depId, sstype, name, id
	delhi.addSupportStaff(100,123,12,"nurse","upasana",11);
	delhi.addSupportStaff(100,124,13,"nurse","upasana",12);
	delhi.addDoctor(100,123,12,"surgeon","abhi",10);
	delhi.addDoctor(100,124,13,"surgeon","abhi",14);
	//cout<<delhi;

	// areacode1, hospital1 id, area code2, hospitalid2

	/*
	if(delhi.comparehospital(100,123,100,124))
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	cout << "$$$$$$$$$$" << endl;
	*/

	//delhi.displayHospital(100,123);

	//delhi.transferSupportStaff(100,123,12,100,123, 14,"NewDep");
	//delhi.transferSupportStaff(100,123,12,100,124,13);
	//delhi.deleteDepartment(100,123,12);
	//delhi.deleteHospital(100,123);
	delhi.addPatient(100,123,12,500,"ankush","fever",1000);
	delhi.releasePatient(100,123,12,500);
	cout<<delhi;
	int ii;
	cin >> ii;
}
