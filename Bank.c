#include "header.h"

void createAccount(){
    char arr[4];
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    Account temp;
    printf("Enter Your Name\n");
    scanf("%s",temp.name);
    printf("Enter Your Sur Name\n");
    scanf("%s",temp.surname);
    printf("Enter Your Age\n");
    scanf("%d",&temp.age);
    printf("Enter Your Date of Birth\n");
    scanf("%d",&temp.dob);
    printf("Enter Your Mobile Number\n");
    scanf("%d",&temp.mob);
    printf("Type of Account : Press --> 1 for Savings \t Press -->2 for Current \n ");
    scanf("%d",&temp.toa);
    printf("Do you want ATM card? YES or NO\n");
    scanf("%s",arr);

    if(strcmp(arr,"YES")==0){
        temp.atm=1;
    } else {
        temp.atm=0;
    }

    printf("Do you want Chequebook? YES or NO\n");
    scanf("%s",arr);

    if(strcmp(arr,"YES")==0){
        temp.cheque=1;
    } else {
        temp.cheque=0;
    }


    printf"What amount you want to deposit ?\n");
    scanf("%d",&temp.money);

    decidePoint();

    if(Point == MaxLen){
        startPtr=(Account*) realloc(startPtr,MaxLen*sizeof(Account)*2);
        MaxLen=MaxLen*2;
    }

    temp.acc_no=Point;
    temp.acc_id=1;
    startPtr[Point]=temp;

    printf("\e[1;1H\e[2J");

    printf("Your Account number is %d\n",Point);
    


}

void depositFunds(){
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    
    long long int acc_no,amount;

    printf("ENTER ACCOUNT NUMBER = ");
    scanf("%lld",&acc_no);

    if(startPtr[acc_no].acc_id == 1){
        printf("\e[1;1H\e[2J");
        printf("ENTER THE AMOUNT TO BE ADDED : ");
        scanf("%lld",&amount);

        startPtr[acc_no].money += amount;
        printf("SUCCESSFULLY ADDED\n");

    }
    else{
        printf("INVALID ACCOUNT NUMBER\n");
    }

}

void withdrawFund(){
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    
    long long int acc_no,amount;

    printf("ENTER ACCOUNT NUMBER = ");
    scanf("%lld",&acc_no);

    if(startPtr[acc_no].acc_id == 1){
        printf("\e[1;1H\e[2J");
        printf("ENTER THE AMOUNT TO BE DEDUCTED : ");
        scanf("%lld",&amount);
        min_notes(amount);
        startPtr[acc_no].money -= amount;

        printf("SUCCESSFULLY DEDUCTED \n");

    }
    else{
        printf("INVALID ACCOUNT NUMBER\n");
    }

}


void checkBalance(){
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    
    long long int acc_no;

    printf("ENTER ACCOUNT NUMBER = ");
    scanf("%lld",&acc_no);

    if(startPtr[acc_no].acc_id == 1){
        printf("\e[1;1H\e[2J");
        printf("AVAILABLE BALANCE = %lld",startPtr[acc_no].money);
    }
    else{
        printf("INVALID ACCOUNT NUMBER\n");
    }

}

void allAccountHoldersDetail(){
    printf("\e[1;1H\e[2J");
    printf("\n--------- Welcome To MNNIT Bank ---------\n");
    
    printf("ACCOUNT NUMBER \t NAME \t SURNAME \t DOB \t AGE \t MOBILE NUMBER \t ACCOUNT TYPE\n");

    for(int i=0;i<Max_Len;i++){
        if(startPtr[i].acc_id == 1){
            printf("%lld \t %s \t %s \t %s \t %d \t %lld \t",startPtr[i].acc_no,startPtr[i].name,startPtr[i].surname,startPtr[i].dob,startPtr[i].age,startPtr[i].mobile_no);
            if(startPtr[i].account_type == 1) printf("SAVING\n");
            else printf("CURRENT\n");
        }
    }

}



