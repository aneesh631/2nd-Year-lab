#include <stdio.h>
#include <stdlib.h>
struct node_s{
	int data;
	struct node_s* next;
};
struct node_d{
	int data;
	struct node_d* next;
	struct node_d* prev;
};
void insert_s(struct node_s** head,int v){
	if(*head == NULL){
		*head = (struct node_s*)malloc(sizeof(struct node_s));
		(*head)->data = v;
		return;
	}
	struct node_s* p = *head;
	while(p->next != NULL)
		p = p->next;
	struct node_s* newNode = (struct node_s*)malloc(sizeof(struct node_s));
	newNode->data = v;
	p->next = newNode;
}
void d_from_s(struct node_s** sll,struct node_d** dll){
	if(*sll == NULL)
		return;
	struct node_d* prevNode = NULL;
	struct node_s* p = *sll;

	(*dll) = (struct node_d*)malloc(sizeof(struct node_d));
	(*dll)->data = p->data;
	(*dll)->next = NULL;
	(*dll)->prev = prevNode;
	prevNode = (*dll);
	p = p->next;

	while(p != NULL){
		struct node_d* newNode = (struct node_d*)malloc(sizeof(struct node_d));
		prevNode->next = newNode;
		newNode->data = p->data;
		newNode->next = NULL;
		newNode->prev = prevNode;
		prevNode = newNode;
		p = p->next;
	}
}
void print_s(struct node_s** head){
	struct node_s* p = *head;
	while(p != NULL){
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}
void print_d(struct node_d** head){
	struct node_d* p = *head;
	while(p != NULL){
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	struct node_s* sll = NULL;
	insert_s(&sll,1);
	insert_s(&sll,2);
	insert_s(&sll,3);
	print_s(&sll);

	struct node_d* dll = NULL;
	d_from_s(&sll,&dll);
	print_d(&dll);
	return 0;
}