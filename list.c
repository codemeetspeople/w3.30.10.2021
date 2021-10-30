#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 10


typedef struct {
    int* array;
    int size;
    int current;
} List;


void init(List* list) {
    list->size = CHUNK_SIZE;
    list->current = 0;
    list->array = (int*)malloc(list->size*sizeof(int));

    if ( list->array == NULL ) {
        printf("No memory available!\n")
    }
}

void destroy(List* list) {
    list->size = 0;
    list->current = 0;
    free(list->array);
}

void push_back(List* list, int value) {
    int new_current = list->current + 1;

    if ( new_current == list->size ) {
        int* bkp = list->array;
        int new_size = list->size + CHUNK_SIZE;

        list->array = (int*)realloc(list->array, new_size*sizeof(int));

        if ( list->array == NULL ) {
            printf("No memory available!\n");
            list->array = bkp;
            return;
        }
        list->size = new_size;
    }

    list->array[list->current] = value;
    list->current = new_current;
}

int pop_back(List* list) {
    int new_current = list->current - 1;

    if ( new_current < 0 ) {
        printf("List is empty!\n");
        return -1;
    }

    list->current = new_current;
    return list->array[list->current];
}


void clear(List* list) {
    if ( list->size - list->current < CHUNK_SIZE ) {
        return;
    }

    int new_size = list->current + (CHUNK_SIZE - list->current % CHUNK_SIZE);
    int* bkp = list->array;

    list->array = (int*)realloc(list->array, new_size*sizeof(int));

    if ( list->array == NULL ) {
        printf("No memory available!\n");
        list->array = bkp;
        return;
    }
    list->size = new_size;
}

void insert(List* list, int index, int value) {
    // Insert value to index in array
    // before: [1, 2, 3, 4, 5, 6, 7]
    // insert(list, 3, 42);
    // after: [1, 2, 3, 42, 4, 5, 6, 7]
}

void erase(List* list, int index) {
    // Insert value to index in array
    // before: [1, 2, 3, 4, 5, 6, 7]
    // erase(list, 3);
    // after: [1, 2, 3, 5, 6, 7]
}

void print(List* list) {
    int last = list->current - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", list->array[i]);
    }
    printf("%d\n", list->array[last]);
}


int main() {
    List list;

    init(&list);

    for ( int i = 0; i < 15; i++ ) {
        push_back(&list, 42+i);
    }
    printf("full size:%d actual size: %d\n", list.size, list.current);
    print(&list);

    for ( int i = 0; i < 7; i++ ) {
        pop_back(&list);
    }

    printf("full size:%d actual size: %d\n", list.size, list.current);
    print(&list);

    clear(&list);
    printf("full size:%d actual size: %d\n", list.size, list.current);
    print(&list);

    destroy(&list);

    return 0;
}