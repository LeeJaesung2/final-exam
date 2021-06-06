#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message){
    printf("%s\n",message);
    exit(1);
}

void queue_init(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return(q->front==q->rear);
}

int is_full(QueueType *q){
    return((q->rear+1)%MAX_QUEUE_SIZE==q->front);
}

void enqueueu (QueueType *q, element item){
    if(is_full(q)){
        error("queue is full");
    }
    q->rear = (q->rear +1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("queue is empty");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define MAX_VERTICES 50

typedef struct GraphType
{
    int n;
    int adj_mat[MAX_QUEUE_SIZE][MAX_QUEUE_SIZE];
}GraphType;

bool visited[MAX_QUEUE_SIZE];

void graph_init(GraphType *g){
    g->n = 0;
    for(int r=0; r<MAX_QUEUE_SIZE; r++){
        for(int c=0; c<MAX_QUEUE_SIZE; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    if(((g->n)+1)>MAX_QUEUE_SIZE){
        error("vertex is over");
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end){
    if(start>=g->n || end>=g->n){
        error("vertex number error");
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void bfs_mat(GraphType *g, int v){
    QueueType *q;
    queue_init(q);

    visited[v] = true;
    printf("%d visit->",v);
    enqueueu(q,v);
    while(!is_empty(q)){
        v = dequeue(q);
        for(int w=0; w<g->n; w++){
            if(g->adj_mat[v][w]&&!visited[w]){
                visited[w] = true;
                printf("%d visit->",w);
                enqueueu(q,w);
            }
        }
    }
}

int main(void){
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    for(int i=0; i<6; i++){
        insert_vertex(g,i);
    }
    insert_edge(g,0,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,0,4);
    insert_edge(g,4,5);
    insert_edge(g,1,5);

    printf("breadth first search\n");
    bfs_mat(g,0);
    printf("\n");
    free(g);
    return 0;
}