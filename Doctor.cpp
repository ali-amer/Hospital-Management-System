/*

GROUP :-

	   NAME : MUHAMMAD ALI AMER              ROLL No# : 19F-0191
	   NAME : ABEEHA MUZAFAR				 ROLL No# : 19F-0160


*/




#include"Administrator.h"
#include"Doctor.h"
#include"Patient.h"

int menuD()
{
	cout << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
	Sleep(1000);
	cout << "\t\t======================     DOCTOR MODULE    ====================" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl << endl;
	int e;
	
	do {
		cout << "Press 1 to View Your Appointments" << endl;
		cout << "Press 2 to update Appointments" << endl;
		cout << "Enter your choice: " << endl;
		cin >> e;
		if (e >= 3 || e <= 0)
		{
			continue;
		}
	} while (e >= 3 || e <= 0);
	return e;
}
void doctor_()
{
	Doctor* ptr = new Doctor;//allocating memory dynamically
	while (true)
	{
		switch (menuD())//calling main menu and user choice
		{
		case 1:
			ptr->viewAppointments();
		case 2:
			ptr->updateAppointment();
		case 3:
			exit(0);
		}
	}
}
void Doctor::viewAppointments()
{
	string ID;
	cout << "Enter your ID: ";
	cin >> ID; //enter doctor ID
	
	ifstream read;
	read.open("AppointmentAssigned.txt", ios::app);//reading from appointmentAssigned file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	string* p = new string[100]; //allocating memory dynamically
	while (read.good())
	{
		getline(read, p[i]); //reading contents of file into p
		i++;
	}
	for (int j = 0; j < i; j++)
	{
			if (p[j] == ID) //if p[j] is equal to ID entered then enter condition
			{
				cout << "Your Appointments are: " << endl;
				cout << "Appointment ID: " << p[j - 3] << endl;//p[j] is the location where the ID is found. Using that location to determing the positions
				cout << "Appointment Status: " << p[j - 2] << endl;
				cout << "Appointment Time: " << p[j - 1] << endl;
			}
	}
}
void Doctor::updateAppointment()
{
	string* ptr = new string[100]; //allocating memory dynamically
	ifstream read1;
	read1.open("AppointmentID.txt", ios::app);//reading from appointmentID file
	if (!read1.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	cout << endl << "Appointments List: " << endl;
	while (read1.good())
	{
		getline(read1, ptr[i]);//reading the contents from file and storing it into ptr
		cout << ptr[i] << endl;//displaying the contents in ptr
		i++;
	}

	string ID;
	int ch;
	cout << "Enter relevant ID from the list: ";
	cin >> ID;//enter patient ID
	ifstream read;
	read.open("Appointment.txt", ios::app);//reading from appointment file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	string* p = new string[100];//allocating memory dynamically
	 i = 0;
	while (read.good())//loading everything from file into string array p
	{
		getline(read, p[i]);
		i++;
	}
	{
		string* updated = new string[1];//dynamically allocate memory 
		cout << "Enter updated Status: ";
		cin >> updated[0];//enter updated status

		for (int j = 0; j < i; j++)
		{
			if (p[j] == ID)//if p[j]== Id entered then enter condition
			{
				p[j + 3] = updated[0];//p[j] is the location where the ID is found. Using that location to determing the positions
			}
		}
	}
	ofstream write;
	write.open("Appointment.txt");//FILE IS OPEN - OLD DATA IS DELETED
	if (!write.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	//Now Re-Writing the File with new data from string array
	for (int j = 0; j < i; j++)
	{
		write << p[j] << endl;
	}
	cout << "Data has been modified" << endl;
	cout << "Press 1 to edit again, Press 2 to exit ";
	cin >> ch;
	if (ch == 1)
	{
		UpdateAppointment();
	}
	else
	{
		admin();
	}
}