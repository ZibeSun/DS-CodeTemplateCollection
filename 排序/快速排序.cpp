#include<iostream>
using namespace std;
int getPivotkey(int* item, int low, int high)
{
	int key = item[low];
	while (low < high)
	{
		while (low < high && item[high] >= key)
		{
			high--;
		}
		if (low < high)
		{
			item[low] = item[high];
		}

		while (low < high && item[low] <= key)
		{
			low++;
		}
		if (low < high)
		{
			item[high] = item[low];
		}
	}
	item[low] = key;
	return low;
}
//快速排序
//不稳定排序
void QuickSort(int* item, int low, int high)
{
	if (low <= high)
	{
		int pivotkey = getPivotkey(item, low, high);
		cout << item[pivotkey] << " " << pivotkey + 1 << endl;
		QuickSort(item, low, pivotkey - 1);
		QuickSort(item, pivotkey + 1, high);
	}
}