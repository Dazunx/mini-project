#include "manager.h" 

int main(void){
    Product *p[100]; //포인터변수 선언
    int count = 0, menu;
    int index = 0;
    int num;
    char user[20];

#ifdef USER
    printf("Username : ");
    scanf("%s",user);
    printf("Welcome %s!\n",user);
#endif
    while (1){
	menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1) {
            if(count > 0)
                listProduct(p,index);
            else   
                printf("데이터가 없습니다.\n");
        }
        else if (menu == 2) {
            p[index] = (Product *)malloc(sizeof(Product)); //메모리 동적할당
            count += createProduct(p[index++]);
            printf("=> 추가됨!\n");
        }
        else if (menu == 3) {
            num = selectDataNo(p,index);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p[num-1]);
        }
        else if (menu == 4) {
            num = selectDataNo(p,index);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(p[num-1]) free(p[num-1]); //동적할당 해제
                p[num-1] = NULL; //포인터 해제
                count--;
                printf("=> 삭제됨!\n");
            }
        }
        else if (menu == 5) {
            searchProduct(p, count);
        }
        else if (menu == 6) {
            savdData(p,count);
        }
    }
    printf("종료됨!\n");
    return 0;
}


