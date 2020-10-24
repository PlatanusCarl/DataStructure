#include "stdafx.h"
#include <conio.h>
#include <iostream>

//1. �����ⲿ����ͷ�ļ�
#include "windows.h"

//������ṹ��
typedef struct pts
{
	float x;
	float y;
	struct pts *next;
}FloatPT;

//Ҫ�ؽṹ��
typedef struct LineInfo
{
	int ptCount;
	FloatPT *ptHead;
	struct LineInfo *next;
}LineLink;

//���ļ���������
void readFileToLineLink(LineLink **head)
{
	FILE *fp=fopen("D:\\WHU\\ѧϰ\\�γ�\\���ݽṹGIS\\chinaBoundaryL.mif","r");
	if(fp==NULL)
	{
		printf("�ļ�������\n");
		return;
	}
	int size,i;
	char tmpStr[80];
	LineLink *curLK,*link = NULL;
	FloatPT *curHD,*ptHD=NULL;
	FloatPT *pt=NULL;
	while( !feof(fp))
	{
		fscanf(fp,"%s",tmpStr);
		if( strcmp(tmpStr,"Pline") == 0) //����Pline����
		{
			//����LineLink������ӵ�����
			link = (LineLink *)malloc(sizeof(LineLink));
			if(*head==NULL)
				*head = link;
			else
			{//׷�ӵ����(link)
			  /*	LineLink *linkHD = *head;
				while( linkHD ->next != NULL)
					linkHD = linkHD->next;
				linkHD->next = link;
			   */
				curLK->next = link;
			}

			fscanf(fp,"%d",&size);
			link->ptCount = size;
			ptHD = NULL;

			for(i=0;i<size;i++)
			{
				//����FloatPT�������ӵ�������ȥ
				pt = (FloatPT *)malloc(sizeof(FloatPT));
				fscanf(fp,"%f%f",&pt->x,&pt->y);
				pt->next = NULL;
				if( ptHD == NULL)
					ptHD = pt;
				else
					curHD->next = pt;

				curHD = pt;//ָ��ǰ���һ������ڵ�(point)
			}
			link->ptHead=ptHD;
			link->next = NULL;
			curLK = link;  //ָ��ǰ���һ������ڵ�(Line)
		}
	}	
}
void transWCtoDC(int cx,int cy,float x,float y,float *x1,float *y1)
{
	float minx = 70.0;
	float maxx = 140.0;
	float miny = 0;
	float maxy = 60;
	*x1 = (x-minx)/(maxx-minx)* cx;
	*y1 = cy - ( (y - miny )/(maxy - miny) *cy );
}
//��������
void drawLineLink(LineLink *head)
{
	LineLink *hd = head;
	FloatPT *pt;
	float x,y;

	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd); 
	RECT rc;
	GetWindowRect(hwnd,&rc);

	HPEN pen=CreatePen(PS_SOLID,1,RGB(255,0,0));
	SelectObject(hdc,pen);

	int cx = rc.right-rc.left;
	int cy = rc.bottom - rc.top;
	while(hd!=NULL)
	{
		pt = hd->ptHead;
		while(pt!=NULL)
		{
			transWCtoDC(cx,cy,pt->x,pt->y,&x,&y);
			if( pt == hd->ptHead)
				MoveToEx(hdc,x,y,NULL);
			else
				LineTo(hdc,x,y);
			pt=pt->next;
		}
		hd=hd->next;
	}
}
//�ͷſռ�
void freeLineLink(LineLink **head)
{
	LineLink *hd,*hdTmp;
	FloatPT *pt,*ptTmp;

	hd = *head;
	while(hd!=NULL)
	{
		hdTmp = hd->next;

		pt = hd->ptHead;
		while(pt!=NULL)
		{
		    ptTmp = pt->next;
			free(pt);
			pt=ptTmp;
		}
		free(hd);
		hd=hdTmp;
	} 
}
int main()
{
	LineLink *lineHD = NULL;
	readFileToLineLink(&lineHD);

	printf("��ȡ�ļ���ɣ�����\n");
	
	char c = 'a';
	while(c!= '*')
	{
		drawLineLink(lineHD);
		c = getch();
	}
	return 0;
}