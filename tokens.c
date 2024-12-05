#include "shell.h"

t_tokens *create_token(int type, char *value) {
    t_tokens *token = (t_tokens *)malloc(sizeof(t_tokens));
    if (!token)
        return NULL;
    token->type = type;
    token->value = strdup(value);
    token->next = NULL;
    return token;
}

void add_token_to_list(t_tokens **tokens, t_tokens *new_token) {
    if (!tokens || !new_token)
        return;
    if (!*tokens)
        *tokens = new_token;
    else {
        t_tokens *current = *tokens;
        while (current->next)
            current = current->next;
        current->next = new_token;
    }
}

t_tokens *finall_tokenize_input(char *input) {
    t_tokens *tokens = NULL;
    int i = 0, start = 0;

    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\t') {
            i++; // Pomijamy białe znaki
            continue;
        }

        // Obsługa specjalnych znaków
        if (input[i] == '|') {
            add_token_to_list(&tokens, create_token(PIPE, strdup("|")));
            i++;
        } else if (input[i] == '>') {
            if (input[i + 1] == '>') {
                add_token_to_list(&tokens, create_token(APPEND, strdup(">>")));
                i += 2;
            } else {
                add_token_to_list(&tokens, create_token(REDIRECT_OUT, strdup(">")));
                i++;
            }
        } else if (input[i] == '<') {
            if (input[i + 1] == '<') {
                add_token_to_list(&tokens, create_token(HEREDOC, strdup("<<")));
                i += 2;
            } else {
                add_token_to_list(&tokens, create_token(REDIRECT_IN, strdup("<")));
                i++;
            }
        } else {
            // Obsługa słów
            start = i;
            while (input[i] && input[i] != ' ' && input[i] != '\t' &&
                   input[i] != '|' && input[i] != '>' && input[i] != '<') {
                i++;
            }
            // Tworzymy token na podstawie wyciętego słowa
            add_token_to_list(&tokens, create_token(WORD, strndup(&input[start], i - start)));
        }
    }
    return tokens;
}
