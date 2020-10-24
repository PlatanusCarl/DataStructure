//顺序表
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;
#define MaxSize 50
const char* address = "C:\\Users\\Platanus\\Desktop\\chnMainCities.txt";
 struct CityInfo
{
	 int id;
	 char name[50];
	 float x;
	 float y;
};

typedef struct//定义
{
	CityInfo list[MaxSize];
	int size;
}Seqlist;


void loadfile(const char* address, Seqlist *list)
{
	ifstream read(address, ios::in);
	int i= 0;
	while (!read.eof())
	{
		read >> (list)->list[i].id >> (list)->list[i].x >> (list)->list[i].y >> (list)->list[i++].name;
		(list)->size++;
	}

}

void bubbleSort(Seqlist *list)
{
	for (int j = 0; j < list->size-1; j++)
	{
		for (int i = 0; i < list->size-1; i++)
		{
			if (list->list[i].id < list->list[i + 1].id)
			{
				CityInfo temp = list->list[i];
				list->list[i] = list->list[i + 1];
				list->list[i + 1] = temp;
			}
		}
	}
}

void insertSort(Seqlist *list)
{
	for (int m = list->size-1; m >=0; m--)
		list->list[m+1] = list->list[m];
	for (int i = 2; i <= list->size; i++)
		if(list->list[i].id<list->list[i-1].id)
		{
			CityInfo temp = list->list[i];
			list->list[i] = list->list[i - 1];
			int j;
			for ( j = i - 2; temp.id < list->list[j].id; j--)
				list->list[j + 1] = list->list[j];
			list->list[j + 1] = temp;
		}
}

void print(Seqlist *list)
{
	for(int i=0; i<list->size ;i++)
		cout << list->list[i].id<<endl;
}

void ListInitiate(Seqlist *L)//初始化
{
	L->size = 0;
}



int main()
{
	Seqlist list;
	Seqlist *listptr = &list;
	ListInitiate(listptr);
	loadfile(address, listptr);
	print(listptr);

	cout << "排序后……" << endl;
	bubbleSort(listptr);
	print(listptr);
	cout << "inser"<<endl;
	insertSort(listptr);
	print(listptr);

	system("pause");
	return 0;
}