#include<fstream>
#include<iostream>
#include<ostream>
#include<istream>
#include<iomanip>
#include<Windows.h>

const char *txtaddr = "C:\\Users\\Platanus\\Desktop\\chnCities.txt";
const char *midaddr = "C:\\Users\\Platanus\\Desktop\\chinaBoundaryL.mid";
const char *mifaddr = "C:\\Users\\Platanus\\Desktop\\chinaBoundaryL.mif";

using namespace std;

struct CityInfo
{
	int id;
	float CorX;
	float CorY;
	char CityName[50];
	struct CityInfo *next;
};

struct snode
{
	CityInfo *data;
	snode *next;
};

struct pts
{
	float x;
	float y;
	struct pts *next;
};


CityInfo *initHead();//��ʼ��
void Insert(int pos, CityInfo newone, CityInfo *list);//����
void Delete(int pos, CityInfo *p);//ɾ��
int Search(CityInfo *list);//˳����ң�����λ��
CityInfo * binarySearch(CityInfo ** list);//���ֲ���
void Reverse(CityInfo **list);//����
void Loadfile(const char *address, CityInfo *head);//��ȡ�ļ�����������
void Output(CityInfo *head);//��ʽ�����
void Free(CityInfo **head);//��������

void nodeSwap(CityInfo *node1, CityInfo *node2);//����
void Shellssort(CityInfo **list);//ϣ������
void Bubblesort(CityInfo **list);//ð������

snode *initStack();//��ʼ����ջ
bool stackNotEmpty(snode *shead);//�ж�ջ��
void stackPush(snode **shead, CityInfo*newone);//��ջ
bool stackPop(snode ** shead, CityInfo **output);//��ջ


int main()
{
	CityInfo* list = initHead();
	snode * stack = initStack();


	Loadfile(txtaddr, list);
	Output(list);
	Delete(3, list);Output(list);

	Reverse(&list);
	Search(list);
	Output(list);

	Bubblesort(&list);
	Output(list);

	Free(&list);
	
	system("pause");
	return 0;
}

CityInfo *initHead()
{
	CityInfo *head;
	head = new CityInfo;
	head->next = nullptr;
	return head;
}

bool listNotEmpty(CityInfo *head)
{
	if (head->next == nullptr)
		return false;
	return true;
}

void Insert(int pos, CityInfo newone, CityInfo *list)
{
	if (pos < 1)
	{
		cout << "Invalid";
		exit(1);
	}
	while (list->id != pos-1 && list->next != nullptr)
		list = list->next;
	if (list->next == nullptr)
	{
		cout << "No such one";
		exit(1);
	}
	
	CityInfo *newn = new CityInfo;
	*newn = newone;
	newn->next = list->next;
	list->next = newn;
}

void Delete(int pos, CityInfo *p)
{
	cout << "����ɾ����" << pos << "��Ԫ�ء���" << endl;
	if (pos < 1)
	{
		cout << "Invalid";
		exit(1);
	}
	
	while (p->next!=nullptr)
	{
		if (p->next->id  == pos)
		{
			CityInfo *q = p->next;
			p->next = p->next->next;
			delete q;
			cout << "ɾ���ɹ���" << endl;
			return;
		}
		p = p->next;
	}
}

int Search(CityInfo *list)//���ص�һ��ƥ��Ľڵ�id
{
	char aim[50];
	cin >> aim;
	while (list != nullptr)
	{
		if (!strcmp(list->CityName,aim))
		{
			cout << "��Ѱ�ҵĳ��еı��Ϊ��"<<list->id<<endl;
			return list->id;
		}
		list = list->next;
	}
	cout << "No such one" << endl;
}

CityInfo * binarySearch(CityInfo ** list)
{
	return nullptr;
}

void Reverse(CityInfo **list,snode *stack)
{
	stackPush(&stack, *list);
	if (!listNotEmpty(*list))
	{
		cout << "����Ϊ��!" << endl;
		exit(1);
	}
	cout << "�����С���" << endl;
	CityInfo *p = (*list)->next;

	(*list)->next = nullptr;
	while (p != nullptr)
	{
		CityInfo *q = new CityInfo;
		q = p;
		p = p->next;
		q->next = (*list)->next;
		(*list)->next = q;
	}
	cout << "���óɹ���";
}

void Loadfile(const char *address,CityInfo *head)
{
	CityInfo *p = new CityInfo;
	p = head;
	ifstream read(address, ios::in);
	if (read.bad())
	{
		cout << "Error";
		exit(1);
	}
	while (!read.eof())
	{
		CityInfo *q = new CityInfo;
		read >> q->id>> q->CorX >> q->CorY>> q->CityName;
		p->next = q;
		p = q;
	}
	p->next = nullptr;
	read.close();
}

void Output(CityInfo *head)//���
{
	cout << setfill(' ') << setw(25) << "���" << endl;
	if (head == nullptr)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	CityInfo *p = head->next;
	while (p!=nullptr)
	{
		cout << "��" << p->id << "��Ԫ�أ�������ϢΪ��"<< p->CityName << 
			"," << '(' << p->CorX << ',' << p->CorY << ')'
			<< endl;
		p = p->next;
	}
}

void Free(CityInfo **head)//��������
{
	cout << "ɾ���С���" << endl;
	if (*head != nullptr)
	{
		CityInfo *phead = *head;
		*head = (*head)->next;
		delete phead;
	}
	*head = nullptr;
	cout << "ɾ���ɹ�" << endl;
}

void deleteNode(CityInfo *&node,snode *stack)
{
	CityInfo *temp = node;
	node = node->next;
	stackPush(&stack, temp);
	delete temp;
}

void insertNode(CityInfo *& pre, CityInfo *node)
{
	
}

CityInfo * findPreNode(CityInfo *list, CityInfo *node)
{
	if (list = node)
	{
		CityInfo *p = new CityInfo;
		p->next = list;
		return p;
	}
	while (list->next != node)
		list = list->next;
	return list;
}

void Shellssort(CityInfo **list)
{

}

void Bubblesort(CityInfo **list)
{

}

snode *initStack()
{
	snode * shead = new snode;
	shead->data = nullptr;
	shead->next = nullptr;
	return shead;
}

bool stackNotEmpty(snode *shead)
{
	if (shead->next == nullptr)
		return false;
	return true;
}

void stackPush(snode **shead, CityInfo*newone)
{
	snode *p = new snode;
	p->data = newone;
	p->next = (*shead)->next;
	(*shead)->next = p;
}	 

bool stackPop(snode ** shead, CityInfo **output)
{
	snode * p = (*shead)->next;
	if (p != nullptr)
	{
		(*shead)->next = p->next;
		*output = p->data;
		delete p;
		return true;
	}
	cout << "ջ�գ�" << endl;
	return false;
}
