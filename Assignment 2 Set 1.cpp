#include<iostream>
using namespace std;

float bmrcalcmale(int a, int b, int c)
{
    float d;
	d = (10 * b) + (6.25 * c) - (5 * a) + 5;
	return d;
}

float bmrcalcfem(int a, int b, int c)
{
     float d;
	 d = (10 * b) + (6.25 * c) - (5 * a) - 161;
	 return d;
}

int main()
{
    int age, Weight, Height;
    char gender, data;
    float bmr, Calorie1, Calorie2, Calorie3, Calorie4, Calorie5, Calorie6;
    string activityLevel ;
    
	do
	{	
		cout<<"Basal Metabolic Rate (BMR) Calculator\n\n";
		
		do
		{
			cout << "Age [15-80] : ";
			cin >> age;
			
		}while(age<15 || age>80);
		
		do
		{
			cout <<"Gender [F @ M]: ";
			cin >> gender;
			
		}while(gender!='F' && gender!='f' && gender!='m' && gender!='M');
		
		cout << "Height (cm): ";
		cin >> Height;
		
		cout << "Weight (kg) : ";
		cin >> Weight;
	
		if (gender == 'M' || gender == 'm') 
    	{
    	    bmr = bmrcalcmale(age, Weight, Height);
    	} 
    	else  
    	{
        	bmr = bmrcalcfem(age, Weight, Height);
    	}
    
		cout << endl << "BMR = " << bmr << " Calories/day (using Mifflin-St Jeor Equation)" << endl;
		cout << endl << "Daily calorie needs based on activity level" << endl << endl;
    	cout << "Activity Level\t\t\t\t\t\tCalorie" << endl;
    	
    	Calorie1 = bmr * 1.2;
    	cout << "Sedentary (little or no exercise)\t\t\t" << Calorie1 << endl;
    	
    	Calorie2 = bmr * 1.375;
    	cout << "Exercise 1-3 times/week\t\t\t\t\t" << Calorie2 << endl;
    	
    	Calorie3 = bmr * 1.55;
    	cout << "Exercise 4-5 times/week\t\t\t\t\t" << Calorie3 << endl;
    	
    	Calorie4 = bmr * 1.725;
    	cout << "Daily exercise or intense exercise 3-4 times/week\t" << Calorie4 << endl;
    	
    	Calorie5= bmr * 1.9;
    	cout << "Intense exercise 6-7 times/week\t\t\t\t" << Calorie5 << endl;
    	
    	Calorie6 = bmr * 2.0;
    	cout << "Very intense exercise daily, or physical job\t\t" << Calorie6 << endl;
    	
		cout << "\n\nExercise: 15-30 minutes of elevated heart rate activity." << endl;
		cout << "Intense exercise: 45-120 minutes of elevated heart rate activity." << endl;
		cout << "Very intense exercise: 2+ hours of elevated heart rate activity." << endl;

		cout << "\nDo you want to enter another data? [Y @ N]: ";
		cin >> data;
		
	}while(data=='Y' || data=='y');
	
	cout << endl << "Thank you :)";
	
	return 0;
}