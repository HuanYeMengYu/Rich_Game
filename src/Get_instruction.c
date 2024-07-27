# include "utils.h"
void Get_instruction(char* keyboard_input){
    char* command = strtok(keyboard_input, " ");
    char* argument = strtok(NULL, " ");
     if (command == NULL) {
        printf("Are you sure you want to type NULL?\n");
        return;
    }
    if (strcmp(command, "Roll") == 0) {
        get_gold;//完成掷骰子和位置更新
        display_map;//刷新地图的函数
    } else if (strcmp(command, "Robot") == 0) {

        printf("Executing Jump command\n");//等待使用清扫机器人的函数
        display_map;//刷新地图的函数
    } else if (strcmp(command, "Query") == 0) {
        printf("Executing Run command\n");//等到显示自家资产的函数
        
    } else if (strcmp(command, "Help") == 0) {
        printf("Executing Jump command\n");//等待查看命令的函数
    } else if (strcmp(command, "Quit") == 0) {
        printf("Executing Run command\n");//等待强制退出的函数
        display_map;//刷新地图的函数
    }else if (strcmp(command, "Sell") == 0) {//以下需要根据后面的数字进行操作
                                             //等待售卖的函数
        printf("Executing Run command\n");
        display_map;//刷新地图的函数
    } else if (strcmp(command, "Block") == 0) {
        printf("Executing Jump command\n");//等待放置路障的函数、刷新地图的函数
        display_map;//刷新地图的函数
    } else if (strcmp(command, "Bomb") == 0) {
        printf("Executing Run command\n");// 等待放置炸弹的函数、刷新地图的函数
        display_map;//刷新地图的函数
    }else if (strcmp(command, "Step") == 0) {
        printf("Executing Run command\n");//等待遥控骰子的函数、刷新地图、刷新人物位置的函数
        display_map;//刷新地图的函数
    }
    
    else printf("Unknown command\n");
}