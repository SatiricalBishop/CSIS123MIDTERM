/*
Victor Semenok and John Hammons Midterm Project for CSIS 123
Create a program that guides the user through Murphyville and allows for them to interact with a jukebox, cafe, or shop depending on the time of day and day of the week.


*/


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> //fixes "system is ambigious error"
#include <fstream>

using namespace std;

char staying;
bool here;

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
int amtBiscuits; // amt of Biscuits ordered
int amtCakes; // amt of pancakes ordered
int amtDilloSteak; // amt of steak ordered
int amtSquirrelOnStick; // amt of squirrel ordered
int stockDilloSteak = 5; // stock of steak left
int stockSquirrelOnStick = 5; // stock of squirrel

int main() {
	
	//Welcome Screen
	
	do {

		while (staying != 'y' || staying != 'Y' || staying != 'n' || staying != 'N') {
			cout << "welcome to Murphyville are you staying?(y/n)" << endl;
			cin >> staying;

			cout << "Please input y for yes or n for no" << endl;
		}

		cout << "what day of the week are you visting?" << endl;
		cin >> day;

		cout << "what time of day are you visiting (4 digit 24 hour clock no colon or leading zero i.e 1100 or 700)?" << endl;
		cin >> timeDay;

		cout << "Where would you like to go?" << endl;

		//Setting 'here' boolean
		if (staying == 'y' || staying == 'y')
			here = true;
		else
			here == false;

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
		while () {
			if (weekend) {
				if (timeDay >= 700 && timeDay <= 2200) {
					cout << "You can visit the cafe(c) or the souvenir shop(s), or just play with the juke box(j)" << endl;
				}
				else if (timeDay <= 2300 && timeDay >= 500) {
					cout << "The cafe is open(c), and it has a juke box(j) ;)" << endl;
				}
				else {
					cout << "Sorry nothing is open in murphyville" << endl;
				}
			}
			else {
				if (timeDay >= 800 && timeDay <= 2000) {
					cout << "You can visit the cafe(c) or the souvenir(s), or just play with the juke box(j)" << endl;
				}
				else if (timeDay <= 2300 && timeDay >= 500) {
					cout << "The cafe is open(c), and it has a juke box(j) ;)" << endl;
				}
				else {
					cout << "Sorry nothing is open in murphyville" << endl;
				}
			}
		}
		if(activity == 'c' || activity == 'C'){
		
		//Cafe Menu Selection
		if (timeDay <= 2000 && timeDay >= 1100) {
			cout << "Breakfast and Dinner menu" << endl;

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

	}while(here);
	
	system("pause");
	return 0;
}