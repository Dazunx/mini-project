#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256
#define USER

typedef struct 
{
    char name[MAX];  // 제품명
    char comment[MAX]; //설명
    char size[MAX]; //중량
    int price;  // 판매가격
    int deli; // 배송방법 (1:새벽배송 /2:택배배송)  
}Product;
int loadData(Product *p[], int count); // 파일에서 데이터 불러오는 함수
void savdData(Product *p[], int count); // 파일에 데이터 저장하는 함수
int createProduct(Product *p); // 제품을 추가하는 함수
int readProduct(Product p); // 하나의 제품 출력 함수
int listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력
int updateProduct(Product *p); // 제품내용 수정할 함수
int deleteProduct(Product *p[], int count); // 제품 삭제 함수
void searchProduct(Product *p[], int count); // 제품이름 검색
int selectDataNo(Product *p[], int count);
int selectMenu();
void savdData(Product *p[],int count); // 파일에 데이터 저장하는 함수
int loadData(Product *p[],int index); // 파일에서 데이터 불러오는 함수

