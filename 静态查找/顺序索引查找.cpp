#include<iostream>
using namespace std;
//顺序索引查找类
class Sequential_Index_Search
{
private:
	int n;    //主表长度
	int k;    //主表划分出的块数
	int* item;//主表
	int* maxkey_index;//最大关键字索引表
	int* StartPosition_index;//最大关键字起始位置索引表
public:
	//构造函数
	Sequential_Index_Search(int n1, int k1, int* item1, int* a)
	{
		n = n1;
		k = k1;
		item = item1;
		maxkey_index = a;
		StartPosition_index = new int[k];
		int p = 1;
		for (int i = 0; i < k; i++)
		{
			StartPosition_index[i] = p + i * (n / k);
		}
	}
	//顺序索引查找
	int Search(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
						return j;
				}
				return 0;
			}
		}
		return 0;
	}
	//输出带查找次数的顺序索引查找
	void Search_times(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
					{
						//(j - spi + 1)表示在块内查找的次数
						//(i + 1)表示在块间查找的次数
						cout << j << "-" << (j - spi + 1) + (i + 1) << endl;
						return;
					}
				}
				cout << "error" << endl;
				return;
			}
		}
		cout << "error" << endl;
	}
};