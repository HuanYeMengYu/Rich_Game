# include "utils.h"

void display_map(Map map){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
        map.cells[0].show_char,
        map.cells[1].show_char,
        map.cells[2].show_char,
        map.cells[3].show_char,
        map.cells[4].show_char,
        map.cells[5].show_char,
        map.cells[6].show_char,
        map.cells[7].show_char,
        map.cells[8].show_char,
        map.cells[9].show_char,
        map.cells[10].show_char,
        map.cells[11].show_char,
        map.cells[12].show_char,
        map.cells[13].show_char,
        map.cells[14].show_char,
        map.cells[15].show_char,
        map.cells[16].show_char,
        map.cells[17].show_char,
        map.cells[18].show_char,
        map.cells[19].show_char,
        map.cells[20].show_char,
        map.cells[21].show_char,
        map.cells[22].show_char,
        map.cells[23].show_char,
        map.cells[24].show_char,
        map.cells[25].show_char,
        map.cells[26].show_char,
        map.cells[27].show_char,
        map.cells[28].show_char
    );
    printf("%c                           %c", map.cells[69].show_char, map.cells[29].show_char);
    printf("%c                           %c", map.cells[68].show_char, map.cells[30].show_char);
    printf("%c                           %c", map.cells[67].show_char, map.cells[31].show_char);
    printf("%c                           %c", map.cells[66].show_char, map.cells[32].show_char);
    printf("%c                           %c", map.cells[65].show_char, map.cells[33].show_char);
    printf("%c                           %c", map.cells[64].show_char, map.cells[34].show_char);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
        map.cells[63].show_char,
        map.cells[62].show_char,
        map.cells[61].show_char,
        map.cells[60].show_char,
        map.cells[59].show_char,
        map.cells[58].show_char,
        map.cells[57].show_char,
        map.cells[56].show_char,
        map.cells[55].show_char,
        map.cells[54].show_char,
        map.cells[53].show_char,
        map.cells[52].show_char,
        map.cells[51].show_char,
        map.cells[50].show_char,
        map.cells[49].show_char,
        map.cells[48].show_char,
        map.cells[47].show_char,
        map.cells[46].show_char,
        map.cells[45].show_char,
        map.cells[44].show_char,
        map.cells[43].show_char,
        map.cells[42].show_char,
        map.cells[41].show_char,
        map.cells[40].show_char,
        map.cells[39].show_char,
        map.cells[38].show_char,
        map.cells[37].show_char,
        map.cells[36].show_char,
        map.cells[35].show_char
    );
}
