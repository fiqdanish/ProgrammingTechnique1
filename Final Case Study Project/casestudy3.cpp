/*MUHAMMAD AFIQ DANISH BIN MOHD HAZNI A23CS0118
AHMAD ZIYAAD BIN MOHD ABBAS A23CS0206
AFIF SHAQIR IRFAN BIN ARQAM A23CS0204
MUHAMMAD SYAHMI FARIS BIN RUSLI A23CS0138*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#define months 12
#define stores 5
using namespace std;

void readFile (ifstream&, ofstream&);
void grandTotalSales(float [][months], int, ofstream&);
void highestSale (string[], int, float [][months], int, ofstream&);
void lowestSale (string[], int, float [][months], int, ofstream&);
void totmonthsales (float [][months], int, ofstream&);
void totstoresales (string [], int, float [][months], int, ofstream&);
void profitstore (string [], int, float [][months], int, ofstream&);

int main ()
{
    float yearlysales, averagesales;
    
    ifstream salesfile ("sales2014.txt");
    ofstream report ("salesreport.txt");

    if (!salesfile)
    {
        cout << "Error! The file cannot be opened";
    }
    else
    {
        readFile (salesfile, report);
    }

    salesfile.close();
    report.close ();

    system ("pause");

    return 0;
}

void readFile (ifstream& salesfile, ofstream& report)
{
    float salespermonth [stores][months];
    string branchstore [stores];

    for (int i=0; i<stores; i++)
    {
        for (int j=0; j<months; j++)
        {
            salesfile >> salespermonth [i][j]; 
        }

        getline (salesfile, branchstore[i]);
    }

    grandTotalSales (salespermonth, 5, report);

    highestSale (branchstore, 5, salespermonth, 5, report);

    lowestSale (branchstore, 5, salespermonth, 5, report);

    totmonthsales (salespermonth, 5, report);

    totstoresales (branchstore, 5, salespermonth, 5, report);

    profitstore (branchstore, 5, salespermonth, 5, report);
}

void grandTotalSales (float salespermonth [][months], int rows, ofstream& report)
{
    float annualsales = 0, averagesales;

    for (int index=0; index<stores; index++)
    {
        for (int count=0; count<months; count++)
        {
            annualsales += salespermonth[index][count];
        }
    }

    annualsales *= 1000;

    averagesales = annualsales/12;

    report << fixed << setprecision (2);
    report << "total of sales over all stores: RM " << annualsales << endl;
    report << "Average sales per month: RM " << averagesales << endl << endl;
}

void highestSale (string branchstore[], int size, float salespermonth[][months], int rows, ofstream& report)
{
    float monthsale = 0, highest = 0;
    string higheststore, highestmonth;

    for (int a=0; a<stores; a++)
    {
        for (int b=0; b<months; b++)
        {
            if (salespermonth [a][b] > highest)
            {
                highest = salespermonth [a][b];
                higheststore = branchstore[a];

                if (b==0)
                    highestmonth = "Jan";
                if (b==1)
                    highestmonth = "Feb";
                if (b==2)
                    highestmonth = "Mar";
                if (b==3)
                    highestmonth = "Apr";
                if (b==4)
                    highestmonth = "May";
                if (b==5)
                    highestmonth = "Jun";
                if (b==6)
                    highestmonth = "Jul";
                if (b==7)
                    highestmonth = "Aug";
                if (b==8)
                    highestmonth = "Sep";
                if (b==9)
                    highestmonth = "Oct";
                if (b==10)
                    highestmonth = "Nov";
                if (b==11)
                    highestmonth = "Dec";
            }
            else
                continue;
        }
    }

    report << "The highest sales:" << endl;
    report << "------------------" << endl;
    report << "Store:" << higheststore << endl;
    report << "Month: " << highestmonth << endl;
    report << "Sales: " << setw(10) << highest*1000 << endl << endl;
}

void lowestSale (string branchstore[], int size, float salespermonth[][months], int rows, ofstream& report)
{
    float monthsales = 0, lowest = 100;
    string loweststore, lowestmonth;

    for (int a=0; a<stores; a++)
    {
        for (int b=0; b<months; b++)
        {
            if (salespermonth [a][b] < lowest)
            {
                lowest = salespermonth [a][b];
                loweststore = branchstore[a];

                if (b==0)
                    lowestmonth = "Jan";
                if (b==1)
                    lowestmonth = "Feb";
                if (b==2)
                    lowestmonth = "Mar";
                if (b==3)
                    lowestmonth = "Apr";
                if (b==4)
                    lowestmonth = "May";
                if (b==5)
                    lowestmonth = "Jun";
                if (b==6)
                    lowestmonth = "Jul";
                if (b==7)
                    lowestmonth = "Aug";
                if (b==8)
                    lowestmonth = "Sep";
                if (b==9)
                    lowestmonth = "Oct";
                if (b==10)
                    lowestmonth = "Nov";
                if (b==11)
                    lowestmonth = "Dec";
            }
            else
                continue;
        }
    }

    report << "The lowest sales:" << endl;
    report << "------------------" << endl;
    report << "Store:" << loweststore << endl;
    report << "Month: " << lowestmonth << endl;
    report << "Sales: " << setw (10) << lowest*1000 << endl << endl;
}

void totmonthsales (float salespermonth [][months], int rows, ofstream& report)
{
    float sales = 0;

    report << endl << "Total sales by month:" << endl;
    report << "Month" << setw (15) << "Sales" << endl;
    report << "-----" << setw (15) << "-----" << endl;

    for (int z=0; z<months; z++)
    {
        for (int h=0; h<stores; h++)
        {
            sales += salespermonth [h][z];
        }

        if (z==0)
            report << "Jan     RM" << setw (10) << sales*1000 << endl;
        if (z==1)
            report << "Feb     RM" << setw (10) << sales*1000 << endl;
        if (z==2)
            report << "Mar     RM" << setw (10) << sales*1000 << endl;
        if (z==3)
            report << "Apr     RM" << setw (10) << sales*1000 << endl;
        if (z==4)
            report << "May     RM" << setw (10) << sales*1000 << endl;
        if (z==5)
            report << "Jun     RM" << setw (10) << sales*1000 << endl;
        if (z==6)
            report << "Jul     RM" << setw (10) << sales*1000 << endl;
        if (z==7)
            report << "Aug     RM" << setw (10) << sales*1000 << endl;
        if (z==8)
            report << "Sep     RM" << setw (10) << sales*1000 << endl;
        if (z==9)
            report << "Oct     RM" << setw (10) << sales*1000 << endl;
        if (z==10)
            report << "Nov     RM" << setw (10) << sales*1000 << endl;
        if (z==11)
            report << "Dec     RM" << setw (10) << sales*1000 << endl;

        sales = 0;
    }
    
}

void totstoresales (string branchstore[], int size, float salespermonth [][months], int rows, ofstream& report)
{
    float storesales = 0;
    
    report << endl << "Total sales by store:" << endl;
    report << "Store" << setw (20) << "Total Sales" << endl;
    report  << "-----" << setw (20) << "-----------" << endl;

    for (int r=0; r<stores; r++)
    {
        for (int u=0; u<months; u++)
        {
            storesales += salespermonth [r][u];
        }

        if (r==0)
            report << branchstore [r] << setw (4) << "RM" << setw (10) << storesales*1000 << endl;
        if (r==1)
            report << branchstore [r] << setw (8) << "RM" << setw (10) << storesales*1000 << endl;
        if (r==2)
            report << branchstore [r] << setw (5) << "RM" << setw (10) << storesales*1000 << endl;
        if (r==3)
            report << branchstore [r] << setw (4) << "RM" << setw (10) << storesales*1000 << endl;
        if (r==4)
            report << branchstore [r] << setw (8) << "RM" << setw (10) << storesales*1000 << endl;

        storesales = 0;
    }
}

void profitstore (string branchstore[], int size, float salespermonth[][months], int rows, ofstream& report)
{
    float total_sales = 0;

    report << endl << "Profitable stores:" << endl;
    report << "-----------------" << endl;

    for (int v=0; v<stores; v++)
    {
        for (int y=0; y<months; y++)
        {
            total_sales += salespermonth [v][y];
        }

        if (total_sales >= 600)
        {
            if (v==0)
                report << branchstore [v] << endl;
            if (v==1)
                report << branchstore [v] << endl;
            if (v==2)
                report << branchstore [v] << endl;
            if (v==3)
                report << branchstore [v] << endl;
            if (v==4)
                report << branchstore [v] << endl;
        }

        total_sales = 0;
    }
}