#include<iostream>
using namespace std;
void get_next(string t, int* next)
{
	int i = 0, j = -1;
	next[i] = j;
	while (i < (int)t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
//kmp算法，查找成功则返回起始位置，查找失败则返回-1
int KMP(string str, string t)
{
	int i = 0, j = 0;
	int* next = new int[t.length() + 1];
	get_next(t, next);
	while (i < (int)str.length() && j < (int)t.length())
	{
		if (j == -1 || str[i] == t[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j == (int)t.length())
	{
		return i - j;
	}
	else
		return -1;
}