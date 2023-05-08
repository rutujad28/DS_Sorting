#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 1000
#define MAX_LANDING_QUEUE_SIZE 100
#define MAX_TAKEOFF_QUEUE_SIZE 100

typedef struct {
    int timestamp;
    char type; // 'L' for landing, 'T' for takeoff
} Request;

typedef struct {
    Request data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enqueue(Queue *queue, Request request) {
    queue->rear++;
    queue->data[queue->rear] = request;
}

Request dequeue(Queue *queue) {
    Request request = queue->data[queue->front];
    queue->front++;
    return request;
}

int is_empty(Queue *queue) {
    return queue->front > queue->rear;
}

int main() {

    Queue landing_queue, takeoff_queue;
    init_queue(&landing_queue);
    init_queue(&takeoff_queue);

    int landing_count = 0, takeoff_count = 0;

    for (int i = 0; i < 120; i += 5) {
        printf("Time: %d\n", i);

        // Generate a landing or takeoff request
        char type;
        printf("Enter 'L' for Landing or 'T' for Takeoff : ");
        scanf(" %c", &type);
        getchar();

        // Try to grant the request
        if (type == 'L') {
            printf("Landing requested.\n");
            if (landing_count < 8) {
                printf("Landing granted.\n");
                landing_count++;
            } else if (landing_queue.rear < MAX_LANDING_QUEUE_SIZE - 1) {
                printf("Landing queueing.\n");
                Request request = {i, type};
                enqueue(&landing_queue, request);
            } else {
                printf("Landing denied.\n");
            }
        } 
        
        else if(type == 'T'){
            printf("Takeoff requested.\n");
            if (takeoff_count < 8) {
                printf("Takeoff granted.\n");
                takeoff_count++;
            } else if (takeoff_queue.rear < MAX_TAKEOFF_QUEUE_SIZE - 1) {
                printf("Takeoff queueing.\n");
                Request request = {i, type};
                enqueue(&takeoff_queue, request);
            } else {
                printf("Takeoff denied.\n");
            }
        }

        // Process completed landings and takeoffs
        if (!is_empty(&landing_queue) && landing_count < 8) {
            Request request = dequeue(&landing_queue);
            printf("Landing granted from queue.\n");
            landing_count++;
        }
        if (!is_empty(&takeoff_queue) && takeoff_count < 8) {
            Request request = dequeue(&takeoff_queue);
            printf("Takeoff granted from queue.\n");
            takeoff_count++;
        }
    }

    printf("Landing count : %d\n", landing_count);

    printf("Takeoff count : %d\n", takeoff_count);

    printf("Final landing queue contents:\n");
    while (!is_empty(&landing_queue)) {
        Request request = dequeue(&landing_queue);
        printf("Timestamp: %d, Type: %c\n", request.timestamp, request.type);
    }

    printf("Final takeoff queue contents:\n");
    while (!is_empty(&takeoff_queue)) {
        Request request = dequeue(&takeoff_queue);
        printf("Timestamp: %d, Type: %c\n", request.timestamp, request.type);
    }
}
