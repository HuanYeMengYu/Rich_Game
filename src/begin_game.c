# include "utils.h"

void begin_game(){
    if(strlen(users)!=0){
        int i=0;
        int len=strlen(users);
        while(users[i]!='\0'){
            switch(users[i]){
                case '1':
                    // memset(QianFuren.properties, DONT_HAVE, sizeof(int)*CELL_NUMS);
                    for(int j=0;j<len;j++)
                    {
                        if(use_players[i].number==users[i]-'0')
                        {
                            QianFuren=use_players[i];
                        }
                    }
                    break;
                case '2':
                    // memset(ATubo.properties, DONT_HAVE, sizeof(int)*CELL_NUMS);
                    for(int j=0;j<len;j++)
                    {
                        if(use_players[i].number==users[i]-'0')
                        {
                            ATubo=use_players[i];
                        }
                    }
                    break;
                case '3':
                    // memset(SunXiaomei.properties, DONT_HAVE, sizeof(int)*CELL_NUMS);
                    for(int j=0;j<len;j++)
                    {
                        if(use_players[i].number==users[i]-'0')
                        {
                            SunXiaomei=use_players[i];
                        }
                    }
                    break;
                case '4':
                    // memset(JinBeibei.properties, DONT_HAVE, sizeof(int)*CELL_NUMS);
                    for(int j=0;j<len;j++)
                    {
                        if(use_players[i].number==users[i]-'0')
                        {
                            JinBeibei=use_players[i];
                        }
                    }
                    break;
            }
            i++;
        }
        player_number = now_user[0]-'0';
    }else{
        int Init_money = init_money();
        init_all_players(Init_money);
    }
    choose_players();
}
