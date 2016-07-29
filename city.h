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

public:
	city(string cityName ,int population);
	hospital * findHospital(int , int , int );
	friend ostream & operator <<(ostream &,city &);

	void addAreaCode(int code);
	void createHospital(hospital &);
	void addHospital(string,int,int);
	void addDepartment(int ac,int hid,string depname,int did);
	void addSupportStaff(int,int,int,string,string,int,int);
	void addDoctor(int,int,int,string,string,int,int);
	void addPatient(int,int,int,int,string,string,int,int);
	

	bool comparehospital(int ,int ,int ,int);
	void transferSupportStaff(int,int,int,int,int,int,string s="");
	void transferDoctors(int ,int ,int ,int, int ,int ,int,int );
	
	void deleteHospital(int ,int );
	void deleteDepartment(int,int,int);
	void releasePatient(int ,int ,int ,int );
	void deleteDoctor(int ,int ,int ,int );
	void supportStaffResigns(int ,int ,int ,int );

	void displayHospital(int,int);
	void displayHospitals();
};

#endif