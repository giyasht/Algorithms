#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct node *create_node(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph
{
    int numVertices;
    int *visited;
    struct node **adjacencylists;
};

struct Graph *create_graph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjacencylists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjacencylists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void add_edge(struct Graph *graph, int src, int dest)       // to add edge between source and destination
{

    struct node *newNode = create_node(dest);
    newNode->next = graph->adjacencylists[src];
    graph->adjacencylists[src] = newNode;
    newNode = create_node(src);
    newNode->next = graph->adjacencylists[dest];
    graph->adjacencylists[dest] = newNode;
}

void print_graph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjacencylists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFS(struct Graph *graph, int vertex)       // function for Depth First Search
{
    struct node *adjlist = graph->adjacencylists[vertex];
    struct node *temp = adjlist;
    graph->visited[vertex] = 1;
    printf("%d --> ", vertex);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, choice, src, dest, x;
    printf("Enter no fo vertices\n");
    scanf("%d", &n);  //n is no of vertices
    struct Graph *graph = create_graph(n);
    while (1)
    {
        printf("\nEnter from following choices:\t1.add edge\t\t2. print graph\t\t 3.DFS\t\t4.Exit \n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter source vertex for edge\n");
            scanf("%d", &src);
            printf("enter destination vertex for edge\n");
            scanf("%d", &dest);
            add_edge(graph, src, dest);  //add edge
            break;
        case 2:
            print_graph(graph);   
            break;
        case 3:
            printf("Enter node\n");
            scanf("%d", &x);
            DFS(graph, x);   // Depth First Search
            break;
        case 4:
            exit(0); // exit of loop

        default:
            printf("Wrong Input\n");
        }
    }
    return 0;
}
