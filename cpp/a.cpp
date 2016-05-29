#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
	ifstream ifile("a.in", ios::in);
	ofstream ofile("a.out", ios::out | ios::trunc);
	char s[10];
	int n= 0, count=0;

	while (!ifile.eof()) 
	{
		ifile.get(s, 10);
	}
	for(int i=0; i<10; i++)
	{
		if(s[i] == '\0')
		{
			break;
		}
		count++;
	}
	int c = count-1;
	for(int j=0; j<count; j++)
	{
		int num = 1;
		for(int k=0; k<c; k++)
		{
			num *= 10;
		}
		c--;
		n += ((int)s[j]-48) * num;
	}
	
	count=0;
	char res[6] = {'\0'};
	if(n % 3 == 0)
	{
		count++;
		res[0] = '3';
		res[1] = '\0';
	}
	if(n % 5 == 0)
	{
		count++;
		if(count == 2)
		{
			res[1] = ' ';
			res[2] = '5';
			res[3] = '\0';
		}
		else
		{
			res[0] = '5';
			res[1] = '\0';
		}
	}
	if(n % 7 == 0)
	{
		count++;
		if(count == 3)
		{
			res[3] = ' ';
			res[4] = '7';
			res[5] = '\0';
		}
		else if(count == 2)
		{
			res[1] = ' ';
			res[2] = '7';
			res[3] = '\0';
		}
		else
		{
			res[0] = '7';
			res[1] = '\0';
		}
	}
	ofile << res;
	return 0;
}
