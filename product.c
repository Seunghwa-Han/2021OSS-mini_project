//product.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

int add(Product * p){
	printf("추가할 상품의 이름은? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1] = '\0';
	
	printf("추가할 상품의 중량은? (g) ");
	scanf("%d", &p->weight);

	printf("추가할 상품의 가격은? (₩) ");
	scanf("%d", &p->price);
	
	printf("추가할 상품의 별점은? (1~5) ");
	scanf("%d", &p->star);
	printf("추가할 상품의 별점 개수는? ");
	scanf("%d", &p->star_count);	
	printf("=> 추가됨 !!\n");
	return 1;
}

void read(Product p){
	printf("%6dg %5d₩ %4d  %12d  %s\n",p.weight,p.price,p.star,p.star_count,p.name);
}

int update(Product * p){
	printf("수정할 상품의 이름은? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1] = '\0';
	
	printf("수정할 상품의 중량은? (g) ");
	scanf("%d", &p->weight);

	printf("수정할 상품의 가격은? (₩) ");
	scanf("%d", &p->price);
	
	printf("추가할 상품의 별점은? (1~5) ");
	scanf("%d", &p->star);
	printf("추가할 상품의 별점 개수는? ");
	scanf("%d", &p->star_count);	
	printf("=> 수정 성공 !!\n");
	return 1;
}

int deleteProduct(Product * p){
	p->weight = -1;
	printf("=> 삭제됨 !!\n");
	
	return 1;
}

void saveData(Product * p[], int count){

	FILE * fp;
	fp = fopen("product.txt","wt");
	for(int i =0; i<count; i++){
		if(p[i]->weight == -1) continue;
		fprintf(fp,"%d %d %d %d %s\n",p[i]->weight,p[i]->price,p[i]->star,p[i]->star_count,p[i]->name);
	}
	fclose(fp);
	printf("저장됨!!\n");
}

int loadData(Product * p[]){
	int i = 0;
	FILE * fp;
	fp = fopen("product.txt","rt");
	if(fp == NULL){
		printf("=> 파일 없음!!\n");
		return 0;  //왜 이거 없으면 에러가 나지..??
	}
	else{
		while(1){
			p[i] = (Product *)malloc(sizeof(Product));
			if(fscanf(fp,"%d %d %d %d %[^\n]s", &p[i]->weight,&p[i]->price,&p[i]->star,&p[i]->star_count,p[i]->name)<5) break;
			i++;
		}
		printf("=> 로딩성공!!\n");
	}
	fclose(fp);
	return i;

}

void searchName(Product * p[], int count, char s_name[]){
	int check = 0;
	printf("\nNo Weight  Price  Star  numberOfStar  Name\n");	
	for(int i = 0; i<count ;i++){
		if(p[i]->weight==-1) continue;
		if(strstr(p[i]->name,s_name)){
			check = 1;
			printf("%2d ",i+1);
			read(*p[i]);		
		}	
	}	
	if(check == 0) printf("=> 없습니다..\n");

}

void searchPriceDown(Product * p[], int count, int s_price){
	int check = 0;
	printf("\nNo Weight  Price  Star  numberOfStar  Name\n");	
	for(int i = 0; i<count ;i++){
		if(p[i]->weight==-1) continue;
		if(p[i]->price <= s_price){
			check = 1;
			printf("%2d ",i+1);
			read(*p[i]);		
		}	
	}	
	if(check == 0) printf("=> 없습니다..\n");

}

void searchStar(Product * p[], int count, int s_star){
	int check = 0;
	printf("\nNo Weight  Price  Star  numberOfStar  Name\n");	
	for(int i = 0; i<count ;i++){
		if(p[i]->weight==-1) continue;
		if(p[i]->star == s_star){
			check = 1;
			printf("%2d ",i+1);
			read(*p[i]);		
		}	
	}	
	if(check == 0) printf("=> 없습니다..\n");
	
}
