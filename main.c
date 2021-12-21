#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;     // QueueType ����ü ����: int front, rear�� 10������ �迭 queue�� ����

void queue_init(QueueType* q) {
    q->front = q->rear = 0;
} 	//queue_init(QueueType* q)�Լ� ����: ������ q�� ����Ű�� QueueType�� front�� rear�� 0 ����

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}	//int is_empty: q->front == q->rear�̸� return 1 (empty), �ƴϸ� return 0

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}	//int is_full: (q->rear + 1)�� 1�� �ڸ����� q->front�� ������ return 1 (full), �ƴϸ� return 0

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("Queue is full.\n");
    }   //enqueue(QueueType* q, element item)�Լ� ����: is_full = 1�̸� "Queue is full." ��� 
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}       //q->rear�� (q->rear + 1)�� 1���ڸ� �� ����, ��� queue[rear]�� item ����

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    }   //element dequeue: is_empty = 1�̸� "Queue is empty." ���
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}       //q->front�� (q->front + 1)�� 1���ڸ� �� ����, return q->queue[front]

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType; //GraphType ����ü ����: int n�� adj_mat[50][50]�� ����

void graph_int(GraphType* g) {
    int r, c;
    g->n = 0;         //graph_int(GraphType* g)�Լ� ����: g->n�� 0 ����
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }        //g->adj_mat[0][0]���� g->adj_mat[50][50]���� 0 ����
    }
}

int vertex_arr[MAX_VERTICES]; // ��尪�� �����ϴ� �������� 
int ver_cnt = 0; // ��ü ����� ������ �����ϴ� ��������
int sum_of_even_value_vertexes=0; // ¦����� ���� ���� �����ϴ� ��������

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {       // insert_vertex(GraphType* g, int v)�Լ� ����: g->n�� 1�� ���� ���� 50���� ũ��
        printf("Graph: The number of vertices is more than MAX.\n");     //"Graph: The number of vertices is more than MAX." ���
        return;
    }

    vertex_arr[g->n] = v;

    g->n++;     // g->n 1�� ����
    
    ver_cnt++; // ��� ���� 1 ����
}

void insert_edge(GraphType* g, int start, int end) {    //insert_edge(GraphType* g, int start, int end)�Լ� ����
    if (start >= g->n || end >= g->n) {     // start�Ǵ� end�� g->n���� ũ�ų� ���� ��
        printf("Graph: Vertex ID Error.\n");    //"Graph: Vertex ID Error." ���
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;     //g->adj_mat[start][end]�� g->adj_mat[end][start]�� 1 ����
}

int visited[MAX_VERTICES];  //50 ������ �迭 visited
void bfs_mat(GraphType* g, int v) { //bfs_mat(GraphType* g, int v)�Լ� ����
    int w;
    QueueType q;                    // int w, QueueType q
    queue_init(&q);                // q->front�� rear�� 0 ����
    visited[v] = TRUE;              // visited[v]�� TRUE ����
    printf("NODE %d ", v);          // "NODE v" ���
    enqueue(&q, v);                 // QueueType* q�� full �̸� "Queue is full." ���, q->rear�� + 1, queue[rear]�� v ����
    while (!is_empty(&q)) {         // QueueType* q�� empty�� �ƴ� �� (front �� rear�� ��) �ݺ�
        v = dequeue(&q);            // q->front + 1, v�� queue[front] ����
        for (w = 0; w < g->n; w++) {    // w < g->n�� �� �ݺ�
            if (g->adj_mat[v][w] && !visited[w]) {  //adj_mat[v][w]�� 1�̰� visited[w]�� 0�̸�
                visited[w] = TRUE;
                printf("NODE %d ", w);  //visited[w] = 1, "NODE w" ���

                enqueue(&q, w);     // QueueType* q�� full �̸� "Queue is full." ���, q->rear + 1, queue[rear]�� w ����
            }
        }
    }
}



int main(void) {
    GraphType* g; // ������ g�� GraphType�� ����Ŵ
    g = (GraphType*)malloc(sizeof(GraphType));  // GraphType�� ũ�⸸ŭ �޸� �Ҵ�
    graph_int(g); //  GraphType* g�� adj_mat �ʱ�ȭ
     

    //�׽�Ʈ ���� ��� ����

    
    insert_vertex(g, 10);
    insert_vertex(g, 11);
    insert_vertex(g, 3);
    insert_vertex(g, 8);
    insert_vertex(g, 1);
    insert_vertex(g, 7);
    insert_vertex(g, 2);
    insert_vertex(g, 2);
    insert_vertex(g, 2);


    



    insert_edge(g, 0, 1);   // GraphType* g�� adj_mat[0][1], adj_mat[1][0]�� 1 ����
    insert_edge(g, 0, 2);   // adj_mat[0][2], adj_mat[2][0]�� 1 ����
    insert_edge(g, 0, 3);   // adj_mat[0][3], adj_mat[3][0]�� 1 ����
    insert_edge(g, 1, 4);   // adj_mat[1][4], adj_mat[4][1]�� 1 ����
    insert_edge(g, 2, 5);    // adj_mat[2][5], adj_mat[5][2]�� 1 ���� 
    bfs_mat(g, 0);      // bfs_mat(GraphType* g, int v)���� => "NODE~"���
    printf("\n");
    free(g);    // g ���� 



    //������ Ȯ���� ���� vertex�� vertex�� ���� ����� ������ Ȯ���Ѵ�.
    /*
    for (int i = 0; i < ver_cnt; i++) {
        printf("vertex %d ��° : %d\n",i,vertex_arr[i]);

    }
    printf("Sum of Even Value Vertexes: %d\n",sum_of_even_value_vertexes); 
    */


    for (int i = 0; i < ver_cnt; i++) {
        if (visited[i] == 1 && vertex_arr[i] % 2 == 0) {
            sum_of_even_value_vertexes += vertex_arr[i];
        }
    }





    //������ ���� �ϱ�!!!
    for (int i = 0; i < ver_cnt; i++) {
        printf("%d�� ��� �湮 ����:%d\n", i,visited[i]);
    }


    // root.txt ���� �Է� �κ�
    FILE* fp = NULL;
    fp = fopen("root.txt", "w"); // ���� ���� ���� ����

    if (fp == NULL) {
        printf("Failed to read file\n"); // ������ ���ų� �̻�ÿ� Failed to read file ���
        return 0;
    }
    for (int i = 0; i < ver_cnt; i++) {
        if (visited[i] == TRUE && vertex_arr[i] % 2 == 0) {
            fprintf(fp, "vertex%d : %d\n", i,vertex_arr[i]); //vertex 0�� ��� ���� ���� �׻� �湮�ϹǷ� ���Ͽ� �߰��Ѵ�.
        }
    }
    fprintf(fp, "Sum of Even Value Vertexes = %d\n", sum_of_even_value_vertexes); // �湮�� vertex �� ¦�� ���� ���� �����Ѵ�. 

    fclose(fp); // ������ �ݴ´�.

    return 0;
}
