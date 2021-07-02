#include<iostream>
#include<cmath>
using namespace std;
//2路归并排序，递归做法
//稳定排序
class MergeSort
{
private:
	int* item;  //需要排序的数组
	int* temp;  //临时数组
	int* item1;  //合并函数所使用的临时数组
	int len;  //需要排序的数组长度
	int k;
	int p;  //2路归并排序次数
	//2路归并排序函数
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//左边归并排序，使得左子序列有序
			sort(mid + 1, right);//右边归并排序，使得右子序列有序
			merge(left, mid, right);
		}
		p++;
	}
	//归并函数
	void merge(int left, int mid, int right)
	{
		int i = left;//左序列指针
		int j = mid + 1;//右序列指针
		int t = 0;//临时数组指针
		while (i <= mid && j <= right)
		{
			if (item[i] < item[j])
			{
				temp[t] = item[i];
				t++;
				i++;
			}
			else
			{
				temp[t] = item[j];
				t++;
				j++;
			}
		}
		while (i <= mid)
		{
			//将左子序列剩余元素填入temp中
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= right)
		{
			//将右子序列剩余元素填入temp中
			temp[t] = item[j];
			t++;
			j++;
		}
		//将temp中的元素全部拷贝到原数组中
		t = 0;
		while (left <= right)
		{
			item[left] = temp[t];
			t++;
			left++;
		}
	}
	//判断a是否为整数
	bool IsInteger(double a)
	{
		if (a - (int)a == 0)
			return true;
		else
			return false;
	}
	//选择排序函数
	void SelectSort(int* arr, int n)
	{
		int min;
		for (int i = 0; i < n; i++)
		{
			min = i;
			for (int k = i + 1; k < n; k++)
			{
				if (arr[k] < arr[min])
				{
					min = k;
				}
			}

			int m = arr[i];
			arr[i] = arr[min];
			arr[min] = m;
		}
	}
public:
	//合并函数
	MergeSort(int* str, int n)
	{
		p = 0;
		item = str;
		len = n;
		item1 = new int[len];
		for (int i = 0; i < len; i++)
		{
			item1[i] = str[i];
		}
		temp = new int[len];
		if (IsInteger(log2(len)))
			k = (int)log2(len) + 1;
		else
			k = (int)log2(len) + 2;
		sort(0, len - 1);
		cout << p << endl;
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};