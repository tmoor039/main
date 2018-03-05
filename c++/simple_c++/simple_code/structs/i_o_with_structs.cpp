//finalExamReview.cpp
//April 23, 2012
//Reviewed 25 Feb 2018

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

struct Inventory
{
	int itemNumber, itemCount;
	string itemName;
	float itemPrice;
	
	Inventory()
	{
	itemNumber = itemCount = 0;
	itemPrice = 0.0;
	}
};

//return type: void
//parameters: 1 array of Inventory, 1 int by value(n)
//Purpose: This function reads in the data from text file and stores in array.
void ReadInData(Inventory[], int);

//return type: void
//parameters: 1 array of Inventory, 1 int by value(n)
//Purpose: This function displays a formatted chart of data in array
void CreateReport(const Inventory[], int);

//return type: Inventory
//parameters: none
//Purpose: This function prompts for the data for a single Inventory item and returns that value
Inventory GetItem();

//return type: void
//parameters: a single Inventory item by value
//Purpose: This function appends the file "Inventory.txt" with the given item
void AddItemToFile(Inventory);

//return type: float
//parameters:  1 array of Inventory, 1 int by value(n)
//Purpose: This function returns the total cost of the items in the array
float TotalCost(const Inventory[], int);

int main()
{
	//declare an array of Inventory, size 4
	Inventory myInventory[4];
	//declare an instance of Inventory called newItem
	Inventory newItem;
	//declare a total
	float total = 0.0;
	
	//read in data from file
	ReadInData(myInventory,4);
	
	//display the data that was read in
	CreateReport(myInventory, 4);
	
	//prompt for a new Inventory item
	newItem = GetItem();
	
	//add the new item to file
	AddItemToFile(newItem);
	
	//store the total cost in total
	total = TotalCost(myInventory, 4);
	
	cout<<"The total cost of the items = $"<<total<<endl;

 return 0;
}

void ReadInData(Inventory tempArr[], int n)
{
	//declare file pointer for reading
	ifstream infile;
	//open file "Inventory.txt" for reading
	infile.open("Inventory.txt", ios::in);
	for(int i = 0; i < 4; i++)
	{
		infile>>tempArr[i].itemNumber>>tempArr[i].itemName>>tempArr[i].itemCount>>tempArr[i].itemPrice;
	}

	//close file
	infile.close();
}

void CreateReport(const Inventory tempArr[], int n)
{	//display heading
	cout<<"**************************Inventory Report*************************\n";
	cout<<"Item Number\tItem Name\t\tItemCount\tItem Price\n";
	cout<<"---------------------------------------------------------------\n";
	for(int i = 0; i < n; i++)
	{
		cout<<fixed<<showpoint<<setprecision(2);
		cout<<tempArr[i].itemNumber<<"\t\t"<<tempArr[i].itemName<<"\t\t"<<tempArr[i].itemCount<<"\t\t$"<<tempArr[i].itemPrice<<endl;
	}

}

Inventory GetItem()
{
	//declare a local Inventory item
	Inventory tempInv;
	
	//prompt for data
	cout<<"Enter the item number: ";
	cin>>tempInv.itemNumber;
	cout<<"Enter the item name: ";
	cin>>tempInv.itemName;
	cout<<"Enter the item count: ";
	cin>>tempInv.itemCount;
	cout<<"Enter the item price: $";
	cin>>tempInv.itemPrice;

	return tempInv;
}

void AddItemToFile(Inventory tempInv)
{
	//declare a file pointer for output
	ofstream outfile;
	
	//open file for appending
	outfile.open("Inventory.txt", ios::app);
	
	//append the file
	outfile<<tempInv.itemNumber<<"\t"<<tempInv.itemName<<"\t"<<tempInv.itemCount<<"\t"<<tempInv.itemPrice<<endl;

	//close the file
	outfile.close();
}

float TotalCost(const Inventory tempArr[], int n)
{
	//local variable
	float total = 0.0;

	for(int i= 0; i < n; i++)
	{
		total += tempArr[i].itemCount * tempArr[i].itemPrice;
	
	}

	return total;
}
