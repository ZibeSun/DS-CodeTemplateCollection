#include<iostream>
using namespace std;
class hash_map
{
private:
	int* hashmap;
	int len;

	//哈希插入冲突时递归散列
	//私有函数，类内调用
	void next_insert(int& key, int p)
	{
		key++;
		if (key >= len)
			key = 0;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
			next_insert(key, p);
	}
	//哈希查找冲突时递归散列
	//私有函数，类内调用
	int next_find(int& key, int target, int& num)
	{
		num++;
		key++;
		if (key >= len)
			key = 0;
		if (hashmap[key] < 0)
			return 0;
		else if (hashmap[key] == target)
			return key + 1;
		else
			next_find(key, target, num);
	}
public:
	hash_map(int m)
	{
		len = m;
		hashmap = new int[m];
	}
	//哈希遍历展示函数
	void hash_display()
	{
		for (int i = 0; i < len; i++)
		{
			if (hashmap[i] >= 0)
				cout << hashmap[i] << " ";
			else
			{
				cout << "NULL ";
				//cout << hashmap[i] << " ";
			}
		}
		cout << endl;
	}
	//哈希插入函数
	void hash_insert(int p)
	{
		int key;
		key = p % 11;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
			next_insert(key, p);
	}

	//哈希查找函数
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		int num;  //查找次数
		num = 1;
		if (hashmap[key] < 0)
		{
			cout << 0 << " ";
			cout << num << endl;
		}
		else if (hashmap[key] == target)
		{
			cout << 1 << " ";
			cout << num << " ";
			cout << key + 1 << endl;
		}
		else
		{
			int result = next_find(key, target, num);
			if (result != 0)
			{
				cout << 1 << " ";
				cout << num << " ";
				cout << result << endl;
			}
			else
			{
				cout << 0 << " ";
				cout << num << endl;
			}
		}
	}
};