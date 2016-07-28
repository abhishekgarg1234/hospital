#include<iostream>
#include"staff.h"
#include"doctor.h"
#include"department.h"
#include"linklist.h"
using namespace std;

doctor::doctor(string s,int id):staff(s,id){
}

surgeon::surgeon(string s,int id):doctor(s,id){

}

radiologist::radiologist(string s,int id):doctor(s,id){

}

oncologist::oncologist(string s,int id):doctor(s,id){

}

paediatrician::paediatrician(string s,int id):doctor(s,id){

}
doctor::~doctor(){
}
