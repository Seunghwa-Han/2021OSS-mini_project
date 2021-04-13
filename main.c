#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#define SIZE 100

int select_menu(){
	int menu;
	printf("\n*************************\n");
	printf("1. 상품 추가\n2. 상품 목록\n3. 상품 수정\n4. 상품 삭제\n5. 파일 저장\n6. 파일 불러오기\n7. 이름으로 검색\n0. 종료\n");
	printf("*************************\n");
	scanf("%d", &menu);
	getchar();
	return menu;
}
void save_data(Product * p[], int index){
	FILE * fp;
	fp = fopen("product.txt","wt");
	for(int i =0; i<index; i++){
		if(p[i]->weight == -1) continue;
		fprintf(fp,"%d %d %d %d %s\n",p[i]->weight,p[i]->price,p[i]->star,p[i]->star_count,p[i]->name);
	}
	fclose(fp);
	printf("저장됨!!");
}
int load_data(Product * p[]){
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
void search_name(Product * p[], int index, char s_name[]){
	for(int i = 0; i<index ;i++){
	
	}	
}

int main(){
#ifdef DEBUG
	printf("=>DEBUG MODE\n");
#endif
	Product * p[SIZE];
	int menu;
	int count = 0;
	int index = 0;
	
	while(1){
		menu = select_menu();
		printf("\n");
		if(menu == 1){ 
			p[index] = (Product *)malloc(sizeof(Product));
			count+=add(p[index++]);
		} 
		else if(menu == 2) list_p(p,index); 
		
		else if(menu == 3){ 
			int num = update_num(p,index);
			getchar();
			update(p[num-1]);
		}
		else if(menu == 4){
			int num = delete_num(p,index);
			int check;
			printf("정말로 삭제하시겠습니까? (삭제: 1) ");
			scanf("%d",&check);
			if(check==1){
		       		if(deleteProduct(p[num-1]))
					count--;
			}else{
				printf("취소되었습니다!\n");
			}
		}
		else if(menu == 5) 
			save_data(p,index);	
		else if(menu == 6){
			index = load_data(p);
			count = index;
		}
		else if(menu == 7){
			char s_name[SIZE];
			printf("검색할 이름은? ");
			scanf("%[^\n]s", s_name);
			search_name(p,index,s_name);
		}
		else if(menu == 0) break;
	}
	return 0;
}
