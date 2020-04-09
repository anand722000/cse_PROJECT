#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;
int main()

{
char fname[20];
time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
timeinfo = localtime ( &rawtime );

re:
cout<<"\t\t##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##\n";
cout<<"\t\t##| _____________________________________|##\n";
cout<<"\t\t##|                                      |##\n";
cout<<"\t\t##|                                      |##\n";
cout<<"\t\t##|            WELCOME TO                |##\n";
cout<<"\t\t##|                                      |##\n";
cout<<"\t\t##| PATIENT PROFILE AND ADMISSION MODULE |##\n";
cout<<"\t\t##|         MANAGMENT SYSTEM             |##\n";
cout<<"\t\t##|                                      |##\n";
cout<<"\t\t##|______________________________________|##\n";
cout<<"\t\t##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##\n\n\t\t\t";
system("pause");
system("cls");



int i;
int login();
login();
b:
cout<<"\n\t\t\tPATIENT MANAGEMENT SYSTEM \n\n";
cout<<"\n\t\tPlease,Choose from the following Options: \n\n";
cout<<"\t\t _____________________________________________ \n";
cout<<"\t\t|                                             |\n";
cout<<"\t\t|  1  >> Add New Patient Record               |\n";
cout<<"\t\t|  2  >> Add or Update Patient Information    |\n";
cout<<"\t\t|  3  >> Search for Prticular Patient         |\n";
cout<<"\t\t|  4  >> Exit the Program                     |\n";
cout<<"\t\t|_____________________________________________|\n\n";
a:cout<<"\t\tEnter your choice: ";cin>>i;
if(i>5||i<1){cout<<"\n\tInvalid Choice\n";cout<<"\t\tTry again...........\n\n";goto a;} //if inputed choice is other than given choice



system("cls");

if(i==1)
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);
  ofstream pat_file;
  char fname[20];
  cout<<"\n\n\n\nEnter the patient's file name : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
                        struct patient_info
                        {
                            char name[20];
                            char address[100];
                            char contact[10];
                            char age[5];
                            char sex[8];
                            char blood_gp[5];
                            char disease_past[50];
                            char id[15];
                        };

            patient_info ak;
            cout<<"\n********************\n";pat_file<<"\n*******************\n\n";//fn1353 st
            cout<<"\nName : ";pat_file<<"Name : ";gets(ak.name);pat_file<<ak.name<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";gets(ak.address);pat_file<<ak.address<<"\n";
            cout<<"\nContact Number : ";pat_file<<"Contact Number : ";gets(ak.contact);pat_file<<ak.contact<<"\n";
            cout<<"\nAge : ";pat_file<<"Age : ";gets(ak.age);pat_file<<ak.age<<"\n";
            cout<<"\nSex : ";pat_file<<"Sex : ";gets(ak.sex);pat_file<<ak.sex<<"\n";
            cout<<"\nBlood Group : ";pat_file<<"Blood Group : ";gets(ak.blood_gp);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";gets(ak.disease_past);pat_file<<ak.disease_past<<"\n";
            cout<<"\nPatient ID : ";pat_file<<"Patient ID : ";gets(ak.id);pat_file<<ak.id<<"\n";
            cout<<"\n**********************\n";pat_file<<"\n********************\n\n";
            cout<<"\nInformation Saved Successfully\n";
            }
  system("pause");
  system("cls");
  goto b;

}

if(i==2)
{
    fstream pat_file;
    cout<<"\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\t\t...........Information about "<<fname<<" ............\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            cout<<"\n";
			cout<<"Adding more information in patient's file.....on : "<<asctime (timeinfo);pat_file<<"Description of "<<asctime (timeinfo)<<"\n";
                            struct app
                            {
                                char symptom[500];
                                char diagnosis[500];
                                char medicine[500];
                                char addmission[30];
                                char ward[15];
                            };
            app add;
            cout<<"\nSymptoms : "; pat_file<<"Symptoms : ";gets(add.symptom); pat_file<<add.symptom<<"\n";
            cout<<"\nDiagnosis : "; pat_file<<"Diagnosis : ";gets(add.diagnosis); pat_file<<add.diagnosis<<"\n";
            cout<<"\nMedicines : "; pat_file<<"Medicines : ";gets(add.medicine); pat_file<<add.medicine<<"\n";
            cout<<"\nAddmission Required? : "; pat_file<<"Addmission Required? : ";gets(add.addmission); pat_file<<add.addmission<<"\n";
            cout<<"\nType of ward : "; pat_file<<"Type of ward : ";gets(add.ward); pat_file<<add.ward<<"\n";pat_file<<"\n***********\n";
            cout<<"\n\n"<<add.ward<<" ward is alloted Successfully\n";
			pat_file.close();
			cout<<"\n\n";
			system("pause");
            system("cls");
			goto b;
		}
}
if(i==3)
{
    fstream pat_file;
    cout<<"\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\t........... Full Medical History of "<<fname<<" ............\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        system("pause");
        system("cls");
        goto b;
}
if(i==4)
{
system("cls");
cout<<"\n\n\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________|@@\n";
cout<<"\t\t\t\t\t@@|                                       |@@\n";
cout<<"\t\t\t\t\t@@|          THANK YOU FOR USING          |@@\n";
cout<<"\t\t\t\t\t@@|                                       |@@\n";
cout<<"\t\t\t\t\t@@|       PATIENT MANAGEMENT SYSTEM       |@@\n";
cout<<"\t\t\t\t\t@@|                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                       |@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}


cout<<"\n";

}

int login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\t\tPATIENT MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t-----------------";
   cout<<"\n\t\t\t    LOGIN \n";
   cout<<"\t\t\t-----------------\n\n";
   cout << "\t\t\t\tEnter Password(anand):"; //Password is anand
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "anand"){
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}

