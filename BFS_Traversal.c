//BFS Traversal Implementation
#include<stdio.h>
#include<conio.h>
#define MAX 8

//Prototype Decleration
void BFS(int graph[][MAX], int vertex);

void main(){
    //Initilizing the graph using Adjacency Matrix
    int graph[MAX][MAX] = {
                            {0,1,1,0,0,0,0,0},
                            {1,0,0,1,1,0,0,0},
                            {1,0,0,0,0,1,1,0},
                            {0,1,0,0,0,0,0,1},
                            {0,1,0,0,0,0,0,1},
                            {0,0,1,0,0,0,0,1},
                            {0,0,1,0,0,0,0,1},
                            {0,0,0,1,1,1,1,0},
                        };
    BFS(graph, 0);

}
void BFS(int graph[][MAX], int vertex){
    int Q[MAX], f = -1, r = -1;
    int visited[MAX] = {0};
    int k;
    Q[++r] = vertex;
    f++;
    visited[vertex]  = 1;
    printf("BFS:- ");
    while(r >= f){
        vertex = Q[f++];
        printf("%d ", vertex);
        for(k = 0; k < MAX; k++){
            if(graph[vertex][k] == 1 && visited[k] == 0){
                Q[++r] = k;
                visited[k] = 1;
            }
        }
    }
    
}