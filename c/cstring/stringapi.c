/*
 * stringapi.c
 *
 *  Created on: 2018年4月7日
 *      Author: anker
 */

#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
# define __STDC_WANT_LIB_EXT!__ 1;
void getStringRawLength();
void checkC11();
void getStringRawLengthAPI();
void getStringRawLengthNewAPI();
void stringCopy();
void stringCopyNew();
void stringCat();
void charSearch();
void takeWord();
void count_digit();
void countWord();
int main(void) {
	// checkC11();
	//getStringRawLengthAPI();
	//getStringRawLengthNewAPI();
	//stringCopy();
	//stringCopyNew();
	// stringCat();
//	charSearch();
	//takeWord();
//	count_digit();
	countWord();
	return 0;
}
/**
 * 分解word
 */
void countWord() {
	char delimiters[] = " \".,;!?:)(][-";
	char buf[100];
	char str[200];
	str[0] = '\0';
	size_t str_len = sizeof(str);
	size_t buf_len = sizeof(buf);
	printf("enter the num that is less than %d \n", str_len);
	while (true) {
		if (!gets(buf)) {
			printf("error reading string.\n");
			return;
		} else {
			printf("buf is %s\n", buf);
		}
		if (!strnlen(buf, buf_len)) {
			printf("buffer empty\n");
			break;
		}
		if (strncat(str, buf, buf_len)) {
			printf("length exceed\n");
			break;
		} else {
			printf("str is s%", str);
		}
	}
	printf("string need to take word is %s ,result is :\n", str);
	int word_count = 0;
	char * ptr = NULL;
	char *temp = str;
	char *words[50];
	int sums[50];
	int sum = 0;
	char * pword = strtok_r(temp, delimiters, &ptr);
	while (pword != NULL) {
		sum++;
		printf("%-18s", pword);
		int i = -1;
		int has_found = 0;
		while (words[i + 1] != NULL && !has_found) {
			if (strncmp(pword, words[i + 1], sizeof(pword)) == 0) {
				sums[i + 1]++;
				has_found = 1;
			} else {
				i++;
			}

		}
		if (!has_found) {
			words[i + 1] = pword;
			sums[i + 1] = 1;
		}
		if (++word_count % 5 == 0) {
			printf("\n");
			//	return;
		}
		temp = NULL;
		pword = strtok_r(temp, delimiters, &ptr);
	}
	printf("\n all words num is %d\n", sum);
	int k = 0;
	while (words[k] != NULL) {
		printf("%s num is %d\n", words[k], sums[k]);
		k++;
	}
	if (!word_count) {
		printf("No words found");
	}

}
void count_digit() {
	char buffer[200];
	if (!gets(buffer)) {
		printf("failed to get word");
	}
	size_t i = 0;
	int char_count = 0;
	int digit_count = 0;
	int punct = 0;
	while (buffer[i]) {
		if (isalpha(buffer[i])) {
			char_count++;
		} else if (isdigit(buffer[i])) {
			digit_count++;
		} else if (ispunct(buffer[i])) {
			punct++;
		}
		i++;
	}
	printf("char_count is %d,digit_count is %d,puntct is %d", char_count,
			digit_count, punct);

}
/**
 * 分解word
 */
void takeWord() {
	char delimiters[] = " \".,;!?:)(";
	char buf[100];
	char str[200];
	str[0] = '\0';
	size_t str_len = sizeof(str);
	size_t buf_len = sizeof(buf);
	printf("enter the num that is less than %d \n", str_len);
	while (true) {
		if (!gets(buf)) {
			printf("error reading string.\n");
			return;
		} else {
			printf("buf is %s\n", buf);
		}
		if (!strnlen(buf, buf_len)) {
			printf("buffer empty\n");
			break;
		}
		if (strncat(str, buf, buf_len)) {
			printf("length exceed\n");
			break;
		} else {
			printf("str is s%", str);
		}
	}
	printf("string need to take word is %s ,result is :\n", str);
	int word_count = 0;
	char * ptr = NULL;
	char *temp = str;
	char * pword = strtok_r(temp, delimiters, &ptr);
	while (pword != NULL) {
		printf("%-18s", pword);
		if (++word_count % 5 == 0) {
			printf("\n");
			//	return;
		}
		temp = NULL;
		pword = strtok_r(temp, delimiters, &ptr);
	}
	if (!word_count) {
		printf("No words found");
	}

}

/**
 * 搜索字符串位置
 */
void charSearch() {
	char str1[] = "zsssdjojizminiojzsjofjoz";
	char ch = 'z';
	char *go = str1;
	int count = 0;
	while (go = strchr(go, ch)) {
		count++;
		go++;
	}
	printf("%c is %s num is %d", ch, str1, count);
}
void getStringRawLength() {
	char str1[] = "zhuminh";
	unsigned int count = 0;
	while (str1[count] != '\0') {
		count++;
	}
	printf("str1 length %d", count);
}
/**
 * 求字符串长度
 */
void getStringRawLengthAPI() {
	char str1[] = "zhuminh";
	unsigned int count = strlen(str1);
	printf("str1 api length %d", count);
}
/**
 * 安全的方式 求字符串长度
 */
void getStringRawLengthNewAPI() {
	char str1[] = "zhuminh";
	unsigned int count = strnlen(str1, sizeof(str1));
	printf("str1 new  api length %d", count);
}
/**
 * 字符串的复制
 */
void stringCopy() {
	char source[] = "huolizhuminh";
	char des[50];
	if (strcpy(des, source)) {
		printf("failed to copy");
		printf("des is %s", des);
	} else {
		printf("des is %s", des);
	}

}
/**
 * 字符串的复制
 */
void stringCopyNew() {
	char source[] = "huolizhuminh";
	char des[50];
	strncpy(des, source, sizeof(des));
	printf("des is %s", des);
}
/**
 * 字符串连接
 */
void stringCat() {
	char str1[50] = "huolizhuminh";
	char str2[] = "hello";
	strncat(str1, str2, 2);
	printf("cat result is %s", str1);

}
void checkC11() {
# if defined __STDC_LIB_EXT1__
	printf("define");
# else
	printf("no define");
# endif

}
