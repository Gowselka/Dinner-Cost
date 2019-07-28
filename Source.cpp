// Sinclair Community College
//CIS 1111 Programming Assignment - Expressions
//Kevin Gowsell
//Febuary 3rd, 2019

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//Variables 
	const double DINNER_COST = 31.80;    //dinner cost per person 
	double guestNumber;                     //input the number of guests
	const double SERVER_WAGE = 15.00;    //server wage per hour
	double serverCost;                   //server cost as a function of # of guests
	const double SERVER_OVERTIME = 0.5;  //server overtime by minute
	string customerName;                 //input customer first name
	int eventMinutes;                    //input how long dinner will be.
	double averageCost;                  //calculate the average cost per person
	double eventCost;                    //total bill for the event
	const double depositPercent = 0.25;  //25% required deposit
	string eventName;                    //input the name of the event
	double serverNumber;				 //# of servers
	double roundedUpServers;			 //# of servers rounded up
	double dinnerCost;					 //cost of the dinner based on guests
	double eventHours;                   //used to determine server wages per hour
	double remainingMinutes;             //used to determine server overtime
	const double SERVER_MAX = 15;        //the maximum people a server can serve
	const double MINUTES_IN_HOUR = 60;   //60 minutes in an hour
	double deposit;						 //deposit required based on event cost

	//Prompt the User for Name of Function
	cout << "Please enter the name of your event: ";
	getline(cin, eventName);

	//Enter Customer First and Last Name
	cout << "Please enter your first and last name: ";
	getline(cin, customerName);
	cout << "";

	//Enter the number of guests
	cout << "Please enter the number of guests attending: ";
	cin >> guestNumber;

	//Enter the number of minutes of the event
	cout << "Please enter the length of the event in minutes: ";
	cin >> eventMinutes;
	cout << "";
	cout << "";
	//Total cost for food
	dinnerCost = DINNER_COST * guestNumber;

	//one server for every 15 guests. 
	serverNumber = guestNumber / SERVER_MAX;
	roundedUpServers = ceil(serverNumber);
	
    //Servers make $15.00 an hour and $0.50 per minute for every minute over an hour.
	eventHours = eventMinutes / MINUTES_IN_HOUR;
	remainingMinutes = eventMinutes % 60;
	serverCost = (eventHours * SERVER_WAGE) + (remainingMinutes * SERVER_OVERTIME);
	
	//Total & Average cost per person
	eventCost = serverCost + dinnerCost;
	averageCost = eventCost / guestNumber;

    //Catering requires a 25% deposit
	deposit = eventCost * depositPercent;

	//Display the outputs 
	cout << eventName << endl;
	cout << "Event Estimate for: " << customerName << endl;
	cout << "";
	cout << "The number of servers needed: " << roundedUpServers << endl;
	cout << "The cost for those servers: " << setprecision(2) << fixed << serverCost << endl;
	cout << "The cost for the food: " << setprecision(2) << fixed << dinnerCost << endl;
	cout << "The average cost per person is: " << setprecision(2) << fixed << averageCost << endl;
	cout << "The total cost for your event is: " << setprecision(2) << fixed << eventCost << endl;
	cout << "";
	cout << "Please provide a 25% deposit to reserve the event" << endl;
	cout << "The deposit total is: " << setprecision(2) << fixed << deposit << endl;

	system("pause");
	return 0;
}
	