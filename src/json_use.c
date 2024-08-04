#include"json_use.h"

void json_to_txt(const char* json_filepath, const char* txt_filepath) {
    // 读取JSON文件
    char* json_data = read_file(json_filepath);
    if (json_data == NULL) {
        printf("Unable to read the JSON file.\n");
        return;
    }
    
    // 解析JSON数据
    cJSON* root = cJSON_Parse(json_data);
    if (root == NULL) {
        printf("Error parsing JSON.\n");
        free(json_data);
        return;
    }

    // 打开TXT文件以写入
    FILE* txt_file = fopen(txt_filepath, "w");
    if (txt_file == NULL) {
        printf("Unable to open TXT file for writing.\n");
        cJSON_Delete(root);
        free(json_data);
        return;
    }

    // 写入MAP信息
    cJSON* cjson_map = cJSON_GetObjectItem(root, "MAP");
    cJSON* cjson_tool = cJSON_GetObjectItem(cjson_map, "tool");
    int cjson_tool_size = cJSON_GetArraySize(cjson_tool);
    
    fprintf(txt_file, "MAP:\n");
    fprintf(txt_file, "Tool positions and kinds:\n");
    for (int i = 0; i < cjson_tool_size; i++) {
        cJSON* item = cJSON_GetArrayItem(cjson_tool, i);
        if (cJSON_GetArraySize(item) == 2) {
            int cell = cJSON_GetArrayItem(item, 0)->valueint;
            int kind = cJSON_GetArrayItem(item, 1)->valueint;
            fprintf(txt_file, "Cell: %d, Tool Kind: %d\n", cell, kind);
        }
    }

    // 写入users和now_user信息
    fprintf(txt_file, "\nUsers: %s\n", cJSON_GetObjectItem(root, "users")->valuestring);
    fprintf(txt_file, "Current User: %s\n", cJSON_GetObjectItem(root, "now_user")->valuestring);

    // 写入players信息
    cJSON* players = cJSON_GetObjectItem(root, "players");
    int player_count = cJSON_GetArraySize(players);
    
    fprintf(txt_file, "\nPlayers:\n");
    for (int i = 0; i < player_count; i++) {
        cJSON* player = cJSON_GetArrayItem(players, i);
        fprintf(txt_file, "Player %d:\n", i + 1);
        fprintf(txt_file, "  Alive: %d\n", cJSON_GetObjectItem(player, "alive")->valueint);
        fprintf(txt_file, "  Money: %d\n", cJSON_GetObjectItem(player, "money")->valueint);
        fprintf(txt_file, "  Point: %d\n", cJSON_GetObjectItem(player, "point")->valueint);
        fprintf(txt_file, "  Number: %d\n", cJSON_GetObjectItem(player, "number")->valueint);
        fprintf(txt_file, "  Tool1 (Block): %d\n", cJSON_GetObjectItem(player, "tool1")->valueint);
        fprintf(txt_file, "  Tool2 (Bomb): %d\n", cJSON_GetObjectItem(player, "tool2")->valueint);
        fprintf(txt_file, "  Tool3 (Robot): %d\n", cJSON_GetObjectItem(player, "tool3")->valueint);
        fprintf(txt_file, "  Buff: %d\n", cJSON_GetObjectItem(player, "buff")->valueint);
        fprintf(txt_file, "  Continue: %d\n", cJSON_GetObjectItem(player, "continue")->valueint);
        fprintf(txt_file, "  Debuff0 (Prison): %d\n", cJSON_GetObjectItem(player, "debuff0")->valueint);
        fprintf(txt_file, "  Debuff1 (Hospital): %d\n", cJSON_GetObjectItem(player, "debuff1")->valueint);
        fprintf(txt_file, "  Decontinue: %d\n", cJSON_GetObjectItem(player, "decontinue")->valueint);
        fprintf(txt_file, "  Position: %d\n", cJSON_GetObjectItem(player, "position")->valueint);

        cJSON* properties = cJSON_GetObjectItem(player, "properties");
        int prop_count = cJSON_GetArraySize(properties);
        fprintf(txt_file, "  Properties:\n");
        for (int j = 0; j < prop_count; j++) {
            cJSON* property = cJSON_GetArrayItem(properties, j);
            if (cJSON_GetArraySize(property) == 2) {
                int prop_id = cJSON_GetArrayItem(property, 0)->valueint;
                int prop_value = cJSON_GetArrayItem(property, 1)->valueint;
                fprintf(txt_file, "    Property ID: %d, Value: %d\n", prop_id, prop_value);
            }
        }
        fprintf(txt_file, "\n");
    }

    // 清理资源
    fclose(txt_file);
    cJSON_Delete(root);
    free(json_data);

    printf("JSON file has been successfully converted to TXT.\n");
}

void read_json(char *filepath){
    char *json_data = read_file(filepath);
    if (json_data == NULL) {
        printf("Unable to read the JSON file.\n");
        return ;
    }
    
    cJSON *root = cJSON_Parse(json_data);
    if (root == NULL) {
        printf("Error parsing JSON.\n");
        free(json_data);
        return ;
    }
    cJSON* cjson_map = cJSON_GetObjectItem(root, "MAP");
    cJSON* cjson_tool = cJSON_GetObjectItem(cjson_map, "tool");
    int cjson_tool_size = cJSON_GetArraySize(cjson_tool);
    int* tool_cell = (int*)malloc(cjson_tool_size * sizeof(int));
    int* tool_kind = (int*)malloc(cjson_tool_size * sizeof(int));
    for(int i = 0; i < cjson_tool_size; i++)
    {
         cJSON *item = cJSON_GetArrayItem(cjson_tool, i);
        if (cJSON_GetArraySize(item) == 2) {
            tool_cell[i] = cJSON_GetArrayItem(item, 0)->valueint;
            tool_kind[i] = cJSON_GetArrayItem(item, 1)->valueint;  
        }
    }
    init_map(&map);

    // map = (Map*)malloc(sizeof(Map));
    for(int i=0;i<cjson_tool_size;i++){
        map.cells[tool_cell[i]].has_tool = tool_kind[i];
    }
    
    //MAP读取完毕/////////////////////////////////////////////////////////////
    strcpy(users, cJSON_GetObjectItem(root, "users")->valuestring);
    strcpy(now_user, cJSON_GetObjectItem(root, "now_user")->valuestring);
    
    cJSON *players = cJSON_GetObjectItem(root, "players");
    if (players == NULL) {
        printf("No players array found.\n");
        cJSON_Delete(root);
        free(json_data);
        return ;
    }
    
    int player_count = cJSON_GetArraySize(players);
    int* alive = (int*)malloc(player_count * sizeof(int));
    int* money = (int*)malloc(player_count * sizeof(int));
    int* point = (int*)malloc(player_count * sizeof(int));
    int* number = (int*)malloc(player_count * sizeof(int));
    int* tool1 = (int*)malloc(player_count * sizeof(int));
    int* tool2 = (int*)malloc(player_count * sizeof(int));
    int* tool3 = (int*)malloc(player_count * sizeof(int));
    int* buff = (int*)malloc(player_count * sizeof(int));
    int* continue_ = (int*)malloc(player_count * sizeof(int));
    int* debuff0 = (int*)malloc(player_count * sizeof(int));
    int* debuff1 = (int*)malloc(player_count * sizeof(bool));
    int* decontinue = (int*)malloc(player_count * sizeof(int));
    int* position = (int*)malloc(player_count * sizeof(int));
    int** properties_array = (int**)malloc(player_count * sizeof(int*));

    use_players = (Player*)malloc(player_count * sizeof(Player));

    for (int i = 0; i < player_count; i++) {
        properties_array[i] = (int*)malloc(2 * sizeof(int));
    }
    for (int i = 0; i < player_count; i++) {
        memset(use_players[i].properties, DONT_HAVE, sizeof(int)*CELL_NUMS);
        cJSON *player = cJSON_GetArrayItem(players, i);
        if (player == NULL) continue;
        cJSON *properties = cJSON_GetObjectItem(player, "properties");

        use_players[i].alive = cJSON_GetObjectItem(player, "alive")->valueint;
        use_players[i].money = cJSON_GetObjectItem(player, "money")->valueint;
        use_players[i].point = cJSON_GetObjectItem(player, "point")->valueint;
        use_players[i].number = cJSON_GetObjectItem(player, "number")->valueint;
        use_players[i].block = cJSON_GetObjectItem(player, "tool1")->valueint;
        use_players[i].bomb = cJSON_GetObjectItem(player, "tool2")->valueint;
        use_players[i].robot = cJSON_GetObjectItem(player, "tool3")->valueint;
        use_players[i].buff = cJSON_GetObjectItem(player, "buff")->valueint;
        use_players[i]._continue = cJSON_GetObjectItem(player, "continue")->valueint;
        use_players[i].prison = cJSON_GetObjectItem(player, "debuff0")->valueint;
        use_players[i].hospital = cJSON_GetObjectItem(player, "debuff1")->valueint;
        use_players[i].de_continue = cJSON_GetObjectItem(player, "decontinue")->valueint;
        use_players[i].position = cJSON_GetObjectItem(player, "position")->valueint;

        int prop_count = cJSON_GetArraySize(properties);
        // use_players[i].property_count = prop_count;
        for (int j = 0; j < prop_count; j++) {
            cJSON *property = cJSON_GetArrayItem(properties, j);
            // use_players[i].properties[j] = (int*)malloc(2 * sizeof(int));
            // printf("j:%d",j);
            if (cJSON_GetArraySize(property) == 2) {
                int a = cJSON_GetArrayItem(property, 0)->valueint;
                int b = cJSON_GetArrayItem(property, 1)->valueint;
                use_players[i].properties[a] = b;
                map.cells[a].owner = use_players[i].number;
                map.cells[a].kind = b;
                // printf("AB:%d %d",a,b);
            }
        }
        for(int j=0;j<70;j++)
        {
            // printf("%d %d\n",j, use_players[i].properties[j]);
        }
    }

    //players读取完毕/////////////////////////////////////////////////////////////////

   
    cJSON_Delete(root);
}



char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(length + 1);
    if (data) {
        fread(data, 1, length, file);
        data[length] = '\0';
    }
    fclose(file);

    return data;
}
//这里实际上都是静态的存储方
void write_json(const char *folder_result, Player* use_players, Map* use_map,char* users,char* now_user) {

    cJSON* root = cJSON_CreateObject();
    cJSON* map = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "MAP", map);

    cJSON* tool = cJSON_CreateArray();
  
    for (int i = 0; i < CELL_NUMS; i++) {
        if (use_map->cells[i].has_tool != 0) {
            cJSON* temp = cJSON_CreateArray();
            cJSON_AddItemToArray(temp, cJSON_CreateNumber(i));
            cJSON_AddItemToArray(temp, cJSON_CreateNumber(use_map->cells[i].has_tool));
            cJSON_AddItemToArray(tool, temp);
        }
    }
      //案例，最后使用for循环进行修改
   
    cJSON_AddItemToObject(map, "tool", tool);
    cJSON_AddStringToObject(root, "users", users);
    cJSON_AddStringToObject(root, "now_user", now_user);
    cJSON* players = cJSON_CreateArray();
    cJSON *temp_player = NULL;
    if (players == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(root, "players", players);
    for (int index = 0; index < strlen(users); ++index)
    {
        temp_player = cJSON_CreateObject();
        if (temp_player == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(players, temp_player);

        
        
        cJSON_AddItemToObject(temp_player, "alive", cJSON_CreateNumber(use_players[index].alive));
        cJSON_AddItemToObject(temp_player, "money", cJSON_CreateNumber(use_players[index].money));
        cJSON_AddItemToObject(temp_player, "point", cJSON_CreateNumber(use_players[index].point));
        cJSON_AddItemToObject(temp_player, "number", cJSON_CreateNumber(use_players[index].number));
        cJSON_AddItemToObject(temp_player, "tool1", cJSON_CreateNumber(use_players[index].block));
        cJSON_AddItemToObject(temp_player, "tool2", cJSON_CreateNumber(use_players[index].bomb));
        cJSON_AddItemToObject(temp_player, "tool3", cJSON_CreateNumber(use_players[index].robot));
        cJSON_AddItemToObject(temp_player, "buff", cJSON_CreateNumber(use_players[index].buff));
        cJSON_AddItemToObject(temp_player, "continue", cJSON_CreateNumber(use_players[index]._continue));
        cJSON_AddItemToObject(temp_player, "debuff0", cJSON_CreateNumber(use_players[index].prison));
        cJSON_AddItemToObject(temp_player, "debuff1", cJSON_CreateNumber(use_players[index].hospital));
        cJSON_AddItemToObject(temp_player, "decontinue", cJSON_CreateNumber(use_players[index].de_continue));
        cJSON_AddItemToObject(temp_player, "position", cJSON_CreateNumber(use_players[index].position));
        cJSON* properties = cJSON_CreateArray();
        if (properties == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(temp_player, "properties", properties);
        // cJSON_AddItemToObject(temp_player, "property_count", cJSON_CreateNumber(use_players[index].property_count));
        //案例，最后使用for循环进行修改
        for(int i=0;i<70;i++){
            if(use_players[index].properties[i]!=-1&&use_players[index].properties[i]!=-1){
                cJSON* temp = cJSON_CreateArray();
                cJSON_AddItemToArray(temp, cJSON_CreateNumber(i));
                cJSON_AddItemToArray(temp, cJSON_CreateNumber(use_players[index].properties[i]));
                cJSON_AddItemToArray(properties, temp);
            }
        }
        
        
    }
    char *string = NULL;
    string = cJSON_Print(root);
    if (string == NULL)
    {
        fprintf(stderr, "Failed to print monitor.\n");
    }

   end:
    cJSON_Delete(root);
    //return string;
    write_file(folder_result, string);
}

int write_file(const char *folder_result, const char *data) {
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s\\output.json", folder_result);
    printf("%s\n", file_path);
    FILE *file = fopen(file_path, "w");
    if (!file) 
    {
        printf("Unable to open file.\n");
        return 0; // 返回0表示打开文件失败
    }

    size_t length = strlen(data);
    size_t written = fwrite(data, 1, length, file);
    fclose(file);

    // 如果实际写入的字节数与数据长度相等，则返回1，否则返回0表示写入失败
    return written == length;
}
