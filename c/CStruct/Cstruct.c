/*
 * Cstruct.c
 *
 *  Created on: 2018年4月15日
 *      Author: anker
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define BUF_LEN 256
typedef struct Date Date;
typedef struct Family Family;
typedef struct Node Node;

Family *get_person(void);
void show_people(bool fowads, Family *pfirst, Family*plast);
void release_memory(Family *pfirst);
void testFamily();
Node *add_nodes(long value, Node *pNode);
Node *create_node(long value);
void list_nodes(Node *pNode);
int testBinaryTree();
struct Date {
	int day;
	int month;
	int year;
};
struct Node {
	long item;
	int count;
	Node *pLeft;
	Node *pRight;
};

struct Family {
	Date dob;
	char name[20];
	char father[20];
	char mother[20];
	Family *next;
	Family *previous;
};

int main(void) {
//	testFamily();
	int testResult = testBinaryTree();
	printf("testResult %d", testResult);
	return 0;
}
int testBinaryTree() {
	Node *pcurrentNode = NULL;
	Node *newNode = NULL;
	char isContinue = '0';
	char buf[BUF_LEN];
	long value = 0L;
	char*endptr = NULL;
	do {
		printf("please enter the value :\n");
		fgets(buf, BUF_LEN, stdin);
		value = strtod(buf, &endptr);
		printf("the value get is %d \n", value);
		newNode = add_nodes(value, pcurrentNode);
		if (!pcurrentNode) {
			printf("pcurrentNode is null\n");
			pcurrentNode = newNode;
		}
		printf("do you want to add node?Enter quit to stop,or continue\n");
		fgets(buf, BUF_LEN, stdin);
		printf("isContinue is %s\n", buf);
	} while (strcmp(buf, "quit\n"));
	printf("sort result :\n");
	list_nodes(pcurrentNode);
	return 0;
}
Node *create_node(long value) {
	Node *pNode = (Node*) malloc(sizeof(Node));
	pNode->item = value;
	pNode->count = 1;
	pNode->pLeft = pNode->pRight = NULL;
	return pNode;
}
Node *add_nodes(long value, Node*pNode) {
	if (!pNode) {
		return create_node(value);
	}
	if (value == pNode->item) {
		++pNode->item;
		return pNode;
	}
	if (value < pNode->item) {
		if (!pNode->pLeft) {
			pNode->pLeft = create_node(value);
			return pNode->pLeft;
		} else {
			return add_nodes(value, pNode->pLeft);
		}
	} else {
		if (!pNode->pRight) {
			pNode->pRight = create_node(value);
			return pNode->pRight;
		} else {
			return add_nodes(value, pNode->pRight);
		}
	}
}
void list_nodes(Node *pNode) {
	if (pNode->pLeft) {
		list_nodes(pNode->pLeft);
	}
	printf("%d * %d \n", pNode->count, pNode->item);
	if (pNode->pRight) {
		list_nodes(pNode->pRight);
	}
}
void testFamily() {
	Family *first = NULL;
	Family *current = NULL;
	Family *last = NULL;
	char more = '\0';
	while (true) {
		printf("\n do you want to enter details of a%s person(Y or N)?",
				first != NULL ? "nother" : "");
		scanf("%c", &more);
		printf("%c", more);
		if (tolower(more) == 'n') {
			break;
		}
		current = get_person();
		if (first == NULL) {

		} else {
			last->next = current;
			current->previous = last;
		}
		last = current;
	}
	show_people(true, first, last);
	release_memory(first);
	first = last = NULL;
}
Family *get_person() {
	Family *temp = (Family*) malloc(sizeof(Family));
	printf("\n enter the name of person:");
	scanf("%s", temp->name);
	printf("\n enter the %s's date of birth (day month year);", temp->name);
	scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);
	printf("who is %s's father?", temp->name);
	scanf("%s", temp->father);
	printf("\n who is %s's mother ", temp->mother);
	scanf("%s", temp->mother);
	temp->next = temp->previous = NULL;
	return temp;

}
void show_people(bool forwards, Family *pfirst, Family *plast) {
	printf("\n");
	for (Family *pcurrent = forwards ? pfirst : plast; pcurrent != NULL;
			pcurrent = forwards ? pcurrent->next : pcurrent->previous) {
		printf("%s was born %d/%d/%d and has %s and %s as parents.\n",
				pcurrent->name, pcurrent->dob.day, pcurrent->dob.month,
				pcurrent->dob.year, pcurrent->father, pcurrent->mother);
	}
}
void release_memory(Family *pfirst) {
	Family *pcurrent = pfirst;
	Family *temp = NULL;
	while (pcurrent) {
		temp = pcurrent;
		pcurrent = pcurrent->next;
		free(temp);
	}
}

