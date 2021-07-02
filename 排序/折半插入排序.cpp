#include<iostream>
using namespace std;
//’€∞Î≤Â»Î≈≈–Ú
//Œ»∂®≈≈–Ú
void BinaryInsertSort(int* item, int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		temp = item[i];
		int low = 0;
		int high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp > item[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		int j;
		for (j = i - 1; j >= high + 1; j--)
			item[j + 1] = item[j];
		item[j + 1] = temp;

		for (int k = 0; k < n; k++)
		{
			cout << item[k] << " ";
		}
		cout << endl;
	}
}