/*

GROUP :-

	   NAME : MUHAMMAD ALI AMER              ROLL No# : 19F-0191
	   NAME : ABEEHA MUZAFAR				 ROLL No# : 19F-0160


*/





#include"Administrator.h"
#include"Patient.h"
#include"Doctor.h"

int c;
void mainMenu() 
{
	cout << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
	cout << "\t\t==============================     WELCOME TO    ==============================" << endl << endl << endl << endl;
	Sleep(2000);
	cout << "\t\t======================     HOSPITAL MANAGEMENT SYSTEM    ====================" << endl << endl;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl << endl;
	string* ptr = new string[3]; //Allocating memory dynamically
	string fileName;
	
	do {
		cout << "Press 1 if you are an Administrator" << endl << "Press 2 if you are a Doctor" << endl << "Press 3 if you are a Patient" << endl;
		cout << "Enter your choice: ";
		cin >> c;
		if (c >= 4 || c <= 0)
		{
			continue;
		}
	} while (c >= 4 || c <= 0);
	switch (c)
	{
	case 1:
		cout << "Enter username: ";
		cin >> ptr[0];
		cout << "Enter password: ";
		cin >> ptr[1];
		ptr[2] = "AdminLock.txt";
		authentication(ptr[0], ptr[1], ptr[2]);//check for password and username of admin
		break;
	case 2:
		cout << "Enter username: ";
		cin >> ptr[0];
		cout << "Enter password: ";
		cin >> ptr[1];
		ptr[2] = "DoctorLock.txt";
		authentication(ptr[0], ptr[1], ptr[2]);//check for password and username of doctor
		break;
	case 3:
		cout << "Enter username: ";
		cin >> ptr[0];
		cout << "Enter password: ";
		cin >> ptr[1];
		ptr[2] = "Patientlock.txt";
		authentication(ptr[0], ptr[1], ptr[2]);//check for password and username of patient
		break;
	}
}
void authentication(string user, string pass, string file)
{
	int valid = 0;
	ifstream read;
	read.open(file);
	if (!read.is_open())
	{
		cout << "File Missing" << endl;
		exit(0);
	}
	string* ptr = new string[100];
	for (int i = 0; i < 100; i = i + 2) //read from file
	{
		read >> ptr[i];//read first index
		read >> ptr[i + 1]; //read second index
		if (ptr[i] == user && ptr[i + 1] == pass) //if string match enter condition
		{
			cout << "User Valid" << endl;
			valid = 1;
			open(c);
		}
	}
	if (valid == 0)
	{
		cout << "Username/Password is incorrect" << endl;
		mainMenu();
	}
}
void open(int on)
{
	if (on == 1)
	{
		admin();
	}
	else if (on == 2)
	{
		doctor_();
	}
	else if (on == 3)
	{
		patient_();
	}
}
int menuA()
{
	cout << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
	Sleep(1000);
	cout << "\t\t======================     ADMIN MODULE    ====================" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl << endl;
	int e;
	do {
		cout << "Press 1 to Add New Doctor" << endl << "Press 2 to Add New Patient" << endl << "Press 3 to Add New Appointment" << endl;
		cout << "Press 4 to assign Appointment" << endl << "Press 5 to edit patient details" << endl << "Press 6 to edit doctor details" << endl;
		cout << "Press 7 to view all patients" << endl << "Press 8 to view all doctors" << endl << "Press 9 to view all appointments" << endl;
		cout << "Press 10 to update appointment" << endl << "Press 11 to view fee status" << endl << "Press 12 to go back" << endl << "Press 13 to exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> e;
		if (e >= 14 || e <= 0)
		{
			continue;
		}
	} while (e >= 14 || e <= 0);
	return e;
}

void admin()
{
	Admin* ptr[3]; //abstract class pointer. Polymorphism used
	ptr[0] = new AddNewDoctor; 
	ptr[1] = new AddNewPatient;
	ptr[2] = new NewAppointment;

	EditPatientDetails* ptr1[4];//abstract class pointer. Polymorphism used
	ptr1[0] = new EditPatientDetails;
	ptr1[1] = new EditDoctorDetails;
	ptr1[2] = new UpdateAppointment;
	ptr1[3] = new FeeStatus;
	string* file = new string[3]; //string array declared to save files
	file[0] = "DoctorData.txt";
	file[1] = "PatientData.txt";
	file[2] = "Appointment.txt";
	int choice;
	choice = menuA();//call admin menu and get user choice
	ofstream write;
	while (true)
	{
		switch (choice)
		{
		case 1:
			write.open(file[choice - 1], ios_base::app); //reading from a file one less than the choice
			if (!write.is_open())
			{
				cout << "File Missing" << endl;
				exit(0);
			}
			ptr[0]->input();
			{
				write << ptr[0]->firstName << endl;
				write << ptr[0]->lastName << endl;
				if (ptr[0]->departmentName == 1)
					write << "Dental" << endl;
				else if (ptr[0]->departmentName == 2)
					write << "Accident & Emergency" << endl;
				else if (ptr[0]->departmentName == 3)
					write << "Orthopedics" << endl;
				else if (ptr[0]->departmentName == 4)
					write << "Psychiatry" << endl;
				else if (ptr[0]->departmentName == 5)
					write << "Physiotherapy" << endl;
				write << ptr[0]->D_id << endl;
				write << ptr[0]->username << endl;
				write << ptr[0]->password << endl;
				write << ptr[0]->registrationDate << endl;
				write << ptr[0]->gender << endl;
				write << ptr[0]->contactNo << endl;
				write << ptr[0]->bloodGroup << endl;
				write << ptr[0]->address << endl;
				write << ptr[0]->qualification << endl;
				write << ptr[0]->salary << endl;
				write.close();
				{
					ofstream write2;// Writing this to a file 'DoctorNames' so that their first and last names are stored seperately. Used for Appointments
					write2.open("DoctorNames.txt", ios::app); 
					if (!write2.is_open())
					{
						cout << "File Missing\n";
						exit(0);
					}
					write2 << ptr[0]->firstName + " " + ptr[0]->lastName << endl;
					if (ptr[0]->departmentName == 1)
						write2 << "Dental" << endl;
					else if (ptr[0]->departmentName == 2)
						write2 << "Accident & Emergency" << endl;
					else if (ptr[0]->departmentName == 3)
						write2 << "Orthopedics" << endl;
					else if (ptr[0]->departmentName == 4)
						write2 << "Psychiatry" << endl;
					else if (ptr[0]->departmentName == 5)
						write2 << "Physiotherapy" << endl;
				}				
				{
					ofstream write4;
					write4.open("DoctorIds.txt", ios::app); //Saving Doctor IDs in a seperate file. Used for editing doctor details
					if (!write4.is_open())
					{
						cout << "File Missing\n";
						exit(0);
					}
					write4 << ptr[0]->D_id << endl;	//Used to store username and password of doctors
				}
					{
						ofstream write5;
						write5.open("DoctorLock.txt", ios::app);
						if (!write5.is_open())
						{
							cout << "File Missing\n";
							exit(0);
						}
						write5 << ptr[0]->username << endl << ptr[0]->password << endl;
					}
				
				admin();
			}
			break;
		case 2:
			write.open(file[choice - 1], ios_base::app);
			if (!write.is_open())
			{
				cout << "File Missing" << endl;
				exit(0);
			}
			ptr[1]->input();//VIRTUAL FUNTION CALLED FROM BASE CLASS POINTER
			{
				write << ptr[1]->firstName << endl;
				write << ptr[1]->lastName << endl;
				if (ptr[1]->departmentName == 1)
					write << "Dental" << endl;
				else if (ptr[1]->departmentName == 2)
					write << "Accident & Emergency" << endl;
				else if (ptr[1]->departmentName == 3)
					write << "Orthopedics" << endl;
				else if (ptr[1]->departmentName == 4)
					write << "Psychiatry" << endl;
				else if (ptr[1]->departmentName == 5)
					write << "Physiotherapy" << endl;
				write << ptr[1]->P_id << endl;
				write << ptr[1]->gender << endl;
				write << ptr[1]->contactNo << endl;
				write << ptr[1]->bloodGroup << endl;
				write << ptr[1]->address << endl;
				write << ptr[1]->feeStatus << endl;
				write.close();
				{
					ofstream write2;
					write2.open("PatientIds.txt", ios::app); //writing patient ID to a different file
					if (!write2.is_open())
					{
						cout << "File Missing\n";
						exit(0);
					}
					write2 << ptr[1]->P_id << endl;
				}
				{
					{
						ofstream write5;
						write5.open("PatientLock.txt", ios::app); //Used to store username and password of patients
						if (!write5.is_open())
						{
							cout << "File Missing\n";
							exit(0);
						}
						write5 << ptr[0]->username << endl << ptr[0]->password << endl;
					}
				}
				{
					if (ptr[1]->feeSubmitted > 0)//storing fee status and patient named to a different file 
					{
						ofstream write4;
						write4.open("PatientNames.txt", ios::app);
						if (!write4.is_open())
						{
							cout << "File Missing\n";
							exit(0);
						}
						write4 << ptr[1]->firstName + " " + ptr[1]->lastName << endl;
						write4.close();
					}
					else
					{
						ofstream write4;
						write4.open("PatientNames.txt", ios::app);
						if (!write4.is_open())
						{
							cout << "File Missing\n";
							exit(0);
						}
						write4 << ptr[1]->firstName + " " + ptr[1]->lastName + "   (FEE NOT PAID)   " << endl;
						write4.close();
					}
				}
				admin();
				break;
			}
		case 3:
			write.open(file[choice - 1], ios_base::app);
			if (!write.is_open())
			{
				cout << "File Missing" << endl;
				exit(0);
			}
			ptr[2]->input();//VIRTUAL FUNTION CALLED FROM BASE CLASS POINTER
			{
				write << ptr[2]->department_name << endl;
				if (ptr[2]->departmentName == 1)
					write << "Dental" << endl;
				else if (ptr[2]->departmentName == 2)
					write << "Accident & Emergency" << endl;
				else if (ptr[2]->departmentName == 3)
					write << "Orthopedics" << endl;
				else if (ptr[2]->departmentName == 4)
					write << "Psychiatry" << endl;
				else if (ptr[2]->departmentName == 5)
					write << "Physiotherapy" << endl;
				write << ptr[2]->appointment_id << endl;
				write << ptr[2]->P_id << endl;
				write << ptr[2]->appointmentTime << endl;
				write << ptr[2]->Status << endl;
				write.close();
				ofstream write2;
				write2.open("AppointmentID.txt", ios::app);//storing appointment ID to a different file
				if (!write2.is_open())
				{
					cout << "File Missing\n";
					exit(0);
				}
				write2 << ptr[2]->appointment_id << endl;
				admin();
				break;
			}
		case 4:
			AssignAppointment obj; 
			obj.selectdoctor();
			obj.assign();
			break;
		case 5:		
			ptr1[0]->displayList();
			ptr1[0]->editDetails();		
			break;
		case 6:
			ptr1[1]->displayList();
			ptr1[1]->editDetails();
			break;
		case 7:
			viewAllPatients();
			break;
		case 8:
			viewAllDoctors();
			break;
		case 9:
			viewAllAppointments();
			break;
		case 10:
			ptr1[2]->displayList();
			ptr1[2]->editDetails();
			break;
		case 11:
			ptr1[3]->displayList();
			break;
		case 12:
			mainMenu();
			break;
		default:			
			exit(0);
			
		}
	}
}

void AddNewDoctor::input()
{
	int count;
	ofstream write;
	ifstream read;
	{
		read.open("Count.txt");//Read count from text file
		if (!read) {
			cout << "File Error" << endl;
		}
		else
		{
			read >> count;
			count = count;
		}
		read.close();
	}
	cout << "Enter First Name: ";
	cin.ignore();
	getline(cin, this->firstName);
	cout << "Enter Last Name: ";
	getline(cin, this->lastName);
	cout << "Enter your deprtment (1 for Dental, 2 for Accident & Emergency, 3 for Orthopedics, 4 for Psychiatry,5 for Physiotherapy): ";
	cin >> this->departmentName;
	this->D_id = "0" + to_string((int)departmentName) + "" + to_string((int)count);
	count++;
	{
	write.open("Count.txt");//Used to store count in a file
	if (!write) 
	{
		cout << "File Error" << endl;
	}
	else
	{
		write << count << endl;
	}
	write.close();
	}
	cout << "Enter your username: ";
	cin.ignore();
	getline(cin, this->username);
	cout << "Enter your password: ";
	getline(cin, this->password);
	cout << "Enter your Registration Date in DD/MM/YYYY format: ";
	getline(cin, this->registrationDate);
	cout << "Enter your gender (M for male, F for female): ";
	cin >> this->gender;
	cout << "Enter your contact No: ";
	cin >> this->contactNo;
	cout << "Enter your Blood Group: ";
	cin >> this->bloodGroup;
	cout << "Enter your address: ";
	cin.ignore();
	getline(cin, this->address);
	cout << "Enter your qualification: ";
	getline(cin, this->qualification);
	cout << "Enter your salary: ";
	cin >> this->salary;
}
void AddNewPatient::input()
{
	int count;
	ofstream write;
	ifstream read;
	{
		read.open("Count1.txt");//Read count from text file
		if (!read) {
			cout << "File Error" << endl;
		}
		else
		{
			read >> count;
			count = count;
		}
		read.close();
	}
	cout << "Enter First Name: ";
	cin.ignore();
	getline(cin, this->firstName);
	cout << "Enter Last Name: ";
	getline(cin, this->lastName);
	cout << "Enter your deprtment (1 for Dental, 2 for Accident & Emergency, 3 for Orthopedics, 4 for Psychiatry,5 for Physiotherapy: ";
	cin >> this->departmentName;
	this->P_id = "0" + to_string((int)departmentName) + "" + to_string((int)count);
	count++;
	{
		write.open("Count1.txt");//Used to store count in a file
		if (!write)
		{
			cout << "File Error" << endl;
		}
		else
		{
			write << count << endl;
		}
		write.close();
	}
	cout << "Enter your gender (M for male, F for female): ";
	cin >> this->gender;
	cout << "Enter your contact No: ";
	cin >> this->contactNo;
	cout << "Enter your Blood Group: ";
	cin >> this->bloodGroup;
	cout << "Enter your address: ";
	cin.ignore();
	getline(cin, this->address);
	cout << "Enter your fee paid in Rs: ";
	cin >> this->feeStatus;
	cout << "Enter your username: ";
	getline(cin, this->username);
	cout << "Enter your password: ";
	getline(cin, this->password);

}
void NewAppointment::input()
{
	int count;
	ofstream write;
	ifstream read;
	{
		read.open("Count2.txt");//Read count from text file
		if (!read) {
			cout << "File Error" << endl;
		}
		else
		{
			read >> count;
			count = count;
		}
		read.close();
	}
	cout << "Enter Department Name: ";
	cin >> this->department_name;
	cout << "Enter Parent deprtment (1 for Dental, 2 for Accident & Emergency, 3 for Orthopedics, 4 for Psychiatry,5 for Physiotherapy: ";
	cin >> this->departmentName;
	this->appointment_id = "0" + to_string((int)departmentName) + "" + to_string((int)count);
	count++;
	{
		write.open("Count2.txt"); //Used to store count in a file
		if (!write)
		{
			cout << "File Error" << endl;
		}
		else
		{
			write << count << endl;
		}
		write.close();
	}
	cout << "Enter Patient ID: ";
	cin >> P_id;
	cout << "Enter Appointment Time: ";
	cin >> this->appointmentTime;
	cout << "Appointment Status: ";
	cin >> this->Status;
}
void AssignAppointment::selectdoctor()
{
	string* p = new string[10];
	string* p1 = new string[10];
	ifstream read1, read2;
	read1.open("DoctorNames.txt"); //used to display doctor names
	read2.open("AppointmentID.txt");//used to display appointment ID
	if (!read1.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	if (!read2.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	cout << "Available Doctors: " << endl;
	while (read1.good())
	{
		getline(read1, p[i]);//reading file content to p string array
		cout << p[i] << endl;//displaying contents
		i++;
	}
	i = 0;
	cout << "Appointments: " << endl;
	while (read2.good())
	{
		getline(read2, p1[i]);//reading file content to p1 string array
		cout << p1[i] << endl;//displaying contents
		i++;
	}
}
void AssignAppointment::assign()
{
	int i;
	
	do {
		cout << "Press 1 to assign Appointment" << endl << "Press 2 to go back ";
		cin >> i;
		if (i >= 3 || i <= 0)
		{
			continue;
		}
	} while (i >= 3 || i <= 0);
	switch (i)
	{
	case 1:
	{
		string* p = new string[9];
		cout << "Enter Appointment to assign :";
		cin >> p[0];
		cout << "Enter Appointment Status: ";
		cin >> p[1];
		cout << "Enter Appointment Time: ";
		cin >> p[2];
		cout << "Enter Doctor's ID: ";
		cin >> p[3];
		cout << "Enter Doctor's First Name: ";
		cin.ignore();
		getline(cin, p[4]);
		cout << "Enter Doctor's Second Name: ";
		getline(cin, p[5]);
		cout << "Enter Patient ID: ";
		getline(cin, p[6]);
		cout << "Enter Patient's First Name: ";
		getline(cin, p[7]);
		cout << "Enter Patient's Second Name: ";
		getline(cin, p[8]);
		ofstream write;
		write.open("AppointmentAssigned.txt", ios::app);
		if (!write.is_open())
		{
			cout << "File Missing\n";
			exit(0);
		}
		write << p[0] << endl << p[1] << endl << p[2] << endl;//writing data to file
		write << p[3] << endl << p[4] << endl << p[5] << endl;
		write << p[6] << endl << p[7] << endl << p[8] << endl;
		write.close();
		cout << "Appointment Assigned Successfully" << endl;
	}break;
	default:
	{
		admin();
	}
	break;
	}
}
void EditPatientDetails::displayList()
{
	string* p = new string[10];
	ifstream read;
	read.open("PatientIds.txt", ios::app);//opening patientIDs file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	cout << endl << "Patients List: " << endl;
	while (read.good())
	{
		getline(read, p[i]);//reading from file
		cout << p[i] << endl;//displaying contents
		i++;
	}
}
void EditPatientDetails::editDetails()
{
	string ID;
	int ch;
	cout << "Enter relevant ID from the list: "; 
	cin >> ID;
	ifstream read;
	read.open("PatientData.txt", ios::app);//opening patientdata file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	string* p = new string[100];
	int i = 0;
	while (read.good())//loading everything from file into string array p
	{
		getline(read, p[i]);
		i++;
	}
	{
		string* updated = new string[5];
		cout << "Enter Updated First Name: ";
		cin >> updated[0];
		cout << "Enter Updated Last Name: ";
		cin >> updated[1];
		cout << "Enter Updated Fee Status: ";
		cin >> updated[2];
		cout << "Enter Updated Address: ";
		getline(cin, updated[3]);
		cout << "Enter Updated Contact Number: ";
		cin >> updated[4];

		for (int j = 0; j < i; j++)
		{
			if (p[j] == ID)//if p[j]=patient ID then enter condition
			{
				p[j - 3] = updated[0];//p[j] is the location where the ID is found. Using that location to determing the positions
				p[j - 2] = updated[1];
				p[j + 6] = updated[2];
				p[j + 8] = updated[3];
				p[j + 9] = updated[4];
			}
		}
	}
	ofstream write;
	write.open("PatientData.txt");//FILE IS OPEN - OLD DATA IS DELETED
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
		EditPatientDetails();
	}
	else
	{
		admin();
	}
}
void EditDoctorDetails::displayList()
{
	string* p = new string[10];
	ifstream read;
	read.open("DoctorIds.txt", ios::app);//opening doctorIds file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	cout << endl << "Doctors List: " << endl;
	while (read.good())
	{
		getline(read, p[i]);//reading from file
		cout << p[i] << endl;//displaying contents
		i++;
	}
}
void EditDoctorDetails::editDetails()
{
	string ID;
	int ch;
	cout << "Enter relevant ID from the list: ";
	cin >> ID;
	ifstream read;
	read.open("DoctorData.txt", ios::app);
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	string* p = new string[100];
	int i = 0;
	while (read.good())//loading everything from file into string array p
	{
		getline(read, p[i]);
		i++;
	}
	{
		string* updated = new string[5];
		cout << "Enter Updated Address: ";
		getline(cin, updated[0]);
		cout << "Enter Updated Contact Number: ";
		cin >> updated[1];
		cout << "Enter Updated Qualification: ";
		cin >> updated[2];
		cout << "Enter Updated Salary: ";
		cin >> updated[3];
		

		for (int j = 0; j < i; j++)
		{
			if (p[j] == ID)//if p[j]=patient ID then enter condition
			{
				p[j + 10] = updated[0];//p[j] is the location where the ID is found. Using that location to determing the positions
				p[j + 8] = updated[1];
				p[j + 7] = updated[2];
				p[j + 11] = updated[3];
			}
		}
	}
	ofstream write;
	write.open("DoctorData.txt");//FILE IS OPEN - OLD DATA IS DELETED
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
		EditDoctorDetails();
	}
	else
	{
		admin();
	}
}
void viewAllPatients()
{
	ifstream read;
	read.open("PatientData.txt");//opening patientData file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	{
		cout << endl;
		while (read.good())
		{
			string* p = new string[13];
			for (int i = 0; i < 13; i++)
			{
				getline(read, p[i]);//reading data from file into p string array
			}
			cout << "Name: " << p[0] + " " + p[1] << "\t\t" << "Department: " << p[2] << "\t\t" << "ID :" << p[3] << endl;
			cout << "---------------------OTHER DETAILS---------------------" << endl;
			for (int i = 0; i < 13; i++)
			{
				if (p[i] == p[0] || p[i] == p[1] || p[i] == p[2] || p[i] == p[3])
				{
				}
				else
				{
					cout << p[i] << endl;
				}
			}
			cout << endl << endl;
		}
	}
	admin();
}
void viewAllDoctors()
{
	ifstream read;
	read.open("DoctorData.txt");//opening doctorData file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	cout << endl;
	while (read.good())
	{
		string* p = new string[13];
		for (int i = 0; i < 13; i++)
		{
			getline(read, p[i]);//reading data from file into p string array
		}
		cout << "Name : " << p[0] + " " + p[1] << "\t" << "Gender :" << p[7] <<
			"\t" << "Qualification :" << p[11] << "\t" << "Contact No# :" << p[8] << "\t\t" << "Username: " << p[4] << endl << endl;
		cout << "\t\t-------------------------------------------------------------------\n\n";
	}
	admin();
}
void viewAllAppointments()
{
	ifstream read;
	read.open("AppointmentAssigned.txt");//opening appointmentAssigned file
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	cout << endl;
	while (read.good())
	{
		string* p = new string[13];
		for (int i = 0; i < 13; i++)
		{
			getline(read, p[i]);//reading data from file into p string array
		}
		cout << p[0] << " ";
		cout << p[1] << " " << p[2] << " " << p[3] << " ";
		cout << p[4] << " " << p[5] << " " << p[6] << p[7] << p[8] << p[9] << endl;
		cout << "\t\t-------------------------------------------------------------------\n\n";
	}
	admin();
}
void UpdateAppointment::displayList()
{
	string* p = new string[100];
	ifstream read;
	read.open("Appointment.txt", ios::app);
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	int i = 0;
	cout << endl << "Appointments List: " << endl;
	while (read.good())
	{
		getline(read, p[i]);//reading all data into p string array
		cout << p[i] << endl;//displaying all data
		i++;
	}
}
void UpdateAppointment::editDetails()
{
	string ID;
	int ch;
	cout << "Enter relevant ID from the list: ";
	cin >> ID;//enter appointment ID
	ifstream read;
	read.open("Appointment.txt", ios::app);
	if (!read.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	string* p = new string[100];
	int i = 0;
	while (read.good())//loading everything from file into string array -
	{
		getline(read, p[i]);
		i++;
	}
	{
		string* updated = new string[2];
		cout << "Enter updated Status: ";
		cin >> updated[0];
		cout << "Enter Updated time: ";
		cin >> updated[1];

		for (int j = 0; j < i; j++)
		{
			if (p[j] == ID)//if p[j]=patient ID then enter condition
			{
				p[j + 3] = updated[0];//p[j] is the location where the ID is found. Using that location to determing the positions
				p[j + 2] = updated[1];
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
void FeeStatus::displayList()
{
	ifstream read, read2;
	read.open("PatientIds.txt");
	read2.open("PatientNames.txt");
	if (!read.is_open() && !read2.is_open())
	{
		cout << "File Missing\n";
		exit(0);
	}
	string* p1 = new string[100];//IDs
	string* p2 = new string[100];//Names

	int i = 0, j = 0;
	while (read.good() && read2.good())
	{
		getline(read, p1[i]);//reading patientID data in p1
		getline(read2, p2[i]);//reading patientnames data in p2
		i++;
	}
	cout << endl << "\t================FEE STATUS KEY================" << endl
		<< "\nDEFAULTERS ARE HIGHLIGHTED - OTHERS HAVE PAID" << endl << endl;
	for (int j = 0; j < i; j++)
	{
		cout << p1[j] << "\t\t" << p2[j] << endl;//displaying content
	}
	admin();
}
