# include "utils.h"

extern Player QianFuren;
extern Player ATubo;
extern Player SunXiaomei;
extern Player JinBeibei;
extern Map map;

int main(){
    srand(time(0));

   

    char command;
    printf("请输入:\n");
    while((command=getchar())!='f'){
        switch (command)
        {
        case 'm':
           begin_game();
            break;
        case 'n':
            printf("%d\n",get_step_count());
            break;
        case 'h':
            printf("请输入你的金矿position：\n");
            int x;
            scanf("%d", &x);
            printf("之前QianFuren.point=%d\n", QianFuren.point);
            get_gold(&QianFuren, x);
            printf("之后QianFuren.point=%d\n", QianFuren.point);
            break;
        case 'g':
            gift_house(&QianFuren);
        default:
            break;
        }
        getchar();
        printf("请输入:\n");
    }

    return 0;
}
