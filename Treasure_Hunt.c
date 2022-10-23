#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include<stdbool.h>  


#define MAX 7
char maze[MAX][MAX];
int i,j;
int pos[2]={0,0};
bool isEnd = false;
bool isTreasureFound = false;

void generateRandomMaze(){
    
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(rand()%10 < 8 || (i==0 && j==1) || (i==6 && j==5)){
                maze[i][j]='-';
            }else if(rand()%10 == 0 || rand()%10 == 9){
                maze[i][j]='*';
            }
            else{
                maze[i][j]='X';
            }
        }
    }
    
    maze[0][0] = 'A';
    maze[6][6] = 'T';
    
}

void reset(){
    printf("\033[0m");
}

void purple(){
    printf("\033[1;35m");
}

void cyan(){
    printf("\033[1;36m");
}

void blue(){
    printf("\033[1;34m");
}

void green(){
    printf("\033[1;32m");
}

void yellow(){
    printf("\033[1;33m");
}

void red(){
    printf("\033[1;31m");
}

void dispInfo(){
    yellow();
    printf("\n");
    printf(" 88888888888                                                              888    888                   888  \n");
    printf("     888                                                                  888    888                   888  \n");
    printf("     888                                                                  888    888                   888   \n");
    printf("     888  888d888 .d88b.   8888b.  .d8888b  888  888 888d888 .d88b.       8888888888 888  888 88888b.  888888\n");
    printf("     888  888P'  d8P  Y8b     '88b 88K      888  888 888P'  d8P  Y8b      888    888 888  888 888 '88b 888   \n");
    printf("     888  888    88888888 .d888888 'Y8888b. 888  888 888    88888888      888    888 888  888 888  888 888   \n");
    printf("     888  888    Y8b.     888  888      X88 Y88b 888 888    Y8b.          888    888 Y88b 888 888  888 Y88b. \n");
    printf("     888  888     'Y8888  'Y888888  88888P'  'Y88888 888     'Y8888       888    888  'Y88888 888  888  'Y888\n\n");
    blue();
    printf(" ----- Instruction ------\n\n");
    green();
    printf(" w - ");
    cyan();
    printf("UP, ");
    green();
    printf("a - ");
    cyan();
    printf("LEFT, ");
    green();
    printf("s - ");
    cyan();
    printf("DOWN, ");
    green();
    printf("d - ");
    cyan();
    printf("RIGHT. \n\n");
    cyan();
    printf(" A ");
    reset();
    printf("- Adventurer, ");
    yellow();
    printf("T ");
    reset();
    printf("- Treasure, ");
    red();
    printf("* ");
    reset();
    printf("- Danger, ");
    purple();
    printf("X ");
    reset();
    printf("- Wall\n\n");
}

void displayMaze(){
    if(isEnd==true){
        red();
        printf("\n ------You're Dead-------");
        reset();
        return;
    }
    else if(isTreasureFound==true){
        green();
        printf("\n -------Congrats!!, You Found The Treasure-----------");
        reset();
        ;
    }
    else{
        dispInfo();
        for(i=0;i<MAX;i++){
            for(j=0;j<MAX;j++){
                switch(maze[i][j]){
                    case 'X':purple();
                            break;
                    case '*':red();
                            break;
                    case 'T':yellow();
                            break;
                    case 'A':cyan();
                            break;
                    default:reset();
                            break;
                }
                printf(" %c ",maze[i][j]);
                reset();
            }
            printf("\n");
        }
    }
    
}

void clear(){
    system("clear");
}

void handleInput(){
    char key,temp;
    do{
    if(isEnd==true || isTreasureFound==true)break;
    printf("\n Enter a Key: ");
    scanf("%c",&key);
    scanf("%c",&temp);
    switch(key){
        case 'w':{
            if(maze[pos[0]-1][pos[1]] == 'X'){
                break;
            }
            else if(maze[pos[0]-1][pos[1]] == '*'){
                isEnd = true;
                break;
            }
            else if(maze[pos[0]-1][pos[1]] == 'T'){
                isTreasureFound = true;
                break;
            }
            else if(pos[0]!=0){
               maze[pos[0]][pos[1]]='-';
                pos[0]=pos[0]-1;
            }
                break; 
                }
        case 's':{
            if(maze[pos[0]+1][pos[1]] == 'X'){
                break;
            }
            else if(maze[pos[0]+1][pos[1]] == '*'){
                isEnd = true;
                break;
            }
            else if(maze[pos[0]+1][pos[1]] == 'T'){
                isTreasureFound = true;
                break;
            }
            else if(pos[0]!=MAX-1){
               maze[pos[0]][pos[1]]='-';
                pos[0]=pos[0]+1;
            }
                break; 
                }
        case 'a':{
            if(maze[pos[0]][pos[1]-1] == 'X'){
                break;
            }
            else if(maze[pos[0]][pos[1]-1] == '*'){
                isEnd = true;
                break;
            }
            else if(maze[pos[0]][pos[1]-1] == 'T'){
                isTreasureFound = true;
                break;
            }
            else if(pos[1]!=0){
               maze[pos[0]][pos[1]]='-';
                pos[1]=pos[1]-1;
            }
                break; 
                }
        case 'd':{
            if(maze[pos[0]][pos[1]+1] == 'X'){
                break;
            }
            else if(maze[pos[0]][pos[1]+1] == '*'){
                isEnd = true;
                break;
            }
            else if(maze[pos[0]][pos[1]+1] == 'T'){
                isTreasureFound = true;
                break;
            }
            else if(pos[1]!=MAX-1){
               maze[pos[0]][pos[1]]='-';
                pos[1]=pos[1]+1;
            }
                break; 
                }
        case '0':{
            isEnd = true;
        }
    }
    maze[pos[0]][pos[1]]='A';
    clear();
    displayMaze();
    }while(isEnd != true || isTreasureFound!=true);
    
}



int main() {
    srand(time(NULL));
    generateRandomMaze();
    displayMaze();
    handleInput();

    return 0;
}

