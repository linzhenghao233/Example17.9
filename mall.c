/* mall.c -- 使用Queue接口 */
/* 和queue.c一起编译 */
#include <stdio.h>
#include <stdlib.h>	//提供rand()和srand()的原型
#include <time.h>	//提供time()的原型
#include "queue.h"	//更改Item的typedef
#include <stdbool.h>
#define MIN_PER_HR 60.0

bool newcustomer(double x);		//是否有新顾客到来？
Item customertime(long when);	//设置顾客参数

int main(void) {
	Queue line;
	Item temp;					//新的顾客数据
	int hours;						//模拟的小时数
	int perhour;					//每小时平均多少位顾客
	long cycle, cyclelimit;	//循环计数器、计数器的上限
	long turnaways = 0;		//因队列已满被拒的的顾客数量
	long customers = 0;		//加入队列的顾客数量
	long served = 0;			//在模拟期间咨询过Sigmund的顾客数量
	long sum_line = 0;		//累计的队列总长
	int wait_time = 0;			//从当前到Sigmund空闲所需的时间
	double min_per_cust;	//顾客到来的平均时间
	long line_wait = 0;		//队列累计的等待时间

	InitializeQueue(&line);
	srand((unsigned int)time(0));	//rand()随机初始化
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf_s("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf_s("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;
}