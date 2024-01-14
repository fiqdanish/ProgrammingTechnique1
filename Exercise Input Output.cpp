#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void readFile (ifstream&, float[], int);
void computeC (float[], float [], int);
float average (float[], int);
void grade (float[], char[], int);
void writeFile (ofstream&, float[], float[], char[], int);

int highcount = 0, medcount = 0, lowcount = 0;

int main ()
{
	ifstream inputFile ("Fahrenheit.txt");
	ofstream outputFile ("Tempsummary.txt");
	const int array_size = 8;
	float fahren [array_size], celc [array_size];
	float averagelist; 
	char desc [array_size];

	if (!inputFile.is_open())
	{
		cout << "Error: Cannot open file!";
	}
	else
	{
		readFile (inputFile, fahren, array_size);
		computeC (fahren, celc, array_size);
		averagelist = average (celc, array_size);
		grade (celc, desc, array_size);
	}
	
	if (!outputFile.is_open())
	{
		cout << "Error: Cannot open file!";
	}
	else
	{
		writeFile (outputFile, fahren, celc, desc, array_size);
	}
	
	cout << "Average of the temperature in Celcius: " << fixed << setprecision (2) << averagelist << endl;
	cout << "Number of high temperature: " << highcount << endl;
	cout << "Number of medium temperature: " << medcount << endl;
	cout << "Number of low temperature: " << lowcount << endl;
	
	return 0;
}

void readFile (ifstream& inputFile, float fah[], int size)
{
	 for (int i=0; i<size; i++)
	{
		inputFile >> fah[i];
 
	}
	inputFile.close ();
}

void computeC (float f[], float C[], int size)
{
	for (int i=0; i<size; i++)
	{
		C[i] = (5.0/9.0)*(f[i]-32);
	}
}

float average (float C[], int size)
{
	float total = 0;
	float avrg = 0;
	
	for (int i=0; i<size; i++)
	{
		total += C[i];
	}
	
	avrg = total/size;
	
	return avrg;
}

void grade (float C[], char grde[], int size)
{
	for (int i=0; i<size; i++)
	{
		if (C[i] >= 35)
		{
			grde [i] = 'H';
			highcount++;
		}
		else if (C[i] >= 20 && C[i] < 35)
		{
			grde [i] = 'M';
			medcount++;
		}
		else if (C[i] < 20)
		{
			grde [i] = 'L';
			lowcount++;
		}
	}
}

void writeFile (ofstream& outputFile, float F[], float C[], char grde[], int size)
{
	outputFile << "C(Celcius)" << setw(20) << "F(Fahrenheit)" << setw(20) << "Description" << endl;
	outputFile << "==========" << setw(20) << "============" << setw(20) << "===========" << endl;
	
	for (int i=0; i<size; i++)
	{
		outputFile << fixed << setprecision (2) << C[i] << setw (20) << F[i] << setw(20) << grde[i] << endl;
	}
	
	outputFile.close();
}