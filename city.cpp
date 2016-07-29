#include<string>
#include<iostream>
#include"city.h"

using namespace std;

city::city(string cName ,int population){
	cityName=cName;
	numOfAreaCodes=population/1000;
	numOfHos_city=0;
	areaCode = new areacode[numOfAreaCodes];
	
	for(int i=0;i<numOfAreaCodes;i++)
	{
		areaCode[i].code=0;
		areaCode[i].nOh=0;
	}
}

hospital * city::findHospital(int numOfAreaCodes,int ac,int hid) {
	for (int i = 0; i<numOfAreaCodes; i++) {
		if (areaCode[i].code == ac) {
			for (int j = 0; j<areaCode[i].nOh; j++) {
				if (areaCode[i].hos[j]->getId() == hid) {
					return areaCode[i].hos[j];
				}
			}
		}
	}
	cout << " hospital not found" << endl;
}

ostream & operator <<(ostream &o, city &s) {
	int i = 0;
	o << endl;
	o << "City name : " << s.cityName << endl;

	while (s.areaCode[i].code != 0 && i<s.numOfAreaCodes) {
		o << endl << "**************" << endl;
		o << "\narea code : " << s.areaCode[i].code << endl << endl;
		for (int j = 0; j<s.areaCode[i].nOh; j++) {
			o << *(s.areaCode[i].hos[j]);
		}
		i++;
	}
	o << endl << endl;
	return o;
}

void city::addAreaCode(int code){
	int i=0,check=0;
	while(areaCode[i].code!=0){
		if(areaCode[i].code==code){
			cout<<"area code already present"<<endl;
			check=1;
			break;
		}
		i++;
	}

	if(check==0)
		areaCode[i].code=code;
	else
		return;
}

void city::createHospital(hospital &h) {
	int aC = h.getAcode();

	if (numOfHos_city <10) {
		numOfHos_city++;
	}
	else {
		cout << "max limit of hospitals in city reached";
		return;
	}

	for (int i = 0; i<numOfAreaCodes; i++) {
		if (areaCode[i].code == aC) {
			for (int k = 0; k<areaCode[i].nOh; k++) {
				if (areaCode[i].hos[k]->getId() == h.getId()) {
					cout << "already present hospital with this id";
					return;
				}
			}

			if (areaCode[i].nOh <= 3) {
				areaCode[i].hos[areaCode[i].nOh] = &h;
				areaCode[i].nOh++;
				break;
			}
			else
				cout << "max limit of hospitals in areacode reached\n";
		}
	}
}

void city::addHospital(string hname, int code, int id) {
	hospital *obj = new hospital(code, hname, id);
	createHospital(*obj);
}

void city::addDepartment(int ac, int hid, string depname, int did) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->addNewDepartment(depname, did);
}

void city::addSupportStaff(int ac, int hid, int did, string stafftype, string name, int id, int ag) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->addNewSupportStaff(did, stafftype, name, id, ag);
}

void city::addDoctor(int ac, int hid, int did, string stafftype, string name, int id, int ag) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->addNewDoctor(did, stafftype, name, id, ag);
}

void city::addPatient(int ac, int hid, int did, int pid, string pname, string illness, int bedno, int ag) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->addNewPatient(did, pid, pname, illness, bedno, ag);
}

bool city::comparehospital(int ac1,int hid1,int ac2,int hid2){

	hospital *a=NULL;
	hospital *b=NULL;
	a = findHospital(numOfAreaCodes, ac1, hid1);
	b = findHospital(numOfAreaCodes, ac2, hid2);
	return a->compareHospital(*b);
}

void city::transferSupportStaff(int ac1,int hid1,int did1, int ac2,int hid2,int did2,string newD){

	hospital *a=NULL;
	hospital *b=NULL;
	a = findHospital(numOfAreaCodes, ac1, hid1);
	if(newD=="")
	{
		b = findHospital(numOfAreaCodes, ac2, hid2);
		
	}
	else
	{
		b = findHospital(numOfAreaCodes, ac2, hid2);
		b->addNewDepartment(newD, did2);
	}
	a->tranferDep(did1,*b,did2);
}

void city::transferDoctors(int ac1, int hid1, int did1, int doc1id, int ac2, int hid2, int did2, int doc2id) {

	hospital *a = NULL;
	hospital *b = NULL;
	a = findHospital(numOfAreaCodes, ac1, hid1);
	b = findHospital(numOfAreaCodes, ac2, hid2);
	a->tranferDoc(did1, *b, did2, doc1id, doc2id);

}

void city::deleteHospital(int ac, int hid)
{
	for (int i = 0; i<numOfAreaCodes; i++) {
		if (areaCode[i].code == ac) {
			for (int j = 0; j<areaCode[i].nOh; j++) {
				if (areaCode[i].hos[j]->getId() == hid) {
					hospital *h = areaCode[i].hos[j];
					delete h;
					for (; j < areaCode[i].nOh - 1; j++) {
						areaCode[i].hos[j] = areaCode[i].hos[j + 1];
					}
					areaCode[i].nOh--;
					break;
					areaCode[i].hos[j] = NULL;
				}
			}
		}
		break;
	}
}

void city::deleteDepartment(int ac,int hid,int did){
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->deleteDepartment(did);
}

void city::releasePatient(int ac, int hid, int did, int pid)
{
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->releasePatient(did, pid);

}

void city::deleteDoctor(int ac ,int hid,int did,int docId ){
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->releaseDoctor(did, docId);
}

void city::supportStaffResigns(int ac, int hid, int did, int sid) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	h->supportStaffResigns(did, sid);
}

void city::displayHospital(int ac, int hid) {
	hospital *h;
	h = findHospital(numOfAreaCodes, ac, hid);
	cout << *h;
}

void city::displayHospitals() {
	int i = 0;
	while (areaCode[i].code != 0 && i<numOfAreaCodes) {
		cout << " a " << areaCode[i].code << "********************" << *(areaCode[i].hos[0]) << endl;
		i++;
	}
}