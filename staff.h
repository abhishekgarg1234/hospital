#ifndef STAFF_H
#define STAFF_H

#include"linklist.h"
using namespace std;

class staff:public person
{
	int staffId;
public:
	staff(string ,int ,int);
	virtual ~staff()=0;
};


class supportStaff:public staff{
	int sStaffCount;
public:
	supportStaff(string ,int,int);

};

class nurse:public supportStaff{
	int nurseCount;
public:
	nurse(string ,int,int);
};

class cleaner:public supportStaff{
	int cleanerCount;
public:
	cleaner(string ,int,int);
};

class frontOffice:public supportStaff
{
	int frontCount;
public:
	frontOffice(string ,int,int);

};

#endif