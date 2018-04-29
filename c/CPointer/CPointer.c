/*
 * CPointer.c
 *
 *  Created on: 2018年4月10日
 *      Author: anker
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define STR_COUNT 10
#define BUF_LEN 256

#define COUNT 5
void test1();
void test2();
void test3();
void test4();
void getPrime();
void getLimitPrime();
void pointCopyStr();
void pointArray();
void pointSort();
void doCaculate();
int main(void) {
	//test1();
	//test2();
	//test3();
	//test4();
	//getPrime();
	//getLimitPrime();
//	pointCopyStr();
//	pointArray();
//	pointSort();
	doCaculate();
	return 0;
}
void doCaculate() {
	char buf[BUF_LEN];
	char op = 0;
	size_t index = 0;
	size_t to = 0;
	size_t buf_length = 0;
	double result = 0.0;
	double number = 0.0;
	char*endptr = NULL;
	printf(
			"To use this calculator enter any expression with or without spaces.\n An expression may include the operators\n");
	printf("+ ,- ,* ,/,^\n");
	printf("\n Enter quit to stop the calculator");
	char *ptr = NULL;
	while (true) {
		ptr = fgets(buf, BUF_LEN, stdin);
		if (!ptr) {
			printf("error reading input.\n");
			return;
		}
		if (strcmp(buf, "quit\n") == 0) {
			break;
		}
		buf_length = strnlen(buf, BUF_LEN);
		buf[--buf_length] = '\0';
		for (to = 0, index = 0; index <= buf_length; ++index) {
			if (*(buf + index) != ' ') {
				*(buf + to++) = *(buf + index);
			}
		}
		buf_length = strnlen(buf, BUF_LEN);
		index = 0;
		if (buf[index] == '=') {
			index++;
		} else {
			result = strtod(buf + index, &endptr);
			index = endptr - buf;
		}
		while (index < buf_length) {
			op = *(buf + index++);
			number = strtod(buf + index, &endptr);
			index = endptr - buf;
			switch (op) {
			case '+':
				result += number;
				break;
			case '-':
				result -= number;
				break;
			case '*':
				result *= number;
				break;
			case '/':
				if (number == 0) {
					printf("\n division by zero error");
				} else {
					result /= number;
				}
				break;
			case '%':
				if ((long long) number == 0LL) {
					printf("\n division by zero error");
				} else {
					result = (double) ((long long) result % (long long) number);
				}
				break;
			case '^':
				result=pow(result,number);
				break;
			default:
				printf("\n\n illegal operation\n");

			}
          printf("=%f\n",result);
		}

	}

}
void pointSort() {
	char buf[BUF_LEN];
	size_t str_count = 0;
	size_t capacity = COUNT;
	char **ps = calloc(capacity, sizeof(char*));
	char** psTemp = NULL;
	char* pTemp = NULL;
	size_t str_len = 0;
	bool sorted = false;
	printf("enter strings to be sorted,press Enter to end:\n");
	char *ptr = NULL;
	while (true) {
		ptr = fgets(buf, BUF_LEN, stdin);
		if (!ptr) {
			printf("error reading str\n");
			free(ps);
			ps = NULL;
			return;
		}
		printf("ptr %s \n", ptr);
		if (*ptr == '\n') {
			printf("end enter \n");
			break;
		}
		printf("str_count %d,capacity %d\n", str_count, capacity);
		if (str_count == capacity) {
			capacity += capacity / 4;
			if (!(psTemp = realloc(ps, capacity))) {
				printf("failed to realloc psTemp\n");
				return;
			}
			ps = psTemp;
		}
		str_len = strlen(buf) + 1;
		printf("str_len %d\n", str_len);
		if (!(ps[str_count] = malloc(str_len))) {
			printf("failed to malloc ps\n");
			return;
		}
		strcpy(ps[str_count++], buf);
	}
	printf("start sort  :\n\n");
	while (!sorted) {
		sorted = true;
		for (size_t i = 0; i < str_count - 1; ++i) {
			if (strcmp(ps[i], ps[i + 1]) > 0) {
				sorted = false;
				pTemp = ps[i];
				ps[i] = ps[i + 1];
				ps[i + 1] = pTemp;
			}
		}
	}
	printf("ascending sequence is :\n\n");
	for (size_t i = 0; i < str_count; i++) {
		printf("%s", ps[i]);
		free(ps[i]);
		ps[i] = NULL;
	}
	free(ps);
	ps = NULL;

}
void pointArray() {

	const size_t BUF_SIZE = 100;
	char buffer[BUF_SIZE];
	char *ps[STR_COUNT] = { NULL };
	size_t str_size = 0;
	for (size_t i = 0; i < STR_COUNT; ++i) {
		scanf("%s", buffer, BUF_SIZE);

		str_size = strlen(buffer) + 1;
		ps[i] = malloc(str_size);
		if (!ps[i]) {
			return;
		}
		strcpy(ps[i], buffer);
	}
	for (size_t i = 0; i < STR_COUNT; i++) {
		printf("%s\n", ps[i]);
		free(ps[i]);
		ps[i] = NULL;
	}

}

void pointCopyStr() {
	const size_t BUF_SIZE = 100;
	char buffer[BUF_SIZE];
	gets(buffer);
	size_t len = strlen(buffer) + 1;
	char *pString = malloc(len);
	if (!pString) {
		printf("memory allocation failed.\n");
		return;
	}
	strcpy(pString, buffer);
	printf("%s", pString);
	free(pString);
	pString = NULL;
}
void getLimitPrime() {
	unsigned long long *prime = NULL;
	int limit = 0;
	int has_found_num;
	int trial = 0;
	bool has_found = false;
	printf("get the num at least 5\n");
	scanf("%d", &limit);
	if (limit < 5) {
		limit = 5;
	}
	int currentAlloc = 8;
	prime = malloc(currentAlloc * sizeof(unsigned long long));
	if (!prime) {
		printf("failed to malloc prime ");
		return;
	}
	*prime = 2;
	*(prime + 1) = 3;
	*(prime + 2) = 5;
	has_found_num = 3;
	trial = 5;
	while (trial <= limit) {

		trial++;
		bool isTrailPrime = true;
		for (int i = 0; i < has_found_num; i++) {
			if (!(trial % (*(prime + i)))) {
				isTrailPrime = false;
				break;
			}
		}
		if (has_found_num == currentAlloc) {
			currentAlloc = 2 * currentAlloc;
			unsigned long long *temp = realloc(prime,
					currentAlloc * sizeof(unsigned long long));
			printf("success to realloc,%d", currentAlloc);
			if (!temp) {
				printf("failed to realloc,size is %d", currentAlloc);
				free(prime);
				prime = NULL;
				return;
			}
			prime = temp;
		}
		if (isTrailPrime) {
			*(prime + has_found_num) = trial;
			has_found_num++;
		}
	}
	for (int i = 0; i < has_found_num; i++) {
		printf("the %d prime is %d\n", i, *(prime + i));
	}
	free(prime);
	prime = NULL;
}
/**
 *    malloc动态分配堆内存，分配之后需要手动释放，并将引用置为NULL。
 */
void getPrime() {
	unsigned long long *prime = NULL;
	int needFoundNum = 0;
	int has_found_num;
	int trial = 0;
	bool has_found = false;
	printf("get the num at least 4\n");
	scanf("%d", &needFoundNum);
	if (needFoundNum < 4) {
		needFoundNum = 4;
	}
	prime = malloc(needFoundNum * sizeof(unsigned long long));
	if (!prime) {
		printf("failed to malloc prime ");
		return;
	}
	*prime = 2;
	*(prime + 1) = 3;
	*(prime + 2) = 5;
	has_found_num = 3;
	trial = 5;
	while (has_found_num < needFoundNum) {

		trial++;
		bool isTrailPrime = true;
		for (int i = 0; i < has_found_num; i++) {
			if (!(trial % (*(prime + i)))) {
				isTrailPrime = false;
			}
		}
		if (isTrailPrime) {
			*(prime + has_found_num) = trial;
			has_found_num++;
		}
	}
	for (int i = 0; i < needFoundNum; i++) {
		printf("the %d prime is %d\n", i, *(prime + i));
	}
	free(prime);
	prime = NULL;
}
void test4() {
	char boad[3][3] =
			{ { '1', '2', '3' }, { '5', '6', '7' }, { '0', '8', '9' } };
	char*pnum = &boad[0][0];
	for (int i = 0; i < 9; i++) {
		printf(" position %d,%c\n", i, *(pnum + i));
	}

}
/**
 *    *baod表示boad[0]一维数组，每次加一位置往后移动一个字符
 *    boad表示二维数组，每次加一位置往后移动3个字符
 */
void test3() {
	char boad[3][3] =
			{ { '1', '2', '3' }, { '5', '6', '7' }, { '0', '8', '9' } };
	for (int i = 0; i < 9; i++) {
		//	printf("position **boad+%d, %c\n", i, **boad + i);
		printf("position **boad+%d, %c\n", i, *(*boad + i));
		printf("position **boad+%d, %c\n", i, **(boad + i));
	}
}
void test2() {
	char boad[3][3] =
			{ { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("position %d,%d,%p \n", i, j, &boad[i][j]);
		}
	}
	printf("*********************\n");
	printf("boad %p\n", boad);
	printf("boad & %p\n", &boad);
	for (int i = 0; i < 3; i++) {
		printf("boad, %d,%p\n", i, boad[i]);
		printf("boad,%d,&%p\n", i, &boad[i]);
	}
	printf("boad data **boad %c\n", **boad);
	printf("boad data *boad %p\n", *boad);

}
void test1() {
	int number = 0;
	int* pnumber = &number;
	number = 10;
	printf("number address:%p\n", &number);
	printf("number value is %d", number);
	printf("pnumber address is %p\n", &pnumber);
	printf("pnumber size is %zd bytes\n", sizeof(pnumber));
	printf("pnumber value is %p bytes\n", pnumber);
	printf("pnumber point to  is %d \n", *pnumber);
	printf("pnumber point to  is %p \n", &pnumber);
}
