//This program will write the following data to a file text called football.txt

#include<fstream>


using namespace std;
int main()
{

//Declare file pointer for output
	ofstream outfile;

	outfile.open("football.txt",ios::app); 

//write data to file

	outfile<<"Deion Branch\n3835000\n32\nNew England Patriots\nWide Receiver\n";

//close file
	outfile.close();

return 0;
}


