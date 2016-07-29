#include<iostream>
#include"staff.h"
#include"linklist.h"
using namespace std;


staff::staff(string s,int id,int ag):person(s,id,ag){
	staffId=id;
}

supportStaff::supportStaff(string s,int id,int ag):staff(s,id,ag){
	//sStaffCount++;
}

nurse::nurse(string s,int id,int ag):supportStaff(s,id,ag){
}

cleaner::cleaner(string s,int id,int ag):supportStaff(s,id,ag){
}

frontOffice::frontOffice(string s,int id,int ag):supportStaff(s,id,ag){
}

staff::~staff(){
}
