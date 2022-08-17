/*
	Ameera Haider
	20I-0799
	BSCS - B
	OOP - Project
	Header File
*/

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

//_____________________________ Booking Class _____________________________ //

class Booking {
	
	string dep_city, dep_country, arr_city, arr_country;
	int dep_time, duration, arr_time;
	char seatType;
	int seatNo;
	bool covid;
	
	public:
		
		void showAvailableSeats();		
		void showAvailableCovidSeats();
		void showSchedule();
		void showRoute();
		void searchFlight();
		void changeSchedule();
		void cancelFlight();
		void bookFlight();
};

//_____________________________ Person Class _____________________________ //

class Person {
	
	string username;
	string name;
	string password;
	int option;
	
	public:
		
		Person();
		
		void setName (string str);
		void setUserName (string str);
		void setPassword (string str);
		
		string getName();
		string getUserName();
		string getPassword();	
};

//_____________________________ Passenger Class _____________________________ //

class Passenger : public Person {
	
	int line;
	int age;
	string cnic;
	char passportType; //L for Local I for International
	bool visa; //Visa
	string history[5];
	Booking bk;
	
	public:
		
		void setAge (int x);
		void setCNIC (string x);
		void setPassportType (char x);
		void setVisa (bool x);
		
		int getAge ();
		string getCNIC();
		char getPassportType();
		bool getVisa ();
		
		void loginPassenger();
		void passengerMenu();
		void viewDetails();
		void updateDetails();	
		void passengerRegister();
		void viewHistory();
		void updateHistory();
			
};

//_____________________________ Admin Class _____________________________ //

class Admin : public Person {
		
	public:
		
		void loginAdmin();
};

//_____________________________ Controller Class _____________________________ //

class Controller : public Admin, public Passenger, public Booking {
	
	int c1;
	char c2;
	
	public :	
		
		void MainMenu();
};

