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

	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line))
				turnaways++;
			else {
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}
		if (wait_time <= 0 && !QueueIsEmpty(&line)) {
			DeQueue(&temp, &line);
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}

	if (customers > 0) {
		printf("customers accepted:%ld\n", customers);
		printf("		customers served:%ld\n", served);
		printf("			turnaways:%ld\n", turnaways);
		printf("average queue size:%.2f\n", (double)sum_line / cyclelimit);
		printf("	average wait time: %.2f minutes\n", (double)line_wait / served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&line);
	puts("Bye!");

	return 0;
}

