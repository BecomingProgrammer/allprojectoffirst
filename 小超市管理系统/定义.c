#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h> 
#include<conio.h> 
#include "С������Ʒ����ϵͳ.h"



//�ṹ����������궨�壬���������ļ�
 char s[10][15]={
"���", 
"��Ʒ����",
"����(Ԫ)",
"�ۼ�(Ԫ)",
"������",
"������",
"ʣ����",
"ë��(Ԫ)",
"����ʱ��",
"���۶�(Ԫ)"};



void UserInformation()//�û���Ϣ����ϵͳ 
{ 
	char choose;
	DrawUser();
	fflush(stdin); 
	while(1)
	{
		JudgeChoose(&choose);
		switch(choose)
		{
			case '1':UserLogin();break;
			case '2':UserRegister();break;
			case '3':exit(0);break;
			default:printf("���벻��ȷ�����������룡\n");
		}
		if(choose=='1')
		  break;
	}
}

void DrawUser()//ѡ���û�����  
{
	system("cls");
	printf("\n\n");
	printf("\t\t****************************************************************\n\n");
	printf("\t\t\t\t\t1.�û���¼\n\n");
	printf("\t\t\t\t\t2.�û�ע��\n\n");
	printf("\t\t\t\t\t3.�˳�ϵͳ\n\n");
	printf("\t\t****************************************************************\n");
	printf("����������ѡ�񣺣�1-3��:"); 
} 

void UserLogin()//�û���¼ 
{
	 int j;
	 int i=3;//��¼���� 
	 char name[100];
	 char password[100]; 
	 char account[10];
    char passwrd[17];
	 FILE *faccount;
	 faccount=fopen("password.txt","r");
	 fscanf(faccount,"%s %s",account,passwrd); 
	 system("cls");
	 while(1)
	 {
	 	printf("�������˺ţ�");
	    scanf("%100s",name);
	    fflush(stdin);//��ֹ������� 
	    printf("���������룺");
	    for(j=0;j<100;j++)
	    {
	    	password[j]=getch();
	    	if(password[j]=='\r')
	    	     {
	    	     	password[j]='\0';
	    	     	break;
	    	     }
	    	else
	    	printf("*");
	    }
	    fflush(stdin);
	    if(strcmp(account,name)==0&&strcmp(password,passwrd)==0)
	               {
	               	printf("�ɹ�");
	               	 fclose(faccount);
	               	break;//����useriformation���� 
	               }
	    if(i==0)
		{
			fseek(faccount,0,0); 
			printf("\n�˺��Ѿ�������������ϵ���ߣ�");
			fprintf(faccount,"%d",i);
			fclose(faccount);
			exit(0); 
		} 
	    printf("\n�˺Ŵ������������㻹��%d�λ�������\n",i--);
     }
}

void UserRegister()//�û�ע�� 
{
	char choose;
	system("cls");
	printf("\t\t****************************************************************\n\n");
	printf("\t\t\t\t\tע������ϵQQ:1246767689\n");
	printf("\t\t\t\t\t  ���ߣ�Alexander\n");
	printf("\t\t\t\t\t   ��1������\n");
	printf("\t\t****************************************************************\n\n");
	printf("����������ѡ��");
	while(1)
	{
		JudgeChoose(&choose);
		switch(choose)
		{
			case '1':DrawUser();break;
			default:printf("ѡ��������������룡");
		}
		if(choose=='1')
		 break;
	}
	
}

void CommodityInformation()//��Ʒ��Ϣ���� 
{
	HISTORY *headhistory=NULL;
	FILE *fp;
	COMMODITY *head=NULL;
	char choose;
	char string[30]="      �û���¼�ɹ�!!\n";
	headhistory=OpenLog();
	
	WriteHistory(headhistory,string);
	fp=fopen("С������Ʒ����.txt","r+");
	if(fp==NULL)
	{
		printf("��Դ����ʧ�ܣ����飡"); 
		exit(0);
	}
	DrawCommodity();
	head=MakeList(fp);//�������� 
	while(1)
	{
		JudgeChoose(&choose);
		switch(choose)
		{
			case '1':AddCommodity(head);WriteHistory(headhistory,"  1.  �����Ʒ\n");break;
			case '2':ChangeCommodity(head);WriteHistory(headhistory,"  2.  �޸���Ʒ��Ϣ\n");break;
			case '3':InquiryInformation(head,headhistory);break;
			case '4':BuyCommodity(head);WriteHistory(headhistory,"  4.  �������\n");break;
			case '5':DeleteCommodity(head);WriteHistory(headhistory,"  5.  ɾ����Ʒ\n");break;
			case '6':LookUpCommodity(head,headhistory);break;
			case '7':LookHistory(headhistory);break; 
			case '8':EXIT(head,headhistory);break;
			case '9':EXIT(head,headhistory);exit(0);break;
			default:printf("ѡ��������������룡");
		}
	 if(choose=='8')
	   break;
	}
	UserInformation();
	CommodityInformation();
} 


void DrawCommodity()//ѡ���ܽ��� 
{
	system("cls");
	
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t\t\t1.�����Ʒ\n\n");
    printf("\t\t\t\t\t2.�޸���Ʒ��Ϣ\n\n");
    printf("\t\t\t\t\t3.��ѯ\n\n");
    printf("\t\t\t\t\t4.������Ӻ͹�����Ʒ\n\n");
    printf("\t\t\t\t\t5.ɾ����Ʒ\n\n");
    printf("\t\t\t\t\t6.�鿴��Ʒ\n\n");
    printf("\t\t\t\t\t7.��ʷ��¼\n\n");
    printf("\t\t\t\t\t8.���ص�¼ҳ��\n\n");
    printf("\t\t\t\t\t9.��ȫ�˳�\n\n");
	printf("\t\t****************************************************************\n\n");
	printf("����������ѡ��(1-7)��");
}

void AddCommodity(COMMODITY *head)//�����Ʒ 
{
	COMMODITY *current,**link=&head;
	char choose;
	system("cls");
	while(current=*link)
	 link=&current->next;
    while(1)
    {
    	current=(COMMODITY *)malloc(sizeof(COMMODITY));
    	printf("%s��",s[0]);
    	scanf("%d",&current->num); 
    	printf("%s��",s[1]);
    	scanf("%s",current->name);
    	printf("%s��",s[2]);
    	scanf("%f",&current->purchase_price);
    	printf("%s��",s[3]);
    	scanf("%f",&current->selling_price);
    	printf("%s��",s[4]);
    	scanf("%d",&current->purchae_num);
    	printf("%s��",s[5]);
    	scanf("%d",&current->selling_num);
    	printf("%s��",s[6]);
    	scanf("%d",&current->surplus_num);
    	printf("%s��",s[7]);
    	scanf("%f",&current->profit);
    	printf("%s��",s[8]);
    	scanf("%s",current->date);
    	printf("%s��",s[9]);
    	scanf("%f",&current->salves_tall);
		Calculate(current);
		*link=current;
		link=&current->next;
		printf("�Ƿ�������루Y��N��:");
		//���ѡ���㷨�ж� 
		fflush(stdin); 
	   do
		{
		scanf("%c",&choose);
		getchar();
		switch(choose)
		{
			case 'Y':;break;
			case 'y':;break;
			case 'N':DrawCommodity(); break;
			case 'n':DrawCommodity();break;
			default:printf("\n��������Ƿ������ӣ�Y��N��:"),choose=0;
		} 
	   }while(choose==0);
		if(choose=='N'||choose=='n')
		   break;
    }
	*link=NULL; 
	
}


void ChangeCommodity(COMMODITY *head)//�޸���Ʒ��Ϣ 
{
	//�����޸ĺ����Ʒ��Ϣ 
   	COMMODITY temp; 
    COMMODITY *current,**link=&head;
	char choose;
	system("cls");
	current=InquiryName(head);
	if(current)
{
    printf("�������޸ĺ����Ʒ��Ϣ:\n");
    	printf("%s��",s[0]);
    	scanf("%d",&current->num); 
    	printf("%s��",s[1]);
    	scanf("%s",current->name);
    	printf("%s��",s[2]);
    	scanf("%f",&current->purchase_price);
    	printf("%s��",s[3]);
    	scanf("%f",&current->selling_price);
    	printf("%s��",s[4]);
    	scanf("%d",&current->purchae_num);
    	printf("%s��",s[5]);
    	scanf("%d",&current->selling_num);
    	printf("%s��",s[6]);
    	scanf("%d",&current->surplus_num);
    	printf("%s��",s[7]);
    	scanf("%f",&current->profit);
    	printf("%s��",s[8]);
    	scanf("%s",current->date);
    	printf("%s��",s[9]);
    	scanf("%f",&current->salves_tall);
		//��ȡ�޸���Ϣĩβ�Ļ��з�
	  getchar(); 
    Calculate(current);;
	printf("�޸ĳɹ�!\n");
}
	printf("��1����............................\n");
	do
	{
		JudgeChoose(&choose); 
		if(choose=='1')
		  break;
		else
		printf("������ϣ��ٵ���·,�������룺\n");
	}while(choose=='0');
	DrawCommodity();
}

void InquiryInformation(COMMODITY *head,HISTORY *headhistory)//��ѯ��Ϣ 
{
	char choose;
	system("cls");
	WriteHistory(headhistory,"  3.  ��ѯ\n");
	 printf("\t\t****************************************************\n\n");
	printf("\t\t\t1.����Ʒ���Ʋ�ѯ\n\n");
	printf("\t\t\t2.����ʣ������ѯ\n\n"); 
	printf("\t\t\t3.����\n\n");
	printf("\t\t****************************************************\n\n");
	do
	{
		printf("����������ѡ��1~3����");
		JudgeChoose(&choose);
		switch(choose)
		{
			case '1':InquiryName(head);WriteHistory(headhistory,"  3.1 ����Ʒ���Ʋ�ѯ\n");break;
			case '2':InquirySurplus(head);WriteHistory(headhistory,"  3.2 ����ʣ������ѯ\n");break;
			case '3':WriteHistory(headhistory,"  3.3 ����������\n");break;
			default :printf("�������"); 
			
		}
		if(choose=='3')
			break;
	}while(1);
	DrawCommodity();
}

COMMODITY *InquiryName(COMMODITY *head)//�����Ʋ�ѯ 
{
    COMMODITY *current,**link=&head;
    char name[15];
    printf("������Ҫ��ѯ����Ʒ���ƣ�");
    gets(name);
	//���б������� 
    while((current=*link)!=NULL&&strcmp(name,current->name)!=0)
         link=&current->next;
    if(*link) 
    {
    printf("%4s%13s%10s%12s%10s%12s%12s%12s%14s%14s\n",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
    printf("%-4d%13s%10.1f%12.1f%10d%12d%12d%12.1f%14s%14.1f\n",current->num,current->name,current->purchase_price,
		current->selling_price,current->purchae_num,current->selling_num,current->surplus_num,
		current->profit,current->date,current->salves_tall);
	} 
	else 
	printf("û�в鵽����Ʒ����Ϣ����ȷ�Ϻ��ѯ\n");
	return current; 
}

void InquirySurplus(COMMODITY *head)//��ʣ������ѯ 
{
	//ʣ���� 
	int surplus;
	 COMMODITY *current,**link=&head;
	 printf("�������ѯ��ʣ������");
	 scanf("%d",&surplus); 
	 getchar();
	 printf("%4s%13s%10s%12s%10s%12s%12s%12s%14s%14s\n",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
	 while((current=*link)!=NULL)
         {
         	if(current->surplus_num<=surplus)
        printf("%-4d%13s%10.1f%12.1f%10d%12d%12d%12.1f%14s%14.1f\n",current->num,current->name,current->purchase_price,
		current->selling_price,current->purchae_num,current->selling_num,current->surplus_num,
		current->profit,current->date,current->salves_tall);
		     link=&current->next;
         }
     
}


void BuyCommodity(COMMODITY *head) //���� 
{
	char choose;
    char name[15];
	int num; 
    COMMODITY *current,**link=&head;
    system("cls");
    printf("\t\t****************************************************\n\n");
	printf("\t\t\t1.����\n\n");
	printf("\t\t\t2.������Ʒ\n\n"); 
	
	printf("\t\t****************************************************\n\n");
    printf("���������ѡ��(1-2):");
    while(1)
    {
    	choose=getchar();
switch(choose)
{
	case '1': 
	printf("��������Ʒ��Ҫ���ӵ���Ʒ������\n");
    scanf("%s %d",name,&num);
    //���б������� 
    while((current=*link)!=NULL&&strcmp(name,current->name)!=0)
         link=&current->next;
	if(current)
	{
	 current->purchae_num+=num;
	 Calculate(current);
	 printf("�����ɹ���\n");
	} 
	 else
	 printf("����ʧ�ܣ�������Ʒ�����Ƿ���ȷ��\n"); 
	 fflush(stdin);
	 break;
	 case '2':
	 	printf("��������Ʒ��Ҫ�������Ʒ������\n");
	 	scanf("%s %d",name,&num);
    //���б������� 
    while((current=*link)!=NULL&&strcmp(name,current->name)!=0)
         link=&current->next;
	if(current)
	{
	 current->selling_num+=num;
	 Calculate(current);
	 printf("����ɹ���\n");
	} 
	 else
	 printf("����ʧ�ܣ�������Ʒ�����Ƿ���ȷ��\n"); 
	 fflush(stdin);
	 break;
	 
}
    if(choose=='1'||choose=='2')
	   break;
	 else
	 {
	 	printf("����������������룡\n");
	 	getchar();
	 } 
}
	do
	{
		printf("��1����......\n");
		fflush(stdin);
		choose=getch();
		if(choose=='1')
		  break;
		else
		 choose='0';
	}while(choose=='0') ;
    DrawCommodity();
}

void DeleteCommodity(COMMODITY *head)//ɾ����Ʒ 
{
	char c; 
	char choose;
	COMMODITY *current,**link=&head;
	char name[15];
	system("cls");
	printf("������Ҫɾ������Ʒ��");
	gets(name);
	while((current=*link)!=NULL&&strcmp(name,current->name)!=0)
         link=&current->next;
    if(current==NULL)
    {
    	printf("������������������Ʒ�����Ƿ���ȷ��\n");
    }
    else
    {
	printf("�Ƿ�ɾ����Y/N\n");
	if((c=getchar())=='Y'||c=='y')
	{
		
         *link=current->next;
		 free(current);
		 printf("ɾ���ɹ���\n");
	}
    }
	do
	{
		printf("��1������....\n");
		 fflush(stdin);
		choose=getch();
		if(choose=='1')
		  break;
		else
		 choose='0';
	}while(choose=='0');
	DrawCommodity();
	
} 

void LookUpCommodity(COMMODITY *head,HISTORY *headhistory)//�鿴��Ʒ 
{
	COMMODITY *current,**link=&head;
	char choose;
	WriteHistory(headhistory,"  6.  �鿴��Ʒ\n"); 
	fflush(stdin);
	system("cls"); 
	do
	{
	
	printf("\t\t****************************************************\n\n");
	printf("\t\t\t1.����˳����ʾ\n\n");
	printf("\t\t\t2.��ë���ߵ��͵�˳����ʾ\n\n");
	printf("\t\t\t3.�����۸ߵ��͵�˳����ʾ\n\n"); 
	printf("\t\t\t4.������ʱ�����Զ��˳����ʾ\n\n"); 
	printf("\t\t\t5.����\n\n");
	printf("\t\t****************************************************\n\n");
	choose=getch();
	switch(choose)
	{
		case '1': head=sort(head,comp);print(head);WriteHistory(headhistory,"  6.1 ����˳����ʾ\n");break;
		case '2': head=sort(head,compprofit);print(head);WriteHistory(headhistory,"  6.2 ��ë���ߵ��͵�˳����ʾ\n");break;
		case '3': head=sort(head,compsell);print(head);WriteHistory(headhistory,"  6.3 �����۸ߵ��͵�˳����ʾ\n");break; 
		case '4': head=sort(head,compdate);print(head);WriteHistory(headhistory,"  6.4 ������ʱ�����Զ��˳����ʾ\n");break; 
		case '5':choose='0';WriteHistory(headhistory,"  6.5 ����������\n");break;
	}
	if(choose=='0')
	break;
	} while(1);
	DrawCommodity();
} 


void LookHistory(HISTORY *head)
{
	HISTORY *p;
	char choose;
	system("cls");
	p=head->next;
	if(p)
	{
		while(p)
		{
			printf("%s",p->operate_time);
			p=p->next;
		}
	}
	else
	{
		printf("û����ʷ��¼��\n");
	}
	while(1)
	{
	printf("��1����������...........\n");
	choose=getch();
	if(choose=='1')
	   break;
    }
    DrawCommodity();
}


void JudgeChoose(char *choose)//�˵�ѡ��ʹ�õ��㷨 
{
	scanf("%c",choose);
		if(getchar()!='\n')
		  {
		  	   *choose='0';
		  	   fflush(stdin);
		  } 
}



COMMODITY *MakeList(FILE *fp)//�������� 
{
	COMMODITY *head;
	COMMODITY *current;
	COMMODITY **link=&head;
	//��ȡ�ı��еĵ�һ�� 
  	char abandon[200];
	fgets(abandon,200,fp);
	while(1)
	{
		current=(COMMODITY *)malloc(sizeof(COMMODITY ));
		fscanf(fp,"%d %s %f %f %d %d %d %f %s %f",&current->num,current->name,&current->purchase_price,
		&current->selling_price,&current->purchae_num,&current->selling_num,&current->surplus_num,
		&current->profit,current->date,&current->salves_tall);
		Calculate(current);
		 if(feof(fp)!=0)
		   break;
		*link=current;
		link=&current->next;
	
	}
	*link=NULL;
	link=&head;
	//�رջ���������������ʱ��Ϣ�������д��棬�˳�ʱ�����ļ� 
	fclose(fp); 
	return head;
}



int comp(const void *a,const void *b)
{
	return (*(COMMODITY *)a).num>(*(COMMODITY*)b).num?1:-1;
}

int compprofit(const void *a,const void *b)
{
return (*(COMMODITY *)b).profit>(*(COMMODITY*)a).profit?1:-1;
}

int compsell(const void *a,const void *b)
{
	return (*(COMMODITY*)b).salves_tall>(*(COMMODITY *)a).salves_tall?1:-1; 
}


int compdate(const void *a,const void *b)//��ؼ��� 
{
	int cyear,dyear;
	int cmonth,dmonth;
	int cday,dday;
	COMMODITY *c=(COMMODITY*)a;
	COMMODITY *d=(COMMODITY*)b;
	sscanf(c->date,"%d/%d/%d",&cyear,&cmonth,&cday);
	sscanf(d->date,"%d/%d/%d",&dyear,&dmonth,&dday);
	if(cyear!=dyear)
	 return cyear-dyear;
	else if(cmonth!=dmonth)
	 return cmonth-dmonth;
	else if (cday!=dday)
	return cday-dday;
} 

COMMODITY *sort(COMMODITY *head,int (*comp)(const void *a,const void *b))//��ѡ�����򷨽������������ 
{
	 COMMODITY *current,**link=&head,*current1,**link1=&head,**templink,*tempcurrent,*temp;
	 while(current=*link)
	 {
	 	link1=&current->next;
	 	templink=link;
	 	tempcurrent=current;
	 	while(current1=*link1)//����ɨ��ȵ�ǰ��С�� 
	 	{
	 		if(comp(tempcurrent,current1)>0)
	 		{
	 			    templink=link1;
	 			    tempcurrent=current1;
	 		}
	 		link1=&current1->next;
	 	}
	 	if(current->next==tempcurrent)//����ǰ�Ľڵ����һ���ڵ���tempcurrentʱ 
	 	{
	 		*link=tempcurrent;
	 		temp=tempcurrent->next;
	 		tempcurrent->next=current;
	 		current->next=temp;
	 		link=&tempcurrent->next;
	 	}
	 	else if(tempcurrent!=current)
	 	{
	 		temp=current->next;
	 		current->next=tempcurrent->next;
	 		tempcurrent->next=temp;
	 		*link=tempcurrent;
	 		*templink=current;
	 		link=&tempcurrent->next;
	 	}
	 	else
	 	{
	 		link=&current->next;
	 	}
	 }
	 return head;
} 


void print(COMMODITY *head)
{
	COMMODITY **link=&head,*current;
	printf("%4s%13s%10s%12s%10s%12s%12s%12s%14s%14s\n",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
	while(current=*link)
	{
		printf("%-4d%13s%10.1f%12.1f%10d%12d%12d%12.1f%14s%14.1f\n",current->num,current->name,current->purchase_price,
		current->selling_price,current->purchae_num,current->selling_num,current->surplus_num,
		current->profit,current->date,current->salves_tall);
		link=&current->next;
	}
	printf("\n"); 
}

void Calculate(COMMODITY *current)//�Զ����� 
{
	current->salves_tall=current->selling_price*current->selling_num;
	current->surplus_num=current->purchae_num-current->selling_num;
   	current->profit=current->salves_tall-current->purchase_price*current->selling_num;
}

HISTORY *OpenLog()
{
   char history[200];
   FILE *flog;
   HISTORY  *head=NULL,*current,*p;
	if((flog=fopen("log.txt","r+"))==NULL)
	{
		      printf("open the history failed!\n");
			  exit(0); 
	}
	head=(HISTORY *)malloc(sizeof(HISTORY));
	head->next=NULL;
	p=head;
	for(;;)//����������˳�������� 
	{ 
		fgets(history,200,flog);
		if(feof(flog)!=0)
		    break;
		if(strcmp(history,"\n")==0)
		    break;
		current=(HISTORY *)malloc(sizeof(HISTORY));
		strcpy(current->operate_time,history);
		p->next=current;
		p=current;
		
	}
	p->next=NULL;
	fclose(flog);
	return head; 
}


void  WriteHistory(HISTORY *head,const char *operate)
{
	time_t t;
    struct tm *p;
    HISTORY *current; 
    int i;
    t=time(NULL);
    p=localtime(&t);
    current=(HISTORY *)malloc(sizeof(HISTORY));//������ȳ���˳��������� 
    strcpy(current->operate_time,asctime(p));
    for(i=0;current->operate_time[i]!='\n';i++)
                   ;
    current->operate_time[i]='\0';
    strcat(current->operate_time,operate);
    current->next=head->next;
    head->next=current;
} 

void EXIT(COMMODITY *head,HISTORY *headhistory) 
{
	COMMODITY *current=head;
	FILE *fp,*flog;
	fp=fopen("С������Ʒ����.txt","w+");
	flog=fopen("log.txt","w+");
	fprintf(fp,"%4s%13s%10s%12s%10s%12s%12s%12s%14s%14s\n",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9]);
	while(current)//�˳�ʱ�����ļ� 
	{
		fprintf(fp,"%-4d%13s%10.1f%12.1f%10d%12d%12d%12.1f%14s%14.1f\n",current->num,current->name,current->purchase_price,
		current->selling_price,current->purchae_num,current->selling_num,current->surplus_num,
		current->profit,current->date,current->salves_tall);
		current=current->next;
	}
	headhistory=headhistory->next;
	while(headhistory)
	{
		fprintf(flog,"%s",headhistory->operate_time);
		headhistory=headhistory->next;
	}
	
}



