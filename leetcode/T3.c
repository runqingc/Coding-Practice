#include<stdio.h>
#include<stdlib.h>
#define MAXN 1020

int N;
struct graph{
    int size;
    int weight;
    double density;
};
struct graph* g_list[MAXN];

int remain_weight = 128*128;

int cmp(const void* a, const void *b){
    struct graph** pa = (struct graph**) a;
    struct graph** pb = (struct graph**) b;
    if((*pa)->density - (*pb)->density > 0){
        return 1;
    }
    return 0;
}


int main(){

    scanf("%d", &N);
    int i, s, w;
    for(i=0; i<N; i++){
        scanf("%d %d", &s, &w);
        g_list[i] = (struct graph*) malloc (sizeof(struct graph));
        g_list[i]->size = s/8;
        g_list[i]->weight = w;
        g_list[i]->density = g_list[i]->weight / g_list[i]->size;
        printf("%lf ", g_list[i]->density);
    }
    for(i=0; i<N; i++) printf("%lf ", g_list[i]->density);
    qsort(g_list, sizeof(struct graph*), N, cmp);
    for(i=0; i<N; i++) printf("%lf ", g_list[i]->density);



    return 0;
}