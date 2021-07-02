#include<iostream>
#include<stdio.h>
using namespace std;
//顺序表
class SeqList
{
private:
	int* list;   //数组
	int maxsize;   //最大表长
	int size;      //当前表长
public:
	SeqList();
	~SeqList();
	void list_int(int n);  //输入n个数，并依次存入顺序表中从0开始的位置
	int list_size();   //计算并返回当前顺序表的表长
	void list_insert(int i, int item);  //把item插入到顺序表的第i个位置
	void list_del(int i);  //删除顺序表中第i个数据
	void list_get(int i);  //打印顺序表中第i个数据
	void list_display();   //打印整个顺序表中的内容
	//插入多个数据的list_multiinsert函数，实现在第i个位置，连续插入来自数组item的n个数据。
	//即从位置i开始插入多个数据。
	void list_multiinsert(int i, int n, int* item); 
	//删除多个数据的list_multidel函数，实现从第i个位置开始，连续删除n个数据。
	//即从位置i开始删除多个数据。
	void list_multidel(int i, int n);
	void list_sort();  //顺序表排序函数
	int* list_getlist();  //返回数组指针，与list_combine函数配合
	int list_getsize();   //返回数组长度，与list_combine函数配合
	SeqList list_combine(SeqList& a, SeqList& b);  //合并两个顺序表
	void list_move(int d, int n);  //顺序表循环移位函数
};
//构造函数
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
//析构函数
SeqList::~SeqList()
{
	delete[]list;
}
//输入n个数，并依次存入顺序表中从0开始的位置
void SeqList::list_int(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	size = n;
}
//计算并返回当前顺序表的表长
int SeqList::list_size()
{
	for (int i = 0; i < 1000; i++)
	{
		if (list[i] == '\0')
			size = i + 1;
	}
	return size;
}
//把item插入到顺序表的第i个位置
void SeqList::list_insert(int i, int item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size; k >= i; k--)
		{
			list[k] = list[k - 1];
		}
		list[i - 1] = item;
		size++;
		list_display();
	}
	else
		cout << "error" << endl;
}
//删除顺序表中第i个数据
void SeqList::list_del(int i)
{
	if ((i > 0) && (i <= size))
	{
		size--;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + 1];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
//打印顺序表中第i个数据
void SeqList::list_get(int i)
{
	if ((i > 0) && (i <= size))
		cout << list[i - 1] << endl;
	else
		cout << "error" << endl;
}
//打印整个顺序表中的内容
void SeqList::list_display()
{
	//先打印顺序表的表长
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
//插入多个数据的list_multiinsert函数，实现在第i个位置，连续插入来自数组item的n个数据。
//即从位置i开始插入多个数据。
void SeqList::list_multiinsert(int i, int n, int* item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size + n - 1; k > i; k--)
		{
			list[k] = list[k - n];
		}
		for (int k = i - 1; k < i - 1 + n; k++)
		{
			list[k] = item[k - i + 1];
		}
		size += n;
		list_display();
	}
	else
		cout << "error" << endl;
}
//删除多个数据的list_multidel函数，实现从第i个位置开始，连续删除n个数据。
//即从位置i开始删除多个数据。
void SeqList::list_multidel(int i, int n)
{
	if ((i > 0) && (i <= size))
	{
		size -= n;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + n];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
//顺序表排序函数
void SeqList::list_sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				int mid;
				mid = list[i];
				list[i] = list[i + 1];
				list[i + 1] = mid;
			}
		}
	}
}
//返回数组指针，与list_combine函数配合
int* SeqList::list_getlist()
{
	return list;
}
//返回数组长度，与list_combine函数配合
int SeqList::list_getsize()
{
	list_size();
	return size;
}
//合并两个顺序表
SeqList SeqList::list_combine(SeqList& a, SeqList& b)
{
	SeqList sum;
	sum.list_multiinsert(0, a.list_getsize(), a.list_getlist());
	sum.list_multiinsert(1, b.list_getsize(), b.list_getlist());
	sum.list_sort();
	sum.list_display();
	return sum;
}
//顺序表循环移位函数
void SeqList::list_move(int d, int n)
{
	int* nlist = new int[size];
	if (d == 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i - n < 0)
			{
				nlist[i - n + size] = list[i];
			}
			else
			{
				nlist[i - n] = list[i];
			}
		}
	}
	else if (d == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (i + n > size - 1)
			{
				nlist[i + n - size] = list[i];
			}
			else
			{
				nlist[i + n] = list[i];
			}
		}
	}
	list = nlist;
}