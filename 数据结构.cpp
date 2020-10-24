#include "stdafx.h"
#include <conio.h>
#include <iostream>

//1. 引入外部绘制头文件
#include "windows.h"

//点坐标结构体
typedef struct pts
{
	float x;
	float y;
	struct pts *next;
}FloatPT;

//要素结构体
typedef struct LineInfo
{
	int ptCount;
	FloatPT *ptHead;
	struct LineInfo *next;
}LineLink;

//读文件到线链表
void readFileToLineLink(LineLink **head)
{
	FILE *fp=fopen("D:\\WHU\\学习\\课程\\数据结构GIS\\chinaBoundaryL.mif","r");
	if(fp==NULL)
	{
		printf("文件打开有误！\n");
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
		if( strcmp(tmpStr,"Pline") == 0) //碰到Pline对象
		{
			//创建LineLink，并添加到链表
			link = (LineLink *)malloc(sizeof(LineLink));
			if(*head==NULL)
				*head = link;
			else
			{//追加到最后(link)
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
				//创建FloatPT点对象并添加到链表中去
				pt = (FloatPT *)malloc(sizeof(FloatPT));
				fscanf(fp,"%f%f",&pt->x,&pt->y);
				pt->next = NULL;
				if( ptHD == NULL)
					ptHD = pt;
				else
					curHD->next = pt;

				curHD = pt;//指向当前最后一个链表节点(point)
			}
			link->ptHead=ptHD;
			link->next = NULL;
			curLK = link;  //指向当前最后一个链表节点(Line)
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
//绘制链表
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
//释放空间
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

	printf("读取文件完成！！！\n");
	
	char c = 'a';
	while(c!= '*')
	{
		drawLineLink(lineHD);
		c = getch();
	}
	return 0;
}