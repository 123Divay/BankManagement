#include "header.h"

int main() {
    MinimumACnoStart=(MinimumACno*)malloc(sizeof(MinimumACno));
    MinimumACnoEnd=(MinimumACno*)malloc(sizeof(MinimumACno));
    MinimumACnoPoint=(MinimumACno*)malloc(sizeof(MinimumACno));
    MinimumACnoStart=NULL;
    MinimumACnoEnd=NULL;
    MinimumACnoPoint=NULL;
    startPtr=(Account*)malloc(sizeof(Account)*2);
    MaxLen=2;
    Point=0;
    Last=-1;
    int First;
    while(1) {
        mainPrompt();
        scanf("%d",&First);
        first_Selection(First);
    }
    return 0;
}