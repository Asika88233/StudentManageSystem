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


student* head;//��������ͷָ�� int float double
void read_compelte();//����ļ��Ƿ��ȡ�ɹ�
void create_head();
student* New_student();
void free_student(student* one);
int read_file();//��ȡ�ļ�����

void start();//��ʼ����
void menu();//�˵�����
int input_check();//�����麯��������Ϊ����Ƿ��������ظ���ѧ�ţ�������Ϸ����򷵻�1�������벻�Ϸ����򷵻�0
void display();//��ʾ�ļ���������ӵ�ѧ��
void add_student();//���ѧ��
void del_student();//ɾ��ѧ��
void mod_student();//�޸�ѧ����Ϣ
student* serach_student();//��ѯѧ��
int save();
void fix();
#endif