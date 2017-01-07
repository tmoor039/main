//practice program form class


#include<iostream>
#include<string>
using namespace std;

// declare struct names shirt

struct Shirt
{
	string sleeveType, material, color;

	int size;

	float price;

	Shirt()
	{//contrsuctor

		 size = 0;
		 price = 0.0;
	}

};



Shirt GetShirt();


void DisplayShirts(Shirt[], int);

void CalculateTotals(Shirt[],float &);


const int size = 4;

int main()
{
	//declare variables
	int longsleevesize = 0, shortsleevesize = 0;
	float totalcost = 0;

// declare an array of shirts

Shirt Myshirts[size];

//promt for all values in the array of shirts

for (int i = 0 ; i < size; i ++)
{
	Myshirts[i]= GetShirt();
}

//display shirts
DisplayShirts(Myshirts,size);

//calculate total price of shirts in array

CalculateTotals(Myshirts,totalcost);





cout<<"The total for all the shirts is "<<totalcost<<endl;

cout<<"peace\n\n\n\n";







return 0;
}






Shirt GetShirt()
{
	//declare local shirt
	Shirt tempshirt;
	//promt for values  of the shirt
	cout<<"Enter type: ";
	cin>>tempshirt.sleeveType;
	cout<<"Enter material: ";
	cin>>tempshirt.material;
	cout<<"Enter size: ";
	cin>>tempshirt.size;
	cout<<"Enter price: ";
	cin>>tempshirt.price;
	cout<<"Enter color: ";
	cin>>tempshirt.color;

	return tempshirt;
}



void DisplayShirts(Shirt SampleArr[],int size)
{
	
	for(int i = 0; i < size; i ++)
	{
	cout<<SampleArr[i].material<<"\t"<<SampleArr[i].price<<"\t"<<SampleArr[i].color<<"\t"<<SampleArr[i].sleeveType<<endl;

	}
}


void CalculateTotals(Shirt SampleArr[], float &total)
{

	total = 0;

	for(int i = 0; i < size; i ++)
	{
		total += SampleArr[i].price;
	}


}
	
