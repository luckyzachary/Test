#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
	char buffer[256];
	ifstream ifile("itest.txt", ios::in);
	ofstream ofile("otest.txt", ios::out | ios::trunc);
	ofstream ofile1("otest1.txt", ios::out | ios::trunc);
	while (!ifile.eof()) 
	{
		ifile.getline(buffer,100);
		ofile << buffer << endl;
	}
	while(!ifile.eof())
	{	
		char* read;
		ifile.getline(read, 100, ' ');
		ofile1 << read << endl;
	}
	return 0;
}