// Implementation of Graph Using Adjacency List

#include<stdio.h>
#include<stdlib.h>

// Initilizing the List Node 
struct ListNode{
    int nodeVal;
    struct ListNode *next;
};
// Initilizing the structure of the graph
struct Graph{
    int v;
    int e;
    struct ListNode **adj;
};

struct Graph* AdjacencyList(){
    int k, x, y;
    struct Graph *G;
    struct ListNode *t, *temp;
    
    G = (struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter the No. of Vertex: ");
    scanf("%d", &x);
    G->v = x;
    printf("Enter the No. of Edges: ");
    scanf("%d", &y);
    G->e = y;
    
    // Initilizing the List Node Array
    G->adj = malloc(x * sizeof(struct ListNode*));

    // Memory Initilization in each block 
    for(k = 0; k < G->v; k++){
        G->adj[k] = (struct ListNode*)malloc(sizeof(struct ListNode));
        G->adj[k]->nodeVal = k;
        G->adj[k]->next = NULL;
    }

    // Joining the Source Node & Destination Nodes
    for(k = 0; k < G->e; k++){
        printf("Enter the Source Node & Destination Node: ");
        scanf("%d %d", &x, &y);
        t = G->adj[x];
        while(t->next != NULL){
        	t = t->next;
            // printf("n");
        }
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->nodeVal = y;
        temp->next = NULL;
        t->next = temp;
    }
	return G;
}

// Printing the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->v; v++) {
    struct ListNode* temp = graph->adj[v];
    printf("\n Vertex %d\n: ", v);
    while (temp != NULL) {
      if(temp->next == NULL)
        printf("%d  ", temp->nodeVal);
      else
        printf("%d -> ", temp->nodeVal);

      temp = temp->next;
    }
    printf("\n");
  }
}

int main(){
	struct Graph *graph;
    graph = AdjacencyList();
    printGraph(graph);
    return 0;
}