#include<iostream>
using namespace std;
//直接插入排序
//稳定排序
void StraightInsertSort(int* item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k - 1])
			{
				int m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}

		//每趟排序后输出一次结果
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}