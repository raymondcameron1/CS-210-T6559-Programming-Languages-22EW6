//Raymond Cameron 7/17/2022

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int formatTwoSpaces(int myInt)
{
	cout << setw(2) << setfill('0') << myInt << endl;
	return myInt;
}

string nCharString(size_t stringLength, char c) 
{
	string newString;
	for (size_t i = 0; i < stringLength; i++) {
		newString += c;
	}
	return newString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string tempReturnString = "a";
	cout << "The time is ";
	cout << setw(2) << setfill('0') << h << ":";
	cout << setw(2) << setfill('0') << m << ":";
	cout << setw(2) << setfill('0') << s << "." << endl;
	// I dont understand why this string needs to be returned here.
	return tempReturnString;

}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string tempReturnString = "a";
	if (h > 12) {
		h = h - 12;
		cout << "The time is ";
		cout << setw(2) << setfill('0') << h << ":";
		cout << setw(2) << setfill('0') << m << ":";
		cout << setw(2) << setfill('0') << s << " pm." << endl;
	}
	else {
		cout << "The time is ";
		cout << setw(2) << setfill('0') << h << ":";
		cout << setw(2) << setfill('0') << m << ":";
		cout << setw(2) << setfill('0') << s << " am." << endl;
	}
	// I dont understand why this string needs to be returned here.
	return tempReturnString;
}

int hourHandler(unsigned int h, unsigned int m, unsigned int s) {

	while (s > 59) {
		s = s - 60;
		m = m + 1;
	}
	while (m > 59) {
		m = m - 60;
		h = h + 1;
	}
	while (h > 24) {
		h = h - 24;
	}
	return (h);
}

int minuteHandler(unsigned int h, unsigned int m, unsigned int s) {

	while (s > 59) {
		s = s - 60;
		m = m + 1;
	}
	while (m > 59) {
		m = m - 60;
		h = h + 1;
	}
	while (h > 24) {
		h = h - 24;
	}
	return (m);
}

int secondHandler(unsigned int h, unsigned int m, unsigned int s) {

	while (s > 59) {
		s = s - 60;
		m = m + 1;
	}
	while (m > 59) {
		m = m - 60;
		h = h + 1;
	}
	while (h > 24) {
		h = h - 24;
	}
	return (s);
}

int addOneSecond(unsigned int h, unsigned int m, unsigned int s) {
	s++;
	secondHandler(h, m, s);
	return s;
}

int addOneMinute(unsigned int h, unsigned int m, unsigned int s) {
	m++;
	minuteHandler(h, m, s);
	return m;
}

int addOneHour(unsigned int h, unsigned int m, unsigned int s) {
	h++;
	hourHandler(h, m, s);
	return h;
}

int userMenu(int hourInt, int minuteInt, int secondInt) {
	//variable declerations
	string myString;
	int menuChoiceInt;

	// starts the program by outputting formatted time
	hourInt = hourHandler(hourInt, minuteInt, secondInt);
	minuteInt = minuteHandler(hourInt, minuteInt, secondInt);
	secondInt = secondHandler(hourInt, minuteInt, secondInt);
	formatTime24(hourInt, minuteInt, secondInt);
	formatTime12(hourInt, minuteInt, secondInt);

	cout << "Type ""exit"" if you would like to exit the program. Otherwie type ""no""." << endl;
	cin >> myString;
	if (myString == "exit") {
		menuChoiceInt = 4;
		return menuChoiceInt;
	}
	if (myString != "exit") {
		cout << "Would you like to add 1 hour to the time?" << endl;
		cin >> myString;
		if (myString == "yes") {
			menuChoiceInt = 1;
			return menuChoiceInt;
		}
		if (myString != "yes") {
			cout << "Would you like to add 1 minute to the time?" << endl;
			cin >> myString;
			if (myString == "yes") {
				menuChoiceInt = 2;
				return menuChoiceInt;
			}
			if (myString != "yes") {
				cout << "Would you like to add 1 second to the time?" << endl;
				cin >> myString;
				if (myString == "yes") {
					menuChoiceInt = 3;
					return menuChoiceInt;
				}
			}
		}
	}
}

int main()
{

	//main variable declerations
	int myInt = 0;
	int stringLength = 13;
	char fillChar = '*';
	int maxChoices = 15;
	int hourInt = 0;
	int minuteInt = 0;
	int secondInt = 0;
	int menuChoiceInt = 0;


	//runs the menu function and returns the choice.
	//loop to call menu function
	while (menuChoiceInt != 4) {
		menuChoiceInt = userMenu(hourInt, minuteInt, secondInt);

		//adds 1 hour then handles time conversions
		if (menuChoiceInt == 1) {
			hourInt = addOneHour(hourInt, minuteInt, secondInt);
			hourInt = hourHandler(hourInt, minuteInt, secondInt);
			minuteInt = minuteHandler(hourInt, minuteInt, secondInt);
			secondInt = secondHandler(hourInt, minuteInt, secondInt);
		}

		//adds 1 minute then handles time convrsions
		if (menuChoiceInt == 2) {
			minuteInt = addOneMinute(hourInt, minuteInt, secondInt);
			hourInt = hourHandler(hourInt, minuteInt, secondInt);
			minuteInt = minuteHandler(hourInt, minuteInt, secondInt);
			secondInt = secondHandler(hourInt, minuteInt, secondInt);
		}

		//Adds 1 second then handles time conversions
		if (menuChoiceInt == 3) {
			secondInt = addOneSecond(hourInt, minuteInt, secondInt);
			hourInt = hourHandler(hourInt, minuteInt, secondInt);
			minuteInt = minuteHandler(hourInt, minuteInt, secondInt);
			secondInt = secondHandler(hourInt, minuteInt, secondInt);
		}
	}

	/*
	//function calls

	//"add one" functions
	secondInt = addOneSecond(hourInt, minuteInt, secondInt);
	minuteInt = addOneMinute(hourInt, minuteInt, secondInt);
	hourInt = addOneHour(hourInt, minuteInt, secondInt);

	//time increment functions
	hourInt = hourHandler(hourInt, minuteInt, secondInt);
	minuteInt = minuteHandler(hourInt, minuteInt, secondInt);
	secondInt = secondHandler(hourInt, minuteInt, secondInt);
	
	//function to format with added 0's
	nCharString(stringLength, fillChar);
	
	//functions to display the time
	formatTime24(hourInt, minuteInt, secondInt);
	formatTime12(hourInt, minuteInt, secondInt);
	*/

	return 0;
}