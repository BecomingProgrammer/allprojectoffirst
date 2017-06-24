

typedef struct Commodity
{
	int num;
	char name[15];//���� 
	float purchase_price;//���� 
	float selling_price;//�ۼ� 
	int purchae_num;//������� 
	int selling_num;//�������� 
	int surplus_num;//ʣ���� 
	float profit;//ë��
	char date[12];//����ʱ�� 
	float salves_tall;//���۶� 
	struct Commodity *next;
}COMMODITY;


typedef struct history
{ 
	char operate_time[80];
	struct history *next;
}HISTORY;




 

void JudgeChoose(char *choose);//ѡ��˵��㷨 

COMMODITY *MakeList(FILE *fp);//�������� 

void UserInformation();//�û���Ϣ����

void DrawUser();//ѡ���û����� 

void UserLogin();//�û���¼ 

void UserRegister();//�û�ע�� 

void CommodityInformation();//��Ʒ��Ϣ����

void DrawCommodity();//ѡ���ܽ���  

void AddCommodity(COMMODITY *head);//�����Ʒ 

void ChangeCommodity(COMMODITY *head);//�޸���Ʒ��Ϣ 

void InquiryInformation(COMMODITY *head,HISTORY *headhistory);//��ѯ��Ϣ 

COMMODITY * InquiryName(COMMODITY *head);//�����Ʋ�ѯ

void InquirySurplus(COMMODITY *head);//��ʣ������ѯ 

void BuyCommodity(COMMODITY *head) ;//���� 

void DeleteCommodity(COMMODITY *head);//ɾ����Ʒ 

int comp(const void *a,const void *b);//�����������˳�� 

int compprofit(const void *a,const void *b);//������������˳�� 

int compsell(const void *a,const void *b);//�������۶�����˳�� 

int compdate(const void *a,const void *b);//��������ʱ������˳�� 

COMMODITY *sort(COMMODITY *head,int (*comp)(const void *a,const void *b));//���� 

void print(COMMODITY *head);//��� 

void LookUpCommodity(COMMODITY *head,HISTORY *headhistory);//�鿴��Ʒ 

void Calculate(COMMODITY *current);//�Զ����� 

HISTORY *OpenLog();//����־

void  WriteHistory(HISTORY *head,const char *operate);//д����־

void LookHistory(HISTORY *head);//�鿴��־

void EXIT(COMMODITY *head,HISTORY *headhistory);//�˳������ļ� 
