#include"patient.h"
patient::patient(int pid,string pname,string illness,int bedno,int did,int ag):person(pname,pid,ag){
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
