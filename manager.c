#include "manager.h"


int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 제품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int selectDataNo(Product *p[], int count){
    int num;

    listProduct(p,count);
    printf("번호는 (취소:0)? ");
    scanf("%d",&num);
    return num;
}



// 제품을 추가하는 함수
int createProduct(Product *p) {
#ifdef USER
	printf("You can add product\n\n");
#endif
	printf("추가할 제품명은? ");
   	scanf("%s",p->name);
   	printf("제품에 대한 설명을 적어주세요. ");
   	getchar();
	fgets(p->comment,MAX-1,stdin);
	p->comment[strlen(p->comment)-1]='\0';
    	printf("제품의 중량은 어느정도 입니까? ");
    	scanf("%s",p->size);
    	printf("제품의 가격은 얼마입니까? ");
    	scanf("%d",&(p->price));
    	printf("제품의 배송방법은 무엇입니까?(1:새벽배송 /2:택배배송) ");
    	scanf("%d",&(p->deli));
	return 1;
}

// 하나의 제품 출력 함수
int readProduct(Product p) {
    printf("%s  %-5s  %s  %d원   ",p.name,p.size,p.comment,p.price);
    if(p.deli==1) printf("새벽배송\n");
    else printf("택배배송 \n");
    return 0;
}

// 전체 등록된 제품 리스트 출력
int listProduct(Product *p[], int count) {
    printf("%-10s %-10s %-20s %-10s %-10s\n","제품명", "중량", "제품설명", "가격", "배송방법");
    printf("----------------------------------------------------\n");
    for(int i=0;i<count;i++)
    {
        if(p[i]==NULL) continue;
        printf("%2d ",i+1);
        readProduct(*p[i]);
    }
    return 0;
}

// 메뉴 수정할 함수
int updateProduct(Product *p){
    printf("새 제품명은? ");
    getchar();
    fgets(p->name,255,stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("제품에 대한 설명을 적어주세요. ");
    fgets(p->comment,MAX-1,stdin);
    p->comment[strlen(p->comment)-1]='\0';
    printf("제품의 중량은 어느정도 입니까? ");
    scanf("%s",p->size);
    printf("제품의 가격은 얼마입니까? ");
    scanf("%d",&(p->price));
    printf("제품의 배송방법은 무엇입니까?(1:새벽배송 /2:택배배송) ");
    scanf("%d",&(p->deli));

    printf("=> 수정성공!\n");
    return 1;
}

// 메뉴 삭제할 함수
int deleteProduct(Product *p[], int count){
    int num;
    listProduct(p, count);
    printf("몇번을 삭제하시겠습니까? (취소:0)? ");  //삭제할 제품 번호 묻기
    scanf("%d",&num);

    //삭제 취소
    if(num == 0) {
        printf("=> 취소됨!\n");
        return 0;
    }
    int deleteok;
    printf("정말로 삭제하시겠습니까?(삭제 :1)"); 
    scanf("%d",&deleteok); 
    //삭제 진행
    if(deleteok == 1){
        if(p[num-1]) free(p[num-1]);
        p[num-1] = NULL;
        count--;
        printf("=> 삭제됨!\n");
    }
    return 0;
}

// 제품 검색
void searchProduct(Product *p[], int count) {
    int scnt =0, num;
    char search[MAX];

    printf("검색하고 싶은 메뉴는?(1.제품명 2.중량, 3.가격 4.배송방법) "); //제품검색할 방법 묻기
    scanf("%d",&num);

    //1. 제품이름으로 검색
    if(num==1){
        printf("검색할 제품이름은? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%-5s %-5s %-5s %-5s %-5s\n","제품명", "중량", "제품설명", "가격", "배송방법");
        printf("----------------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(p[i]==NULL) continue;
            if(strstr(search,p[i]->name)) {
                printf("%2d ",i+1);
                readProduct(*p[i]);
                scnt++;
            }
        }
    }

    //2. 제품 중량으로 검색
    else if(num==2){
        printf("검색할 제품의 중량은? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%-5s %-5s %-5s %-5s %-5s\n","제품명", "중량", "제품설명", "가격", "배송방법");
        printf("----------------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(p[i]==NULL) continue;
            if(strstr(search,p[i]->size)) {
                printf("%2d ",i+1);
                readProduct(*p[i]);
                scnt++;
            }
        }
    }
    //3. 제품 가격으로 검색
    else if(num==3){
        printf("검색할 제품의 가격은? ");
        scanf("%d",&num);

        printf("%-5s %-5s %-5s %-5s %-5s\n","제품명", "중량", "제품설명", "가격", "배송방법");
        printf("----------------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(p[i]==NULL) continue;
            if(num==p[i]->price) {
                printf("%2d ",i+1);
                readProduct(*p[i]);
                scnt++;
            }
        }
    }
    //4. 제품 배송방법으로 검색
    else if(num==4){
        printf("검색할 제품의 배송방법은? ");
        scanf("%d",&num);

        printf("%-5s %-5s %-5s %-5s %-5s\n","제품명", "중량", "제품설명", "가격", "배송방법");
        printf("----------------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(p[i]==NULL) continue;
            if(num == p[i]->deli) {
                printf("%2d ",i+1);
                readProduct(*p[i]);
                scnt++;
            }
        }
    }

    if(scnt==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void savdData(Product *p[],int count){
    FILE *fp = fopen("menu.txt","wt");

    for(int i=0;i<count;i++){
        if(p[i]==NULL) continue;
        fprintf(fp, "%s;%s;%s;%d;%d;\n",p[i]->name,p[i]->size,p[i]->comment,p[i]->price,p[i]->deli, 256);
    }
    fclose(fp);
    printf("==> 저장됨!\n\n");
}

int loadData(Product *p[],int index){
    char *ptr;
    char str[256];
    int count=0;
    FILE *fp = fopen("menu.txt","rt");


    while(!feof(fp)){
        fgets(str,255,fp);

        p[count+index] = (Product *)malloc(sizeof(Product)); //메모리 동적할당

        ptr = strtok(str,";");
        strcpy(p[count+index]->name,ptr);
        ptr = strtok(NULL,";");
        strcpy(p[count+index]->size,ptr);
        ptr = strtok(NULL,";");
        strcpy(p[count+index]->comment,ptr);
        ptr = strtok(NULL,";");
        p[count+index]->price = atoi(ptr);
        ptr = strtok(NULL,";");
        p[count+index]->deli = atoi(ptr);
        ptr = strtok(NULL,";");
        count++;
    }
    fclose(fp);

    return count;
}
