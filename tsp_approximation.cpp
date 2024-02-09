#include "header.h"
int total=0;

void dfs(int v,bool vis[],int graph[][city]){
    vis[v]=1;
    printf("%d --> ",v);

    for(int child=0;child<city;child++){
        if(graph[v][child] && !vis[child]){
            total+=cost[v][child];
            dfs(child,vis,graph);
        }
    }

}

int findMinKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < city; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST()
{
    int key[city];
    int parent[city];
    bool mstSet[city];
    for (int i = 0; i < city; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < city - 1; count++)
    {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < city; v++)
        {
            if (cost[u][v] && mstSet[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    int graph[city][city];

    for(int i=0;i<city;i++){
        for(int j=0;j<city;j++){
            if(parent[j]==i){
                graph[i][j]=1;
                graph[j][i]=1;
            }
            else {
                graph[i][j]=0;
            }
        }
    }
    
    bool vis[city];
    
    dfs(0,vis,graph);
    
    printf("0");
    
    printf("\n TOTAL = %d",total);

}

void approximation()
{
    char arr[city][20];
    printf("PLEASE ENTER CITY NAMES : \n");
    for (int i = 0; i < city; i++)
    {
        scnaf("%s", arr[i]);
    }

    cost = (int **)malloc(sizeof(int *) * city);

    for (int i = 0; i < city; i++)
    {
        cost[i] = (int *)malloc(sizeof(int) * city);
    }

    for (int i = 0; i < city; i++)
        cost[i][i] = 0;

    for (int i = 0; i < city; i++)
    {
        for (int j = 0; j < city; j++)
        {
            if (i != j)
            {
                printf("Enter cost for %s to %s \n", arr[i], arr[j]);
                scanf("%d", arr[i][j]);
            }
        }
    }

    primMST();
}