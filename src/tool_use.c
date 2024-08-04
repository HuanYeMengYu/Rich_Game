# include "utils.h"

// 触发道具
int tool_trigger(Player *player,int motion){
    // 判断步数内是否有道具（路障/机器人）
    for(int i=1;i<=motion;i++){
        // 该cell没有道具，继续判断

        if(map.cells[(player->position+i) % CELL_NUMS].has_tool==0){
            continue;
        }
        // 该cell有路障
        else if(map.cells[(player->position+i) % CELL_NUMS].has_tool==1){
            printf("位置%d有路障，您被挡住\n", (player->position+i) % CELL_NUMS);
            strcpy(map.cells[player->position].show_char,map.cells[player->position].origion_char);
            player->position=(player->position+i) % CELL_NUMS;
            map.cells[player->position].has_tool=0;
            switch (player->number)
            {
            case QIANFUREN_NUMBER:
                strncpy(map.cells[player->position].show_char, "\033[31mQ", 7);
                break;
            case ATUBO_NUMBER:
                strncpy(map.cells[player->position].show_char, "\032[32mA", 7);
                break;
            case SUNXIAOMEI_NUMBER:
                strncpy(map.cells[player->position].show_char, "\033[34mS", 7);
                break;
            case JINBEIBEI_NUMBER:
                strncpy(map.cells[player->position].show_char, "\033[33mJ", 7);
                break;
            default:
                break;
            }
            
            return 1;
        }
        // 该cell有炸弹
        else if(map.cells[(player->position+i) % CELL_NUMS].has_tool==2){
            printf("获得财神爷赐福\n");
            // 财神爷所在cell字符从'F'变回原来的
            strncpy(map.cells[(player->position+i) % CELL_NUMS].show_char, map.cells[(player->position+i) % CELL_NUMS].origion_char, 7);
            
            map.cells[(player->position+i) % CELL_NUMS].has_tool = 0;
            
            player->_continue = 5;
            player->buff = 1;

            cur_god_round = 5;
            // 玩家移动
            move(player, motion);
            return 1;
            // printf("%d有炸弹，您被炸伤，进入医院住院，3回合内轮空\n", (player->position+i) % CELL_NUMS);
            // strcpy(map.cells[player->position].show_char,map.cells[player->position].origion_char);
            // player->hospital=1;
            // player->de_continue=3;
            
            // map.cells[(player->position+i) % CELL_NUMS].has_tool=0;
            // strcpy(map.cells[(player->position+i) % CELL_NUMS].show_char,map.cells[(player->position+i) % CELL_NUMS].origion_char);
            // player->position=HOSPITAL_POSITION;
            // // 角色符号直接显示在医院
            // strncpy(map.cells[HOSPITAL_POSITION].origion_char, map.cells[HOSPITAL_POSITION].show_char, 7);
            // switch (player->number)
            // {
            // case QIANFUREN_NUMBER:
            //     strncpy(map.cells[HOSPITAL_POSITION].show_char, "\033[37mQ", 7);
            //     break;
            // case ATUBO_NUMBER:
            //     strncpy(map.cells[HOSPITAL_POSITION].show_char, "\033[32mA", 7);
            //     break;
            // case SUNXIAOMEI_NUMBER:
            //     strncpy(map.cells[HOSPITAL_POSITION].show_char, "\033[34mS", 7);
            //     break;
            // case JINBEIBEI_NUMBER:
            //     strncpy(map.cells[HOSPITAL_POSITION].show_char, "\033[33mJ", 7);
            //     break;
            // default:
            //     break;
            // }
            // return 2;
        }
    }
    return 0;
}

// 使用机器人
void Robot(Player *player){
    if(player->robot==0){
        printf("你没有机器娃娃\n");
        return;
    }
    player->robot--;
    for(int i=1;i<=10;i++){
        if(map.cells[(player->position+i) % CELL_NUMS].has_tool!=0){
       
         map.cells[(player->position+i) % CELL_NUMS].has_tool=0;
        strcpy(map.cells[(player->position+i) % CELL_NUMS].show_char,map.cells[(player->position+i) % CELL_NUMS].origion_char);
        }

    }    
}

// 使用路障
void Block(Player *player,int n){
    bool flag=true;
    char tmp[7]={'\0'};
    strncpy(tmp,"\033[37m#",6);
    if(player->block==0){
        printf("你没有路障！\n");
        return;
    }
    if(n<-10||n>10){
        printf("你不能把路障放这么远！\n");
        return;
    }

    int temp=player->position;
    if(temp+n<0){
        int lll=-0-n-temp;
        temp = 70-lll;
    }else{
        temp = (player->position+n) % CELL_NUMS;
    }

    if(QianFuren.position==(temp)){
        flag=false;
    }else if(ATubo.position==(temp)){
        flag=false;
    }else if(SunXiaomei.position==temp){
        flag=false;
    }else if(JinBeibei.position==temp){
        flag=false;
    }
    if (!flag)
    {
        /* code */
        printf("目标位置有玩家存在，不能放路障！\n");
        return;
    }

    bool flag1=true;


     if(PRISON_POSITION==temp){
        flag1=false;
    }else if(HOSPITAL_POSITION==temp){
        flag1=false;
    }else if(TOOL_HOUSE_POSITION==temp){
        flag1=false;
    }else if(GIFT_HOUSE_POSITION==temp){
        flag1=false;
    }else if(MAGIC_HOUSE_POSITION==temp){
        flag1=false;
    }
    if (!flag1)
    {
        /* code */
        printf("特殊建筑不可以放路障！\n");
        return;
    }
    if(map.cells[temp].has_tool==0){
        map.cells[temp].has_tool=1;
        player->block--;
        strcpy(map.cells[temp].origion_char,map.cells[temp].show_char);
        strcpy(map.cells[temp].show_char,tmp);
        printf("%s\n", map.cells[temp].show_char);
        return;
    }else{
        printf("目标位置已经存在道具！\n");
        return;
    }
}

// 使用炸弹
void Bomb(Player *player,int n){
    bool flag0=true;
    char tmp[7]={'\0'};
    strncpy(tmp,"\033[37m@",6);
    if(player->bomb==0){
        printf("你没有炸弹！\n");
        return;
    }
        if(n<-10||n>10){
        printf("你不能把炸弹放这么远！\n");
        return;
    }

    int temp=player->position;
    if(temp+n<0){
        int lll=-0-n-temp;
        temp = 70-lll;
    }else{
        temp = (player->position+n) % CELL_NUMS;
    }

    if(QianFuren.position==temp){
        flag0=false;
    }else if(ATubo.position==temp){
        flag0=false;
    }else if(SunXiaomei.position==temp){
        flag0=false;
    }else if(JinBeibei.position==temp){
        flag0=false;
    }
    if (!flag0)
    {
        /* code */
        printf("目标位置有玩家存在，不能放炸弹！\n");
        return;
    }
    bool flag1=true;
     if(PRISON_POSITION==temp){
        flag1=false;
    }else if(HOSPITAL_POSITION==temp){
        flag1=false;
    }else if(TOOL_HOUSE_POSITION==temp){
        flag1=false;
    }else if(GIFT_HOUSE_POSITION==temp){
        flag1=false;
    }else if(MAGIC_HOUSE_POSITION==temp){
        flag1=false;
    }
    if (!flag1)
    {
        /* code */
        printf("特殊建筑不可以放炸弹！\n");
        return;
    }



    if(map.cells[temp].has_tool==0){

        map.cells[temp].has_tool=2;
        player->bomb--;
        strcpy(map.cells[temp].origion_char,map.cells[temp].show_char);
        strcpy(map.cells[temp].show_char,tmp);
        return;
    }else{
         printf("目标位置已经存在道具！\n");
        return;
    }
}
