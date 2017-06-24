#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAX 9999

int synchronize_start(char *s);//��������ַ���ʽ�����վ����ת��Ϊ��Ӧ����
int synchronize_des(char *d);//��������ַ���ʽ���յ�վ����ת��Ϊ��Ӧ����
void draw();//����ͼ�ν���
void floyd(char *s, char *d);
char *display(int code);//�����������վ����Ϣת��Ϊվ�����������

int main()
{
	draw();

	return 0;
}

//���Ƶ�ͼ
void draw()
{
	char dest[15], start[15];

	initgraph(1500, 800);
	setcolor(WHITE);

	IMAGE img;
	loadimage(&img, "C:\\Image_1.jpg");
	putimage(20, 700, &img);

	IMAGE img2; 
	loadimage(&img2, "C:\\map.jpg");
	putimage(20, 48, &img2);

	RECT r = {100, 100, 2300, 200};
	drawtext("����վ�� ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT rr = {100, 100, 2300, 500};
	drawtext("�յ�վ�� ", &rr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT dis = {100, 100, 2300, 800};
	drawtext("��̾��룺 ", &dis, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r3 = {100, 100, 20, 1200};
	drawtext("�Ƽ�·���� ", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r4 = { 5, 5, 50, 50};
	drawtext("��ͼ�� ", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	bar(1250, 130, 1400, 180);
	bar(1250, 270, 1400, 320);
	bar(1250, 425, 1350, 475);
	bar( 250, 625, 1500, 675);

	InputBox(start, 20, "���������");
	sscanf(start, "%d", &start);

	InputBox(dest, 15, "������ȥ");
	sscanf(dest, "%d", &dest);

	getch();

	setcolor(WHITE);
	outtextxy(1300, 150, start);
	outtextxy(1300, 280, dest);

	floyd(start, dest);

	getch();
	closegraph();

}

//�㷨ʵ�����·��
void floyd(char *s, char *d)
{
	int des=0, sta=0, next;
	int info[28][28]={0}, dist[28][28] = {0}, path[28][28]={0};
	int i, j, k;
	char step[15], start[15], destinaion[15];
	char shortest[5];
	int distance;
	char temp[15];
	int count=0;
	FILE *fp;


	//���β�ת��һ����ʽ
	strcpy(start, s);
	strcpy(destinaion, d);

	sta = synchronize_start(start);
	des = synchronize_des(destinaion);
	while( sta == 99 || des == 99)
	{
		printf("There isn't this step, please check again!\n");
		return ;
	}

	fp = fopen("lisa.txt", "r");
	if (fp == NULL)
	{
		printf("can't open the file.\n");
		return ;
	}

	for (i=0; i<28; i++)
	{
		for (j=0; j<28; j++)
		{
			fscanf(fp, "%d	", &info[i][j]);
		}
	}

	for(i=0; i<28; i++)
	{
		for(j=0; j<28; j++)
		{
			dist[i][j]=info[i][j];
			if( dist[i][j]<9999 )
				path[i][j]=j;
			else
				path[i][j]=-1;
		}
	}

	for ( k=0; k<28; k++)
	{
		for ( i=0; i<28; i++)
		{
			for ( j=0; j<28; j++)
			{
				if ( info[i][k] + info[k][j] < info[i][j])
				{
					info[i][j]=info[i][k]+info[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}

	distance = info[sta][des];

	sprintf(shortest, "%d", distance);
	outtextxy(1300, 450, shortest);

	strcpy(start,display(sta));
	outtextxy(260, 650, start);

	next = path[sta][des];
	while(next != des) 
	{
		strcpy(step, display(next));
		outtextxy(400+count*100, 650, step);
		next = path[next][des];
		count++;
	}

	strcpy(destinaion,display(des));
	outtextxy(1350, 650, destinaion);

}


int synchronize_start(char *s)
{
	char name[15], temp[28][15]={
		"ۯ�ؿ�������","����¥վ","������","ʯ��","�ɶ���վ",
		"��ɳ��վ","����ӿ���վ","������","˫������",
		"���ɺ�","������","�츮�㳡","ʡ������","���ͳ�",
		"����·","����·","������","ĥ����","���Ŵ���",
		"��ҽ��Ժ","��˫·","������","����·",
		"����԰","����·","ţ����","�ɶ�����վ",
		"������"};
	int start=0;
	int i;

	strcpy(name, s);

	for(i=0; i<28;i++)
	{
		if(strcmp(name,temp[i])==0)
		{
			break;
		}
	}

	if (i>=28)
	{
		return 99;
	}

	else
	{
		start = i;
	}

	return start;
}

int synchronize_des(char *d)
{
	char name[15], temp[28][15]={
		"ۯ�ؿ�������","����¥վ","������","ʯ��","�ɶ���վ",
		"��ɳ��վ","����ӿ���վ","������","˫������",
		"���ɺ�","������","�츮�㳡","ʡ������","���ͳ�",
		"����·","����·","������","ĥ����","���Ŵ���",
		"��ҽ��Ժ","��˫·","������","����·",
		"����԰","����·","ţ����","�ɶ�����վ",
		"������"};
	int des=0;
	int i;

	strcpy(name, d);

	for(i=0; i<28;i++)
	{
		if(strcmp(name,temp[i])==0)
		{
			break;
		}
	}

	if (i>=28)
	{
		return 99;
	}

	else
	{
		des = i;
	}

	return des;
}


char *display(int code)
{
	char step[15];
	char temp[28][15]={
		"ۯ�ؿ�������","����¥վ","������","ʯ��","�ɶ���վ",
		"��ɳ��վ","����ӿ���վ","������","˫������",
		"���ɺ�","������","�츮�㳡","ʡ������","���ͳ�",
		"����·","����·","������","ĥ����","���Ŵ���",
		"��ҽ��Ժ","��˫·","������","����·",
		"����԰","����·","ţ����","�ɶ�����վ",
		"������"};

	strcpy(step, temp[code]);

	return step;
}