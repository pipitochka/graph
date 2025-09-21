#include "tokenizer.h"
#include "parser.h"
#include "render.h"
#include "line_reader.h"

int main() {
  char *expr = readLine();
  struct list* list = tokenize(expr);
  struct list* parsed_list = parse(list);
  free_list(list);
  
  render(parsed_list);
  
  free_list(parsed_list);
}
