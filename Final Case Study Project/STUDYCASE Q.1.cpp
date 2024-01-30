#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
//MUHAMMAD AFIQ DANISH BIN MOHD HAZNI A23CS0118
//AHMAD ZIYAAD BIN MOHD ABBAS A23CS0206
//AFIF SHAQIR IRFAN BIN ARQAM A23CS0204
// MUHAMMAD SYAHMI FARIS BIN RUSLI A23CS0138

const int typeofcereal=4;
string listofcereal[typeofcereal];
float listofcarb[typeofcereal];
float listofprotein[typeofcereal];
float listoffat[typeofcereal];
float carbgram[typeofcereal];
float proteingram[typeofcereal];
float fatgram[typeofcereal];
float dvcarb[typeofcereal];
float dvprotein[typeofcereal];
float dvfat[typeofcereal];
float sumofcarb=0;
float sumofprotein=0;
float sumoffat=0;
float avgdvcarb;
float avgdvprotein;
float avgdvfat;
string condavgcarb;
string condavgprotein;
string condavgfat;
string condcarb[typeofcereal];
string condprotein[typeofcereal];
string condfat[typeofcereal];
int numread=0;



void readfile()
{
	ifstream ounce;
	ounce.open("cereal.txt");
	
	if (!"cereal.txt"){
		cout<<"While opening a file an error is encountered"<<endl;
	}
	
	for(numread=0;numread<typeofcereal;numread++)
	{
		ounce>>listofcereal[numread]>>listofcarb[numread]>>listofprotein[numread]>>listoffat[numread];
	}
	ounce.close();
}

void calconvert()
{
	for(numread=0;numread<typeofcereal;numread++)
	{
		carbgram[numread]=(listofcarb[numread])*(28.35);
		proteingram[numread]=(listofprotein[numread])*(28.35);
		fatgram[numread]=(listoffat[numread])*(28.35);
	}
}
void calDV()
{
		for(numread=0;numread<typeofcereal;numread++)
	{
		dvcarb[numread]=(carbgram[numread])/(300.0)*(100.0);
		dvprotein[numread]=(proteingram[numread])/(50.0)*(100.0);
		dvfat[numread]=(fatgram[numread])/(65.0)*(100.0);
	}
}
void category(){
	for(numread=0;numread<typeofcereal;numread++)
	{
		if(dvcarb[numread]<=5)
		condcarb[numread]="(low)     ";
		else if((dvcarb[numread]>5)&&(dvcarb[numread]<20))
		condcarb[numread]="(moderate)";
		else
		condcarb[numread]="(high)    ";
		
		if(dvprotein[numread]<=5)
		condprotein[numread]="(low)     ";
		else if((dvprotein[numread]>5)&&(dvprotein[numread]<20))
		condprotein[numread]="(moderate)";
		else
		condprotein[numread]="(high)    ";
		
		if(dvfat[numread]<=5)
		condfat[numread]="(low)     ";
		else if((dvfat[numread]>5)&&(dvfat[numread]<20))
		condfat[numread]="(moderate)";
		else
		condfat[numread]="(high)    ";
     } 
}

void calcaverage()
{
	for(numread=0;numread<typeofcereal;numread++)
	{
		sumofcarb+=dvcarb[numread];
	}
	avgdvcarb=(sumofcarb/4.0);
	
		if(avgdvcarb<=5)
		condavgcarb="(low)";
		else if((avgdvcarb>5)&&(avgdvcarb<20))
		condavgcarb="(moderate)";
		else
		condavgcarb="(high)";
	
	for(numread=0;numread<typeofcereal;numread++)
	{
		sumofprotein+=dvprotein[numread];
	}
	avgdvprotein=(sumofprotein/4.0);
	
		if(avgdvprotein<=5)
		condavgprotein="(low)";
		else if((avgdvprotein>5)&&(avgdvprotein<20))
		condavgprotein="(moderate)";
		else
		condavgprotein="(high)";
		
	for(numread=0;numread<typeofcereal;numread++)
	{
		sumoffat+=dvfat[numread];
	}
	avgdvfat=(sumoffat/4.0);
	
		if(avgdvfat<=5)
		condavgfat="(low)";
		else if((avgdvfat>5)&&(avgdvfat<20))
		condavgfat="(moderate)";
		else
		condavgfat="(high)";
}

void screen(){
	
	ofstream content;
	content.open("content.txt");
	
	content<<"Type    		  Carbohydrate		    Protein	       Fat   \n";
	content<<"========		  ============		    =======            ===   \n";
	for(numread=0;numread<typeofcereal;numread++)
	{
	content<<fixed<<setprecision(1)<<left<<setw(25)<<listofcereal[numread]<<right<<setw(5)<<dvcarb[numread]<<"%"<<condcarb[numread]<<right<<setw(15)<<dvprotein[numread]<<"%"<<condprotein[numread]<<right<<setw(8)<<dvfat[numread]<<"%"<<condfat[numread]<<"\n\n";
    }
    
    content<<"The four cereal types produce an average %DV of: \n";
    content<<"Carbohydrate : "<<static_cast<int>(avgdvcarb)<<"% "<<condavgcarb<<"\n";
    content<<"Protein      : "<<static_cast<int>(avgdvprotein)<<"% "<<condavgprotein<<"\n";
    content<<"Fat          : "<<static_cast<int>(avgdvfat)<<"% "<<condavgfat;
	content.close();	
}

int main()
{
readfile();
calconvert();
calDV();
category();
calcaverage();
screen();
int choice1,choice2;
char yn;
string type,carbohydrate,protein,fat;
string level,low,moderate,high;

do{
	cout<<"\t1. Carbohydrate"<<endl<<"\t2. Protein"<<endl<<"\t3. Fat"<<endl;
	cout<<"\nPlease enter your choice>>";
	cin>>choice1;
	if(choice1==1)
	  type="carbohydrate";
	else if(choice1==2)
	  type="protein";
	else if(choice1==3)
	  type="fat";
	
	cout<<endl;
	cout<<"\t1. Low"<<endl<<"\t2. Moderate"<<endl<<"\t3. High"<<endl;
	cout<<"\nPlease enter your choice>>";
	cin>>choice2;
	if(choice1==1)
	  level="low";
	else if(choice1==2)
	  level="moderate";
	else if(choice1==3)
	  level="high";
	
	cout<<endl;
	
	cout<<"List of cereal(s) with ";
	cout<<level;
	cout<<" amount of ";
	cout<<type;
	cout<<":";
	cout<<endl;
	
	//carbohydarte
	if (choice1==1&& choice2==1)
	   cout<<"1. Cereal B";
	else if(choice1==1 && choice2==2)
	   cout<<"1. Cereal D";
	else if(choice1==1 && choice2==3)
	   cout<<"1. Cereal A"<<endl<<"2. Cereal C";
	   
	//protein
	if(choice1==2 && choice2==1)
	   cout<<"n/a";
	else if(choice1==2 && choice2==2)
	   cout<<"1. Cereal A"<<endl<<"2. Cereal C";
	else if(choice1==2 && choice2==3)
	   cout<<"1. Cereal B"<<endl<<"2. Cereal D";
	   
	//fat
	if(choice1==3 && choice2==1)
	   cout<<"1. Cereal B";
	else if(choice1==3 && choice2==2)
	   cout<<"1. Cereal A"<<endl<<"2. Cereal D";
	else if(choice1==3 && choice2==3)
	   cout<<"1. Cereal C";
	  
	  
    cout<<endl;	
	cout<<"\n\nChoose again? Y/N >>";
	cin>>yn;
}while (yn!='N');
return 0;
}


