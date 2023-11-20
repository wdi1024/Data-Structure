#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF 1000
#define N 7

int dist[N];
int visit[N];

typedef struct Edge
{
    char v1, v2;
    int weight;
    struct Edge *next;
}Edge;

typedef struct IncidentEdge
{
    char aName; 
    Edge *e;
    struct IncidentEdge *next;
}IncidentEdge;

typedef struct Vertex
{
    char vName;
    int isVisit;
    IncidentEdge *iHead;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex * vHead;
    Edge *eHead;
    int eCount, vCount;
}GraphType;

void init(GraphType *G)
{
    G->vHead = NULL;
    G->eHead = NULL;
    G->vCount = G->eCount = 0;
}

void makeVertex(GraphType *G, char vName)
{
    Vertex *v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;
    
    G->vCount++;
    
    Vertex *p = G->vHead;
    
    if(p == NULL)
        G->vHead = v;
    else
    {
        while(p->next != NULL)
            p = p->next;
            
        p->next = v;    
    }
}

void makeIncidentEdge(Vertex *v, char aName, Edge *e)
{
    IncidentEdge *p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->e = e;
    p->next = NULL;
    
    IncidentEdge* q = v->iHead;
    if(q == NULL)
        v->iHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
            
        q->next = p;    
    }
}

Vertex* findVertex(GraphType *G, char vName)
{
    Vertex *v = G->vHead;
    
    while(v->vName != vName)
        v = v->next;
        
    return v;    
}

void insertEdge(GraphType *G, char v1, char v2, int w)
{
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->weight = w;
    e->v1 = v1;
    e->v2 = v2;
    e->next = NULL;
    
    G->eCount++;
    
    Edge *q = G->eHead;
    
    if(q == NULL)
        G->eHead = e;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = e;    
    }
    
    
    Vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2, e);
    
    v = findVertex(G, v2);
    makeIncidentEdge(v, v1, e);
}

void incSort(GraphType* G, Edge* e[])
{
    int i, least;
    Edge* p = G->eHead;
    for(i = 0; i < G->eCount; i++)
    {
        e[i] = p;
        p = p->next;
    }
    
    for(i = 0; i < G->eCount - 1; i++)
    {
        least = i;
        for(int j = i + 1; j < G->eCount; j++)
            if(e[j]->weight < e[least]->weight)
                least = j;
        
        p = e[least];
        e[least] = e[i];
        e[i] = p;
    }
    
    for(i = 0; i < G->eCount; i++)
        printf("[%c%c%d] ", e[i]->v1, e[i]->v2, e[i]->weight);
    printf("\n\n");    
}


void print(int graph[N][N])
{
    printf("=============================\n");
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            if(graph[i][j]==INF)
                printf("  * ");
            else
                printf("%3d ", graph[i][j]);
        printf("\n");
    }
    printf("=============================\n");
}

int vFind(int v[], int vNum)
{

    while(v[vNum] != -1)
        vNum = v[vNum];
        
    return vNum;    
}

void vUnion(int v[], int vNum1, int vNum2)
{
    int v1 = vFind(v, vNum1);
    int v2 = vFind(v, vNum2);
    
    v[v2] = v1;
}

void kruskal(GraphType *G, Edge* e[], int v[])
{
    int eCnt = 0, i = 0;
    int vNum1, vNum2;
    Edge *p;
    
    while(eCnt < G->vCount - 1)
    {
        p = e[i];
        
        vNum1 = vFind(v, p->v1 - 97);
        vNum2 = vFind(v, p->v2 - 97);
        
        if(vNum1 != vNum2)
        {
            eCnt++;
            printf("%d. [%c%c %d]\n", eCnt, p->v1, p->v2, p->weight);
            vUnion(v, vNum1, vNum2);
        }
        i++;
    }
}

char getMinVertex(GraphType *G, int dist[])
{
    Vertex *p = G->vHead;
    char vName;
    
    for(; p != NULL; p = p->next)
    {
        if(p->isVisit == FALSE)
        {
            vName = p->vName;
            break;
        }
    }
    
    for(p = G->vHead; p != NULL; p = p->next)
        if(p->isVisit == FALSE && (dist[p->vName - 97] < dist[vName - 97]))
            vName = p->vName;
            
    return vName;        
}

void prim(GraphType *G, char vName, int dist[])
{
    Vertex *p = findVertex(G, vName);
    IncidentEdge *q;
    char c;
    
    dist[vName - 97] = 0;
    
    for(int i = 0; i < G->vCount; i++)
    {
        c = getMinVertex(G, dist);
        p = findVertex(G, c);
        p->isVisit = TRUE;
        printf("[%c] ", p->vName);
        
        for(q = p->iHead; q != NULL; q = q->next)
        {
            p = findVertex(G, q->aName);
            if(p->isVisit == FALSE && dist[q->aName - 97] > q->e->weight) 
                dist[q->aName - 97] = q->e->weight;
        }
    }
}

int findMin()
{
    int min = 2*INF, minIdx;
    for(int i=0; i < N; i++)
    {
        if (dist[i] < min && visit[i]==FALSE)
        {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int graph[N][N], int start)
{
    int u, v;
    for(int i=0; i<N; i++)
    {
        dist[i] = graph[start][i];
        visit[i] = FALSE;
    }
    visit[start] = TRUE;
    printf("%d(%d) ", start, dist[start]);

    for(int i=0; i< N-1; i++)
    {
        u = findMin();
        visit[u] = TRUE;
        printf("%d(%d) ", u , dist[u]);
        for(int v=0; v<N; v++)
        {
            if(visit[v]==FALSE)
                if(dist[u]+ graph[u][v] < dist[v])
                    dist[v] = dist[u]+ graph[u][v];
        }
    }
    printf("\n");
}

void printStatus()
{
    static int step = 1;
    printf("STEP %d. ", step++);
    
    for (int i=0; i<N; i++)
    {
        if (dist[i] == INF)
            printf("  * ");
        else
            printf("%2d ", dist[i]);
    }
    printf("\n");
    printf(" visit : ");
    for (int i=0; i<N; i++)
    {
        if(visit[i] == FALSE)
            printf("F  ");
        else
            printf("T  ");
    }
    printf("\n");
}

void floyd(int graph[N][N])
{
    for (int k=0; k< N; k++)
    {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

        printf("k : %d\n", k);
        print(graph);
    }
}

int main()
{
    int graph[N][N] =
    {
        {0, 7, INF, INF, 3, 10, INF},
        {7, 0, 4, 10, 2, 6, INF},
        {INF, 4, 0, 2, INF, INF, INF},
        {INF, 10, 2, 0, 11, 9, 4},
        {3, 2, INF, 11, 0, INF, 5},
        {10, 6, INF, 9, INF, 0, INF},
        {INF, INF, INF, 4, 5, INF, 0}
    };

    print(graph);
    dijkstra(graph, 0);
    floyd(graph);
    
    return 0;
}













