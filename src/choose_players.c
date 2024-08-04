# include "utils.h"

void choose_players(){
    printf("请选择2~4位不重复玩家,输入编号即可(1.钱夫人;2.阿土伯;3.孙小美;4.金贝贝),可自由排序:");
    char scan_players[TOTAL_PLAYER_NUM+1] = {'\0'};
    if(strlen(users)!=0)
    {
        strcpy(scan_players,users);
    }
    else {
        while(1){
            scanf("%s", scan_players);
            int flag0=0,flag1=0;
            for(int i=0;i<strlen(scan_players);i++){
                
                if(scan_players[i]>='5'){
              
                    flag0=1;
                }
            }
            for(int i=0;i<strlen(scan_players)-1;i++){
                for(int j=i+1;j<strlen(scan_players);j++){
                    if(scan_players[i] == scan_players[j]){
                        flag1=1;
                    }
                }
            }
                if(strlen(scan_players)>4){
                    printf("输入长度不符合规范，请重新输入：");
                }else if(flag0==1){
                    printf("输入编号大小不符合规范，请重新输入：");
                }else if(flag1==1){
                    printf("输入重复角色编号，请重新输入：");
                }else
                    break;
        }
    }
    left_player_nums = 0;

    for(int i=0;i<=TOTAL_PLAYER_NUM-1;i++){
        if(scan_players[i] == '\0')
            break;
        left_player_nums++;
        int number = (int)(scan_players[i] - '0');
        player_number_arr[i] = number;
        if(strlen(users)==0)
        {
            switch (player_number_arr[i])
            {
            case QIANFUREN_NUMBER:
                QianFuren.alive = 1;
                QianFuren.position = 0;
                break;
            case ATUBO_NUMBER:
                ATubo.alive = 1;
                ATubo.position = 0;
                break;
            case SUNXIAOMEI_NUMBER:
                SunXiaomei.alive = 1;
                SunXiaomei.position = 0;
                break;
            case JINBEIBEI_NUMBER:
                JinBeibei.alive = 1;
                JinBeibei.position = 0;
                break;
            default:
                break;
            }
        }
    }
    sort_player_number_arr();
}
