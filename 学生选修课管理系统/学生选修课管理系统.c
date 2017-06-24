#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#define LEN sizeof(struct Kecheng)

struct Kecheng
{
	int num;
	char name[21];
	char xingzhi[11];
	int timezong;
	int timeke;
	int timeji;
	int fen;
	int term;
	struct Kecheng *next;
};

void zhuyemian(void);
void luru(void);
void xinjian(void);
void write(struct Kecheng *head);
struct Kecheng *read(void);
void xiugai(void);
void shanchu(void);
void liulan(void);
void chaxun(void);
void xuanke(void);
void print(struct Kecheng *head);
struct Kecheng *paixunum(struct Kecheng *head);
struct Kecheng *paixuxingzhi(struct Kecheng *head);

int main()
{
	zhuyemian();
	return 0;
}

void zhuyemian(void)
{
	int i;
	system("cls");
	puts("********************************************************************************");
	puts("			  ��ӭʹ��ѧ��ѡ�޹���ϵͳ!\n");
	puts("********************************************************************************");
	puts("��ѡ��Ҫʹ�õĹ���:\n");
	puts("  1.�γ�¼��\n");
	puts("  2.�γ����\n");
	puts("  3.�γ̲�ѯ\n");
	puts("  4.ѧ��ѡ��\n");
	puts("  5.�˳�ϵͳ\n");
	puts("********************************************************************************");
	printf("������������ѡ���Ӧ�Ĺ���:");
	scanf("%d",&i);
	while(i<0||i>5)
	{
		printf("�����������������:");
		scanf("%d",&i);
	}
	switch(i)
	{
	case 1:luru();break;
	case 2:liulan();break;
	case 3:chaxun();break;
	case 4:xuanke();break;
	default:break;
	}
}

void luru(void)
{
	int i;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����γ�¼�����!\n");
	puts("********************************************************************************");
	puts("��ѡ��Ҫʹ�õĹ���:\n");
	puts("  1.�½��γ�\n");
	puts("  2.�γ��޸�\n");
	puts("  3.�γ�ɾ��\n");
	puts("  4.����������\n");
	puts("********************************************************************************");
	printf("������������ѡ���Ӧ�Ĺ���:");
	scanf("%d",&i);
	while(i<0||i>4)
	{
		printf("�����������������:");
		scanf("%d",&i);
	}
	switch(i)
	{
	case 1:xinjian();break;
	case 2:xiugai();break;
	case 3:shanchu();break;
	default:zhuyemian();
	}
}

void xinjian(void)
{
	char c;
	struct Kecheng *head,*p1,*p2;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ�����½�����!\n");
	puts("********************************************************************************");
	puts("������Ҫ�½��Ŀγ���Ϣ(��������ȫ0ʱ�������)");
	puts("�γ̱�� �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ ѧ�� ����ѧ��");
	head=NULL;
	p1=p2=(struct Kecheng *)malloc(LEN);
	scanf("%d %s %s %d %d %d %d %d",&p2->num,p2->name,p2->xingzhi,&p2->timezong,&p2->timeke,&p2->timeji,&p2->fen,&p2->term);
	while(p2->num!=0)
	{
		if(head==NULL)
			head=p2;
		else
		{
			p1->next=p2;
			p1=p2;
		}
		p2=(struct Kecheng *)malloc(LEN);
		scanf("%d %s %s %d %d %d %d %d",&p2->num,p2->name,p2->xingzhi,&p2->timezong,&p2->timeke,&p2->timeji,&p2->fen,&p2->term);
	}
	p1->next=NULL;
	free(p2);
	write(head);	
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

void write(struct Kecheng *head)  
{
	FILE *fp;
	struct Kecheng *p;
	p=head;
	if((fp=fopen("ѧ��ѡ�޿ι���ϵͳ.txt","w"))==NULL)
		puts("�ļ�����ʧ��!");
	else
	{
		while(p!=NULL)
		{
			fprintf(fp,"%d %s %s %d %d %d %d %d ",p->num,p->name,p->xingzhi,p->timezong,p->timeke,p->timeji,p->fen,p->term);
			p=p->next;
		}
	}
	fclose(fp);
}

struct Kecheng *read(void)
{
	FILE *fp;
	struct Kecheng *head,*p1,*p2;
	head=NULL;
	if((fp=fopen("ѧ��ѡ�޿ι���ϵͳ.txt","r"))==NULL)
		puts("�ļ���ʧ��!");
	else
	{
		p1=p2=(struct Kecheng *)malloc(LEN);
		fscanf(fp,"%d %s %s %d %d %d %d %d",&p2->num,p2->name,p2->xingzhi,&p2->timezong,&p2->timeke,&p2->timeji,&p2->fen,&p2->term);
		while(!feof(fp))
		{
			if(head==NULL)
				head=p2;
			else
			{
				p1->next=p2;
				p1=p2;
			}
			p2=(struct Kecheng *)malloc(LEN);
			fscanf(fp,"%d %s %s %d %d %d %d %d",&p2->num,p2->name,p2->xingzhi,&p2->timezong,&p2->timeke,&p2->timeji,&p2->fen,&p2->term);
		}
		p1->next=NULL;
		free(p2);
	}
	fclose(fp);
	return head;
}

void xiugai(void)
{
	char c,s[21];
	int i,j,flag=0;
	struct Kecheng *head,*p;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����γ��޸Ľ���!\n");
	puts("********************************************************************************");
	do{
		puts("��ѡ��������Ϣ�������Ҫ�޸ĵĿγ�(1Ϊ�γ̱�� 2Ϊ�γ�����):");
		scanf("%d",&i);
		while((i!=1)&&(i!=2))
		{
			printf("�����������������:");
			scanf("%d",&i);
		}
		head=read();
		p=head;
		switch(i)
		{
		case 1:
			{
				printf("������Ҫ�޸Ŀγ̵ı��:");
				scanf("%d",&j);
				while((p!=NULL)&&(p->num!=j))
				p=p->next;
				if(p==NULL)
				{
					if(flag==1)
						write(head);
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		case 2:
			{
				printf("������Ҫ�޸Ŀγ̵�����:");
				c=getchar();
				gets(s);
				while((p!=NULL)&&(strcmp(p->name,s)!=0))
					p=p->next;
				if(p==NULL)
				{
					if(flag==1)
						write(head);
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		default:break;
		}
		puts("�γ����ҵ�");
		puts("�γ̱�� �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ ѧ�� ����ѧ��");
		printf("%d %s %s %d %d %d %d %d\n",p->num,p->name,p->xingzhi,p->timezong,p->timeke,p->timeji,p->fen,p->term);
		printf("�������޸ĺ������:\n");
		scanf("%d %s %s %d %d %d %d %d",&p->num,p->name,p->xingzhi,&p->timezong,&p->timeke,&p->timeji,&p->fen,&p->term);
		flag=1;
		printf("�Ƿ�����޸�(Y or N):");
		c=getchar();
		scanf("%c",&c);
	}while((c=='Y')||(c=='y'));
	write(head);	
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

void shanchu(void)
{
	char c,s[21];
	int i,j,flag=0;
	struct Kecheng *head,*p1,*p2;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����γ�ɾ������!\n");
	puts("********************************************************************************");
	do{
		puts("��ѡ��������Ϣ�������Ҫɾ���Ŀγ�(1Ϊ�γ̱�� 2Ϊ�γ�����):");
		scanf("%d",&i);
		while((i!=1)&&(i!=2))
		{
			printf("�����������������:");
			scanf("%d",&i);
		}
		head=read();
		p1=p2=head;
		switch(i)
		{
		case 1:
			{
				printf("������Ҫɾ���γ̵ı��:");
				scanf("%d",&j);
				while((p2!=NULL)&&(p2->num!=j))
				{
					p1=p2;
					p2=p2->next;
				}
				if(p2==NULL)
				{
					if(flag==1)
						write(head);
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		case 2:
			{
				printf("������Ҫɾ���γ̵�����:");
				c=getchar();
				gets(s);
				while((p2!=NULL)&&(strcmp(p2->name,s)!=0))
				{
					p1=p2;
					p2=p2->next;
				}
				if(p2==NULL)
				{
					if(flag==1)
						write(head);
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		default:break;
		}
		puts("�γ����ҵ�");
		puts("�γ̱�� �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ ѧ�� ����ѧ��");
		printf("%d %s %s %d %d %d %d %d\n",p2->num,p2->name,p2->xingzhi,p2->timezong,p2->timeke,p2->timeji,p2->fen,p2->term);
		printf("�Ƿ�ȷ��ɾ�����ſγ�(Y or N):");
		c=getchar();
		scanf("%c",&c);
		if((c=='Y')||(c=='y'))
			if(p2!=head)
				p1->next=p2->next;
			else
				head=p2->next;
		flag=1;
		printf("�Ƿ����ɾ��(Y or N):");
		c=getchar();
		scanf("%c",&c);
	}while((c=='Y')||(c=='y'));
	write(head);	
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

void liulan(void)
{
	char c;
	int i,flag=0;
	struct Kecheng *head;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����γ��������!\n");
	puts("********************************************************************************");
	puts("��ѡ��������Ϣ������ȷ���γ�����ʽ(1Ϊ�γ̱�� 2Ϊ����):");
	scanf("%d",&i);
	while((i!=1)&&(i!=2))
	{
		printf("�����������������:");
		scanf("%d",&i);
	}
	puts("�γ̱�� �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ ѧ�� ����ѧ��");
	head=read();
	if(head==NULL)
	{
		printf("û�пγ̼�¼!");
		exit(0);
	}
	switch(i)
		{
		case 1:head=paixunum(head);break;
		case 2:head=paixuxingzhi(head);break;
			
		default:break;
		}
	print(head);
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

void chaxun(void)
{
	int i,j;
	char c,s[21];
	struct Kecheng *head,*p;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����γ̲�ѯ����!\n");
	puts("********************************************************************************");
	do{
		puts("��ѡ��������Ϣ�����Բ��ҿγ�(1Ϊ�γ̱�� 2Ϊ�γ�����):");
		scanf("%d",&i);
		while((i!=1)&&(i!=2))
		{
			printf("�����������������:");
			scanf("%d",&i);
		}
		head=read();
		p=head;
		switch(i)
		{
		case 1:
			{
				printf("������Ҫ���ҿγ̵ı��:");
				scanf("%d",&j);
				while((p!=NULL)&&(p->num!=j))
					p=p->next;
				if(p==NULL)
				{
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		case 2:
			{
				printf("������Ҫ���ҿγ̵�����:");
				c=getchar();
				gets(s);
				while((p!=NULL)&&(strcmp(p->name,s)!=0))
					p=p->next;
				if(p==NULL)
				{
					printf("û���ҵ����ſγ�,�Ƿ񷵻���ҳ����²���(Y or N):");
					c=getchar();
					scanf("%c",&c);
					if((c=='Y')||(c=='y'))
						zhuyemian();
					else
						exit(0);
				}
				break;
			}
		default:break;
		}
		puts("�γ����ҵ�");
		puts("�γ̱�� �γ����� �γ����� ��ѧʱ �ڿ�ѧʱ ʵ����ϻ�ѧʱ ѧ�� ����ѧ��");
		printf("%d %s %s %d %d %d %d %d\n",p->num,p->name,p->xingzhi,p->timezong,p->timeke,p->timeji,p->fen,p->term);
		printf("�Ƿ��������(Y or N):");
		c=getchar();
		scanf("%c",&c);
	}while((c=='Y')||(c=='y'));
	write(head);	
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

void print(struct Kecheng *head)
{
	struct Kecheng *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d %s %s %d %d %d %d %d\n",p->num,p->name,p->xingzhi,p->timezong,p->timeke,p->timeji,p->fen,p->term);
		p=p->next;
	}
}

void xuanke(void)
{
	struct Kecheng *head,*p,*p1,*p2,*p3;
	int s=0,i=0,j,flag=0;
	char c;
	p=NULL;
	system("cls");
	puts("********************************************************************************");
	puts("			   ��ӭ����ѧ��ѡ�ν���!\n");
	puts("********************************************************************************");
	puts("Ŀǰ��ѡ�γ���:");
	head=read();
	head=paixunum(head);
	print(head);
	p3=p2=(struct Kecheng *)malloc(LEN);
	do
	{
		printf("\n��������Ҫ��Ҫѡ��γ̵ı��:");
		scanf("%d",&j);
		p1=head;
		while((p1!=NULL)&&(p1->num!=j))
			p1=p1->next;
		if(p1==NULL)
			printf("û���ҵ��ÿγ�!");
		else
		{
			if(p1->term==1)
			{
				puts("��Ҫѡ��Ŀγ���:");
				printf("%d %s %s %d %d %d %d %d\n",p1->num,p1->name,p1->xingzhi,p1->timezong,p1->timeke,p1->timeji,p1->fen,p1->term);
				if(i==0)
				{
					*p2=*p1;
					p=p2;
				}
				else
				{
					p3=p2;
					p2=(struct Kecheng *)malloc(LEN);
					*p2=*p1;
					p3->next=p2;	
				}
				i++;
				s=s+p1->fen;
				if(s>80)
				{
					puts("����ѡ�γ��ѳ���80ѧ��,���һ�ſγ�ѡ��ʧ��!");
					s=s-p1->fen;
					i--;
					flag=1;
				}
				printf("��������ѡ %d �ſγ�,���� %d ��ѧ��\n",i,s);
			}
			else
				puts("ѡ��ʧ�ܣ�����ѡ�Ŀγ̷Ǳ�ѧ�ڿγ�");
		}
		printf("�Ƿ����ѡ��(Y or N):");
		c=getchar();
		scanf("%c",&c);
	}while((c=='Y')||(c=='y'));
	if(s>60)
	{
		if(flag==0)
			p2->next=NULL;
		else
			p3->next=NULL;
		puts("\n����ѡ�γ�Ϊ:");
		print(p);
	}
	else
	{
		puts("����ѡ�γ̲���60ѧ��,��ѡ�γ̲�����¼!");
	}
	printf("�Ƿ񷵻�������(Y or N):");
	c=getchar();
	scanf("%c",&c);
	if((c=='Y')||(c=='y'))
		zhuyemian();
}

struct Kecheng *paixunum(struct Kecheng *head)
{
	int flag=0;
	struct Kecheng *p1,*p2,*p3,*p4;
	if(head==NULL)
		return head;
	else
		p1=p2=head->next;
	while(p2!=NULL)
	{
		p1=p1->next;
		if(p2->num<head->num)
		{
			p2->next=head;
			if(flag==0)
				head->next=NULL;
			head=p2;
			flag++;
		}
		else
		{
			if(flag>0)
			{
				p3=p4=head;
				while((p3!=NULL)&&(p2->num>p3->num))
				{
					p4=p3;
					p3=p3->next;
				}
				p4->next=p2;
				p2->next=p3;
			}
			if(flag==0)
			{
				flag++;
				p2->next=NULL;
			}
		}
		p2=p1;
	}
	return head;
}

struct Kecheng *paixuxingzhi(struct Kecheng *head)
{
	int flag=0;
	struct Kecheng *p1,*p2,*p3,*p4;
	if(head==NULL)
		return head;
	else
		p1=p2=head->next;
	while(p2!=NULL)
	{
		p1=p1->next;
		if(strcmp(p2->xingzhi,head->xingzhi)<0)
		{
			p2->next=head;
			if(flag==0)
				head->next=NULL;
			head=p2;
			flag++;
		}
		else
		{
			if(flag>0)
			{
				p3=p4=head;
				while((p3!=NULL)&&(strcmp(p2->xingzhi,p3->xingzhi)>0))
				{
					p4=p3;
					p3=p3->next;
				}
				p4->next=p2;
				p2->next=p3;
			}
			if(flag==0)
			{
				flag++;
				p2->next=NULL;
			}
		}
		p2=p1;
	}
	return head;
}