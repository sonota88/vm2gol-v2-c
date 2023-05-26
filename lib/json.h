#pragma once

NodeList* Json_parse(char* input);
void Json_print(NodeList* list, int pretty);
void to_json_line(char* dest, NodeItem* item);
