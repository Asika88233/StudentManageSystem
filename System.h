#ifndef SYSTEM_H
#define SYSTEM_H

typedef struct student_
{
	int  num;
	int  age;
    char* name;
	char* address;
	struct student_ *next;
}student;


student* head;//定义链表头指针 int float double
void read_compelte();//检查文件是否读取成功
void create_head();
student* New_student();
void free_student(student* one);
int read_file();//读取文件函数

void start();//开始界面
void menu();//菜单界面
int input_check();//输入检查函数，功能为检查是否输入了重复的学号，若输入合法，则返回1。若输入不合法，则返回0
void display();//显示文件中所有添加的学生
void add_student();//添加学生
void del_student();//删除学生
void mod_student();//修改学生信息
student* serach_student();//查询学生
int save();
void fix();
#endif