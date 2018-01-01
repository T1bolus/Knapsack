#pragma once

#include <vector>
using std::vector;

class Knapsack
{
public:
	Knapsack(int capacity, int n, vector<int> &weights, vector<int> &use) : g(capacity), n(n), a(weights), w(use) {}
	void calc();
	int **getW();
	vector<int> **getR();
 
private:
	int g;
	int n;
	vector<int> a;
	vector<int> w;

	int **W;
	vector<int> **R;
};


void Knapsack::calc()
{
	W = new int*[n + 2];
	for (size_t i = 0; i <= n; i++)
	{
		W[i] = new int[g + 2];
	}

	R = new vector<int>*[n + 2];
	for (size_t i = 0; i <= n; i++)
	{
		R[i] = new vector<int>[g + 2];
	}

	for (int j = 0; j <= g; j++) 
	{ 
		//R[0][j] = 0; //Vector ist immer am Anfang leer
		W[0][j] = 0;
	}

	for (int k = 1; k <= n; k++) 
	{
		for (int j = 0; j <= g; j++) 
		{
			if ((a[k] <= j) &&
				(W[k - 1][j] < W[k - 1][j - a[k]] + w[k])) 
			{
				/* Verbesserung durch Hinzunahme von k */
				R[k][j] = R[k - 1][j - a[k]];
				R[k][j].push_back(k); //Adde k zum vector hinzu

				W[k][j] = W[k - 1][j - a[k]] + w[k];
			}
			else 
			{
				/* keine Verbesserung durch k */
				R[k][j] = R[k - 1][j];
				W[k][j] = W[k - 1][j];
			}
		}
	}
}

inline int ** Knapsack::getW()
{
	return W;
}


inline vector<int>** Knapsack::getR()
{
	return R;
}