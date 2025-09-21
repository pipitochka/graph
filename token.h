#ifndef TOKEN_H
#define TOKEN_H

typedef enum TokenType {
  TOKEN_NUMBER,
  TOKEN_VARIABLE,
  TOKEN_OPERATOR,
  TOKEN_FUNCTION,
  TOKEN_SCOPE,
} TokenType;

typedef struct token {
  TokenType type;
  char* lexeme;
} token;

token* init_token(TokenType type, char* lexeme);

void free_token(token* token);

#endif //TOKEN_H
