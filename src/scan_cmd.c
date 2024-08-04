# include "utils.h"

int scan_cmd(char* cmd_buf) {
    // TODO: write code to get commands here
    //scanf("%s", cmd_buf);

    if (fgets(cmd_buf, 20, stdin) != NULL) {  
        // 去除可能的换行符（如果存在的话）  
        cmd_buf[strcspn(cmd_buf, "\n")] = 0;

    }

    return 0;
}
