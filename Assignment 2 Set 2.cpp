#include <iostream>
using namespace std;
float calcinstall (float, float, float, float);

int main ()
{
	int mod, var, reg;
	float price, downpaym, rate, period, monthinstall;
	char otherdata;	
	
	do 
	{	
		cout << "Proton Car Loan Calculator" << endl << endl;
	
		cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
		cin >> mod;
	
		cout << "Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
		cin >> var;
	
		cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
		cin >> reg;
	
		cout << endl << "Car Info" << endl;
		cout << "Model: ";
	
		if (mod==1)
		{
			cout << "X50" << endl;
		}
		else if (mod==2)
		{
			cout << "Exora" << endl;
		}
		else if (mod==3)
		{
			cout << "Persona" << endl;
		}
	
		cout << "Variant: ";
	
		if (var==1)
		{
			cout << "1.6L Standard CVT" << endl;
		}
		else if (var==2)
		{
			cout << "1.6L Premium CVT" << endl;
		}
	
		cout << "Region: ";
	
		if (reg==1)
		{
			cout << "Peninsular Malaysia" << endl;
		}
		else if (reg==2)
		{
			cout << "East Malaysia" << endl;
		}
	
		cout << "Paint type: Metallic" << endl;
	
		cout << "Price (MYR): ";
	
		if (mod==1)
		{
			if (var==1)
			{
				price = 86300;
				cout << price << ".00" << endl;
			}
			else if (var==2)
			{
				price = 101800;
				cout << price << ".00" << endl;
			}	
		}
		else if (mod==2)
		{
			if (var==1)
			{
				price = 62800;
				cout << price << ".00" << endl;		
			}
			else if (var==2)
			{
				price = 69800;
				cout << price << ".00" << endl;
			}
		}
	
		else if (mod==3)
		{
			if (var==1)
			{
				price = 47800;
				cout << price << ".00" << endl;
			}
			else if (var==2)
			{
				price = 54600;
				cout << price << ".00" << endl;
			}
		}
	
		cout << endl << "Down Payment (MYR): ";
		cin >> downpaym;
	
		cout << "Interest Rate (%): ";
		cin >> rate;
	
		cout << "Repayment period (in years): ";
		cin >> period;
	
		monthinstall = calcinstall (price, downpaym, rate, period);
		
		cout << endl << "MONTHLY INSTALLMENT (MYR): " << monthinstall << endl << endl;
	
		cout << "Do you want to enter other data? [Y @ N]: ";
		cin >> otherdata;
		
	}while (otherdata == 'Y' || otherdata == 'y');
	
	cout << endl << "Thank you :)";
	
	return 0;
}

float calcinstall (float a, float b, float c, float d)
{
	float loan, totinterest, monthly;
	
	loan = a-b;
	totinterest = (c/100)*loan*d;
	monthly = (loan+totinterest)/(12*d);
	
	return monthly;
}