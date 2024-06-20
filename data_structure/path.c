#include <stdio.h>
#include "backend.h"

/****************************************
Implement Breadth-First Search on the graph constructed in "backend.c" and
use it in the find_path() below.

You can access functions and data structures constructed in "backend.c" via
"backend.h"
*****************************************/

int queue[N], f, r;
int state[N], parent[N];

void push(int x) {
    /************************************
    Since the number of undiscovered words is always matches
    the number of empty spaces in the queue, overflow never occurs.
    *************************************/
    queue[r] = x;
    r++;
}

void pop() {
    /************************************
    Since pop() doesn't work when the queue is empty,
    underflow never occurs.
    *************************************/
    f++;
}

void init_queue() {
    f = 0;
    r = 0;
}

void init_state() {
    // UNDISCOVERED = 0, DISCOVERED = 1, PROCESSED = 2
    for (int i = 0; i < N; i++) state[i] = 0;
}

void print_path(int start, int goal) {
    int i, j;
    int path[N];

    i = 0;
    while (start != goal) {
        path[i++] = goal;
        goal = parent[goal];
    }
    path[i] = start;

    j = 0;
    while (i >= 0) {
        printf("          %d ", j++);
        print_word(path[i--]);
        printf("\n");
    }
}

void find_path(char start[5], char goal[5]) {
    int i, j, k, l;

    // initialization
    init_queue();
    init_state();
    i = search_index(start);
    j = search_index(goal);
    l = 0;

    if (i < 0) {
        printf("Sorry. ");
        print_five_chars(start);
        printf(" is not in the dicitonary.");
    } else if (j < 0) {
        printf("Sorry. ");
        print_five_chars(goal);
        printf(" is not in the dicitonary.");
    } else {
        state[i] = 1;
        push(i);
        parent[i] = -1;

        while (f < r) {
            int cur = queue[f];
            struct node *p = adj_list[cur];

            pop();
            while (p != NULL) {
                k = p->index;

                if (state[k] == 0) {
                    state[k] = 1;
                    push(k);
                    parent[k] = cur;
                    if (k == j) {
                        l = 1;
                        break;
                    }
                }
                p = p->next;
            }
            if (l == 1) break;
            state[cur] = 2;
        }
    }
    if (l == 1)
        print_path(i, j);
    else {
        printf("Sorry. There is no path from ");
        print_five_chars(start);
        printf(" to ");
        print_five_chars(goal);
        printf(".\n");
    }
}
