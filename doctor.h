#ifndef DOCTOR_H
#define DOCTOR_H

#include"linklist.h"
#include"staff.h"
using namespace std;

class doctor:public staff{
	int age;
	int mobileNo;
public:
	doctor(string ,int ,int);
	virtual ~doctor()=0;
};

class surgeon : public doctor{
public:
	surgeon(string ,int ,int);
};

class radiologist : public doctor{
public:
	radiologist(string ,int ,int);
};

class oncologist : public doctor{
public:
	oncologist(string ,int ,int);
};

class paediatrician : public doctor{
public:
	paediatrician(string ,int ,int);
};

#endif