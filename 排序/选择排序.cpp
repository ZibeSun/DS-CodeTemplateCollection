#include<iostream>
using namespace std;
//—°‘Ò≈≈–Ú
//≤ªŒ»∂®≈≈–Ú
void SelectSort(int* item, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int k = i + 1; k < n; k++)
		{
			if (item[k] < item[min])
			{
				min = k;
			}
		}

		int m = item[i];
		item[i] = item[min];
		item[min] = m;

		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}