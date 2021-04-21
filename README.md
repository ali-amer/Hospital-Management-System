# Hospital-Management-System
This project was my final 3rd semester project. I create a full hospital management system with doctor, patient, and administrator modules. 
Following are the description for header and main files and their corresponding functions.
 
1. Administrator.h - This file has all declarations for Administrator module. 
2. Doctor.h - This file has all declarations for Doctor module. 
3. Patient.h - This file has all declarations for Teacher module. 

1. MAIN.cpp: 	
main() - Houses a function mainMenu()

Void mainMenu() -	Switch case which houses the main menu and asks for username and password  
 
 
IMPLEMENTATION FILES: 
 
2. Admin_Source.cpp: 
Void Authentication(string, string, string) -	Authenticates the username and password provided from mainMenu() 

Void open() - Is used to determine which module to open. 

Int  menuA() - Is a function in which all of the admin options are displayed to the user.

Void admin() - Is the main function based on switch case. It has all the functionality of the admin module. 

class AddNewDoctor : public Admin - A class which is derived from Admin class. It provides the functionality of adding new doctor

Class Admin - has all the Data members required for the whole Admin Module. This is an abstract class

class AddNewPatient : public Admin - A class which is derived from Admin class. It provides the functionality of adding new patient

class NewAppointment : public Admin - A class which is derived from Admin class. It provides the functionality of adding new patient
 
class EditPatientDetails - This class allows the admin to edit the details of patients. This is an abstract class. It has pure virtual functions which are overridden in derived classes
 
class AssignAppointment	void playlist();//shows list of teachers and courses from file void AssignCouses();//Takes inputs from user and saves in associated text file . 
 
class EditDoctorDetails : public EditPatientDetails - This class allows the admin to edit the details of doctor.

class UpdateAppointment : public EditPatientDetails - This class updates the status and time of a specific appointment.

class FeeStatus : public EditPatientDetails - This class tells the admin about status of the patients fees.
 	
void viewAllPatients(); - This function displays all the registered patients
 	
void viewAllDoctors(); - This function displays all the registered doctors	

void viewAllAppointments();	- This function displays all the registered appointments	
 
 
3.	Doctor.cpp : 
Void doctor_() - Is the driver function for doctor module. Based on switch case. Takes input from user to function
 
Int menuD() - Is a function in which all of the doctor options are displayed to the user.

void viewAllAppointments() - Views all the appointments of the logged in doctor
 
Void updateAppointment()	- Updates the appointment status for patients
 
4.	Patient.cpp : 
Void patient()_  - Is the driver function for patient module. Based on switch case. Takes input from user to function
 
Int menuP()	- Is a function in which all of the patient options are displayed to the user. 

void viewAllAppointment() 

Views all the appointments of the logged in patient 
 
Void ViewFeeStatus()	Shows the status of the fee to the logged in patient.
 
 
 
