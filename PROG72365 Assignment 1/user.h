#pragma once


#define USERNAME_LENGTH 10

typedef enum { RED, BLUE, GREEN } faction_t;

typedef struct {
    char username[USERNAME_LENGTH + 1]; // +1 for null terminator
    int level;
    faction_t faction;
} user_t;