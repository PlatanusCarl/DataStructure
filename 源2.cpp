//������
#include <stdlib.h> 
#include <stdio.h>
#include <malloc.h>

typedef struct List//��������
{
	int data;
	struct List *next;
}LinkList;

LinkList *Listinitiate(int n)//��ʼ��
{
	LinkList *head, *node, *end;//����ڵ�
	head = (LinkList*)malloc(sizeof(LinkList));//�����ַ
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

void change(LinkList *list, int n)//�޸�
{
	LinkList *t = list;
	int i = 0;
	while (i < n && t != NULL)//�ҵ���n�����
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

void delet(LinkList *list, int n)//ɾ��
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

void insert(LinkList *list, int n)//����
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

void print(LinkList *list)//���
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