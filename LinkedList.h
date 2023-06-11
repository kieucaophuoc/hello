#include <stdio.h>
#include <stdlib.h>
//2. Linked list
typedef struct _listnode{
	int num;
	struct _listnode *next;
}ListNode;
//could more on linkedlist, not only num

typedef struct _linkedlist{
	ListNode *head;
	ListNode *tail;
	int size;
}LinkedList;

void printList(ListNode *head){
	ListNode *cur=head;
	if (cur== NULL) {
		printf("Empty!\n") ;
		return;
	}
	while (cur!= NULL){
		printf("%d\n", cur ->num);
		cur = cur ->next;
	}
}

ListNode* findNode(ListNode *head, int i){ 
	ListNode *cur=head; 
	if (head==NULL || i<0) {
		printf("Doesn't exist!\n") ;
		return NULL;
	}
	if (i == 0) return head;
	while(i>0){
		cur=cur->next;
		if (cur==NULL) {
			printf("Doesn't exist!\n") ;
			return NULL;
		}
		i--;
	}
	return cur;
}

void insertNode(ListNode **ptrHead, int index, int value){ 
	ListNode *cur, *newNode; 
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		newNode = malloc(sizeof(ListNode));
		newNode->num = value;
		newNode->next = *ptrHead;
		*ptrHead = newNode; 
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	else if ((cur = findNode(*ptrHead, index-1)) != NULL){
		newNode = malloc(sizeof(ListNode));
		newNode->num = value;
		newNode->next = cur->next; 
		cur->next = newNode; 
	}
	else printf("Can not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index){
	ListNode *cur, *pre;
	if (index == 0 ) {
		cur = *ptrHead ;
		*ptrHead = cur->next  ;
		free(cur);
	}
	else {
		pre = findNode(*ptrHead, index-1);
		cur = pre->next ;
		pre->next = cur->next ;
		free(cur);
	}
}