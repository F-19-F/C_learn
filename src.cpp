#include <iostream>
using namespace std;
struct DATA 
{
	char name[20];
	int Mark;
	DATA *Next;
};
class list 
{
private :
	int length;
	DATA *Head,*Last;//Head�����洢ͷ���ĵ�ַ��Last�����洢�����β��
public :
	list ()
	{
		printf ("create class list\n");
		Initlist();
	}
	~list()//����ͬʱ�ѷ�����ڴ��ͷ�
	{
		/*DATA*temp=Head;
		DATA*temp_Next;
		while(temp)
		{
		temp_Next=temp->Next;
		free(temp);
		temp=temp_Next;
		}*/
		Clearlist();
	}
	bool Initlist ();//�����ʼ��
	bool Insertlist(int Mark,char*name,int n);//��������
	bool Deletelist(int n);//ɾ��ĳ�����
	bool Addlist(int Mark,char*name);//���������
	void Showlist();//չʾ����
	void Createlist();//����һ����������
	void Clearlist();
};
bool list::Initlist ()//��ʼ������
{
	if (!Head)//�������Ѿ�����Headʱ����Initlist
		return NULL;
	if((Head=(DATA*)malloc (sizeof(DATA))))
	{	
		Head->Next=NULL;
		Last=Head;
		length=0;
	}
	else 
		return NULL;
	return 1;
}
bool list::Insertlist(int Mark,char* name,int n)
{
	DATA *Temp=Head;
	if (n==length)//�������ڵ���ĩβʱ���ٵ���Lastָ��,���Լ��ٲ���ĩβʱ���ٶ�
		if(Addlist(Mark,name))
			return true;
		else
			return false;
	int i=0,j=0;//iָ��Ϊλ��ָʾ��
	while (Temp!=NULL)
	{
		if (i+1==n)
		{
			DATA *T;//�洢ǰһ������β��
			T=Temp->Next;
			Temp->Next=(DATA*)malloc(sizeof(DATA));//�����ڴ�
			Temp=Temp->Next;//ʹ���·�����ڴ�
			Temp->Next=T;//���������һλ����ַ�������뵽�Ľ��
			Temp->Mark=Mark;//�����Ǹ�����Ľ�㸳ֵ
			while (1)
			{
				Temp->name[j]=*name;
				if (*name=='\0')
					break;
				name++;
				j++;
			}
			length++;
			return true;
		}
		Temp=Temp->Next;
		i++;
	}
	return false;
}
bool list::Addlist(int Mark,char *name)//��ĩβ���һ�����
{
	DATA *Temp=Last;
	if(Temp->Next=(DATA*)malloc(sizeof (DATA)))
		Temp=Temp->Next;
	else return false;
	Temp->Mark=Mark;
	int j=0;
	while (1)
	{
		Temp->name[j]=*name;
		if (*name=='\0')
			break;
		name++;
		j++;
	}
	Temp->Next=NULL;
	Last=Temp;
	length++;
}
bool list::Deletelist(int n)
{
	return NULL;
}
void list::Showlist()
{
	DATA *temp;
	temp=Head->Next;
	while (temp!=NULL)
	{
		cout<<"����"<<temp->name<<endl;
		cout<<"����"<<temp->Mark<<endl;
		cout<<endl;
		temp=temp->Next;
	}
}
void list::Createlist()
{
	int i=length+1;
	int times=i;
	DATA *temp=Last;
	char Name[20];
	int Mark;
	cout<<"**********����С��0ʱ����������***********"<<endl;
	cout<<"�������"<<i<<"������"<<endl;
	cout<<"����:";
	cin>>Mark;
	while (Mark>0)
	{
		if (i==times)
		{
			temp=Last->Next=(DATA*)malloc(sizeof(DATA));
			cout<<"����:";
			cin>>Name;
			temp->Mark=Mark;
			char *name=Name;
			int j=0;
			while (1)
			{
				temp->name[j]=*name;
				if (*name=='\0')
					break;
				name++;
				j++;
			}
			Last=temp;
			Last->Next=NULL;
			i++;
			continue;
		}
		cout<<"�������"<<i<<"������"<<endl;
		cout<<"����:";
		cin>>Mark;
		if (Mark<=0)
			break;
		cout<<"����:";
		cin>>Name;
		temp=Last->Next=(DATA*)malloc(sizeof(DATA));
		temp->Mark=Mark;
		char *name=Name;
			int j=0;
			while (1)
			{
				temp->name[j]=*name;
				if (*name=='\0')
					break;
				name++;
				j++;
			}
		Last->Next=temp;
		Last=temp;
		Last->Next=NULL;
		i++;
	}

}
void list::Clearlist()//��ÿ��������free����������
{
	DATA*temp=Head;
	DATA*temp_Next;
	while(temp)
	{
		temp_Next=temp->Next;
		free(temp);
		temp=temp_Next;
	}
	Head=Last=NULL;
}
int main()
{
	list a;
	char *b="shabi";
	a.Createlist();
	/*a.Addlist(12,b);
	a.Addlist(13,b);*/
	a.Insertlist(16,b,3);
	a.Showlist();
	system("pause");
	return 0;
}