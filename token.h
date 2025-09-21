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

token* initToken(TokenType type, char* lexeme);

void freeToken(token* token);

#endif //TOKEN_H
