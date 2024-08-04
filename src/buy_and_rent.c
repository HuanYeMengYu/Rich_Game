#include "utils.h"

void BuyAndRent(Player *player){
    int base_price = 0;
    int total_price = 0;
    int rent_price = 0;

    switch (map.cells[player->position].kind){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        return;
    }

    switch (map.cells[player->position].rank){
    case 1:
        base_price = RANK1_PRICE;
        break;
    case 2:
        base_price = RANK2_PRICE;
        break;
    case 3:
        base_price = RANK3_PRICE;
        break;
    default:
        break;
    }
    
    // 总价格
    total_price = one_house_total_price(player->position);
    // 租金价格
    rent_price = total_price / 2;

    if(map.cells[player->position].owner==player->number){
        Upgradation(player, base_price);
    }else if(map.cells[player->position].owner==0){
        BuyPlace(player, base_price);
    }else{
        // 如果有财神buff，不用交房租
        if(player->buff == 1){
            printf("财神附身，可免过路费\n");
            printf("您的财神还有%d轮\n", player->_continue);
            return;
        }
        bool skip_rent = false;
        switch (map.cells[player->position].owner)
        {
        case QIANFUREN_NUMBER:
            // 如果房主在监狱，不用交房租
            if(QianFuren.prison == 1){
                printf("房主在监狱，可免过路费\n");
                skip_rent = true;
            }
            // 如果房主在医院，不用交房租
            if(QianFuren.hospital == 1){
                printf("房主在医院，可免过路费\n");
                skip_rent = true;
            }
            if(skip_rent){
                return;
            }
            break;
        case ATUBO_NUMBER:
            // 如果房主在监狱，不用交房租
            if(ATubo.prison == 1){
                printf("房主在监狱，可免过路费\n");
                skip_rent = true;
            }
            // 如果房主在医院，不用交房租
            if(ATubo.hospital == 1){
                printf("房主在医院，可免过路费\n");
                skip_rent = true;
            }
            if(skip_rent){
                return;
            }
            break;
        case SUNXIAOMEI_NUMBER:
            // 如果房主在监狱，不用交房租
            if(SunXiaomei.prison == 1){
                printf("房主在监狱，可免过路费\n");
                skip_rent = true;
            }
            // 如果房主在医院，不用交房租
            if(SunXiaomei.hospital == 1){
                printf("房主在医院，可免过路费\n");
                skip_rent = true;
            }
            if(skip_rent){
                return;
            }
            break;
        case JINBEIBEI_NUMBER:
            // 如果房主在监狱，不用交房租
            if(JinBeibei.prison == 1){
                printf("房主在监狱，可免过路费\n");
                skip_rent = true;
            }
            // 如果房主在医院，不用交房租
            if(JinBeibei.hospital == 1){
                printf("房主在医院，可免过路费\n");
                skip_rent = true;
            }
            if(skip_rent){
                return;
            }
            break;
        default:
            break;
        }

        printf("您现在需要缴纳租金%d元\n", rent_price);
        printf("您之前的金钱为%d\n", player->money);

        player->money -= rent_price;

        if(player->money>=0){
            switch (map.cells[player->position].owner)
            {
            case QIANFUREN_NUMBER:
                QianFuren.money += rent_price;
                break;
            case ATUBO_NUMBER:
                ATubo.money += rent_price;
                break;
            case SUNXIAOMEI_NUMBER:
                SunXiaomei.money += rent_price;
                break;
            case JINBEIBEI_NUMBER:
                JinBeibei.money += rent_price;
                break;
            default:
                break;
            }
        }

        if(player->money < 0){
            printf("%s已经破产\n", get_player_name(player->number));
            player->money = 0;
            Bankruptcy(player);
        }else{
            printf("您现在的金钱为%d\n", player->money);
        }
    }
}

void Upgradation(Player *player,int price){
    char l;

    if(map.cells[player->position].kind==3){
        printf("您已经升级到最高级\n");
        return;
    }else if(player->money < price){
        printf("您的金钱不足以升级，自动跳过\n");
        return;
    }

    printf("当前钱为%d,升级需要%d元\n", player->money, price);
    printf("是否升级(y/n)\n");
    while(1){

        char buf[40] = {'\0'};
        fgets(buf, 40, stdin);
        if(buf[2] != '\0'){
            printf("输入长度不符合规范，请重新输入\n");
            continue;
        }

        if(buf[0] == 'y'){
            char tmp[7]={'\0'};
            char tmp1[7]={'\0'};
            switch (player->number){
            case QIANFUREN_NUMBER:
                strncpy(tmp, "\033[31m", 7);
                strncpy(tmp1, "\033[31m", 7);
                break;
            case ATUBO_NUMBER:
                strncpy(tmp, "\033[32m", 7);
                strncpy(tmp1, "\033[32m", 7);
                break;
            case SUNXIAOMEI_NUMBER:
                strncpy(tmp, "\033[34m", 7);
                strncpy(tmp1, "\033[34m", 7);
                break;
            case JINBEIBEI_NUMBER:
                strncpy(tmp, "\033[33m", 7);
                strncpy(tmp1, "\033[33m", 7);
                break;
            default:
                break;
            }
            tmp1[5] = get_player_show_char(player->number);
            tmp[5] = (char)('0' + map.cells[player->position].kind + 1);
            strncpy(map.cells[player->position].show_char, tmp1, 7);
            strncpy(map.cells[player->position].origion_char, tmp, 7);
            map.cells[player->position].kind++;          //修改房屋等级
            //修改Player的参数
            player->money -= price;        //修改剩余金额
            player->properties[player->position]++;   //修改资产记录
            return;
        }
        else if(buf[0] == 'n'){
            printf("您选择不升级\n");
            return;
        }else {
            printf("输入错误选项，请重新输入\n");
        }
    }

}

// 买空地函数
void BuyPlace(Player *player,int price){
    char l;

    if(player->money < price){
        printf("您的金钱不足\n");
        return;
    }
    printf("当前钱为%d,购买需要%d元\n", player->money, price);
    printf("是否购买(y/n):");
    while(1){

        char buf[40] = {'\0'};
        fgets(buf, 40, stdin);
        if(buf[2] != '\0'){
            printf("输入长度不符合规范，请重新输入\n");
            continue;
        }

        if(buf[0]=='y'){
            char tmp[7]={'\0'};
            char tmp1[7]={'\0'};
            switch (player->number)
            {
            case QIANFUREN_NUMBER:
                strncpy(tmp, "\033[31m0", 7);
                strncpy(tmp1, "\033[31mQ", 7);
                break;
            case ATUBO_NUMBER:
                strncpy(tmp, "\033[32m0", 7);
                strncpy(tmp1, "\033[32mA", 7);
                break;
            case SUNXIAOMEI_NUMBER:
                strncpy(tmp, "\033[34m0", 7);
                strncpy(tmp1, "\033[34mS", 7);
                break;
            case JINBEIBEI_NUMBER:
                strncpy(tmp, "\033[33m0", 7);
                strncpy(tmp1, "\033[33mJ", 7);
                break;   
            //其他case
            default:
                break;
            }

            //修改所有人
            map.cells[player->position].owner = player->number;

            strncpy(map.cells[player->position].show_char, tmp1, 7);
            strncpy(map.cells[player->position].origion_char, tmp, 7);

            //修改Player的参数

            //修改价格
            player->money -= price;        
            //修改资产记录
            player->properties[player->position] = BLANK_SPACE;
            //资产数 + 1
            player->property_count++;
            return;
        }
        else if(buf[0] == 'n'){
            printf("您选择不购买\n");
            return;
        }else{
            printf("输入错误选项，请重新输入\n");
        }
    }

}

// 破产函数
void Bankruptcy(Player *player){
    // 清空房产
    for(int i=START_POSITION;i<CELL_NUMS;i++){
        if(player->properties[i] != -1){
            // 修改房屋等级 kind
            map.cells[QianFuren.position].kind = BLANK_SPACE; 
            // 修改房屋所有人
            map.cells[i].owner = NO_ONE;
            // 清空玩家产权
            player->properties[i] = -1;
            // 恢复显示白色空地 '0'
            strncpy(map.cells[i].show_char, "\033[37m0", 7);
            player->property_count--;
        }
    }
    // 角色死亡，退出游戏
    player->alive = DEATH;
    // 角色死亡，符号应该在地图上消失
    strncpy(map.cells[player->position].show_char, map.cells[player->position].origion_char, 7);
    player_exit_game(player->number);
}
