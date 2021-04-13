//product.h

typedef struct Product{
    char name[100]; //이름
    int weight; //중량(g)
    int price;   //가격(₩)
    int star;    //별점 (1~5)
    int star_count; //별점 개수
} Product;

int add(Product * p); //제품 추가하는 함수 C, 정상적으로 추가되었으면 1을 리턴 
void read(Product p); //하나의 제품을 출력 함수 R
int update(Product * p); //제품 수정하는 함수 U, 정상적으로 수정되었으면 1을 리턴 
int deleteProduct(Product * p); //제품 삭제하는 함수 D, 정상적으로 삭제되었으면 1을 리턴 

void saveData(Product * p[], int count); //file에 저장하는 함수
int loadData(Product * p[]); //file에서 데이터 불러오는 함수, 데이터 개수(product 개수)를 리턴 

void searchName(Product * p[], int count, char s_name[]);   //이름을 검색하는 함수 
void searchPriceDown(Product * p[], int count, int s_price); //가격을 검색하는 함수 (예 : 얼마 미만인 제품)
void searchStarUp(Product * p[], int count, int s_star);   //별점을 검색하는 함수 (예 : 별점 몇 개 이상인 제품)

