#include <stdio.h>
#define MAX 4
struct queue{
	int a[MAX];
	int f,r;
};
void insert(struct queue* q,int val){
	if((q->r + 1)%MAX == q->f){
		printf("Queue is full!\n");
		return;
	}
	q->a[q->r] = val;
	q->r = (q->r + 1)%MAX;
}
int pop(struct queue* q){
	if(q->f == q->r){
		printf("Queue is empty!\n");
		return -1;
	}
	int ans = q->a[q->f];
	q->f = (q->f + 1)%MAX;
	return ans;
}
int main(){
	struct queue q;
    q.f = 0;
    q.r = 0;

	insert(&q,1);
	insert(&q,2);
	insert(&q,3);
	insert(&q,5);
	printf("%d\n",pop(&q));
	printf("%d\n",pop(&q));
	return 0;
}