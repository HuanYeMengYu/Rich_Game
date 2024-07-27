#include "utils.h"

/*
 * 函数简介：买地和收租金函数
 * 参数：map 地图结构体
 * 参数：player 包含4个玩家结构体的数组
 * 参数：ResentPlayer 确定当前进行操作的玩家编号
 * 返回值：无
 */
void BuyAndRent(Map* map ,Player* player ,unsigned char ResentPlayer){
    //变量初始化
    int price = 0;
    int rent = 0;

    //判断是否是特殊地段（医院、监狱）
    switch(map->cells[player[ResentPlayer].position].kind){
        //0,1,2,3都不是特殊地段，继续运行
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        //特殊地产，直接退出函数
        default:
            return;
    }

    //判断该位置是什么地段
    switch(map->cells[player[ResentPlayer].position].rank){     //判断地段
        case 1:     //地段1
            price = RANK1_PRICE;
            break;
        case 2:     //地段2
            price = RANK2_PRICE;
            break;
        case 3:     //地段3
            price = RANK3_PRICE;
            break;
        default:    //特殊位置
            break;
    }
    //租金
    rent = price/2;

    //判断是 自己的房子 还是 空地 还是 别人的房子
    if(map->cells[player[ResentPlayer].position].owner == ResentPlayer){          //自己的房子，升级
        //调用升级函数
        Upgradation(map ,player ,ResentPlayer ,price);
    }
    else if(map->cells[player[ResentPlayer].position].owner == 0){                //空地，买地
        //调用购买空地函数
        BuyPlace(map ,player ,ResentPlayer ,price);
    }
    else{                                                                        //别人的房子，收租
        printf("您需要缴纳租金%d元\r\n",rent);
        printf("您现在有%d元\r\n",player[ResentPlayer].money);
        player[ResentPlayer].money -= rent;
        player[map->cells[player[ResentPlayer].position].owner].money += rent;
        if(player[ResentPlayer].money < 0){
            //调用破产函数
            Bankruptcy(map ,player ,ResentPlayer);
        }
        else{
            printf("您现在剩余%d元\r\n",player[ResentPlayer].money);
        }
        
    }    
}

/*
 * 函数简介：升级函数
 * 参数：map 地图结构体
 * 参数：player 包含4个玩家结构体的数组
 * 参数：ResentPlayer 确定当前进行操作的玩家编号
 * 参数：price 当前地皮的价格
 * 返回值：无
 */

void Upgradation(Map* map ,Player* player ,unsigned char ResentPlayer ,int price){
    //满级，升不了
    if(map->cells[player[ResentPlayer].position].kind == HOUSE_3){
        printf("当前房屋已经满级，无法升级\r\n");
        return;
    }
    //钱不够，升不了
    else if(player[ResentPlayer].money < price){
        printf("您的钱不够，无法升级房屋\r\n");
        return;
    }
    
    //提示信息
    print("您现在拥有的现金:%d，升级这块地需要的现金:%d\r\n",player[ResentPlayer].money,price);
    printf("是否升级该房屋(y/n)???\r\n");

    //刘浩然命令行解析函数，读取命令行输入
    char l;
    while((l=getchar())!='n' || (l=getchar())!='y'){
        printf("输入错误，请重新输入\r\n");
        getchar();
    }
    //判断是y还是n，执行操作
    switch(l){      
        case 'y':
            //升级房屋
            //修改房屋参数
            map->cells[player[ResentPlayer].position].show_char++;     //修改显示
            map->cells[player[ResentPlayer].position].kind++;          //修改房屋等级
            //修改Player的参数
            player[ResentPlayer].money -= price;        //修改剩余金额
            player[ResentPlayer].properties[player[ResentPlayer].position]++;   //修改资产记录
            break;
        case 'n':
            //提示信息
            printf("您拒绝了升级该地皮！\r\n");
            return;
        default:
            break;
    }
}

/*
 * 函数简介：买地函数
 * 参数：map 地图结构体
 * 参数：player 包含4个玩家结构体的数组
 * 参数：ResentPlayer 确定当前进行操作的玩家编号
 * 参数：price 当前地皮的价格
 * 返回值：无
 */

void BuyPlace(Map* map ,Player* player ,unsigned char ResentPlayer ,int price){
    //钱不够，买不了
    if(player[ResentPlayer].money < price){
        printf("您的钱不够，无法购买房屋\r\n");
        return;
    }

    //提示信息
    print("您现在拥有的现金:%d，买下这块地需要的现金:%d\r\n",player[ResentPlayer].money,price);
    printf("是否购买该地皮(y/n)???\r\n");

    //刘浩然命令行解析函数，读取命令行输入
    char l;
    while((l=getchar())!='n' || (l=getchar())!='y'){
        printf("输入错误，请重新输入\r\n");
        getchar();
    }
    //判断是y还是n，执行操作
    switch(l){      
        case 'y':
            //买房
            //修改房屋参数
            map->cells[player[ResentPlayer].position].owner = ResentPlayer;              //修改所有人
            map->cells[player[ResentPlayer].position].show_char = HOUSE_1_SHOW_CHAR;     //修改显示
            map->cells[player[ResentPlayer].position].kind = HOUSE_1;                    //修改房屋等级
            //修改Player的参数
            player[ResentPlayer].money -= price;        //修改价格
            player[ResentPlayer].properties[player[ResentPlayer].position] = PROPERTY_HOUSE_1;   //修改资产记录
            player[ResentPlayer].property_count++;      //资产数 + 1
            break;
        case 'n':
            //提示信息
            printf("您拒绝了购买该地皮！\r\n");
            return;
        default:
            break;
    }
}

/*
 * 函数简介：破产函数
 * 参数：map 地图结构体
 * 参数：player 包含4个玩家结构体的数组
 * 参数：ResentPlayer 确定当前进行操作的玩家编号
 * 返回值：无
 */

void Bankruptcy(Map* map ,Player* player ,unsigned char ResentPlayer){
    //所有地产变为空地
    for(int i=0;i<70;i++){
        if(player[ResentPlayer].properties[i]){
            player[ResentPlayer].properties[i] = 0;
            map->cells[player[ResentPlayer].position].owner = NO_ONE;                        //修改所有人
            map->cells[player[ResentPlayer].position].show_char = BLANK_SPACE_SHOW_CHAR;     //修改显示
            map->cells[player[ResentPlayer].position].kind = BLANK_SPACE;                    //修改房屋等级
            player[ResentPlayer].property_count--;
        }
    }
    //似了
    player[ResentPlayer].alive = 0;
}
