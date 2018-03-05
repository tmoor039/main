//This program will write the following data to a file text called football.txt

#include<fstream>


using namespace std;
int main()
{

//Declare file pointer for output
	ofstream outfile;

	outfile.open("football.txt",ios::out); 

//write data to file

	outfile<<"Eli Manning\n12940475\n31\nNew York Giants\nQuarterback\n";

//close file
	outfile.close();

return 0;
}


