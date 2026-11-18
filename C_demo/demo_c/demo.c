#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "common.h"


#define TABLE_SIZE   (U1)10
U1 output_view_init[TABLE_SIZE];


// 光标移动到指定位置
void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 无闪烁清屏：光标回左上角，靠后续输出覆盖
void clear_screen_no_flicker(void) {
    gotoxy(0, 0);
}


void vdg_demo(void)
{
    U1 i;
    for(i = 0;i<TABLE_SIZE;i++)
    {
        output_view_init[i] = 0;
    }

    static U1 j = 0;
    output_view_init[j] = 1;
    for(i=0;i<TABLE_SIZE;i++)
    {
        if(output_view_init[i] == 1)
        {
            printf("->");
        }
        else
        {
            printf(" ");
        }
    }
    j++;

    if ( j >= TABLE_SIZE)
    {
        j = 0;
    }
    
    return;
}

void vdg_demo_main(void)
{
    /* 隐藏光标 */
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(hOutput, &cursor_info);
    cursor_info.bVisible = 0;
    SetConsoleCursorInfo(hOutput, &cursor_info);


    while(1)
    {
        vdg_demo();
        Sleep(75);
        clear_screen_no_flicker();
    }
    return;
}