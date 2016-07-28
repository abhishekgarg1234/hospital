#ifndef DOCTOR_H
#define DOCTOR_H

#include"linklist.h"
#include"staff.h"
using namespace std;

class doctor:public staff{
public:
	doctor(string ,int );
	virtual ~doctor()=0;
};

class surgeon : public doctor{
public:
	surgeon(string ,int );
};

class radiologist : public doctor{
public:
	radiologist(string ,int );
};

class oncologist : public doctor{
public:
	oncologist(string ,int );
};

class paediatrician : public doctor{
public:
	paediatrician(string ,int );
};

#endif