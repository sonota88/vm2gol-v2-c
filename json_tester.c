#include <stdio.h>
#include "lib/utils.h"
#include "lib/types.h"
#include "lib/json.h"

#define INPUT_SIZE (1024 * 20)

int main(void) {
  char input[INPUT_SIZE];

  read_stdin_all(input, INPUT_SIZE);

  NodeList* list = Json_parse(input);

  print_as_json(list, 1);

  return 0;
}
