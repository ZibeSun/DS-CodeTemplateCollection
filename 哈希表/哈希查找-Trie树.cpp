#include<iostream>
#include<string>
#include<queue>
using namespace std;
//Trie树结点类
class TrieTreeNode
{
public:
	string word;  //结点字符
	int num;    // 有多少单词通过这个节点,即由根至该节点组成的字符串模式出现的次数
	bool isEnd; // 是不是最后一个节点
	TrieTreeNode** Nextword = new TrieTreeNode * [26];
	TrieTreeNode()
	{
		num = 0;
		isEnd = false;
		for (int i = 0; i < 26; i++)
		{
			Nextword[i] = NULL;
		}
	}
	//~TrieTreeNode();
};

//Trie树类
class TrieTree
{
private:
	TrieTreeNode* Root;   //根节点指针
public:
	TrieTree();
	//~TrieTree();
	void insert(string str); //在字典树中插入一个单词
	int find(string str);   //在字典树中查找以该字符串为公共前缀的单词数
	void show();            //层次遍历字典树
};
TrieTree::TrieTree()
{
	Root = new TrieTreeNode();
}
//在字典树中插入一个单词
void TrieTree::insert(string str)
{
	if (str == "" || str.length() == 0)
	{
		return;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//如果当前节点的儿子节点中没有该字符，则构建一个TrieTrieTreeNode并复值该字符
		if (T->Nextword[pos] == NULL)
		{
			T->Nextword[pos] = new TrieTreeNode();
			T->Nextword[pos]->word = str[i];
			T->Nextword[pos]->num++;
		}
		//如果已经存在，则将由根至该儿子节点组成的字符串模式出现的次数+1
		else
		{
			T->Nextword[pos]->num++;
		}
		T = T->Nextword[pos];
	}
	T->isEnd = true;
}
//在字典树中查找以该字符串为公共前缀的单词数
int TrieTree::find(string str)
{
	if (str == "" || str.length() == 0)
	{
		return 0;
	}
	TrieTreeNode* T = Root;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		//如果当前节点的儿子节点中没有该字符，则构建一个TrieTrieTreeNode并复值该字符
		if (T->Nextword[pos] != NULL)
		{
			T = T->Nextword[pos];
		}
		//如果已经存在，则将由根至该儿子节点组成的字符串模式出现的次数+1
		else
		{
			return 0;
		}
	}
	return T->num;
}
//层次遍历字典树
void TrieTree::show()
{
	if (!Root) return;
	deque<TrieTreeNode*> q;
	q.push_back(Root);
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			TrieTreeNode* tp = q.front(); q.pop_front();
			cout << tp->word;
			for (int i = 0; i < 26; i++)
				if (tp->Nextword[i]) q.push_back(tp->Nextword[i]);
		}
	}
	cout << endl;
}