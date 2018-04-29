/*
 * CFile.c
 *
 *  Created on: 2018年4月21日
 *      Author: anker
 */

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
#define NAME_MAX 20
#define PRE_LINE 8
#define MEM_PRIMES 10*PRE_LINE
#define LENGTH 81
struct {
	char *filename;
	FILE *pfile;
} global = { .filename = "myfile.bin", .pfile = NULL };
typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct Family {
	Date dob;
	char name[NAME_MAX];
	char pa_name[NAME_MAX];
	char ma_name[NAME_MAX];
} Family;

void simpleReadAndWrite();
void simpleReadAndWriteStr();
bool get_person(Family *pfamily);
void getname(char*name, size_t size);
void show_person_date(void);
void get_parent_dob(Family *pfamily);
void open_file(char *mode);
void close_file(void);
void testFamily();
int main(void) {
	//simpleReadAndWrite();
	//simpleReadAndWriteStr();
	testFamily();
}
void testFamily() {
	Family member;
	open_file("ab");
	while (get_person(&member)) {
		fwrite(&member, sizeof member, 1, global.pfile);
	}
	fclose(global.pfile);
	show_person_date();
}
bool get_person(Family *temp) {
	 char more [LENGTH];
	 char waste [LENGTH];
	printf("\nDo your want to enter details of %s person(Y or N)",
			more[0] != '\0' ? "another" : "a");
	fgets(more, LENGTH,stdin);
	printf("scanf rusult is %s\n",more);
	if (tolower(more[0]) == 'n') {
		printf("print n to return\n");
		return false;
	}
	printf("enter the name of the person:\n");
	getname(temp->name, sizeof(temp->name));
	printf("get the %s birthday\n",temp->name);
	scanf("%d %d %d", &temp->dob.day,& temp->dob.month, &temp->dob.year);
	fgets(waste,LENGTH,stdin);
	printf("who is %s's father?", temp->name);
	getname(temp->pa_name, sizeof(temp->pa_name));
	printf("who is %s's mother?", temp->name);
	getname(temp->ma_name, sizeof(temp->ma_name));
	return true;
}
void getname(char *name, size_t size) {
	fflush(stdin);
	fgets(name, size, stdin);
	printf("getname name  %s",name);
	int len = strnlen(name, size);
	printf("getname name length %d\n",len);
	if (name[len - 1] == '\n') {
		printf("sent the last name char\n");
		name[len - 1] = '\0';
		printf("end sent the last name char\n");
	}
}
void show_person_date(void) {
	Family  member;
	open_file("rb");
	while (fread(&member, sizeof member, 1, global.pfile)) {
		printf("%s's father is %s,and mother is %s.\n", member.name,
				member.pa_name, member.ma_name);
		get_parent_dob(&member);
	}
	close_file();
}
void get_parent_dob(Family *pmember) {
	Family relative;
	int num_found = 0;
	fpos_t current;
	fgetpos(global.pfile, &current);
	rewind(global.pfile);
	while (fread(&relative, sizeof(Family), 1, global.pfile)) {
		if (strcmp(pmember->pa_name, relative.name) == 0) {
			printf("pa was born on %d/%d%d.", relative.dob.day,
					relative.dob.month, relative.dob.year);
			++num_found;
		} else if (strcmp(pmember->ma_name, relative.name) == 0) {
			printf("ma was born on %d/%d%d.", relative.dob.day,
					relative.dob.month, relative.dob.year);
			++num_found;
		}
		if(num_found==2){
			break;
		}
	}
	if(!num_found){
		printf("no info on parents available.\n");

	}
	if(fsetpos(global.pfile,&current)){
		printf("error set file position\n");
		exit(1);
	}

}
void open_file(char *mode){
	if(global.pfile){
		close_file();
	}
	if(!(global.pfile=fopen(global.filename,mode))){
		printf("unable to open %s with mode %s",global.filename,mode);
	}
	setvbuf(global.pfile,NULL,_IOFBF,BUFSIZ);
}
 void close_file(void){
	fclose(global.pfile);
	global.pfile=NULL;
}
void simpleReadAndWriteStr() {
	char * mychars[] = { "zhuminhui is a \n", "boy\n", "a very handsome boy\n" };
	char more[LENGTH];
	FILE *file;
	char *file_name = "myfilestr.txt";
	if (!(file = fopen(file_name, "w"))) {
		printf("failed to open file %s", file_name);
		exit(0);
	}
	setvbuf(file, NULL, _IOFBF, BUFSIZ);
	for (size_t i = 0; i < sizeof mychars / sizeof mychars[0]; i++) {
		if (fputs(mychars[i], file) == EOF) {
			printf("error write\n");
			exit(0);
		}
	}
	fclose(file);
	file = NULL;

	if (!(file = fopen(file_name, "a"))) {
		printf("error open\n");
		exit(1);
	}
	setvbuf(file, NULL, _IOFBF, BUFSIZ);
	while (true) {
		fgets(more, LENGTH, stdin);
		if (more[0] == '\n') {
			break;
		}
		if (EOF == fputs(more, file)) {
			printf("error append\n");
			exit(1);
		}
	}
	fclose(file);
	file = NULL;

	if (!(file = fopen(file_name, "r"))) {
		printf("error open reading\n");
		exit(1);
	}
	setvbuf(file, NULL, _IOFBF, BUFSIZ);

	printf("the file in %s are :\n", file_name);
	while (fgets(more, LENGTH, file)) {
		printf("%s", more);
	}

	fclose(file);
	file = NULL;

}
void simpleReadAndWrite() {
	char buffer[LENGTH];
	FILE *file = NULL;
	char *file_name = "myfile.txt";
	printf("enter the message you want to save\n");
	gets(buffer);
	char myChar;
	printf("the message you enter is :%s", buffer);
	if (!(file = fopen(file_name, "w"))) {
		printf("failed to open the file %s to write\n", file_name);
		exit(1);
	}
	setvbuf(file, NULL, _IOFBF, BUFSIZ);
	for (int i = strlen(buffer) - 1; i >= 0; i--) {
		fputc(buffer[i], file);
	}
	fclose(file);
	if (!(file = fopen(file_name, "r"))) {
		printf("failed to the file %s to read\n", file_name);
		exit(0);
	}
	printf("begin to read message from file\n");
	setvbuf(file, NULL, _IOFBF, BUFSIZ);
	while ((myChar = fgetc(file)) != EOF) {
		putchar(myChar);
	}
	putchar('\n');
	fclose(file);
	file = NULL;
	remove(file_name);

}
