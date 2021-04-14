#include <stdio.h>
#include "manager.h"

void list_p(Product * p[], int index){

	printf("No Weight  Price  Star  numberOfStar  Name\n");
	for(int i=0; i<index; i++){
		if(p[i]->weight==-1) continue;
		printf("%2d ",i+1);
		read(*p[i]);
	}
}
int update_num(Product * p[], int index){
	list_p(p,index);
	printf("수정할 상품 번호는? ");
	int num;
	scanf("%d",&num);
	return num;
}
int delete_num(Product * p[], int index){
	list_p(p,index);
	printf("삭제할 상품 번호는? ");
	int num;
	scanf("%d", &num);
	return num;
}
