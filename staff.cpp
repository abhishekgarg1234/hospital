#include<iostream>
#include"staff.h"
#include"linklist.h"
using namespace std;


staff::staff(string s,int id):person(s){
	staffId=id;
}

supportStaff::supportStaff(string s,int id):staff(s,id){
	//sStaffCount++;
}

nurse::nurse(string s,int id):supportStaff(s,id){
}

cleaner::cleaner(string s,int id):supportStaff(s,id){
}

frontOffice::frontOffice(string s,int id):supportStaff(s,id){
}

staff::~staff(){
}
