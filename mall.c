/* mall.c -- ʹ��Queue�ӿ� */
/* ��queue.cһ����� */
#include <stdio.h>
#include <stdlib.h>	//�ṩrand()��srand()��ԭ��
#include <time.h>	//�ṩtime()��ԭ��
#include "queue.h"	//����Item��typedef
#include <stdbool.h>
#define MIN_PER_HR 60.0

bool newcustomer(double x);		//�Ƿ����¹˿͵�����
Item customertime(long when);	//���ù˿Ͳ���

int main(void) {
	Queue line;
	Item temp;					//�µĹ˿�����
	int hours;						//ģ���Сʱ��
	int perhour;					//ÿСʱƽ������λ�˿�
	long cycle, cyclelimit;	//ѭ����������������������
	long turnaways = 0;		//������������ܵĵĹ˿�����
	long customers = 0;		//������еĹ˿�����
	long served = 0;			//��ģ���ڼ���ѯ��Sigmund�Ĺ˿�����
	long sum_line = 0;		//�ۼƵĶ����ܳ�
	int wait_time = 0;			//�ӵ�ǰ��Sigmund���������ʱ��
	double min_per_cust;	//�˿͵�����ƽ��ʱ��
	long line_wait = 0;		//�����ۼƵĵȴ�ʱ��

	InitializeQueue(&line);
	srand((unsigned int)time(0));	//rand()�����ʼ��
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf_s("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf_s("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;
}