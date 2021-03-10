#include"greedy.h"

int main(){
    snake NBE1;
    vector<string> pixels;
    init_pixels(pixels);
    init_snake(NBE1,pixels);
    
    pixels[LENGTH-2][WIDTH/2]=pixels[1][WIDTH/2]='@';
    
    initscr();
    noecho();
    refresh(pixels);    
    char command;
    
    while(1){
        if(command=timed_getch())
            NBE1.direc=command;
        if(!move_snake(NBE1,pixels))
            break;
        refresh(pixels);
    }    
    echo();
    endwin();
    return 0;
}
