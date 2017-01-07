//Tiago Moore

//loop.cpp

// this program prompts the user for a number n and returns the sum of the values from 1  to n.

#include<iostream>
using namespace std;

int main()
	
{
	int n = 0, sum = 0;

	cout<<"Enter a number: ";
	cin>>n;

	for (int i = 1;i<=n;i++)
	{
	sum += i;
 
	}
		cout<<"The sum is "<<sum<<endl;

	return 0;

}

