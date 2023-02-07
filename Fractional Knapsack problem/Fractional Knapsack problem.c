// Fractional Knapsack problen on Profit by weight ratio

#include <stdio.h>
#include <stdlib.h>
struct obj{
    int p;
    int w;
    double r;
};
int cmp(const void* a, const void* b){
    struct obj* x = (struct obj*)a;
    struct obj* y = (struct obj*)b;
    if(y->r > x->r){
        return 1;
    }
    else if(x->r == y->r){
        return 0;
    }
    else{
        return -1;
    }
}
int main(){
    int m;
    printf("Enter capacity of the bag:\n");
    scanf("%d", &m);
    int n;
    printf("\nEnter n value:\n");
    scanf("%d", &n);
    struct obj o[n];
    int i;
    printf("\nEnter profit and weight of every obect:\n");
    for(i = 0; i < n; i++){
        scanf("%d%d", &o[i].p, &o[i].w);
    }
    for(i = 0; i < n; i++){
        o[i].r = (double)o[i].p / o[i].w;
    }
    qsort(o, n, sizeof(struct obj), cmp);
    int profit = 0;
    for(i = 0; i < n; i++){
        if(o[i].w <= m){
            profit = profit + o[i].p;
            m = m - o[i].w;
        }
        else{
            break;
        }
    }
    if(i != n){
        profit = profit + o[i].r * m;
    }
    printf("\nProfit is : %d", profit);
    return 0;
}

