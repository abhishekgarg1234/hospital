#include"patient.h"
patient::patient(int pid,string pname,string illness,int bedno,int did):person(pname){
	pId=pid;
	pName=pname;
	p_illness=illness;
	bedNo=bedno;
	depId=did;
}

int patient::getBedNo()
{
	return bedNo;
}
