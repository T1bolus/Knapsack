#include "Functions.h"



#include <iostream>
#include <fstream>

using namespace std;


void out(int **o, int a, int b)
{
	for (size_t i = 1; i < a; i++)
	{
		for (size_t d = 1; d <= b; d++)
		{
			cout << o[i][d] << "\t";
		}
		cout << "\n";
	}
	cout << "-------------------------------------\n";
}


void out(vector<int> **o, int a, int b)
{
	for (size_t i = 1; i < a; i++)
	{
		for (size_t d = 1; d <= b; d++)
		{
			for (size_t z = 0; z < o[i][d].size(); z++)
			{
				cout << o[i][d][z];
				if (z < o[i][d].size() - 1)
					cout << ",";
			}
			cout << "\t";
		}
		cout << "\n";
	}
	cout << "-------------------------------------\n";
}

int main()
{
	int n;
	int anzahlWk;
	int lWk;
	int preis;

	vector<int> gewicht;
	vector<int> nutzen;


	gewicht.push_back(0);
	nutzen.push_back(0);

#define debug 1
	
	ifstream read("test.txt"); 
#define limit 10

	//ifstream read("wunderkerzen.txt");
//#define limit 9000
	
	
	while (!read.eof())
	{
		read >> n;
		read >> anzahlWk;
		read >> lWk; 
		read >> preis;


		for (size_t i = 0; i < n; i++)
		{
			gewicht.push_back(preis);
			nutzen.push_back(anzahlWk * lWk);
		}
	}
	read.close();

	Knapsack sack(limit, gewicht.size() - 2, gewicht, nutzen);
	sack.calc();

	if (debug) out(sack.getR(), gewicht.size() - 1, limit);
	if (debug) out(sack.getW(), gewicht.size() - 1, limit);

	cout << "Max Value: " << sack.getW()[gewicht.size() - 2][limit] << endl;
	cout << "Packets: ";
	for (size_t z = 0; z < sack.getR()[gewicht.size() - 2][limit].size(); z++)
	{
		cout << sack.getR()[gewicht.size() - 2][limit][z];
		if (z < sack.getR()[gewicht.size() - 2][limit].size() - 1)
			cout << ",";
	}
	cout << endl;

	int s = sack.getR()[gewicht.size() - 2][limit].size();
	cout << "Packet Counter: " << s << endl;


	cin.get();
}