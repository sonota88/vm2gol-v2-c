#pragma once

NodeList* parse_json(char* input);
void print_as_json(NodeList* list);
void to_json_line(char* dest, NodeItem* item);
