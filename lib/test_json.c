#include <stdio.h>
#include "utils.h"
#include "types.h"
#include "json.h"

#define INPUT_SIZE (1024 * 20)

int main(void) {
  char input[INPUT_SIZE];

  read_stdin_all(input);

  NodeList* list = parse_json(input);

  print_as_json(list);

  return 0;
}
