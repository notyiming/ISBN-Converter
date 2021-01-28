#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void main()
{
	ifstream readin;
	ofstream printout;
	readin.open("ISBN BOOKS.txt", ios::in);
	printout.open("ISBN13 RESULTS.txt", ios::out);
	if (readin.fail())
	{
		cerr << "File Not Found!";
		_getch();
		exit(-1);
	}
	string front;
	int B[4], ISBN10[10], ISBN13[13], remainder, count=0, invalidcount=0, sum10, sum13, i=0;
	printout << "------------------------------------------------------------------------\n";
	printout << "No	|	ISBN-10 number		|	ISBN-13 number\n";
	printout << "------------------------------------------------------------------------\n";

	while (!readin.eof())
	{
		sum10 = 0, sum13 = 0;
		count++;
		readin >> front >> B[0] >> B[1] >> B[2] >> B[3];
		ISBN10[0] = B[0] / 100;
		remainder = B[0] % 100;
		ISBN10[1] = remainder / 10;
		ISBN10[2] = remainder % 10;
		ISBN10[3] = B[1] / 10000;
		remainder = B[1] % 10000;
		ISBN10[4] = remainder / 1000;
		remainder = remainder % 1000;
		ISBN10[5] = remainder / 100;
		remainder = remainder % 100;
		ISBN10[6] = remainder / 10;
		ISBN10[7] = remainder % 10;
		ISBN10[8] = B[2];
		ISBN10[9] = B[3];
		for (i = 0; i < 10; i++)
			sum10 += (ISBN10[i] * (10 - i));
		printout << count << "\t" << "|\t" << front << " ";
		for (i = 0; i < 3; i++)printout << ISBN10[i];
		printout << " ";
		for (i = 3; i < 8; i++)printout << ISBN10[i];
		printout << " " << ISBN10[8]<<" "<<ISBN10[9]<<"\t|\t";

		if (sum10 % 11 == 0)
		{
			printout << front << " ";
			//1st 3 numbers
			ISBN13[0] = 9;
			ISBN13[1] = 7;
			ISBN13[2] = 8;
			for (i = 3; i <= 11; i++) //9 numbers are the same
				ISBN13[i] = ISBN10[i - 3];
			for (i = 0; i < 3; i++)
				printout << ISBN13[i];
			printout << " ";
			for (i = 3; i <= 5; i++)
				printout << ISBN13[i];
			printout << " ";
			for (i = 6; i <= 10; i++)
				printout << ISBN13[i];
			printout << " "<<ISBN13[11]<<" ";
			for (i = 0; i <= 11; i++)
			{
				if (i % 2 == 0) sum13 += ISBN13[i]; 
				else
					sum13 += 3 * ISBN13[i];
			}
			ISBN13[12] = 10 - (sum13 % 10);
			if (ISBN13[12] == 10)
				printout << "0\n";
			else
			printout << ISBN13[12] << endl;
					   			 		  		  		 	   			   
		}
		else
		{
			invalidcount++;
			printout << "Invalid\n";
		}
	}
	printout << "------------------------------------------------------------------------\n";
	printout << count << " book(s) in total\n";
	printout << count - invalidcount << " book(s) successfully converted\n";
	printout << invalidcount << " book(s) invalid\n";
	readin.close();
	cout << "DONE";
	_getch();
}