#include<iostream>
#include"linklist.h"
#include<string>
using namespace std;

llperson::llperson()
{
	hd = NULL;
}

void llperson::addNode(person *p){
	
	node *tmp = new node;
	tmp->per = p;
	tmp->nxt = hd;
	hd=tmp;
	
}

person::person(string s,int iD,int ag){
	//cout<<"person"<<endl;
	name=s;
	id=iD;
	age=ag;
}


ostream& operator <<(ostream &o, person const & p)
{
	o<<p.name;
	return o;
}

string person::getName()
{
	return name;
}

int person::getAge(){
	return age;
}

void llperson::dispList()
{
	node *tmp = hd;
	while(tmp!=NULL)
	{
		cout<<tmp->per->getName()<<endl;
		tmp=tmp->nxt;
	}
}

void llperson::deletePerson(int pid)
{
	node * tmp;
	tmp=hd;
	node *prev;
	prev=tmp;
	node *next;
	next = tmp;

	if(tmp->per->getId() == pid){
		hd=hd->nxt;
		delete tmp;
		return;
	}
	prev=tmp;
	tmp=tmp->nxt;
	while(tmp!=NULL)
	{
		if(tmp->per->getId()== pid){
			prev->nxt=tmp->nxt;
			delete tmp;
			return;
		}
		tmp=tmp->nxt;
	}	
}

llperson &  operator +(llperson & first,llperson & sec){
	node *tmp = sec.hd;
	while(tmp!=NULL){
		tmp = tmp->nxt;
	}
	tmp=first.hd;
	return sec;
}


person * llperson::getPerson(int id)
{
	node * tmp;
	tmp=hd;

	while(tmp!=NULL)
	{
		if(tmp->per->getId()== id)
			return tmp->per;

		tmp=tmp->nxt;
	}

	return tmp->per;
}


int person::getId(){
	return id;
}














/*




void hospital::patAdmitted(patient *p){
	patients.addNode(p);
}

void hospital::doctorJoins(doctor *p)
{
	doctors.addNode(p);
}

patient::patient(char *s):person(s){
	illness="fever";
	bedNo=127;
}


void hospital::dispPatList(){
	this->patients.dispList();
}





int patient::getBedNo()
{
	return bedNo;
}

void hospital::dispDocsList()
{
	this->doctors.dispList();
}

int hospital::getBedNo(char * s)
{
	try{
		patient * p = (patient *)this->patients.getPersonByName(s);
		if(p==NULL) throw s;
		return p->getBedNo();
	}
	catch(char * s)
	{
		
		cout<<"Name : "<<s<<" not found."<<endl;
		return 0;
	}
	
	
}

person * llperson::getPersonByName(string s)
{
	node * tmp = hd;
	while(tmp!=NULL)
	{
		if(tmp->per->getName()==s)
		{
			
			return tmp->per;
		}
		tmp=tmp->nxt;
	}
}
*/