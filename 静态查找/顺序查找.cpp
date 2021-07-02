#include<iostream>
using namespace std;
//带哨兵的顺序查找函数
//查找成功则返回元素在数组中的位置
//查找失败则返回0
int Sequential_Search(int* item, int n, int key)
{
	int i = n;
	item[0] = key;

	while (item[i] != key)
		i--;

	return i;
}