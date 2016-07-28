#ifndef LINKLIST_H
#define LINKLIST_H
#include<string>

using namespace std;

class person{
	string name;
public:
	person(string );
	string getName();
	friend ostream& operator <<(ostream &, person const &);
};
struct node{
		person *per;
		node *nxt;
	};
class llperson{
	
	node *hd;
public:
	llperson();
	void addNode(person *);
	void dispList();
	
	void deletePatient(int );
	friend llperson & operator +(llperson &,llperson &);
	//person *getPersonByName(string);
};












/*
class patient:public person{
	string illness;
	int bedNo;
public:
	patient(char *);
	int getBedNo();
};





class hospital{
	llperson patients;
	llperson doctors;
public:
	void patAdmitted(patient *);
	void doctorJoins(doctor *);
	void dispPatList();
	void dispDocsList();
	int getBedNo(char *);
};
*/

#endif