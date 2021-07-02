#include<iostream>
using namespace std;
//双向链表结点类
class ListNode
{
public:
	ListNode* front;  //前一个结点的指针
	char data;  //结点数据
	ListNode* next;  //下一个结点的指针
	//构造函数
	ListNode()
	{
		front = this;
		next = this;
		data = 0;
	}
};
//双向链表类
class LinkList
{
public:
	ListNode* head;  //头结点指针
	int len;  //双向链表长度
	LinkList();
	void LL_add(char x);  //在双向链表末尾添加一个结点
	ListNode* LL_index(int i);  //返回第i个结点
	void LL_insert(int i, char item);  //将item插入双向链表的第i个结点
	void LL_del(int i);  //删除双向链表中的第i个结点
	void LL_display();  //打印输出双向链表所有结点
};
//构造函数
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//在双向链表末尾添加一个结点
void LinkList::LL_add(char x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == head)
	{
		l->front = head;
		head->next = l;
		head->front = l;
	}
	else
	{
		l->front = LL_index(len);
		LL_index(len)->next = l;
		head->front = l;
	}
	len++;
}
//返回第i个结点
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "index_error" << endl;
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
//将item插入双向链表的第i个结点
void LinkList::LL_insert(int i, char item)
{
	if (i == len)
	{
		LL_add(item);
	}
	else if (i == 1)
	{
		if (len == 0)
		{
			LL_add(item);
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			l->front = head;
			l->next = LL_index(1);
			LL_index(1)->front = l;
			head->next = l;
			len++;
		}
	}
	else
	{
		ListNode* l = new ListNode();
		l->data = item;
		l->next = LL_index(i);
		LL_index(i)->front = l;
		LL_index(i - 1)->next = l;
		l->front = LL_index(i - 1);
		len++;
	}
}
//删除双向链表中的第i个结点
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "del_error" << endl;
	}
	else
	{
		if (i == 1)
		{
			if (len == 1)
			{
				head->next = head;
				head->front = head;
			}
			else
			{
				head->next = LL_index(2);
				LL_index(2)->front = head;
			}
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i)->front = LL_index(i - 1);
		}
		len--;
	}
}
//打印输出双向链表所有结点
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	if (p->next == head)
	{
		cout << "-";
	}
	while (p->next != head)
	{
		p = p->next;
		cout << p->data;
	}
	cout << endl;
}