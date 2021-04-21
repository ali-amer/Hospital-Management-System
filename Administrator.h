/*

GROUP :-

	   NAME : MUHAMMAD ALI AMER              ROLL No# : 19F-0191
	   NAME : ABEEHA MUZAFAR				 ROLL No# : 19F-0160


*/




#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<random>
#include<ctime>
#include<Windows.h>
using namespace std;

void mainMenu(); //declaring main menu
void authentication(string user, string pass, string file);//authentication function to check username and password
void admin(); //driver function of admin
int menuA(); //Menu for admin
void open(int on); //used for opening the respective module
void viewAllPatients(); //function to view all patients
void viewAllDoctors(); //function to view all doctors
void viewAllAppointments(); //function to view all appointments
class Admin
{
public:
	string firstName;
	string lastName;
	int departmentName;
	string D_id;
	string username;
	string password;
	string registrationDate;
	char gender;
	long long int contactNo;
	long long int feeSubmitted;
	string bloodGroup;
	string address;
	
	string P_id;
	string feeStatus;
	string qualification;
	long long int salary;

	string department_name;
	string appointment_id;
	string Status;
	string appointmentTime;

	virtual void input() = 0;//pure virtual funtion. Defined in derived class
};
class AddNewDoctor : public Admin //inheriting from admin
{
public:
	void input(); //input for new doctor
};
class AddNewPatient : public Admin//inheriting from admin
{
public:
	void input(); //input for new patient
};
class NewAppointment : public Admin//inheriting from admin
{
public:
	void input(); //input for new appointment
};
class AssignAppointment
{
public:
	void selectdoctor(); //selecting doctor for appointment
	void assign(); //assigning the appointment
};

class EditPatientDetails
{
public: // funtions are virtual - they are over rided in derived class
	virtual void displayList(); //pure virtual functions. Displays the data
	virtual void editDetails(); //pure virtual functions. Reads data from file, modifies it and re writes it.
};
class EditDoctorDetails : public EditPatientDetails
{
public:
	void displayList(); //Inherited from Abstract Classes. Overriding the functions. Polymorphism used
	void editDetails();//Inherited from Abstract Classes. Overriding the functions. Polymorphism used
};
class UpdateAppointment : public EditPatientDetails
{
public:
	void displayList();//Inherited from Abstract Classes. Overriding the functions. Polymorphism used
	void editDetails(); //Inherited from Abstract Classes.Overriding the functions.Polymorphism used
};
class FeeStatus : public EditPatientDetails
{
public:
	void displayList();//Inherited from Abstract Classes. Overriding the functions. Polymorphism used
};