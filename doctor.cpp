#include<iostream>
#include"staff.h"
#include"doctor.h"
#include"department.h"
#include"linklist.h"
using namespace std;

doctor::doctor(string s,int id,int ag):staff(s,id,ag){
	age=ag;
}

surgeon::surgeon(string s,int id,int ag):doctor(s,id,ag){

}

radiologist::radiologist(string s,int id,int ag):doctor(s,id,ag){

}

oncologist::oncologist(string s,int id,int ag):doctor(s,id,ag){

}

paediatrician::paediatrician(string s,int id,int ag):doctor(s,id,ag){

}
doctor::~doctor(){
}
