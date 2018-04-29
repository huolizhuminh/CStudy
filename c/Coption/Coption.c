/*
 * Coption.c
 *
 *  Created on: 2018年4月21日
 *      Author: anker
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define random(NumValues)  ((int)(((double)(rand())*(NumValues))/(RAND_MAX+1.0)))
#define iterations 6
#define test
//#define testf
#define repeatable
int sum(int, int);
int product(int, int);
int difference(int, int);
void test_hong();
void get_current_time();
int main(void) {
	//get_current_time();
	test_hong();
	return 0;
}
void test_hong() {
	int funsel = 0;
	int a = 0, b = 5;
	int result = 0;
	int (*pfun[])(int, int)= {sum,product,difference };
#ifdef repeatable
	srand(1);
#else
	srand((unsigned int)time(NULL));
#endif
	int element_count = sizeof(pfun) / sizeof(pfun[0]);
	for (int i = 0; i < iterations; ++i) {
		funsel = random(element_count);
		if (funsel > element_count - 1) {
			printf("invalid index");
			exit(1);
		}
#ifdef test
		printf("random index=%d\n", funsel);
#endif
		result = pfun[funsel](a, b);
		printf("result=%d\n", result);
	}
}
int sum(int x, int y) {
#ifdef testf
	printf("function sum called args %d and %d.\n", x, y);
#endif
	return x + y;
}
int difference(int x, int y) {
#ifdef testf
	printf("function difference called args %d and %d.\n", x, y);
#endif
	return x - y;
}
int product(int x, int y) {
#ifdef testf
	printf("function product called args %d and %d.\n", x, y);
#endif
	return x * y;
}
void get_current_time() {
	const char*day[7] = { "Sunday", "Monday", "Tuesday", "Wednesday",
			"Thursday", "Friday", "Saturday" };
	const char*month[12] = { "January", "February", "March", "April", "May",
			"June", "July", "August", "September", "October", "Noverber",
			"December" };
	const char*suffix[] = { "st", "nd", "rd", "th" };
	enum sufindex {
		st, nd, rd, th
	} sufsel = th;
	struct tm * ourT;
	time_t tVal = time(NULL);
	if (!(ourT = localtime(&tVal))) {
		printf("failed to populate the struct\n");
		return;
	}
	switch (ourT->tm_mday) {
	case 1:
	case 21:
	case 31:
		sufsel = st;
		break;
	case 2:
	case 22:
		sufsel = nd;
		break;
	case 3:
	case 23:
		sufsel = rd;
		break;
	default:
		sufsel = th;
		break;
	}
	printf("Today is %s the %d%s %s %d", day[ourT->tm_wday], ourT->tm_mday,
			suffix[sufsel], month[ourT->tm_mon], 1900 + ourT->tm_year);
}

