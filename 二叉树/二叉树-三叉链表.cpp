#include<iostream>
using namespace std;
//二叉树的三叉链表结点类
class BiTreeNode
{
public:
	char data;  //结点数据
	int balance;  //结点平衡因子
	BiTreeNode* LeftChild;   //左子树指针
	BiTreeNode* RightChild;  //右子树指针
	BiTreeNode* Parent;      //双亲指针
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL) {}
	//~BiTreeNode();
};

//二叉树的三叉链表类
class BiTree
{
private:
	BiTreeNode* Root;   //根节点指针
	int pos;
	string strTree;

	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t, int i);
	BiTreeNode* Create_PreOrder(int i, string str);
	void Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h);
	void Balance_calculate(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //利用先序遍历结果创建二叉树
	void PreOrder();    //前序遍历
	void InOrder();     //中序遍历
	void PostOrder();   //后序遍历
	void LevelOrder();  //层次遍历不使用队列的递归算法
	void CreatePreOrder(int i, string str);  //递归先序遍历顺序数组存储的二叉树
	int LeafDepth(BiTreeNode* t);  //计算叶子结点相对于根结点的深度
	int LeafDepth(BiTreeNode* t, BiTreeNode* t_root);  //计算叶子结点t相对于t_root结点的深度
	int HeightSubtree(BiTreeNode* t);   //计算子树高度
	void Balance_calculate();  //计算结点平衡因子
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
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //构造右子树
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}
//计算叶子结点相对于根结点的深度
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T == Root)
		{
			return depth;
		}
		else
		{
			if (T->Parent != NULL)
			{
				T = T->Parent;
				depth++;
			}
			else
			{
				return depth;
			}
		}
	}
}
//计算叶子结点t相对于t_root结点的深度
int BiTree::LeafDepth(BiTreeNode* t, BiTreeNode* t_root)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != t_root->Parent)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			depth++;
			return depth;
		}
	}
}
//层次遍历函数
void BiTree::LevelOrder()    //公有函数，对外接口
{
	for (int i = 0; i < 10; i++)
	{
		LevelOrder(Root, i);
	}
}
void BiTree::LevelOrder(BiTreeNode* t, int i)
{
	if (t != NULL)
	{
		if (LeafDepth(t) == i)
		{
			cout << t->data << " ";
		}
		LevelOrder(t->LeftChild, i);
		LevelOrder(t->RightChild, i);
	}
	else
		return;
}
//递归先序遍历顺序数组存储的二叉树
void BiTree::CreatePreOrder(int i, string str)
{
	Root = Create_PreOrder(i, str);
}
BiTreeNode* BiTree::Create_PreOrder(int i, string str)
{
	BiTreeNode* T;
	if (i < str.length())
	{
		if (str[i] != '0')
		{
			T = new BiTreeNode;
			T->data = str[i];
			T->LeftChild = Create_PreOrder(2 * i + 1, str);
			if (T->LeftChild != NULL)
				T->LeftChild->Parent = T;
			T->RightChild = Create_PreOrder(2 * i + 2, str);
			if (T->RightChild != NULL)
				T->RightChild->Parent = T;
		}
		else
		{
			T = NULL;
		}
	}
	else
	{
		T = NULL;
	}
	return T;
}
void BiTree::Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h)
{
	if (t != NULL)
	{
		Height_Subtree(t_root, t->LeftChild, h);
		Height_Subtree(t_root, t->RightChild, h);
		if (LeafDepth(t, t_root) >= h)
			h = LeafDepth(t, t_root);
	}
	else
		return;
}
//计算结点平衡因子
void BiTree::Balance_calculate()  //公有函数，对外接口
{
	Balance_calculate(Root);
}
void BiTree::Balance_calculate(BiTreeNode* t)
{
	if (t != NULL)
	{
		Balance_calculate(t->LeftChild);
		Balance_calculate(t->RightChild);
		t->balance = HeightSubtree(t->LeftChild) - HeightSubtree(t->RightChild);
	}
	else
		return;
}