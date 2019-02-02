#include <stdio.h>

int main(){
	printf("In client!\n");
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		printf("%d ",i);
	printf("\nClient done!\n");
	return 0;
}