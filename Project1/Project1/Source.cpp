/*
Victor Semenok and John Hammons Midterm Project for CSIS 123
Create a program that guides the user through Murphyville and allows for them to interact with a jukebox, cafe, or shop depending on the time of day and day of the week.


*/


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> //fixes "system is ambigious error" sometimes
#include <fstream>


using namespace std;

char staying;


string day;
bool weekend;
int timeDay;
bool PM;

char activity; //where user is going

const float CAFETAX = 0.04125;
const float COSTBISCUITS = 5.00;
const float COSTCAKES = 5.00;
const float COSTDILLOSTEAK = 5.00;
const float COSTSQUIRRELONSTICK = 5.00;

int food; // what food is ordered
int amtFood; // amt of food ordered
int amtItems; // amt of different items
int amtBiscuits; // amt of Biscuits ordered
int amtCakes; // amt of pancakes ordered
int amtDilloSteak; // amt of steak ordered
int amtSquirrelOnStick; // amt of squirrel ordered
int stockDilloSteak = 5; // stock of steak left
int stockSquirrelOnStick = 5; // stock of squirrel

float subtotal;
float total;
int rating;

const float TIPRATE1 = 0.2; //tip rate for 1 star
const float TIPRATE2 = 0.15; //tip rate for 2 star
const float TIPRATE3 = 0.1; //tip rate for 3 star

float jukeMoney; //money put into Jukebox
int quarters; //amount of 25 cent increments put in
int seconds; //amount of seconds to play for

ifstream inFile;
ofstream outFile;

string song;

//song lengths in seconds
const int lengthOn = 171; //On The Road Again    
const int lengthLife = 186; //Life is a Highway 
const int lengthKing = 183; //King of the Road           
const int lengthCantDrive = 255; //I Cant Drive 55              
const int lengthEverywhere = 216; // Ive Been Everywhere      
const int lengthShutUp = 243; // Shut Up and Drive          
const int lengthAllNight = 177; // I drove all night             
const int lengthRoadJack = 303; // Hit the Road Jack           
const int lengthCountryRoadsTakeMeHome = 186; //Country Roads Take Me HOME!    
const int lengthRoad = 177; // Road to Nowhere              

int main() {
	cout << setprecision(2) << fixed; // makes all outputs to two decimal points
	
	//Welcome Screen
	do {
		for (;;) { //infinite loop till if statement
			cout << "WELCOME TO THE WONDERFUL BACKWARDS VILLE OF THE MURPHYVILLE! are you staying?(y/n)" << endl;
			cin >> staying;
			if (staying != 'y' || staying != 'Y' || staying != 'n' || staying != 'N') { //checks for valid input
				break;
			}
		}

		if (staying == 'n' || staying == 'N')
			break;


		cout << "what day of the week are you visting?" << endl;
		cin >> day;

		cout << "what time of day are you visiting (4 digit 24 hour clock no colon or leading zero i.e 1100 or 700)?" << endl;
		cin >> timeDay;

		cout << "Where would you like to go?" << endl;

		//Knowing AM or PM mostly because of requirements
		if (timeDay >= 1200)
			PM = true;
		else
			PM = false;

		//Deciding what is available
		if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday"
			|| day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday") //deciding if it is the weekend
			weekend = true;
		else
			weekend = false;

		//Activity Selection
		if (weekend) {
			if (timeDay >= 700 && timeDay <= 2200) {
				cout << "You can visit the cafe(c) or the souvenir shop(s), or just play with the juke box(j)" << endl;
				cin >> activity;
			}
			else if (timeDay <= 2300 && timeDay >= 500) {
				cout << "The cafe is open(c), and it has a juke box(j)" << endl;
				cin >> activity;
			}
			else {
				cout << "Sorry nothing is open in murphyville" << endl;
			}
		}
		else {
			if (timeDay >= 800 && timeDay <= 2000) {
				cout << "You can visit the cafe(c) or the souvenir(s), or just play with the juke box(j)" << endl;
				cin >> activity;
			}
			else if (timeDay <= 2300 && timeDay >= 500) {
				cout << "The cafe is open(c), and it has a juke box(j)" << endl;
				cin >> activity;
			}
			else {
				cout << "Sorry nothing is open in murphyville" << endl;
			}
		}

		//Cafe
		if (activity == 'c' || activity == 'C') {

			//Cafe Menu Selection
			cout << "How many different items would you like to order?" << endl;
			cin >> amtItems;

			for (amtItems; amtItems > 0; amtItems--) {
				if (timeDay <= 2000 && timeDay >= 1100) {
					cout << "Breakfast and Dinner menu" << endl;


					cout << "what item number would you like?" << endl;
					cin >> food;
					switch (food) {
					case 1:
						cout << "How many: " << endl;
						cin >> amtFood;
						amtBiscuits += amtFood;
						amtFood = 0;
						break;
					case 2:
						cout << "How many: " << endl;
						cin >> amtFood;
						amtCakes += amtFood;
						amtFood = 0;
						break;
					case 3:
						cout << "How many: " << endl;
						cin >> amtFood;
						stockDilloSteak -= amtFood;
						if (stockDilloSteak < 0) {
							cout << "Sorry we are out of that item" << endl;
							break;
						}
						amtDilloSteak += amtFood;
						amtFood = 0;
						break;
					case 4:
						cout << "How many: " << endl;
						cin >> amtFood;
						stockSquirrelOnStick -= amtFood;
						if (stockSquirrelOnStick < 0) {
							cout << "Sorry we are out of that item" << endl;
							break;
						}
						amtSquirrelOnStick += amtFood;
						amtFood = 0;
						break;
					default:
						cout << "that is not an available item" << endl;
						break;

					}

				}
				else if (timeDay <= 2300 && timeDay >= 500) {
					cout << "Breakfast Menu" << endl;


					cout << "what item number would you like?" << endl;
					cin >> food;
					switch (food) {
					case 1:
						cout << "How many: " << endl;
						cin >> amtFood;
						amtBiscuits += amtFood;
						amtFood = 0;
						break;
					case 2:
						cout << "How many: " << endl;
						cin >> amtFood;
						amtCakes += amtFood;
						amtFood = 0;
						break;
					default:
						cout << "that is not an available item" << endl;
						break;
					}
				}
				else {
					cout << "We are closed" << endl;
				}
			}

			subtotal = amtBiscuits * COSTBISCUITS + amtCakes * COSTCAKES + amtDilloSteak * COSTDILLOSTEAK + amtSquirrelOnStick * COSTSQUIRRELONSTICK;

			total = subtotal * (1 + CAFETAX); //total before survey tip

			cout << "On a scale of 1-3 how enjoyable was your meal?" << endl;
			cin >> rating;

			if (rating == 1) {
				total += total * (1 + TIPRATE1);
			}

			if (rating == 2) {
				total += total * (1 + TIPRATE2);
			}

			if (rating == 3) {
				total += total * (1 + TIPRATE3);
			}

			cout << "Must be \"G\"-rated" << endl;
		}

		//Souvenir Shop
		else if (activity == 's' || activity == 'S') {
			if (weekend) {
				if (timeDay >= 700 && timeDay <= 2200) {
					cout << "WELCOME TO THE SOUVENIR STORE" << endl << endl;
					cout << "We are currently selling:" << endl;

				}
				else {
					cout << "Sorry we are closed. Come back between 8 AM or 8 PM on weekdays or 7 AM and 10 PM on weekends" << endl;
				}
			}
			else {
				if (timeDay >= 800 && timeDay <= 2000) {
					cout << "WELCOME TO THE SOUVENIR STORE" << endl << endl;
					cout << "We are currently selling:" << endl;

				}
				else {
					cout << "Sorry we are closed. Come back between 8 AM or 8 PM on weekdays or 7 AM and 10 PM on weekends" << endl;
				}
			}
		}

		//Jukebox
		else if (activity == 'j' || activity == 'J') {

		
		inFile.open("Songs.txt");
		outFile.open("SongsPlayed.txt");
			do{
				cout << "How much money would you like to spend. (0.25 for 3 minutes)" << endl;
				cin >> jukeMoney;

				quarters = jukeMoney * 4;
				seconds = quarters * 180;
				jukeMoney = 0;
				int counter = 0;
				while (getline(inFile,song,' ')) {
					//inFile >> song;
					if (song != "") {
						cout << song << endl;
						outFile << song << endl;
					}
				}


			} while (jukeMoney != 0);
		inFile.close();
		outFile.close();
		}

		else {
		cout << "Not a valid activity" << endl;
		}

	}while(staying == 'y' || staying == 'Y');
	
	system("pause");
	return 0;
}