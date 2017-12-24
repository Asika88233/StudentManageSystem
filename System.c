#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"System.h"
void start()
{
	printf("*****************************");
    printf("欢迎使用学生管理系统");
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
//公式化创建学生节点，注意的是头指针不起存储作用，故不给其内部空间分配空间

int read_file()
{
 FILE *read;
 
 read=fopen("studentInfomation.txt","r");
 if(read==NULL)
 {
  printf("文件打开失败\n");
  return 0;
 }
 while(!feof(read))//第一个致命bug，每写入一个信息后都应该创建一个新的空间来保存它，故在while循环中加入创建新节点的操作，说到底还是自己的理解出现了偏差！将来是要负责任的
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
 return 1;//返回1表示函数执行成功
}
void read_compelte()
{
 if((read_file))//被警告了。。。应该是编译器的标准太老，顺便吐槽一下这个ide，所有变量都必须在函数头部声明，绝了
 {
 printf("文件写入成功！\n");
 }
 else
 {
 printf("文件写入失败！\n");
 }
}



void menu()
{
 printf("-------------------------");
 printf("请输入数字来进行下一步操作");
 printf("-------------------------\n");
 printf("1.查询学生信息\n");
 printf("2.删除学生信息\n");
 printf("3.添加学生信息\n");
 printf("4.显示所有学生\n");
 printf("5.修改学生信息\n");
 printf("6.保存所有信息\n");
 printf("0.退出管理系统\n");
}

void display()
{
      //student *temp=New_student();  temp指针本身不需要给它分配空间，因为它只是一个寻址指针，分配空间造成浪费
	  student* temp=NULL;
	  //student* find=NULL;
	  //find=head;
      temp=head->next;
      printf("*****************************以下为全部学生信息*****************************\n");
	  printf("学号\t姓名\t年龄\t地址\t\n");
	  while(temp)//只要链表节点不为空，就继续打印并指向下一个节点
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

  printf("*****************************正在添加学生信息*****************************\n");
  printf("请输入两次学号,以回车键结束，第一次判断格式是否正确，若无提示则表明格式正确\n");
  scanf("%d",&num);
  while(scanf("%d",&num)!=1||input_check(num)!=1)
  {
	  printf("学号输入有误或者重复！\n");
      printf("请重新输入！\n");
	  fflush(stdin);//刷新缓存区，此时scanf获得的值被刷掉，故重新进行第一步。提醒用户重新输入
   
  }
  printf("请输入姓名\n");//名字用字符串形式保存，且名字也有存在数字的形式，故不做区分
  scanf("%s",name);
  printf("请输入两次年龄,以回车键结束，第一次判断格式是否正确，若无提示则表明格式正确\n");
  scanf("%d",&age);
  while(1!=scanf("%d",&age))
  {
	  printf("年龄输入有误！\n");
      printf("请重新输入！\n");
	  fflush(stdin);//丢掉错误的数据，刷新缓存区，提醒用户重新输入
  }

  printf("请输入地址\n");
  scanf("%s",address);
  
  temp->num=num;
  temp->age=age;
  strcpy(temp->name,name);
  strcpy(temp->address,address);
  
  temp->next=head->next;
  head->next=temp;
  if(temp!=NULL)
  {
   printf("添加学生信息成功！\n");
  }
  else
  {
   printf("添加学生信息失败！\n");
  }
  /* 函数思路 首先创建临时变量储存用户输入的数据，随后进行输入检查
   如果输入有误，则进行刷新缓存区操作。确认无误后，将值赋给temp指针指向的
   存储节点。
  */
}
student* serach_student()//返回一个存储节点
{
  int get_num=0;
  student *temp=New_student();//NULL
  temp=head->next;
  
  printf("*****************************正在查询学生信息*****************************\n\n");
  
  printf("请输入两次学号,以回车键结束，第一次判断格式是否正确，若无提示则表明格式正确\n");
  scanf("%d",&get_num);

  while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("学号输入有误！\n");
      printf("请重新输入！\n");
	  fflush(stdin);//刷新缓存区，此时scanf获得的值被刷掉，故重新进行第一步。提醒用户重新输入
  }
 while(temp&&temp->num!=get_num)
  {
   temp=temp->next;
  }
 return temp;//返回一个结构体供其他函数使用，若想提高函数复用度还可在删除功能中使用，这里没有这么做
}

int input_check(int value)//检查重复函数，如果返回1则无重复，返回0则有重复
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
void fix()//临时debug，因为在读取文件的时候，总是会添加一个学号0的数据，所以删除掉以免影响数据的正确性
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
 find=head;//这步操作的重要性在于如果查询到的学生在链表的第一个位置时也能正确的删除
 printf("*****************************正在删除学生信息*****************************\n");
 printf("请输入两次学号,以回车键结束，第一次判断格式是否正确，若无提示则表明格式正确\n");
 scanf("%d",&get_num);
   while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("学号输入有误！\n");
      printf("请重新输入！\n");
	  fflush(stdin);//刷新缓存区，此时scanf获得的值被刷掉，故重新进行第一步。提醒用户重新输入
  }
   while(temp->num!=get_num)
   {
      find=temp;
      temp=temp->next;
   }
   find->next=temp->next;
   free(temp);  //因为是单向链表，需要一个find指针来保存之前temp指向的地址，才能保证链表不出现问题。

 if(temp)
 {
   printf("删除成功！\n");
 }
 else
 {
   printf("删除失败！\n");
 }
}
void s_display(student* one)
{
 if(one==NULL)
 {
   printf("查询失败!请检查学号输入是否正确!\n");
 }
 else
 {
      printf("学号\t姓名\t年龄\t地址\t\n");
      printf("%d\t",one->num);
	  printf("%s\t",one->name);
	  printf("%d\t",one->age);
	  printf("%s\t",one->address);
	  printf("\n");
 }
}
int save()
{
 int i=0;//计数变量
 FILE *save;
 student* temp=NULL;
 temp=head->next;
 save=fopen("studentInfomation.txt","w+");
 if(save==NULL)
 {
  printf("文件打开失败\n");
  return 0;
 }
 while(temp)
 { 
  fprintf(save,"%d %s %d %s ",temp->num,temp->name,temp->age,temp->address);
  temp=temp->next;
  i++;
 }
 printf("一共保存了%d条学生信息\n",i);
 fclose(save);
 return 1;//返回1表示函数执行成功
}
void mod_student()
{
  int get_num=0;
  int mod=0;
  student* temp=NULL;
  temp=head->next;
  printf("*****************************正在修改学生信息*****************************\n");
  printf("请输入两次学号,以回车键结束，第一次判断格式是否正确，若无提示则表明格式正确\n");
   scanf("%d",&get_num);
   while(scanf("%d",&get_num)!=1||input_check(get_num)==1)
  {
	  printf("学号输入有误或是不存在\n");
      printf("请重新输入！\n");
	  fflush(stdin);//刷新缓存区，此时scanf获得的值被刷掉，故重新进行第一步。提醒用户重新输入
  }
   while(temp->num!=get_num)
   {
      temp=temp->next;
   }
  printf("***************************你想要修改的学生信息如下***************************\n");
   s_display(temp);
    printf("--------------------");
    printf("请输入数字来修改你想要修改的信息！");
    printf("--------------------\n");
    printf("1.学号\t2.姓名\t3.年龄\t4.地址\t\n");
	scanf("%d",&mod);
	
 switch(mod)
 {
 case 1:
   printf("请输入新的学号.\n");
   scanf("%d",&temp->num);
   break;
   case 2:
   printf("请输入新的姓名.\n");
   scanf("%s",temp->name);
   break;
   case 3:
   printf("请输入新的年龄.\n");
   scanf("%d",&temp->age);
   break;
   case 4:
   printf("请输入新的地址.\n");
   scanf("%s",temp->address);
   break;
   default:
   printf("请输入正确的指令.\n");
 }
}