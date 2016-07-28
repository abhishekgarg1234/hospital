#ifndef CITY_H
#define CITY_H

#include<string>
#include"hospital.h"
using namespace std;

struct areacode{
	int code;
	int nOh;
	hospital *hos[4];
};

class city{
	int population;
	string cityName;
	int numOfHos_city;
	int numOfAreaCodes;
	areacode *areaCode;
	//hospital *hosp;

public:
	city(string cityName ,int population);

	void addHospital(string,int,int);
	void addDepartment(int ac,int hid,string depname,int did);
	void addSupportStaff(int,int,int,string,string,int);
	void addDoctor(int,int,int,string,string,int);

	bool comparehospital(int ,int ,int ,int);
	void transferSupportStaff(int,int,int,int,int,int,string s="");
	void deleteDepartment(int,int,int);
	void addPatient(int,int,int,int,string,string,int);


	void displayHospital(int,int);
	void createHospital(hospital &);
	void displayHospitals();
	void addAreaCode(int code);
	void deleteHospital(int ,int );
	friend ostream & operator <<(ostream &,city &);
};

#endif