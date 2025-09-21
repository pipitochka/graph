#include "tokenizer.h"
#include "parser.h"
#include "render.h"
#include "line_reader.h"

int main() {
  char *expr = readLine();
   if (expr == NULL) {
     printf("n/a");
     return 0;
   }
  
  struct list* list = tokenize(expr);
  if (list == NULL) {
    printf("n/a");
    return 0;
  }
//  
//  struct list* parsed_list = parse(list);
//  free_list(list);
//  
//  render(parsed_list);
//  
//  free_list_with_tokens(parsed_list);
}
