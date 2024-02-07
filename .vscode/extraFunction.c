#include "header.h"

void managerOption() {
    int a;
    prompt2();
    scanf("%d",&a);
    managerselection(a);
}

void print(Account* acc) {
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    printf("A/C no\tName\tSurname\tDOB\tAge\tMobile No\tAccount Type\n");
    for (int i=0;i<Last+1;i++) {
          if (acc[i].Act_ID==1) {
            printf("%d\t%s\t%s\t%d\t%d\t%ld\t",acc[i].AccountNo,acc[i].name,acc[i].surname,acc[i].DOB,acc[i].Age,acc[i].MobileNo);
            if (acc[i].TOA==1) {
                printf("Saving\n");
            }
            else {
                printf("Current\n");
            }
          }
    }
}

int comparator(const void *b1,const void *b2) {
    Account *a1=(Account*) b1;
    Account *a2=(Account*) b2;
    return strcmp(a1->name,a2->name);
}

void sort_by_name() {
    Account* sort=(Account*)malloc(sizeof(Account)*MaxLen);
    sort=startPtr;
    qsort(sort,Last+1,sizeof(Account),comparator);
    print(sort);
}

void select_method() {
    int n;
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    printf("1. Brute Force Method\n2. Approximation Method\n\n");
    scanf("%d",&n);
    if (n==1) {
        printf("How many city he has to visit:");
        scanf("%d",&city);
        travel();
    }
    else if (n==2) {
        printf("How many city he has to visit:");
        scanf("%d",&city);
        Approximation();
    }
}