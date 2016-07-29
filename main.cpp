#include<iostream>
#include"hospital.h"
#include"staff.h"
#include"doctor.h"
#include"city.h"
using namespace std;

void addHospitalMain(city &,int ac=0);
void addDepartmentMain(city &,int ac=0,int hid=0);


void addAreaCodeMain(city &c){
	int areaCode;
	cout<<"\nEnter area code : ";
	cin>>areaCode;
	c.addAreaCode(areaCode);

	cout<<"\nDo you want to add hospital : y/n ";
	char check1;
	cin>>check1;
	
	while(check1=='y'){
		if(check1=='y'){
			addHospitalMain(c,areaCode);
			cout<<"\nDo you want to add more hospital : y/n ";
			cin>>check1;
		}
		else
			break;
	}
}
void addHospitalMain(city & c,int ac){
	string hname;
	int hid;
	if(ac==0){
		int areaCode;
		cout<<"\nEnter area code : ";
		cin>>areaCode;
		ac=areaCode;
	}
	cout<<"\nEnter Hospital name : ";
	cin>>hname;
	cout<<"\nEnter hospital id : ";
	cin>>hid;
	c.addHospital(hname,ac,hid);

	cout<<"\nDo you want to add Department : y/n ";
	char check;
	cin>>check;
	
	while(check=='y'){
		if(check=='y'){
			addDepartmentMain(c,ac,hid);
			cout<<"\nDo you want to add more Department : y/n ";
			cin>>check;
		}
		else
			break;
	}
}

void addDepartmentMain(city &c,int ac,int hid){
	int arc, hos, dId;
	string dname;
	
	if(ac==0){
		cout<<"\nEnter area code : ";
		cin>>arc;
		ac=arc;
	}
	if(hid==0){
		cout<<"\nEnter hospital id : ";
		cin>>hos;
		hid=hos;
	}
	cout<<"\n Enter Department name : ";
	cin>>dname;
	cout<<"\nEnter department id : ";
	cin>>dId;
	c.addDepartment(ac,hid,dname,dId);
}

void displayCityMain(city &c){
	cout<<c;
}

void addSupportStaffMain(city &c,int ac=0,int hid=0, int did=0){
	int scheck=1;
	while(scheck){

		int arc,hos,ddid;
		if(ac==0){
			cout<<"\nEnter area code : ";
			cin>>arc;
			ac=arc;
		}
		if(hid==0){
			cout<<"\nEnter hospital id : ";
			cin>>hos;
			hid=hos;
		}
		
		if(did==0){
			cout<<"\nEnter Department id : ";
			cin>>ddid;
			did=ddid;
		}

		int type,sid,ag;
		string staffType,sname;
		cout<<"\nEnter staff type ";
		cout<<"\n0 nurse";
		cout<<"\n1 cleaner";
		cout<<"\n2 front office";
		cin>>type;
		if(type==0){
			staffType="nurse";
		}
		else if(type==1){
			staffType="cleaner";
		}
		else if(type==2){
			staffType="frontOffice";
		}
		else
			cout<<"\nWrong choice ";
		cout<<"\nEnter name : ";
		cin>>sname;
		cout<<"\nEnter Staff id : ";
		cin>>sid;
		cout<<"\nEnter Staff age : ";
		cin>>ag;
		
		c.addSupportStaff(ac,hid,did,staffType,sname,sid,ag);
		cout<<"\nDo you want to enter more support staff 1/0 ";
		cin>>scheck;
	}

}

void addDoctorMain(city &c,int ac=0,int hid=0, int did=0){
	int scheck=1;
	while(scheck){
		int arc,hos,ddid;
		if(ac==0){
			cout<<"\nEnter area code : ";
			cin>>arc;
			ac=arc;
		}
		if(hid==0){
			cout<<"\nEnter hospital id : ";
			cin>>hos;
			hid=hos;
		}
		
		if(did==0){
			cout<<"\nEnter Department id : ";
			cin>>ddid;
			did=ddid;
		}

		
		int type,docid,ag;
		string staffType,dname;
		cout<<"\nEnter doctor type ";
		cout<<"\n0 Surgeon";
		cout<<"\n1 Radiologist";
		cout<<"\n2 Oncologist";
		cout<<"\n3 Paediatrician";
		cin>>type;
		if(type==0){
			staffType="surgeon";
		}
		else if(type==1){
			staffType="radiologist";
		}
		else if(type==2){
			staffType="oncologist";
		}
		else if(type==2){
			staffType="paediatrician";
		}
		else
			cout<<"\nWrong choice ";

		cout<<"\nEnter name : ";
		cin>>dname;
		cout<<"\nEnter Doctor id : ";
		cin>>docid;
		cout<<"\nEnter Doctor age : ";
		cin>>ag;
		c.addDoctor(ac,hid,did,staffType,dname,docid,ag);
		cout<<"\nDo you want to enter more Doctors 1/0 ";
		cin>>scheck;
	}
}

void addStaffMain(city &c,int ac=0,int hid=0, int did=0){
	int arc,hos,ddid;
	if(ac==0){
		cout<<"\nEnter area code : ";
		cin>>arc;
		ac=arc;
	}
	if(hid==0){
		cout<<"\nEnter hospital id : ";
		cin>>hos;
		hid=hos;
	}
	
	if(did==0){
		cout<<"\nEnter Department id : ";
		cin>>ddid;
		did=ddid;
	}

	int check=1;
	while(check){
		cout<<"\nEnter your choice : \n";
		cout<<"\n0 enter support staff : ";
		cout<<"\n1 enter doctor : ";
		cout<<"\n2 exit : ";
		cin>>check;
		switch(check){
			case 0:
				addSupportStaffMain(c,ac,hid,did);
				break;
			case 1:
				addDoctorMain(c,ac,hid,did);
				break;
			case 2:
				check=0;
				break;
			default:
				cout<<"Wrong choice"<<endl;
		}
	}	
}

void compareHospitalMain(city &c){
	int ac1,hid1,ac2,hid2;
	cout<<"\nEnter area code1 : ";
	cin>>ac1;
	cout<<"\nEnter hospital id1 : ";
	cin>>hid1;
	
	cout<<"\nEnter area code2 : ";
	cin>>ac2;
	cout<<"\nEnter hospital id2 : ";
	cin>>hid2;

	if(c.comparehospital(ac1,hid1,ac2,hid2))
		cout<<"\nequal"<<endl;
	else
		cout<<"\nnot equal"<<endl;
}


void transferSupportStaffMain(city &c){
	int ac1,hid1,ac2,hid2,did1,did2,sCheck;
	cout<<"\nEnter area code from which you want to transfer : ";
	cin>>ac1;
	cout<<"\nEnter hospital id from which you want to transfer  : ";
	cin>>hid1;
	cout<<"\nEnter Department id1 from which you want to transfer : ";
	cin>>did1;


	cout<<"\nEnter area code2 : ";
	cin>>ac2;
	cout<<"\nEnter hospital id2 : ";
	cin>>hid2;
	cout<<"\nDo you want to transfer in existing department(0) or you want to create new department(1) : ";
	cin>>sCheck;
	string newD;
	if(sCheck==1)
	{
		cout<<"\nEnter New Department id : ";
		cin>>did2;
		cout<<"\nEnter new department name : ";
		cin>>newD;
		c.transferSupportStaff(ac1,hid1,did1,ac2,hid2,did2,newD);
	}
	else{
		cout<<"\nEnter Existing Department id : ";
		cin>>did2;
		c.transferSupportStaff(ac1,hid1,did1,ac2,hid2,did2);
	}
			
	
}
void accToCity(city & c){
	
	int check=0;
	while(check != -1){
		check=-1;
		cout<<"\nWhat do you want to do? "<<endl;
		cout<<"0 Add area code"<<endl;
		cout<<"1 Add hosp"<<endl;
		cout<<"2 Add department"<<endl;
		cout<<"3 Add staff"<<endl;
		cout<<"4 Display city"<<endl;
		cout<<"5 Compare hospitals"<<endl;
		cout<<"6 Exit"<<endl;
		cin>>check;

		switch(check){
			case 0:
				addAreaCodeMain(c);
				break;
			case 1:
				addHospitalMain(c);
				break;
			case 2:
				addDepartmentMain(c);
				break;
			case 3:
				addStaffMain(c);
				break;
			case 4:
				displayCityMain(c);
				break;
			case 5:
				compareHospitalMain(c);
				break;
			case 6:
				check=-1;
				break;
			default:
				cout<<"default"<<endl;
				check=-1;
				
		}
	}
}


void main(){

	city delhi("delhi",4000);
	delhi.addAreaCode(100);
	delhi.addAreaCode(101);
	delhi.addAreaCode(102);
	delhi.addAreaCode(103);

	////hospitalName areacode hospitalId
	//delhi.addHospital("Fortis",100,123);
	//delhi.addHospital("Apollo",100,124);
	//
	////areacode hospitalId,depName,depId
	//delhi.addDepartment(100,123,"Radiology",12);
	//delhi.addDepartment(100,124,"Pathology",13);

	////areacode, hospitalId,depId, sstype, name, id
	//delhi.addSupportStaff(100,123,12,"nurse","upasana",11);
	//delhi.addSupportStaff(100,124,13,"nurse","upasana",12);
	//delhi.addDoctor(100,123,12,"surgeon","abhi",10);
	//delhi.addDoctor(100,124,13,"surgeon","abhi",14);
	//cout<<delhi;

	//// areacode1, hospital1 id, area code2, hospitalid2

	///*
	//if(delhi.comparehospital(100,123,100,124))
	//	cout<<"equal"<<endl;
	//else
	//	cout<<"not equal"<<endl;
	//cout << "$$$$$$$$$$" << endl;
	//*/

	////delhi.displayHospital(100,123);

	//delhi.transferSupportStaff(100,123,12,100,123, 14,"NewDep");
	////delhi.transferSupportStaff(100,123,12,100,124,13);

	////delhi.deleteDepartment(100,123,12);
	//delhi.transferDoctors(100,123,12,10,100,124,13,11);
	//delhi.deleteDoctor(100,123,12,10);
	//delhi.deleteHospital(100,123);
	////delhi.addPatient(100,123,12,500,"ankush","fever",1000);
	////delhi.releasePatient(100,123,12,500);
	////delhi.supportStaffResigns(100,123,12,11);
	//cout<<delhi;

	accToCity(delhi);
}
