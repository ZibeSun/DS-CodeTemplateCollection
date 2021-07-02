#include<iostream>
using namespace std;
//二叉排序树结点类
class BSTNode
{
public:
	int key;           //结点关键字
	BSTNode* Parent;   //父结点
	BSTNode* Lchild;   //左孩子
	BSTNode* Rchild;   //右孩子
	BSTNode() :key(0), Parent(NULL), Lchild(NULL), Rchild(NULL) {}
};
//二叉排序树类
class BSTree
{
private:
	BSTNode* Root;  //根结点指针

	void InOrder(BSTNode* t);
	BSTNode* Search_BST(BSTNode* T, int key);
	BSTNode* Insert_BST(BSTNode* T, int key);
public:
	int search_times;   //每次查找次数
	BSTree();  //构造函数
	void InOrder();     //中序遍历
	BSTNode* Search_BST(int key);        //二叉排序树的递归查找
	void Insert_BST(int key);            //二叉排序树的递归插入
	void Delete_BST(int key);            //二叉排序树的递归删除
	void Create_BST(int* item, int n);   //构建二叉排序树
};
BSTree::BSTree()
{
	Root = NULL;
	search_times = 0;
}
//定义中序遍历函数
void BSTree::InOrder()  //公有函数，对外接口
{
	InOrder(Root);
}
void BSTree::InOrder(BSTNode* t)
{
	if (t != NULL)
	{
		InOrder(t->Lchild);
		cout << t->key << " ";
		InOrder(t->Rchild);
	}
	else
		return;
}
//定义二叉排序树的递归查找函数
BSTNode* BSTree::Search_BST(int key)  //公有函数，对外接口
{
	search_times = 0;   //查找次数清零
	return Search_BST(Root, key);
}
BSTNode* BSTree::Search_BST(BSTNode* T, int key)
{
	if (T == NULL)
		return NULL;  //搜索失败则返回NULL
	else
	{
		if (T->key == key)
		{
			search_times++;
			return T;         //搜索成功则返回结点指针
		}
		else if (T->key > key)
		{
			search_times++;
			Search_BST(T->Lchild, key);
		}
		else
		{
			search_times++;
			Search_BST(T->Rchild, key);
		}
	}
}
//定义二叉排序树的递归插入函数
void BSTree::Insert_BST(int key)  //公有函数，对外接口
{
	Root = Insert_BST(Root, key);
}
BSTNode* BSTree::Insert_BST(BSTNode* T, int key)
{
	if (T == NULL)
	{
		T = new BSTNode;
		T->key = key;
		return T;
	}
	else
	{
		if (T->key == key)
			return NULL;
		else if (T->key > key)
			T->Lchild = Insert_BST(T->Lchild, key);
		else
			T->Rchild = Insert_BST(T->Rchild, key);
		return T;
	}
}
//定义二叉排序树的递归删除函数
void BSTree::Delete_BST(int key)
{
	BSTNode* T = Search_BST(key);
	if (T == NULL)
	{
		return;   //若要删除的数据不在二叉树中，则不执行操作
	}
	if ((T->Lchild == NULL) && (T->Rchild == NULL))
	{//情况一:该结点是叶子结点
		if (T->Parent->Lchild == T)
			T->Parent->Lchild = NULL;
		else if (T->Parent->Rchild == T)
			T->Parent->Rchild = NULL;
	}
	else if ((T->Lchild != NULL) && (T->Rchild != NULL))
	{//情况二:该结点同时有左、右子树
		BSTNode* t = T->Rchild;
		while (t->Lchild != NULL)
			t = t->Lchild;
		T->key = t->key;

		if (t->Rchild != NULL)
			*t = *t->Rchild;
		else
		{
			if (t->Parent->Lchild == t)
				t->Parent->Lchild = NULL;
			else if (t->Parent->Rchild == t)
				t->Parent->Rchild = NULL;
		}
	}
	else
	{//情况三:该结点只有左子树或右子树
		if (T->Lchild != NULL)
		{
			*T = *T->Lchild;
		}
		else if (T->Rchild != NULL)
		{
			*T = *T->Rchild;
		}
	}
}
//构建二叉排序树
void BSTree::Create_BST(int* item, int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert_BST(item[i]);
	}
}
