//堆栈实习
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include<Windows.h>

using namespace std;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();
const char *midadr = "C:\\Users\\Platanus\\Desktop\\chinaBoundaryL.mid";
const char *mifadr = "C:\\Users\\Platanus\\Desktop\\chinaBoundaryL.mif";

typedef class pts//点坐标
{
	public:
	float x;
	float y;
	pts *next;
}FloatPT;

typedef class LineInfo//要素
{
	public:
	int ptCount;
	FloatPT *ptHead;
	LineInfo *next;
}LineLink;

void AddToLineLink(LineLink **head,LineLink *newone)
{
	if (*head == nullptr)
		*head = newone;
	else
	{
		(*head)->next = newone;
		*head = (*head)->next;
	}
}

void AddToPTLink(FloatPT **ptlink, FloatPT newone)
{
	;
}

void LoadFileToLineLink(const char *address,LineLink **head)//读文件到线链表
{
	ifstream read(address, ios::in);
	if (read.bad())//验证文件打开
	{
		cout << "读文件失败！";
		exit(1);
	}
	
	char tmpStr[80];
	LineLink *link = nullptr;
	FloatPT *pthead = nullptr;
	FloatPT *pt = nullptr;

	while (!read.eof())
	{
		read >> tmpStr;
		if (strcmp(tmpStr, "Pline") == 0)//碰到Pline对象
		{	
			link = new LineLink;
			AddToLineLink(head, link);
			read >> link->ptCount;//读取Pline的大小
			link->ptHead = pthead;
			for(int i =0;i<(link->ptCount);i++)//把点坐标读入链表
			{
				pt = new FloatPT;
				read >> pt->x >> pt->y;
				pt->next = nullptr;
				if (pthead == nullptr)
					pthead = pt;
				else
				{
					pthead->next = pt;
					pthead = pthead->next;
				}
			}
			link -> next = nullptr;
		}
	}
}

void output(LineLink *head)
{
	while (head != nullptr)
	{
		cout << head->ptCount << endl;
		FloatPT *pthead = (head)->ptHead;
		while (pthead !=nullptr)
		{
			cout << pthead->x << "," << pthead->y << endl;
			pthead = pthead->next;
		}
		head = (head)->next;
	}
}

int main()
{
	LineLink* miflink=nullptr;
	LoadFileToLineLink(mifadr, &miflink);
	output(miflink);
	system("pause");
	return 0;
}
