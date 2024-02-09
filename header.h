#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef long long int ll;

/* Structure for Details of Accounts */
typedef struct Account {
    int Act_ID;             // If 1 it means account is active
    int AccountNo;          // This is randomly generated which is always minimum possible number
    char name[20];
    char surname[20];
    int DOB;                // Format ddmmyyyy
    int Age;
    long int MobileNo;
    int Account_Type;       // If 1 account is saving and if 2 account is current
    int ATM;     
    int TOA;           // 0 for No and 1 for Yes
    int cheque;
    ll money;
} Account;

/* Initialize Storing Element */
Account* startPtr;          // Array to store customers
int MaxLen;                 // Max possible customers
int Point;                  // This is point for next position for customer
int Last;                   // Storing last AccountNo
int city;

typedef struct MinimumACno {
    int number;
    struct MinimumACno* next;
} MinimumACno;

MinimumACno* MinimumACnoStart;
MinimumACno* MinimumACnoEnd;
MinimumACno* MinimumACnoPoint;

int** cost;
int** dp;

/* Declaring Selection Functions */
void depositeFunds();
void withdrawFunds();
void checkBalance();
void allAccountHoldersDetails();
void managerOption();
void decidePoint();

void print(Account* acc);
void SetMinimumACno(int);
/* Manager Developer Functions */
void sorts();

/* Divide and Conquer */
void mergeSort(Account arr[], int l, int r);
void mergeSort_age(Account arr[], int l, int r);
void merge(Account arr[], int l, int m, int r);
void merge_age(Account arr[], int l, int m, int r);

/* Min Notes */
void min_Notes(int amount);

void select_method();


void travel();
int tsp(int mask, int pos, int city, int VISITED_ALL);
int min(int a, int b);


void acc_by_name(char name[20]);
int binarySearch(Account arr[], int l, int r, char x[20]);
int comparator(const void *b1,const void *b2);
void sort_by_name();






