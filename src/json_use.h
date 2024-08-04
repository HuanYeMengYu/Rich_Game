#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "utils.h"
#include <windows.h>


void json_to_txt(const char* json_filepath, const char* txt_filepath);
void read_json(char *filepath);
char *read_file(const char *filename);
void write_json(const char *folder_result, Player* use_players, Map* use_map,char* users,char* now_user);
int write_file(const char *folder_result, const char *data);
