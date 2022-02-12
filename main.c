
#include<stdio.h>

char game[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void playerS(char[], char);

void cyan(){
    printf("\033[1;36m");
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
void reset(){
    printf("\033[0m");
}

void display(){
    cyan();
    printf("\n");
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                printf("    %c     |", game[i][j]);
            }
            printf("\n\n");
        }
    reset();
}

void putSign(char player[], char p, int loc){
    if(loc == 1)    game[0][0] = p;
    else if(loc == 2)   game[0][1] = p;
    else if(loc == 3)   game[0][2] = p;
    else if(loc == 4)   game[1][0] = p;
    else if(loc == 5)   game[1][1] = p;
    else if(loc == 6)   game[1][2] = p;
    else if(loc == 7)   game[2][0] = p;
    else if(loc == 8)   game[2][1] = p;
    else if(loc == 9)   game[2][2] = p;
    else {
        red();
        printf("\nWrong Choice");
        reset();
        playerS(player, p);
    }
}

void playerS(char player[], char p){
    int loc;
    printf("\n\nEnter Location: ");
    scanf("%d", &loc);
    putSign(player, p, loc);
}

int check(char player[], char p){
    if(game[0][0] == p && game[0][1] == p && game[0][2] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[0][0] == p && game[1][1] == p && game[2][2] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[0][0] == p && game[1][0] == p && game[2][0] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[0][1] == p && game[1][1] == p && game[2][1] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[0][2] == p && game[1][2] == p && game[2][2] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[1][0] == p && game[1][1] == p && game[1][2] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[2][0] == p && game[2][1] == p && game[2][2] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else if(game[0][2] == p && game[1][1] == p && game[2][0] == p){
            printf("\nWinner is %s", player);
            reset();
            return 1;
        }
        else    return 0;
}

void moves(char player01[], char player02[]){
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < 4; i++){
        yellow();
        printf("\nTurn for %s", player01);
        printf("\nPlease do not enter location of already occupied moves");
        reset();
        playerS(player01, 'X');
        display();
        green();
        p1 = check(player01, 'X');
        if(p1 == 1) return;
        yellow();
        printf("\nTurn for %s", player02);
        printf("\nPlease do not enter location of already occupied moves");
        reset();
        playerS(player02, 'O');
        display();
        green();
        p2 = check(player02, 'O');
        if(p2 == 1) return;
    }   

    red();
    if(p1 == 0 && p2 == 0){
        printf("\nMatch Drawn");
        printf("\nBetter luck next time.\n");
    }
    reset();
}

int main(){
    char player01[50], player02[50];
    printf("\nEnter Player-1 Name: ");
    fgets(player01, 50, stdin);
    printf("\nEnter Player-2 Name: ");
    fgets(player02, 50, stdin);
    display();

    moves(player01, player02);
    
    return 0;
}
