#include<iostream>
using namespace std;
//希尔排序
//不稳定排序
void ShellSort(int* item, int n)
{
	int gap = n / 2;
	while (gap >= 1)
	{
		int t = gap;
		int pos = 0;
		while (t--)
		{
			for (int i = pos; i < n; i += gap)
			{
				for (int k = pos; k < n - gap; k += gap)
				{
					if (item[k] <= item[k + gap])
					{
						int m = item[k];
						item[k] = item[k + gap];
						item[k + gap] = m;
					}
				}
			}
			pos++;
		}

		//每趟排序完输出一次结果
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;

		gap = gap / 2;
	}
}