#ifndef __GREEDY_H__
#define __GREEDY_H__

#include<iostream>
#include<string>
#include<vector>
#include<unistd.h>
#include<utility>
#include<deque>
#include<stdio.h>
#include<ncurses.h>
#include<cstdbool>
#include<cstdlib>
#include<ctime>
using namespace std;
//the width should be double of the length
#define WIDTH 40
#define LENGTH (WIDTH/2)
#define UPPERBOUND (string(1,'+')+string(WIDTH-2,'-')+string("+\n"))
#define INIT_LENGTH 3

struct snake{
    snake();
    //Data members
    deque<pair<int,int>> body;
    char direc;
};

void init_snake(const snake&,vector<string>&);
void init_pixels(vector<string>&);

bool move_snake(snake&,vector<string>&);
void refresh(const vector<string>&);
void take_control(void);
char timed_getch(void);
void new_fruit(vector<string>&);

#endif //!__GREEDY_H__
