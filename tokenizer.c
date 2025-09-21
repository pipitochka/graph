#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_digit(char c) {
  return (c >= '0' && c <= '9');
}

int is_alpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_operator(char c) {
  return strchr("+-*/", c) != NULL;
}

int is_scope_open(char c) {
  return (c == '(' ) ;
}

int is_scope_close(char c) {
  return (c == ')');
}


void skip_spaces(const char* input, int* index) {
  while (input[*index] == ' ') {
    (*index)++;
  }
}

enum tokenizer_state {variable, function, scope_open, scope_close, identifier, operator};

token* get_number_token(const char* input, int* index, enum tokenizer_state* state);

token* get_variable_token(const char* input, int* index, enum tokenizer_state* state);

token* get_scope_token(const char* input, int* index, enum tokenizer_state* state);

token* get_operator_token(const char* input, int* index, enum tokenizer_state* state);

list* tokenize(const char* input){
  list* tokens = init_list();
  token* token;
  int i = 0;
  enum tokenizer_state state = operator;
  int flag = 1;
  
  while (flag && input[i] != '\0'){
    token = NULL;
    if (input[i] == ' '){
      skip_spaces(input, &i);
    } if (is_digit(input[i]) && (state == operator || state == function || state == scope_open)){
      token = get_number_token(input, &i, &state);
    } else if (is_alpha(input[i]) && (state == operator || state == function || state == scope_open)){
      token = get_variable_token(input, &i, &state);
    } else if (is_operator(input[i]) && (state == scope_open || state == scope_close || state == variable || state == identifier)){
      token = get_operator_token(input, &i, &state);
    } else if (is_scope_open(input[i]) && (state == operator)){
      token = get_scope_token(input, &i, &state);
    } else if (is_scope_close(input[i]) && (state == variable || state == identifier)){}
    if (token != NULL){
      push_back(tokens, token);
    } else {
      flag = 0;
    }
  }
}
