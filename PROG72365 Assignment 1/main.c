#include <stdio.h>
#include "queue.h"

int main(int argc, char* argv[])
{

    if (argc != 2) {
        printf("Usage: %s <num_users>\n", argv[0]);
        return 1;
    }

    int num_users = atoi(argv[1]);
    if (num_users <= 0) {
        printf("Error: invalid number of users\n");
        return 1;
    }
    queue_t queue;
    queue_init(&queue);
    if (enqueue_random_users(&queue, num_users) != 0) {
        printf("Error: unable to enqueue users");


    }
    while (!queue_is_empty(&queue)) {
        user_t user = queue_dequeue(&queue);
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

    return 0;
}
   
