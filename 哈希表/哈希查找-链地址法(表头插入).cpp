#include<iostream>
using namespace std;
class hash_node
{
public:
	int data;   //结点数据
	int order;
	hash_node* next;
	hash_node()
	{
		data = -1;
		order = 1;
		next = NULL;
	}
};
//以求余法为哈希函数
//哈希冲突用链地址法(表头插入)
class hash_map
{
private:
	hash_node* hashmap;   //哈希结点数组
public:
	hash_map(int n)
	{
		hashmap = new hash_node[n];
		int a;
		int key;
		while (n--)
		{
			cin >> a;
			key = a % 11;
			if (hashmap[key].data != -1)
			{
				hash_insert(&hashmap[key], a);
			}
			else
				hashmap[key].data = a;
		}
	}
	//递归查找哈希冲突
	int find_next(hash_node* hash, int target)
	{
		if (hash != NULL)
		{
			if (hash->data != target)
				return find_next(hash->next, target);
			else
				return hash->order;
		}
		else
			return 0;
	}
	//哈希查找函数
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		if (hashmap[key].data != target)
		{
			if (find_next(hashmap[key].next, target) != 0)
			{
				cout << key << " " << find_next(hashmap[key].next, target) << endl;
			}
			else
			{
				//查找失败，将数据插入到哈希表中
				hash_insert(&hashmap[key], target);
				cout << "error" << endl;
			}
		}
		else
		{
			cout << key << " " << hashmap[key].order << endl;
		}
	}
	//哈希插入函数
	//将数据target插人到哈希表中，哈希冲突用链地址法(表头插入)
	void hash_insert(hash_node* hash, int target)
	{
		if (hash->data == -1)
		{
			hash->data = target;
			return;
		}
		else
		{
			if (hash->next != NULL)
			{
				hash_insert(hash->next, target);
				hash->order++;
			}
			else
			{
				hash_node* h = new hash_node();
				h->data = target;
				hash->order++;
				hash->next = h;
			}
		}
	}
};