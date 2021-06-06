#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50
typedef struct  GraphType
{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


bool visited[MAX_VERTICES];

void init(GraphType *g){
    g->n = 0;
    for(int r=0; r<MAX_VERTICES; r++){
        for(int c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    if((g->n)+1>MAX_VERTICES){
        printf("그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end){
    if(start >= g->n || end >= g->n){
        printf("그래프:정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType *g){
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void dfs_mat(GraphType *g, int v){
    visited[v] = true; //v에는 방문표시
    printf("vertex %d->",v);
    for(int w=0; w<g->n; w++){
        if(g->adj_mat[v][w] && !visited[w]){//연결되어있고 방문되지 않았으면
            dfs_mat(g,w);//방문
        }
    }
    
}

void main(){
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++){
        insert_vertex(g,i);
    }
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    printf("depth first search\n");
    dfs_mat(g,0);
    printf("\n");

    free(g);
}