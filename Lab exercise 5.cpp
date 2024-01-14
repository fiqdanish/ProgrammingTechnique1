#include <iostream>
#include <iomanip>
using namespace std;
void getInput (int &, int &, int &, int &);
void dispOutput (int);
void dispStatus (int);
int calcAverage (int, int);

int main ()
{
	int totcases = 0, newcases = 0, totdeath = 0, totrecovered = 0, statesnum = 0, totalactcases = 0, highest_case = 0, actcases, average;
	char states [50], highestates [50];
	char loopcheck;
	
	do 
	{
		cout << "<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		
		cout << "State name\t: ";
		cin.getline (states, 50);
		
		statesnum++; //to count the number of states
		
		getInput (totcases, newcases, totdeath, totrecovered);
		
		actcases = totcases + newcases - totdeath - totrecovered;
		
		if (actcases > highest_case) // to check which states has the most highest cases
		{
			highest_case = actcases;
			strcpy (highestates, states);
		}
		
		totalactcases += actcases;
		
		cout << endl << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
		
		dispOutput (actcases);
		
		cout << endl << "Press <ENTER> to continue...";
		cin >> loopcheck;
		
		cin.ignore();
		
		cout << endl;
		
	}while (loopcheck == 'Y' || loopcheck == 'y');
	
	average = calcAverage (totalactcases, statesnum);
	
	cout << "<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
	
	cout << "Total" << setw (4) << ": " << totalactcases << endl;
	cout << "Highest: " << highest_case << " (" << highestates << ")" << endl;
	cout << "Average for 5 states: " << average;
	
	return 0;
}

void getInput (int &reftotcases, int &refnewcases, int &reftotdeath, int &reftotrecovered)
{
	cout << "Total cases\t: ";
	cin >> reftotcases;
	cout << "New cases\t: ";
	cin >> refnewcases;
	cout << "Total death\t: ";
	cin >> reftotdeath;
	cout << "Total recovered" << setw (3) << ": ";
	cin >> reftotrecovered;
}

void dispOutput (int a)
{
	dispStatus (a);
}

void dispStatus (int k) 
{
	cout << "Active cases\t: " << k << endl;
	
	if (k==0)
	{
		cout << "Status\t\t: Green zone" << endl;
	}
	else if (k >= 1 && k <= 20)
	{
		cout << "Status\t\t: Yellow zone" << endl;
	}
	else if (k >= 21 && k <= 40)
	{
		cout << "Status\t\t: Orange zone" << endl;
	}
	else if (k > 40)
	{
		cout << "Status\t\t: Red zone" << endl;
	}
	
}

int calcAverage (int t, int s)
{
	int avrg;
	
	avrg = t/s;
	
	return avrg;
}