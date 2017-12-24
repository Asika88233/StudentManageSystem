#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"System.h"
void start()
{
	printf("*****************************");
    printf("��ӭʹ��ѧ������ϵͳ");
    printf("*****************************\n");
}

 void create_head()
{
  head=(student*)malloc(sizeof(student));
  memset(head,0,sizeof(student));
  head->next=NULL;
}
 void free_student(student* one)
{
	if(one!=NULL)
	{
		if(one->name!=NULL)
		{
			free(one->name);
		}
		if(one->address!=NULL)
		{
			free(one->address);
		}
		
	   free(one);
	}
}
student* New_student()
{

	student* temp=(student*)malloc(sizeof(student));
	if(temp==NULL)
	{
		goto FAILED;
	  }
	 memset(temp,0,sizeof(student));
	 
	  temp->name=(char*)malloc(50*sizeof(char));
	   if(temp->name==NULL)
    	{
		  goto FAILED;
	        }
	    memset(temp->name,0,50*sizeof(char));
	    
	      temp->address=(char*)malloc(100*sizeof(char));
	        if(temp->address==NULL)
	       {
		      goto FAILED;
	           }
              memset(temp->address,0,100*sizeof(char));
              return temp;
                    
	FAILED:
	if(temp!=NULL)
	{
		if(temp->name!=NULL)
		{
			free(temp->name);
		}
		if(temp->address!=NULL)
		{
			free(temp->address);
		}
		
		free(temp);
	}
	return NULL;
}
//��ʽ������ѧ���ڵ㣬ע�����ͷָ�벻��洢���ã��ʲ������ڲ��ռ����ռ�

int read_file()
{
 FILE *read;
 
 read=fopen("studentInfomation.txt","r");
 if(read==NULL)
 {
  printf("�ļ���ʧ��\n");
  return 0;
 }
 while(!feof(read))//��һ������bug��ÿд��һ����Ϣ��Ӧ�ô���һ���µĿռ���������������whileѭ���м��봴���½ڵ�Ĳ�����˵���׻����Լ�����������ƫ�������Ҫ�����ε�
 {
  student *temp=New_student();
  fscanf(read,"%d %s %d %s",&temp->num,temp->name,&temp->age,temp->address);
  if(head->next==NULL)
  {
     head->next=temp;  
  }
  else
  {
     temp->next=head->next;
	 head->next=temp;  
  }
 }
 fclose(read);
 return 1;//����1��ʾ����ִ�гɹ�
}
void read_compelte()
{
 if((read_file))//�������ˡ�����Ӧ���Ǳ������ı�׼̫�ϣ�˳���²�һ�����ide�����б����������ں���ͷ������������
 {
 printf("�ļ�д��ɹ���\n");
 }
 else
 {
 printf("�ļ�д��ʧ�ܣ�\n");
 }
}



void menu()
{
 printf("-------------------------");
 printf("������������������һ������");
 printf("-------------------------\n");
 printf("1.��ѯѧ����Ϣ\n");
 printf("2.ɾ��ѧ����Ϣ\n");
 printf("3.���ѧ����Ϣ\n");
 printf("4.��ʾ����ѧ��\n");
 printf("5.�޸�ѧ����Ϣ\n");
 printf("6.����������Ϣ\n");
 printf("0.�˳�����ϵͳ\n");
}

void display()
{
      //student *temp=New_student();  tempָ�뱾����Ҫ��������ռ䣬��Ϊ��ֻ��һ��Ѱַָ�룬����ռ�����˷�
	  student* temp=NULL;
	  //student* find=NULL;
	  //find=head;
      temp=head->next;
      printf("*****************************����Ϊȫ��ѧ����Ϣ*****************************\n");
	  printf("ѧ��\t����\t����\t��ַ\t\n");
	  while(temp)//ֻҪ����ڵ㲻Ϊ�գ��ͼ�����ӡ��ָ����һ���ڵ�
	  {
		  
	  printf("%d\t",temp->num);
	  printf("%s\t",temp->name);
	  printf("%d\t",temp->age);
	  printf("%s\t",temp->address);
	  printf("\n");
	  temp=temp->next;
	  }
	  
}
void add_student()
{
	
  int num=0;
  int age=0;
  char name[20];
  char address[50];
  student* temp=New_student();

  printf("*****************************�������ѧ����Ϣ*****************************\n");
  printf("����������ѧ��,�Իس�����������һ���жϸ�ʽ�Ƿ���ȷ��������ʾ�������ʽ��ȷ\n");
  scanf("%d",&num);
  while(scanf("%d",&num)!=1||input_check(num)!=1)
  {
	  printf("ѧ��������������ظ���\n");
      printf("���������룡\n");
	  fflush(stdin);//ˢ�»���������ʱscanf��õ�ֵ��ˢ���������½��е�һ���������û���������
   
  }
  printf("����������\n");//�������ַ�����ʽ���棬������Ҳ�д������ֵ���ʽ���ʲ�������
  scanf("%s",name);
  printf("��������������,�Իس�����������һ���жϸ�ʽ�Ƿ���ȷ��������ʾ�������ʽ��ȷ\n");
  scanf("%d",&age);
  while(1!=scanf("%d",&age))
  {
	  printf("������������\n");
      printf("���������룡\n");
	  fflush(stdin);//������������ݣ�ˢ�»������������û���������
  }

  printf("�������ַ\n");
  scanf("%s",address);
  
  temp->num=num;
  temp->age=age;
  strcpy(temp->name,name);
  strcpy(temp->address,address);
  
  temp->next=head->next;
  head->next=temp;
  if(temp!=NULL)
  {
   printf("���ѧ����Ϣ�ɹ���\n");
  }
  else
  {
   printf("���ѧ����Ϣʧ�ܣ�\n");
  }
  /* ����˼· ���ȴ�����ʱ���������û���������ݣ�������������
   ����������������ˢ�»�����������ȷ������󣬽�ֵ����tempָ��ָ���
   �洢�ڵ㡣
  */
}
student* serach_student()//����һ���洢�ڵ�
{
  int get_num=0;
  student *temp=New_student();//NULL
  temp=head->next;
  
  printf("*****************************���ڲ�ѯѧ����Ϣ*****************************\n\n");
  
  printf("����������ѧ��,�Իس�����������һ���жϸ�ʽ�Ƿ���ȷ��������ʾ�������ʽ��ȷ\n");
  scanf("%d",&get_num);

  while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("ѧ����������\n");
      printf("���������룡\n");
	  fflush(stdin);//ˢ�»���������ʱscanf��õ�ֵ��ˢ���������½��е�һ���������û���������
  }
 while(temp&&temp->num!=get_num)
  {
   temp=temp->next;
  }
 return temp;//����һ���ṹ�幩��������ʹ�ã�������ߺ������öȻ�����ɾ��������ʹ�ã�����û����ô��
}

int input_check(int value)//����ظ��������������1�����ظ�������0�����ظ�
{
 student *temp=New_student();
 temp=head->next;
 while(temp&&temp->num!=value)
  {
   temp=temp->next;
  }
 if(temp==NULL)
 {
   return 1;
 }
 else
 {
   return 0;
 }

}
void fix()//��ʱdebug����Ϊ�ڶ�ȡ�ļ���ʱ�����ǻ����һ��ѧ��0�����ݣ�����ɾ��������Ӱ�����ݵ���ȷ��
{
student* temp=NULL;
student* find=NULL;
temp=head->next;
find=head;
while(temp->num!=0)
   {
      find=temp;
      temp=temp->next;
   }
   find->next=temp->next;
   free(temp);  
}

void del_student()
{
 int get_num=0;
 student* temp=NULL;
 student* find=NULL;
 temp=head->next;
 find=head;//�ⲽ��������Ҫ�����������ѯ����ѧ��������ĵ�һ��λ��ʱҲ����ȷ��ɾ��
 printf("*****************************����ɾ��ѧ����Ϣ*****************************\n");
 printf("����������ѧ��,�Իس�����������һ���жϸ�ʽ�Ƿ���ȷ��������ʾ�������ʽ��ȷ\n");
 scanf("%d",&get_num);
   while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("ѧ����������\n");
      printf("���������룡\n");
	  fflush(stdin);//ˢ�»���������ʱscanf��õ�ֵ��ˢ���������½��е�һ���������û���������
  }
   while(temp->num!=get_num)
   {
      find=temp;
      temp=temp->next;
   }
   find->next=temp->next;
   free(temp);  //��Ϊ�ǵ���������Ҫһ��findָ��������֮ǰtempָ��ĵ�ַ�����ܱ�֤�����������⡣

 if(temp)
 {
   printf("ɾ���ɹ���\n");
 }
 else
 {
   printf("ɾ��ʧ�ܣ�\n");
 }
}
void s_display(student* one)
{
 if(one==NULL)
 {
   printf("��ѯʧ��!����ѧ�������Ƿ���ȷ!\n");
 }
 else
 {
      printf("ѧ��\t����\t����\t��ַ\t\n");
      printf("%d\t",one->num);
	  printf("%s\t",one->name);
	  printf("%d\t",one->age);
	  printf("%s\t",one->address);
	  printf("\n");
 }
}
int save()
{
 int i=0;//��������
 FILE *save;
 student* temp=NULL;
 temp=head->next;
 save=fopen("studentInfomation.txt","w+");
 if(save==NULL)
 {
  printf("�ļ���ʧ��\n");
  return 0;
 }
 while(temp)
 { 
  fprintf(save,"%d %s %d %s ",temp->num,temp->name,temp->age,temp->address);
  temp=temp->next;
  i++;
 }
 printf("һ��������%d��ѧ����Ϣ\n",i);
 fclose(save);
 return 1;//����1��ʾ����ִ�гɹ�
}
void mod_student()
{
  int get_num=0;
  int mod=0;
  student* temp=NULL;
  temp=head->next;
  printf("*****************************�����޸�ѧ����Ϣ*****************************\n");
  printf("����������ѧ��,�Իس�����������һ���жϸ�ʽ�Ƿ���ȷ��������ʾ�������ʽ��ȷ\n");
   scanf("%d",&get_num);
   while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("ѧ������������ǲ�����\n");
      printf("���������룡\n");
	  fflush(stdin);//ˢ�»���������ʱscanf��õ�ֵ��ˢ���������½��е�һ���������û���������
  }
   while(temp->num!=get_num)
   {
      temp=temp->next;
   }
  printf("***************************����Ҫ�޸ĵ�ѧ����Ϣ����***************************\n");
   s_display(temp);
    printf("--------------------");
    printf("�������������޸�����Ҫ�޸ĵ���Ϣ��");
    printf("--------------------\n");
    printf("1.ѧ��\t2.����\t3.����\t4.��ַ\t\n");
	scanf("%d",&mod);
	
 switch(mod)
 {
 case 1:
   printf("�������µ�ѧ��.\n");
   scanf("%d",&temp->num);
   break;
   case 2:
   printf("�������µ�����.\n");
   scanf("%s",temp->name);
   break;
   case 3:
   printf("�������µ�����.\n");
   scanf("%d",&temp->age);
   break;
   case 4:
   printf("�������µĵ�ַ.\n");
   scanf("%s",temp->address);
   break;
   default:
   printf("��������ȷ��ָ��.\n");
 }
}