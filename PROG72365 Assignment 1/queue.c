


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"

void queue_init(queue_t* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int queue_is_empty(queue_t* queue) {
    return queue->head == NULL;
}

void queue_enqueue(queue_t* queue, user_t user) {
    queue_node_t* new_node = malloc(sizeof(queue_node_t));
    if (new_node == NULL) {
        // error: unable to allocate memory
        exit(1);
    }
    new_node->next = NULL;
    new_node->user = user;
    if (queue_is_empty(queue)) {
        queue->head = new_node;
    }
    else {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;
}
/*
user_t queue_dequeue(queue_t* queue) {
    if (queue_is_empty(queue)) {
        // error: cannot dequeue from empty queue
        exit(1);
    }
    queue_node_t* old_head = queue->head;
    user_t user = old_head->user;
    queue->head = old_head->next;
    free(old_head);
    if (queue_is_empty(queue)) {
        queue->tail = NULL;
    }
    return user;
}
*/
int enqueue_random_users(queue_t* queue, int num_users) {
    srand(time(NULL)); // initialize random seed
    for (int i = 0; i < num_users; i++) {
        user_t user;
        // generate random username
        for (int j = 0; j < USERNAME_LENGTH; j++) {
            user.username[j] = 'A' + rand() % 26; // uppercase letters
            if (j < USERNAME_LENGTH - 3) {
                user.username[j] = '0' + rand() % 10; // numbers
            }
        }
        user.username[USERNAME_LENGTH] = '\0'; // null terminator
        // generate random level
        user.level = 1 + rand() % 60;
        // generate random faction
        user.faction = rand() % 3;
        queue_enqueue(queue, user);
    }
    return 0;
}


void traverse(queue_node_t* node) {
    if (node == NULL) {
        return;
    }
    user_t user = node->user;
    printf("Username: %s, Level: %d, Faction: ", user.username, user.level);
    switch (user.faction) {
    case RED:
        printf("Red\n");
        break;
    case BLUE:
        printf("Blue\n");
        break;
    case GREEN:
        printf("Green\n");
        break;
    }
    traverse(node->next);
}

void traverseR(queue_node_t* node) {
    if (node == NULL) {
        return;
    }
    traverseR(node->next);
    user_t user = node->user;
    printf("Username: %s, Level: %d, Faction: ", user.username, user.level);
    switch (user.faction) {
    case RED:
        printf("Red\n");
        break;
    case BLUE:
        printf("Blue\n");
        break;
    case GREEN:
        printf("Green\n");
        break;
    }
}

