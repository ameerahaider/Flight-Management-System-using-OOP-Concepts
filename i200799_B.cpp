/*
	Ameera Haider
	20I-0799
	BSCS - B
	OOP - Project
	CPP File
*/

//Libraries Used
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include "i200799_B.h"

using namespace std;

//_____________________________ Booking Class _____________________________ //

		void Booking :: showAvailableSeats(){
			
			cout << "********** AVAILABLE SEATS **********" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* 1 *     * 2 *     * 3 *     * 4 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* 5 *     * 6 *     * 7 *     * 8 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* 9 *     * 10*     * 11*     * 12*" << endl;
			cout << "*****     *****     *****     *****" << endl;
		}
		
		void  Booking :: showAvailableCovidSeats(){
			
			cout << "********** AVAILABLE SEATS **********" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* 1 *     * X *     * 3 *     * X *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* X *     * 6 *     * X *     * 8 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "*                                 *" << endl;
			cout << "*****     *****     *****     *****" << endl;
			cout << "* 9 *     * X *     * 11*     * X *" << endl;
			cout << "*****     *****     *****     *****" << endl;
		}
	
		void Booking :: bookFlight(){
			
			cout << "********** BOOKING FLIGHT **********" << endl;
			
			cout << "Enter Departure Country: ";
			cin >> dep_country;
			cout << "Enter Departure City: ";
			cin >> dep_city;
			cout << "Enter Arrival Country: ";
			cin >> arr_country;
			cout << "Enter Arrival City: ";
			cin >> arr_city;
			
			cout << "Enter Departure Time: ";
			cin >> dep_time;
			
			duration = rand() % 5 + 1;
			
			arr_time = dep_time + duration;
			
			cout << "B Bussiness Class" << endl;
			cout << "E Economy Class" << endl;
			cout << "Enter Seat Type: " << endl;
			cin >> seatType;
			
			cout << "Displaying Available Seats" << endl;
			showAvailableSeats();
			cout << endl << "Select Seat No: ";
			cin >> seatNo;
			
			cout << "BOOKING CONFIRMED! " << endl;	
			cout << "";
		}

//_____________________________ Person Class _____________________________ //

		Person :: Person(){
			
			username = "NULL";
			name = "NULL";
			password = "NULL";
			option = -1;
		}

		void Person :: setName (string str){ name = str;}
		void Person :: setUserName (string str){ username = str;}
		void Person :: setPassword (string str){ password = str;}
		
		string Person :: getName(){ return name;}
		string Person :: getUserName(){ return username;}
		string Person :: getPassword(){ return password;}

//_____________________________ Passenger Class _____________________________ //

		void Passenger :: setAge (int x){ age = x;}
		void Passenger :: setCNIC (string x){ cnic = x;}
		void Passenger :: setPassportType (char x){ passportType = x;}
		void Passenger :: setVisa (bool x){ visa = x;}
				
		int Passenger :: getAge () { return age;}
		string Passenger :: getCNIC (){ return cnic;}
		char Passenger :: getPassportType (){ return passportType;}
		bool Passenger :: getVisa (){ return visa;} 
		
		void Passenger ::  loginPassenger() {
			
			string userid, line, id, password, nm, b;
			int a;
			char c;
			bool d;
			string pass = "";
			char ch;
			bool f = 0;
			
			system ("CLS"); //Clear Screen
			
			cout << "********** LOGIN PASSENGER **********" << endl;
			cout << "Enter username: ";
			cin >> userid;
			
			cout << "Enter password: ";
			ch = _getch();
			
			while (ch != 13) {
				
				pass.push_back(ch); 
			    cout << '*';
			    ch = _getch();
			}
			
			ifstream fin; //Creating an object for reading from a file
	
			fin.open("Passengers.txt"); // Opening a File with the name "Passengers", of type "text", in "input" mode
			
			if (fin.is_open()) //Checking whether the file exists
			{	

				while (!fin.eof()) //Reads until the end of file is reached
				{
					fin >> id >> password >> nm >> a >> b >> c >> d;
					
					//Verifying Data	
					if (userid == id){
						
						//cout << "User Name Verified" << endl;
				
						if (password == pass){
							
							//cout << "Password Verified" << endl;
							f = 1;
							break;
						}	
					}
					else
						continue;	
				}
				
				fin.close(); //Closing the File	
				
				if (f == 0){
					
					cout << endl << "Incorrect Credentials Entered" << endl;
					loginPassenger();
				} 
				else {
					
					cout << endl << endl << "Login Successful!" << endl;
					cout << "Welcome, " << nm << endl;
					
					setUserName(userid);
					setPassword(pass);
					setName(nm); 
					setAge(a);
					setCNIC(b);
					setPassportType(c);
					setVisa(d);
					
					passengerMenu();
				}		
			}
			
			else 
				cout << "Unable to Open File" << endl;
		}
		
		void Passenger :: passengerMenu(){
			
			int c1;
			char c2;
			
			system ("CLS"); //Clear Screen
			
			cout << "************ PASSENGER MENU ************" << endl;
			cout << "*                                      *" << endl;
			cout << "*   Press 1      View Details          *" << endl;
			cout << "*   Press 2      Update Details        *" << endl;
			cout << "*   Press 3      View History          *" << endl;
			cout << "*   Press 4      Update History        *" << endl;
			cout << "*   Press 5      View Schedule         *" << endl;
			cout << "*   Press 6      Book a Flight         *" << endl;
			cout << "*   Press 7      Change Bookings       *" << endl;
			cout << "*   Press 8      Change Bookings       *" << endl;
			cout << "*   Press 9      Return to Main Menu   *" << endl;
			cout << "*                                      *" << endl;
			cout << "****************************************" << endl;
			
			cout << "Enter Choice: ";
			cin >> c1;
			
			while (c1 < 1 || c1 > 9){
				
				cout << "Error! Select again: ";
				cin >> c1;
			}
			
			switch (c1) {
				
				case 1: 
					
					viewDetails();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					cout << "C2 " << c2 << endl;
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
					break;
					
				case 2: 
					
					updateDetails();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
					break;
					
				case 3: 
					
					viewHistory();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
					break;
				
				case 4: 
					
					updateHistory();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
					break;
					
				
				case 5: 
					
					//showSchedule();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
					break;
					
				case 6: 
					
					bk.bookFlight();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
							
					break;
				
				case 7: 
					
					//changeBooking();
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
							
					break;
				
				case 8: 
					
					cout << "Displaying Schedule" << endl;
					
					cout << endl << endl << "Do you want to return to Passenger Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							passengerMenu();
							
					break;
				
				case 9:
					
					cout << "Return to Main Menu!" << endl;
					passengerMenu();
					break;
				
				default: 
					
					cout << "Error! Select again: ";
					cin >> c2;
			}
			
		}
		
		void Passenger :: viewDetails(){
			
			system ("CLS"); //Clear Screen
			
			cout << "Name: " << getName() << endl;
			cout << "Username: " << getUserName() << endl;
			cout << "CNIC: " << getCNIC () << endl;
			cout << "Age: " << getAge () << endl;
			cout << "Type of Passport: ";
				if (getPassportType () == 'L')
					cout << "Local Passport" << endl;
			 	else
			 		cout << "International Passport" << endl;
			 		
			if (getVisa () == 1)
					cout << "Visa Approved" << endl;
			 	else
			 		cout << "Visa Disapproved" << endl;
		}
		
		void Passenger :: updateDetails(){
			
			system ("CLS"); //Clear Screen
			
			cout << getName() << ", Please Update your Data." << endl;
			
			int a;
			string b;
			char c;
			bool d;
			
			cout << "Enter Age: ";
			cin >> a;
			setAge (a);
			
			cout << "I for International Passport" << endl;
			cout << "L for Local Passport" << endl;
			cout << "Type of Passport: " << endl;
			cin >> c;
			setPassportType (c);
			 
			cout << "Enter 1 for VISA APPROVED" << endl;
			cout << "Enter 0 for VISA NOT APPROVED" << endl;
			cout << "Visa: " << endl;
			cin >> d;
			setVisa (d);
			
			cout << "Enter CNIC: ";
			cin >> b;
			setCNIC (b);
		}	
		
		void Passenger :: passengerRegister() {
			
			string name, id, pass = "";
			char ch;
			
			system ("CLS"); //Clear Screen
			
			cout << "**** NEW ACCOUNT ****" << endl;
			
			cout << "Enter Name: ";
			cin >> name;
			
			cout << "Enter Username: ";
			cin >> id;
			
			cout << "Enter password: ";
			ch = _getch();
				
			while (ch != 13) {
					
				pass.push_back(ch); 
				cout << '*';
				ch = _getch();
			}
			
			ofstream fout; //Creating an Output Stream
			
			fout.open("Passengers.txt", ios::app); // Opening a File with the name "myFile", of type "text", in "append" mode
			
			//Writing to the File
			fout << endl << id << " " << pass  << " " << name << endl;
			
			fout.close(); //closing the file
		}
		
		void Passenger :: viewHistory(){
		
			system ("CLS"); //Clear Screen
			
			cout << "**** TRAVEL HISTORY ****" << endl;
			
			for (int i = 0; i < 1; i++){
				
				cout << history[i] << endl;
			}
		}
		
		void Passenger :: updateHistory(){
			
			system ("CLS"); //Clear Screen
			
			cout << "**** UPDATING HISTORY ****" << endl;
			
			for (int i = 0; i < 1; i++){
				
				cout << "Enter country: ";
				cin >> history[i];
			}
		}

//_____________________________ Admin Class _____________________________ //

	void Admin :: loginAdmin() {
			
			string userid, line, id, password, nm;
			string pass = "";
			char ch;
			bool f = 0;
			
			system ("CLS"); //Clear Screen
			
			cout << "********** LOGIN ADMIN **********" << endl;
			cout << "Enter username: ";
			cin >> userid;
			
			cout << "Enter password: ";
			ch = _getch();
			while (ch != 13){
				pass.push_back(ch);
			    cout << '*';
			    ch = _getch();
			}
			
			ifstream fin; //Creating an object for reading from a file
	
			fin.open("Admin.txt"); // Opening a File with the name "myFile", of type "text", in "input" mode
			
			if (fin.is_open()) //Checking whether the file exists
			{	
			
				while (!fin.eof()) //Reads until the end of file is reached
				{
					
					fin >> id >> password >> nm;

					//Verifying Data	
					if (userid == id){
						
						//cout << "User Name Verified" << endl;
				
						if (password == pass){
							
							//cout << "Password Verified" << endl;
							f = 1;
							break;
						}	
					}
					else
						continue;	
				}
				
				fin.close(); //Closing the File	
				
				if (f == 0){
					
					cout << "Incorrect Credentials Entered" << endl;
					loginAdmin();
				} 
				else {
					
					cout << endl << endl << "Login Successful!" << endl;
					cout << "Welcome, " << nm << endl;
					
					setUserName(userid);
					setPassword(pass);
					setName(nm); 
				}
					
			}
			else 
				cout << "Unable to Open File";
		}

//_____________________________ Controller Class _____________________________ //
	
	void Controller :: MainMenu() {
			
			system ("CLS"); //Clear Screen
		
			cout << "********** NEW - PAK Airline Flight System (NPAFS) **********" << endl;
			cout << "*                                                           *" << endl;
			cout << "*             Press 1              Admin Login              *" << endl;
			cout << "*             Press 2              User  Login              *" << endl;
			cout << "*             Press 3              Register New Account     *" << endl;
			cout << "*             Press 4              View Flights Schedule    *" << endl;
			cout << "*             Press 5              Exit                     *" << endl;
			cout << "*                                                           *" << endl;
			cout << "*************************************************************" << endl;
			
			cout << "Enter Choice: ";
			cin >> c1;
			
			while (c1 < 1 || c1 > 5){
				
				cout << "Error! Select again: ";
				cin >> c1;
			}
			
			switch (c1) {
				
				case 1: 
					
					loginAdmin();
					
					cout << endl << endl << "Do you want to return to Main Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							MainMenu();
						else 
							passengerMenu();
					break;
					
				case 2: 
					
					loginPassenger();
					
					cout << endl << endl << "Do you want to return to Main Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							MainMenu();
							
					break;
				
				case 3: 
					
					passengerRegister();
					
					cout << endl << endl << "Do you want to return to Main Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							MainMenu();
							
					break;
				
				case 4: 
					
					cout << "Displaying Schedule" << endl;
					//loginPassenger();
					
					cout << endl << endl << "Do you want to return to Main Menu (y/n): ";
					cin >> c2;
					
						while (c2 != 'y' && c2 != 'Y' && c2 != 'N' && c2 != 'n'){
							
							cout << endl << "Error! Select Again (y/n): ";
							cin >> c2;
						}
						
						if (c2 == 'y' || c2 == 'Y')
							MainMenu();
							
					break;
				
				case 5: 
					
					cout << "Goodbye!" << endl;
					exit(0);
					break;
				
				default: 
					
					cout << "Error! Select again: ";
					cin >> c1;
			}
		}
	
int main () {
	
	Controller obj;
	
	obj.MainMenu();
	
	
	return 0;
}
