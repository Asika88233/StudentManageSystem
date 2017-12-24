#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"System.h"

int main()
{
  int get_num=0;
  student* serach=NULL;

  start();
  create_head();
  read_file();
  read_compelte();
  fix();
  while(1)
  {
  menu();
  scanf("%d",&get_num);
  switch(get_num)
  {
  case 1:
	  serach=serach_student();
	  s_display(serach);
	  break;
  case 2:
	  del_student();
	  break;
  case 3:
	  add_student();
	  break;
  case 4:
	 display();
	 break;
  case 5:
     mod_student();
	 break;
  case 6:
	  save();
	  break;
  case 0:
	  printf("谢谢您的使用\n");
      system("pause");
	  exit(0);
  default:
   printf("请输入正确的指令.\n");
  }
 }
}