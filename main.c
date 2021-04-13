#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#define SIZE 100

int select_menu(){
	int menu;
	printf("\n*************************\n");
	printf("1. 상품 추가\n2. 상품 목록\n3. 상품 수정\n4. 상품 삭제\n5. 파일 저장\n6. 파일 불러오기\n7. 이름으로 검색\n8. 가격으로 검색(down)\n0. 종료\n");
	printf("*************************\n");
	scanf("%d", &menu);
	getchar();
	return menu;
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
			saveData(p,index);	
		else if(menu == 6){
			index = loadData(p);
			count = index;
		}
		else if(menu == 7){
			char s_name[SIZE];
			printf("검색할 이름은? ");
			scanf("%[^\n]s", s_name);
			searchName(p,index,s_name);
		}
		else if(menu == 8){
			int s_price;
			printf("검색할 가격은? ");
			scanf(" %d", &s_price);
			searchPriceDown(p,index,s_price);
		}
		else if(menu == 0) break;
	}
	return 0;
}
