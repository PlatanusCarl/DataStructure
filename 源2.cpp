//单链表
#include <stdlib.h> 
#include <stdio.h>
#include <malloc.h>

typedef struct List//创建链表
{
	int data;
	struct List *next;
}LinkList;

LinkList *Listinitiate(int n)//初始化
{
	LinkList *head, *node, *end;//定义节点
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;
	for (int i = 0; i < n; i++)
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf_s("%d",&node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void change(LinkList *list, int n)//修改
{
	LinkList *t = list;
	int i = 0;
	while (i < n && t != NULL)//找到第n个结点
	{
		t = t->next;
		i++;
	}
	if (t != NULL)
	{
		puts(">");
		scanf_s("%d", &t->data);
	}
	else
		puts("Error");
}

void delet(LinkList *list, int n)//删除
{
	LinkList *t = list, *in= 0;
	int i = 0;
	while (i < n&& t != NULL)
	{
		in = t;
		t = t->next;
		i++;
	}
	if (i != NULL)
	{
		in->next = t->next;
		free(t);
	}
	else
		puts("Error");

}

void insert(LinkList *list, int n)//插入
{
	LinkList *t = list, *in;
	int i = 0;
	while (i < n&&t != NULL)
	{
		t = t->next;
		i++;
	}
	if (t != NULL)
	{
		in = (LinkList*)malloc(sizeof(LinkList));
		puts(">");
		scanf_s("%d", &in->data);

		in->next = t->next;
		t->next = in;
	}
	else
		puts("Error");
}

void print(LinkList *list)//输出
{
	while (list->next != NULL)
	{
		list = list->next;
		printf("%d\n", list->data);
	}
}

void onkey(LinkList *list)
{
	while (true)
	{
		int n; 
		char key;
		key = getchar();
		switch (key)
		{
		case 'c':printf(">");
			scanf_s("%d",&n);
			change(list, n);
			break;
		case 'd':printf(">");
			scanf_s("%d", &n);
			delet(list, n);
			break;
		case 'i':
		default:
			break;
		}
	}
}
int main()
{
	List *mylist = Listinitiate(5);
	print(mylist);
	
	system("pause");
	return 0;
}