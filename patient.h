#ifndef PATIENT_H
#define PATIENT_H

#include"linklist.h"
using namespace std;

class patient:public person{
	string pName;
	string p_illness;
	int pId;
	int bedNo;
	int depId;

public:
	patient(int,string,string,int,int);
	int getBedNo();

};
#endif