#include"greedy.h"
snake::snake():direc('d'){
        for(int i=0;i<INIT_LENGTH;++i)
            body.push_back(make_pair(LENGTH/2,WIDTH/2-i));
}
void init_snake(const snake& it,vector<string>& pixs){
    pixs[it.body.front().first][it.body.front().second]='*';
    for(int i=it.body.front().second-1;i>=it.body.back().second;--i){
        pixs[it.body.front().first][i]='+';
    }
}
void init_pixels(vector<string>& it){
    if(!it.empty())
        it.clear();    
    it.push_back(UPPERBOUND);
    for(int i=1;i<LENGTH-1;++i)
        it.push_back(string(1,'|')+string(WIDTH-2,' ')+string("|\n"));
    it.push_back(*(it.cbegin()));    
}

bool move_snake(snake& it,vector<string>& pixs){
    pair<int,int> coor=it.body.front();
    switch(it.direc){
        case 'w':
            --(coor.first);
            break;
        case 's':
            ++(coor.first);
            break;
        case 'a':
            --(coor.second);
            break;
        case 'd':
            ++(coor.second);
            break;
    }
    switch(pixs[coor.first][coor.second]){
        case ' ':
            pixs[it.body.back().first][it.body.back().second]=' ';
            it.body.pop_back();
        case '@':
            pixs[it.body.front().first][it.body.front().second]='+';
            pixs[coor.first][coor.second]='*';
            it.body.push_front(coor);
            return 1;
        default:
            return 0;
    }
}

void refresh(const vector<string>& pixs){
    for(int i=0,j=pixs.size();i<j;++i)
        cout<<'\r'<<pixs[i];
}

char timed_getch(){
    char ret=0;
    timeout(500);
    if((ret=getch())!=EOF)
        return ret;
    else return 0;
}
