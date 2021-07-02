#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
//二叉树结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	//构造函数
	BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
	//~BiTreeNode();
};

//二叉树类
class BiTree
{
private:
	BiTreeNode* Root;   //根结点指针
	int pos;
	string strTree;

	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void PostOrder_stack(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void PostOrder_stack();  //后序遍历非递归算法
	void LevelOrder();  //层次遍历
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
}

//定义先序遍历函数
void BiTree::PreOrder() //公有函数，对外接口
{
	PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

//定义中序遍历函数
void BiTree::InOrder()  //公有函数，对外接口
{
	InOrder(Root);
}
void BiTree::InOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		InOrder(t->LeftChild);
		cout << t->data;
		InOrder(t->RightChild);
	}
	else
		return;
}

//定义后序遍历函数
void BiTree::PostOrder()  //公有函数，对外接口
{
	PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout << t->data;
	}
	else
		return;
}

//构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray) //公有函数，对外接口
{
	pos = 0;
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
//递归建树，私有函数，类内实现
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c;
	c = strTree[pos++];
	if (c == '0')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //生成根结点
		T->LeftChild = CreateBiTree();    //构造左子树
		T->RightChild = CreateBiTree();   //构造右子树
	}
	return T;
}

//层次遍历函数
void BiTree::LevelOrder()    //公有函数，对外接口
{
	LevelOrder(Root);
}
void BiTree::LevelOrder(BiTreeNode* t)
{//用队列实现
	queue<BiTreeNode*> tq;
	BiTreeNode* p = t;
	if (p != NULL)
	{
		tq.push(p);
	}
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		if (p != NULL)
		{
			cout << p->data;
			tq.push(p->LeftChild);
			tq.push(p->RightChild);
		}
	}
}

//后序非递归遍历
void BiTree::PostOrder_stack()   //公有函数，对外接口
{
	PostOrder_stack(Root);
}
void BiTree::PostOrder_stack(BiTreeNode* t)
{
	stack<BiTreeNode*> s1;
	stack<int> s2;
	int tag;
	BiTreeNode* p = t;
	do
	{
		while (1)
		{
			if (p != NULL)
			{
				s1.push(p);
				tag = 0;
				s2.push(tag);
				p = p->LeftChild;
			}
			else
				break;
		}

		if (s1.empty())
			break;
		if (p == NULL)
		{
			tag = s2.top();
			if (tag == 0)
			{
				s2.top() = 1;
				p = s1.top()->RightChild;
			}
			else
			{
				p = s1.top();
				s1.pop();
				s2.pop();
				cout << p->data;
				p = NULL;
			}
		}
	} while (!s1.empty());
}
