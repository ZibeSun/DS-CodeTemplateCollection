#include<iostream>
using namespace std;
//折半查找函数
//查找成功则返回元素在数组中的位置
//查找失败则返回0
int Binary_Search(int* item, int n, int key)
{
	int low = 1;
	int high = n;
	int mid = (n + 1) / 2;
	while (low <= high)
	{
		if (key < item[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if (key > item[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if (key == item[mid])
		{
			return mid;
		}
	}
	return 0;
}