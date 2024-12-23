#include <stdio.h>
#include <stdlib.h>

// Define the structure
typedef struct s_env {
    char *key;           // Name of the variable
    char *value;         // Value of the variable
    struct s_env *next;  // Pointer to the next node
} t_env;

// Function to print the environment variables
int builtin_env(t_env *node) {
    t_env *current = node;

    if (!current) {
        fprintf(stderr, "some issues with env\n");
        return 1;
    }

    while (current != NULL) {
        printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }

    return 0;
}

int main() {
    // Create and link the nodes
    t_env node1 = {"PATH", "/usr/bin", NULL};
    t_env node2 = {"HOME", "/home/user", NULL};
    t_env node3 = {"SHELL", "/bin/bash", NULL};

    node1.next = &node2;
    node2.next = &node3;

    // Call the function
    builtin_env(&node1);

    return 0;
}
