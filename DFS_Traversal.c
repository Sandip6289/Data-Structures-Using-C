//DFS Traversal Implementation
#include<stdio.h>
#include<conio.h>
#define MAX 8

//Prototype Decleration
void DFS(int graph[][MAX], int visited[], int vertex);

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
    int visited[MAX] = {0};
    DFS(graph, visited, 0);

}
void DFS(int graph[][MAX], int visited[], int vertex){
    int k;
    printf("%d ",vertex);
    visited[vertex] = 1;
    for(k = 0; k < MAX; k++){
        if(graph[vertex][k] == 1 && visited[k] == 0){
            DFS(graph,visited, k);
        }
    }
}