/*
 * CMethod.c
 *
 *  Created on: 2018年4月15日
 *      Author: anker
 */

#include <stdio.h>
#include<stdarg.h>
int sum(int, int);
int product(int, int);
int difference(int, int);
void pointMethodArray();
void changeMethodPoint();
int anyMethod(int ((*pfun)(int, int)), int, int);
void staticMethod();
void testStatic();
void testNoStatic();
double average(double v1, double v2, ...);
int main(int argc,char *argv[]) {
	//pointMethodArray();
	//changeMethodPoint();
//	staticMethod();
//	average(1.5, 1.4, 2.0, 3.4);
//	 printf("program name is %s\n",argv[0]);
//	 printf("argc is %d",argc);
//	 for(int i=1;i<argc;i++){
//		 printf("argument %d is %s ",i,argv[i]);
//	 }

	return 0;
}
double average(double v1, double v2, ...) {
	va_list parg;
	va_start(parg, v2);
	double value;
	double sum = v1+v2;
	int count = 2;
	while ((value = va_arg(parg, double)) != 0.0) {
		printf("value is %f\n", value);
		sum += value;
		++count;
	}
	va_end(parg);
	double average = sum / count;
	printf("sum is %f\n", sum);
	printf("average is %f\n", average);

}
void staticMethod() {
	for (int i = 0; i < 10; i++) {
		testStatic();
		testNoStatic();
	}
}
void testStatic() {
	static int count = 0;
	printf("testStatic count %d\n", count++);
}
void testNoStatic() {
	int count = 0;
	printf("testNoStatic count %d\n", count++);
}
void changeMethodPoint() {
	int ((*pfun)(int, int));
	int a = 6, b = 4;
	int result;
	pfun = sum;
	result = anyMethod(sum, a, b);
	printf("anyMethod sum %d", result);

}
int anyMethod(int ((*pfun)(int, int)), int a, int b) {
	return pfun(a, b);
}

void pointMethodArray() {
	int a = 6;
	int b = 4;
	int result = 0;
	int (*pfun[3])(int, int);
	pfun[0] = sum;
	pfun[1] = product;
	pfun[2] = difference;
	for (int i = 0; i < 3; i++) {
		result = pfun[i](a, b);
		printf("pfun  %d,reuslt %d\n", i, result);
	}
}
int sum(int a, int b) {
	return a + b;
}
int product(int a, int b) {
	return a * b;
}
int difference(int a, int b) {
	return a - b;
}

