/*

GROUP :-

	   NAME : MUHAMMAD ALI AMER              ROLL No# : 19F-0191
	   NAME : ABEEHA MUZAFAR				 ROLL No# : 19F-0160


*/




#include"Administrator.h"
#include"Doctor.h"
#include"Patient.h"
int menuP()
{
	cout << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
	Sleep(1000);
	cout << "\t\t======================     Patient MODULE    ====================" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl << endl;
	int e;
	
	do {
		cout << "Press 1 to View Your Appointments" << endl;
		cout << "Press 2 to view Fee Status" << endl;
		cout << "Enter your choice: " << endl;
		cin >> e;
		if (e >= 3 || e <= 0)
		{
			continue;
		}
	} while (e >= 3 || e <= 0);
	return e;
}
void patient_()
{
	Patient* ptr = new Patient; //allocating memory dynamically
	while (true)
	{
		switch (menuP()) //calling main menu and user choice
		{
		case 1:
			ptr->ViewAppointment();
		case 2:
			ptr->ViewFeeStatus();
		case 3:
			exit(0);
		}
	}
}
void Patient::ViewAppointment()
{
	string ID;
	cout << "Enter your ID: ";
	cin >> ID; //entering patient ID
	ifstream read;
	read.open("Appointment.txt", ios::app); //reading from appointment file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	string* p = new string[100]; //allocating memory dynamically
	while (read.good())
	{
		getline(read, p[i]); //reading all the file contents and storing it in p
		i++;
	}
	for (int j = 0; j < i; j++) 
	{
		if (p[j] == ID) //if p[j]=patient ID then enter condition
		{
			cout << "Your Appointments are: " << endl;
			cout << "Appointment ID: " << p[j - 1] << endl; //p[j] is the location where the ID is found. Using that location to determing the positions
			cout << "Appointment Status: " << p[j + 2] << endl;
			cout << "Appointment Time: " << p[j + 1] << endl;
		}
	}
	menuP();
}
void Patient::ViewFeeStatus()
{
	string p;
	cout << "Enter Your Name: ";
	cin.ignore();
	getline(cin, p); //entering patient name
	ifstream read;
	read.open("PatientNames.txt", ios::app); //reading from patientNames file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	string* pp = new string[100]; //allocating memory dynamically
	while (read.good())
	{
		getline(read, pp[i]); //reading all the contents of file and storing it in pp
		i++;
	}
	char c = true;
	for (int j = 0; j < i; j++) //running until j<i
	{
		if (pp[j] == p) //if pp[j] is found to be equal to the name entered and false then the fee is paid. If found true then unpaid
		{
			c = false;
		}
	}
	if (c == false) //if c==false fee paid
	{
		cout <<" YOUR FEE IS PAID" << endl;
	}
	else
	{
		cout << " YOUR FEE IS NOT PAID" << endl;
	}
	read.close();
}