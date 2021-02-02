#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

void map_init(struct map_st *map) {
    map->count = 0;
}

void map_add(struct map_st *map, char *key, char *value) {
    if (map->count >= MAP_TABLE_LEN) {
        printf("No more room in map.\n");
        exit(-1);
    }
    strncpy(map->table[map->count].key, key, MAP_KEY_LEN);
    strncpy(map->table[map->count].value, value, MAP_VALUE_LEN);
    map->count += 1;
}

char * map_lookup(struct map_st *map, char *key) {
    int i;
    char *value = NULL;

    for (i = 0; i < map->count; i++) {
        if (strncmp(key, map->table[i].key, MAP_KEY_LEN) == 0) {
            value = map->table[i].value;
        }
    }

    return value;
}

#if 0
int main(int argc, char **argv) {
    struct map_st map;
    char *value;
    char *key;

    map_init(&map);

    map_add(&map, "course", "cs315");
    map_add(&map, "year", "2020");
    map_add(&map, "term", "fall");

    key = "year";
    value = map_lookup(&map, key);
    if (value) {
        printf("key = %s, value = %s\n", key, value);
    } else {
        printf("key = %s not found\n", key);
    }

    key = "section";
    value = map_lookup(&map, key);
    if (value) {
        printf("key = %s, value = %s\n", key, value);
    } else {
        printf("key = %s not found\n", key);
    }
    
    return 0;
}
#endif
