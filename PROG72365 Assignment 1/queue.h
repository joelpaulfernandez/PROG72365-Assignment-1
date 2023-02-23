#pragma once


#include "user.h"

typedef struct queue_node {
    struct queue_node* next;
    user_t user;
} queue_node_t;

typedef struct {
    queue_node_t* head;
    queue_node_t* tail;
} queue_t;

void queue_init(queue_t* queue);
int queue_is_empty(queue_t* queue);
void queue_enqueue(queue_t* queue, user_t user);
user_t queue_dequeue(queue_t* queue);