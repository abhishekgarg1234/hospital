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

void city::deleteHospital(int ac, int hid)
{
	for (int i = 0; i<numOfAreaCodes; i++) {
		if (areaCode[i].code == ac) {
			for (int j = 0; j<areaCode[i].nOh; j++) {
				if (areaCode[i].hos[j]->getId() == hid) {
					hospital *h = areaCode[i].hos[j];
					//delete h;
					for (; j < areaCode[i].nOh-1; j++) {
						areaCode[i].hos[j] = areaCode[i].hos[j+1];
					}
					areaCode[i].nOh--;
					break;
					areaCode[i].hos[j] = NULL;
					//cout << *areaCode[i].hos[j];
				}
			}
		}
		break;
	}
}

void city::displayHospital(int ac, int hid)
{
	for (int i = 0; i<numOfAreaCodes; i++) {
		if (areaCode[i].code == ac) {
			for (int j = 0; j<areaCode[i].nOh; j++) {
				if (areaCode[i].hos[j]->getId() == hid) {
					cout << *areaCode[i].hos[j];
				}
			}
		}
	}

}

void city::createHospital(hospital &h){
	int aC=h.getAcode();

	if(numOfHos_city <10){
		numOfHos_city++;}
	else{
		cout<<"max limit of hospitals in city reached";
		return;
	}

	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==aC){
			for(int k=0;k<areaCode[i].nOh;k++){
				if(areaCode[i].hos[k]->getId() == h.getId()){
					cout<<"already present hospital with this id";
					return;
				}
			}

			if(areaCode[i].nOh<=3){
				areaCode[i].hos[areaCode[i].nOh]=&h;				
				areaCode[i].nOh++;
				break;
			}
			else
				cout<<"max limit of hospitals in areacode reached\n";
		}
	}
}

void city::displayHospitals(){
	int i=0;
	while(areaCode[i].code!=0 && i<numOfAreaCodes){
		cout<<" a "<<areaCode[i].code<<"********************"<<*(areaCode[i].hos[0])<< endl;
		i++;
	}	
}

ostream & operator <<(ostream &o,city &s){
	int i=0;
	o<<endl;
	o<<"City name : "<<s.cityName<<endl;

	while(s.areaCode[i].code!=0 && i<s.numOfAreaCodes){
		o<<endl<<"**************"<<endl;
		o<<"\narea code : "<<s.areaCode[i].code<<endl<<endl;
		for(int j=0;j<s.areaCode[i].nOh;j++){
			o<<*(s.areaCode[i].hos[j]);
		}
		i++;
	}
	o<<endl<<endl;
	return o;
}



void city::addHospital(string hname,int code,int id){

	hospital *obj=new hospital(code,hname,id);

	createHospital(*obj);

}


void city::addDepartment(int ac,int hid,string depname,int did){
	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid){
					areaCode[i].hos[j]->addNewDepartment(depname,did);
				}
			}
		}
	}
}


void city::addSupportStaff(int ac,int hid,int did,string stafftype, string name,int id){

	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid){
					areaCode[i].hos[j]->addNewSupportStaff(did,stafftype,name,id);
				}
			}
		}
	}
}

void city::addDoctor(int ac,int hid,int did,string stafftype, string name,int id){
	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid){
					areaCode[i].hos[j]->addNewDoctor(did,stafftype,name,id);
				}
			}
		}
	}
}

bool city::comparehospital(int ac1,int hid1,int ac2,int hid2){

	hospital *a=NULL;
	hospital *b=NULL;
	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac1){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid1){
					a=areaCode[i].hos[j];
				}
			}
		}
	}

	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac2){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid2){
					b=areaCode[i].hos[j];
				}
			}
		}
	}
	return a->compareHospital(*b);
}

void city::transferSupportStaff(int ac1,int hid1,int did1, int ac2,int hid2,int did2,string newD){

	hospital *a=NULL;
	hospital *b=NULL;
	for(int i=0;i<numOfAreaCodes;i++){
			if(areaCode[i].code==ac1){
				for(int j=0;j<areaCode[i].nOh;j++){
					if(areaCode[i].hos[j]->getId()==hid1){
						a=areaCode[i].hos[j];
						break;
					}
				}
				break;
			}
		}
	if(newD=="")
	{
		for(int i=0;i<numOfAreaCodes;i++){
			if(areaCode[i].code==ac2){
				for(int j=0;j<areaCode[i].nOh;j++){
					if(areaCode[i].hos[j]->getId()==hid2){
						b=areaCode[i].hos[j];
						break;
					}
				}
				break;
			}
		}
		
	}
	else
	{
		for(int i=0;i<numOfAreaCodes;i++){
			if(areaCode[i].code==ac2){
				for(int j=0;j<areaCode[i].nOh;j++){
					if(areaCode[i].hos[j]->getId()==hid2){
						areaCode[i].hos[j]->addNewDepartment(newD,did2);
						b=areaCode[i].hos[j];
						break;
					}
				}
				break;
			}
		}

	}
	a->tranferDep(did1,*b,did2);
//a->tranferDep(did1,*b,did2);

}

void city::deleteDepartment(int ac,int hid,int did){

	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid){
					areaCode[i].hos[j]->deleteDepartment(did);
				}
			}
		}
	}



}

void city::addPatient(int ac,int hid,int did,int pid,string pname,string illness,int bedno){

	for(int i=0;i<numOfAreaCodes;i++){
		if(areaCode[i].code==ac){
			for(int j=0;j<areaCode[i].nOh;j++){
				if(areaCode[i].hos[j]->getId()==hid){
					areaCode[i].hos[j]->addNewPatient(did,pid,pname,illness,bedno);
					break;
				}
			}
			break;
		}
	}


}