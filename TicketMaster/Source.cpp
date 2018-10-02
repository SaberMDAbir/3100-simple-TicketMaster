//MD Abir A. Choudhury
//04/13/2018
//CIS 3100
//TicketMaster - Lab 8

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//protoypes
void displayMenu();
void addTicket(string teamName[], int sectionNum[], double price[], int &num);
void displayTickets(string teamName[], int sectionNum[], double price[], int &num);
void displayTicketsBudget(string teamName[], int sectionNum[], double price[], int &num);
double findCheapestTicket(string teamName[], double price[], int &num);

int main() {
	//Declare variables
	const int SIZE = 500; //holds the size of the database
	string teamName[SIZE]; //holds the names of the teams the Knicks are playing against
	int sectionNum[SIZE]; //holds the section Number of the ticket
	double price[SIZE]; //holds the price of the ticket
	int num = 0; //holds the number of tickets issued

	int choice = 0;
	do {
		displayMenu();
		cin >> choice;
		//option 1
		if (choice == 1) {
			addTicket(teamName, sectionNum, price, num);
		}
		//option 2
		else if (choice == 2) {
			displayTickets(teamName, sectionNum, price, num);
		}
		//option 3
		else if (choice == 3) {
			displayTicketsBudget(teamName, sectionNum, price, num);
		}
		//option 4
		else if (choice == 4) {
			double min = 0;
			min = findCheapestTicket(teamName, price, num);
			cout << "The cheapest ticket we could find is priced at: " << min << endl;
		}
	} while (choice != 0);

	system("PAUSE");
	return 0;
}

//displays the menu options
void displayMenu() {
	cout << "+++++++++++++++++++++++\n" 
		<< "+TICKETMASTER v. 1.0.3+\n"
		<< "+++++++++++++++++++++++\n"
		<< "1 - Add New Ticket\n"
		<< "2 - Display All Tickets\n"
		<< "3 - Display Tickets by Budget\n"
		<< "4 - Display Cheapest Price by Event\n"
		<< "0 - Exit\n"
		<< "Pick a choice: ";
}
//add new ticket
void addTicket(string teamName[], int sectionNum[], double price[], int &num) {
	char choice;
	bool cont = true;
	while (cont) {
		cout << "Name of team: ";
		cin >> teamName[num];
		cout << "Section Number: ";
		cin >> sectionNum[num];
		cout << "Price of the ticket: ";
		cin >> price[num];
		num++;

		cout << "Would you like to add another ticket: <Y or N> ";
		cin >> choice;
		if (toupper(choice) == 'Y') {
			cont = true;
		}
		else {
			cont = false;
		}
	}
}
//display tickets in a formatted fashion
void displayTickets(string teamName[], int sectionNum[], double price[], int &num) {
	cout << "List of tickets in database:\n"
		<< "\t Team Name\tSection Number\tPrice\n";
	for (int i = 0; i < num; i++) {
		cout << "Ticket " << i << ": " << teamName[i] << "\t\t" << sectionNum[i] << "\t\t" << price[i] << endl;
	}
}
//displays the tickets available by budget
void displayTicketsBudget(string teamName[], int sectionNum[], double price[], int &num) {
	cout << "Budget: ";
	double budget = 0;
	cin >> budget;

	cout << "Tickets priced according to your budget: \n";
	for (int i = 0; i < num; i++) {
		if (price[i] <= budget) {
			cout << teamName[i] << "\t" << sectionNum[i] << "\t" << price[i] << endl;
		}
	}
}
//finds the cheapest ticket according to name
double findCheapestTicket(string teamName[], double price[], int &num) {
	cout << "Which event are you interested in: ";
	string choice; //holds the team name of the event the user is interested in
	cin >> choice;
	
	double min = price[0];
	for (int i = 0; i < num; i++) {
		if ((min < price[i]) && (choice == teamName[i])) {
			min = price[i];
			cout << teamName[i];
		}
	}
	return min;
}