#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;     // QueueType 구조체 선언: int front, rear와 10사이즈 배열 queue가 있음

void queue_init(QueueType* q) {
    q->front = q->rear = 0;
} 	//queue_init(QueueType* q)함수 정의: 포인터 q가 가리키는 QueueType의 front와 rear에 0 대입

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}	//int is_empty: q->front == q->rear이면 return 1 (empty), 아니면 return 0

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}	//int is_full: (q->rear + 1)의 1의 자리수가 q->front와 같으면 return 1 (full), 아니면 return 0

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("Queue is full.\n");
    }   //enqueue(QueueType* q, element item)함수 정의: is_full = 1이면 "Queue is full." 출력 
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}       //q->rear에 (q->rear + 1)의 1의자리 수 대입, 행렬 queue[rear]에 item 대입

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    }   //element dequeue: is_empty = 1이면 "Queue is empty." 출력
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}       //q->front에 (q->front + 1)의 1의자리 수 대입, return q->queue[front]

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType; //GraphType 구조체 선언: int n과 adj_mat[50][50]이 있음

void graph_int(GraphType* g) {
    int r, c;
    g->n = 0;         //graph_int(GraphType* g)함수 정의: g->n에 0 대입
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }        //g->adj_mat[0][0]부터 g->adj_mat[50][50]까지 0 대입
    }
}

int vertex_arr[MAX_VERTICES]; // 노드값을 저장하는 전역변수 
int ver_cnt = 0; // 전체 노드의 개수를 저장하는 전역변수
int sum_of_even_value_vertexes=0; // 짝수노드 값의 합을 저장하는 전역변수

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {       // insert_vertex(GraphType* g, int v)함수 정의: g->n에 1을 더한 값이 50보다 크면
        printf("Graph: The number of vertices is more than MAX.\n");     //"Graph: The number of vertices is more than MAX." 출력
        return;
    }

    vertex_arr[g->n] = v;

    g->n++;     // g->n 1씩 증가
    
    ver_cnt++; // 노드 개수 1 증가
}

void insert_edge(GraphType* g, int start, int end) {    //insert_edge(GraphType* g, int start, int end)함수 정의
    if (start >= g->n || end >= g->n) {     // start또는 end가 g->n보다 크거나 같을 때
        printf("Graph: Vertex ID Error.\n");    //"Graph: Vertex ID Error." 출력
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;     //g->adj_mat[start][end]와 g->adj_mat[end][start]에 1 대입
}

int visited[MAX_VERTICES];  //50 사이즈 배열 visited
void bfs_mat(GraphType* g, int v) { //bfs_mat(GraphType* g, int v)함수 정의
    int w;
    QueueType q;                    // int w, QueueType q
    queue_init(&q);                // q->front와 rear에 0 대입
    visited[v] = TRUE;              // visited[v]에 TRUE 대입
    printf("NODE %d ", v);          // "NODE v" 출력
    enqueue(&q, v);                 // QueueType* q가 full 이면 "Queue is full." 출력, q->rear에 + 1, queue[rear]에 v 대입
    while (!is_empty(&q)) {         // QueueType* q가 empty가 아닐 때 (front ≠ rear일 때) 반복
        v = dequeue(&q);            // q->front + 1, v에 queue[front] 대입
        for (w = 0; w < g->n; w++) {    // w < g->n일 때 반복
            if (g->adj_mat[v][w] && !visited[w]) {  //adj_mat[v][w]가 1이고 visited[w]가 0이면
                visited[w] = TRUE;
                printf("NODE %d ", w);  //visited[w] = 1, "NODE w" 출력

                enqueue(&q, w);     // QueueType* q가 full 이면 "Queue is full." 출력, q->rear + 1, queue[rear]에 w 대입
            }
        }
    }
}



int main(void) {
    GraphType* g; // 포인터 g는 GraphType을 가리킴
    g = (GraphType*)malloc(sizeof(GraphType));  // GraphType의 크기만큼 메모리 할당
    graph_int(g); //  GraphType* g의 adj_mat 초기화
     

    //테스트 샘플 노드 생성

    
    insert_vertex(g, 10);
    insert_vertex(g, 11);
    insert_vertex(g, 3);
    insert_vertex(g, 8);
    insert_vertex(g, 1);
    insert_vertex(g, 7);
    insert_vertex(g, 2);
    insert_vertex(g, 2);
    insert_vertex(g, 2);


    



    insert_edge(g, 0, 1);   // GraphType* g의 adj_mat[0][1], adj_mat[1][0]에 1 삽입
    insert_edge(g, 0, 2);   // adj_mat[0][2], adj_mat[2][0]에 1 삽입
    insert_edge(g, 0, 3);   // adj_mat[0][3], adj_mat[3][0]에 1 삽입
    insert_edge(g, 1, 4);   // adj_mat[1][4], adj_mat[4][1]에 1 삽입
    insert_edge(g, 2, 5);    // adj_mat[2][5], adj_mat[5][2]에 1 삽입 
    bfs_mat(g, 0);      // bfs_mat(GraphType* g, int v)실행 => "NODE~"출력
    printf("\n");
    free(g);    // g 삭제 



    //과정상 확인을 위해 vertex와 vertex의 값을 출력해 과정을 확인한다.
    /*
    for (int i = 0; i < ver_cnt; i++) {
        printf("vertex %d 번째 : %d\n",i,vertex_arr[i]);

    }
    printf("Sum of Even Value Vertexes: %d\n",sum_of_even_value_vertexes); 
    */


    for (int i = 0; i < ver_cnt; i++) {
        if (visited[i] == 1 && vertex_arr[i] % 2 == 0) {
            sum_of_even_value_vertexes += vertex_arr[i];
        }
    }





    //제출전 삭제 하기!!!
    for (int i = 0; i < ver_cnt; i++) {
        printf("%d번 노드 방문 여부:%d\n", i,visited[i]);
    }


    // root.txt 파일 입력 부분
    FILE* fp = NULL;
    fp = fopen("root.txt", "w"); // 쓰기 모드로 파일 열기

    if (fp == NULL) {
        printf("Failed to read file\n"); // 파일이 없거나 이상시에 Failed to read file 출력
        return 0;
    }
    for (int i = 0; i < ver_cnt; i++) {
        if (visited[i] == TRUE && vertex_arr[i] % 2 == 0) {
            fprintf(fp, "vertex%d : %d\n", i,vertex_arr[i]); //vertex 0의 경우 시작 노드로 항상 방문하므로 파일에 추가한다.
        }
    }
    fprintf(fp, "Sum of Even Value Vertexes = %d\n", sum_of_even_value_vertexes); // 방문한 vertex 중 짝수 값의 합을 저장한다. 

    fclose(fp); // 파일을 닫는다.

    return 0;
}
