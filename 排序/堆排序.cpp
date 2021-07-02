#include<iostream>
using namespace std;
//堆排序
//不稳定排序
class HeapSort
{
private:
	int* item;  //数组指针
	int len;    //数组长度
public:
	HeapSort(int n)
	{
		len = n;
		item = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> item[i];
		}
	}
	void sort()
	{
		//构建小堆顶
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			//从最后一个非叶子结点开始，从下至上，从左至右调整结构
			adjustHeap(i, len);
		}
		display();
		//将堆顶元素和末尾元素进行交换，然后再重新对堆进行调整
		for (int j = len - 1; j > 0; j--)
		{
			swap(0, j);      //将堆顶元素和末尾元素进行交换
			adjustHeap(0, j);  //重新对堆进行调整
			display();
		}
	}
	void adjustHeap(int i, int length)
	{
		int temp = item[i];  //先取出当前元素
		for (int k = i * 2 + 1; k < length; k = k * 2 + 1)
		{
			if (k + 1 < length && item[k] > item[k + 1])//从i结点的左子结点开始，也就是2i+1处开始
			{
				//如果右结点存在，且左结点大于右结点，那么k指向右结点
				k++;
			}
			if (item[k] < temp)
			{
				//如果子节点小于父节点，将子节点值赋给父节点
				item[i] = item[k];
				i = k;
			}
		}
		item[i] = temp;
	}
	void swap(int a, int b)
	{
		int m = item[a];
		item[a] = item[b];
		item[b] = m;
	}
	void display()
	{
		cout << len << " ";
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};