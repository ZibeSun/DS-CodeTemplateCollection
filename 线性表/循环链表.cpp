#include<iostream>
#include<stdio.h>
using namespace std;
//循环链表结点类
class ListNode
{
public:
	int data;  //结点数据
	ListNode* next;  //下一个结点的指针
	//构造函数
	ListNode()
	{
		next = NULL;
		data = 0;
	}
};
//循环链表类
class LinkList
{
public:
	ListNode* head;  //头结点指针
	int len;  //循环链表长度
	LinkList();
	void LL_add(int x);  //在循环链表尾部插入数据x
	ListNode* LL_index(int i);  //查找并返回第i个结点的指针
	void LL_del(int i);  //删除第i个结点
	void LL_display();  //打印输出循环链表所有结点
};
//构造函数
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//在循环链表尾部插入数据x
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		LL_index(len)->next = l;
	}
	len++;
}
//查找并返回第i个结点的指针
ListNode* LinkList::LL_index(int i)
{
	if (i > len)
	{
		i = i - len;
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
//删除第i个结点
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == 1)
		{
			head->next = LL_index(2);
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
		}
		len--;
	}
}
//打印输出循环链表所有结点
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
	}
	cout << endl;
}