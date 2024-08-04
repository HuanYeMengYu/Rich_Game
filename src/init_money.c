# include "utils.h"

int init_money(){
    printf("设置玩家初始资金,范围1000-50000(默认10000)或者输入回车跳过:");
    int init_money = 0;
    char input[100];
    while(1){
        fgets(input, sizeof(input), stdin);
        // 判断用户是否输入了回车键
        if (input[0] != '\n') {
            // 将用户输入的字符串转换为整数
            int funds = atoi(input);
            // 检查输入值是否在合法范围内
            if (funds >= 1000 && funds <= 50000) {
                return funds;
            } else {
                printf("输入资金无效，请重新输入：");
            }
        }else{
            return DEFAULT_MONEY;
        }
    }
    return DEFAULT_MONEY;
}
