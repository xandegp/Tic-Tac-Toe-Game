#include <stdio.h>
#define SIZE 3


//used functions
void print_board(char board[SIZE][SIZE]);
void player_move(int i, int m, int n,char board[SIZE][SIZE]);
int winner(char board[SIZE][SIZE]);
void clear(char board[SIZE][SIZE]);


int main(){
    //create a 3x3 matrix with is the board of the game
    char board[SIZE][SIZE]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    char ans;
    int line;
    int column;

    printf("Welcome to the Tic Tac Toe game in C\n");
    printf("Do you want to play it?(y/n)\n");
    scanf(" %c",&ans);

    //while the user dont say 'n', the game dont stop
    while(ans=='y' || ans=='Y'){
        clear(board);
        printf("Player 1 Starts:\n");
        int win = 0;
    //while nether player 1 ou 2 wins, the game continues until its a draw
        do{
    //Same actions for player 1 and 2
            for(int i=1;i<=2;i++){
                printf("Player %d, choose the position where to place a mark(line,column)\n",i);
                scanf("%d %d",&line,&column);
    //if the player select a position that isn't in the board or a marked one, he will select again a position
                while(line<0||line>2||column<0||column>2||board[line][column]!=' '){
                    printf("Error:Please enter valid and unmarked position in the matrix (between 0-2):\n");
                    scanf("%d %d",&line,&column);
                }                
    //put the mark of the player (X or O) in the selected position
                player_move(i,line,column,board);
    //print the new board with the choices of the players
                print_board(board);


                win = winner(board);
                if(win!=0) break;
            }

        }while(win==0);
        
        if(win==1){
            printf("Player 1 wins!!\n");
        }
        else if(win==2){
            printf("Player 2 wins!!\n");
        }
        else{
            printf("Its a draw!!\n");
        }
        printf("-----------\n");
        printf("Do you want to play it again?(y/n)\n");
        scanf(" %c",&ans);
    }
//ends game
    printf("Ok, goodbye :)\n");

    return 0;
}

//function that prints the board
void print_board(char board[SIZE][SIZE]){
    printf("Board:\n");
    printf("--------\n");
    for(int i=0;i<SIZE;i++){
        printf("|");
        for(int j=0;j<SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("--------\n");
}

//function that register the players choice in the board
void player_move(int i,int m, int n,char board[SIZE][SIZE]){
    
    if(i==1){
        board[m][n] = 'X';
    }
    else{
        board[m][n] = 'O';
    }
}


//function that see if a player won(1 or 2), if its a draw(3) or its in the midle of the game(0)
int winner(char board[SIZE][SIZE]){

    //verify if someone wins with 3 marks in the same line
    int count_line1=0;
    int count_line2=0;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]=='X'){
                count_line1++;
            }
            else if(board[i][j]=='O'){
                count_line2++;
            }
        }
        if(count_line1==3){
            return 1;
        }
        else if(count_line2==3){
            return 2;
        }
        
        count_line1=0;
        count_line2=0;
    }

    //verify if someone wins with 3 marks in the same column
    int count_column1=0;
    int count_column2=0;
    for(int j=0;j<SIZE;j++){
        for(int i=0;i<SIZE;i++){
            if(board[i][j]=='X'){
                count_column1++;
            }
            else if(board[i][j]=='O'){
                count_column2++;
            }
        }
        if(count_column1==3){
            return 1;
        }
        else if(count_column2==3){
            return 2;
        }
        
        count_column1=0;
        count_column2=0;
    }
    
    //verify if someone wins with 3 marks in the first diagonal(\)
    int count_diagonal1=0;
    int count_diagonal2=0;

    for(int i=0;i<SIZE;i++){
        if(board[i][i]=='X'){
            count_diagonal1++;
        }
        else if(board[i][i]=='O'){
            count_diagonal2++;
        }
    }
    if(count_diagonal1==3){
        return 1;
    }
    else if(count_diagonal2==3){
        return 2;
    }
    count_diagonal1=0;
    count_diagonal2=0;

//verify if someone wins with 3 marks in the second diagonal(/)
    
    for(int i=0;i<SIZE;i++){
        if(board[2-i][i]=='X'){
            count_diagonal1++;
        }
        else if(board[2-i][i]=='O'){
            count_diagonal2++;
        }
    }
    if(count_diagonal1==3){
        return 1;
    }
    else if(count_diagonal2==3){
        return 2;
    }
    count_diagonal1=0;
    count_diagonal2=0;

//verify if its a draw
    int count_1=0;
    int count_2=0;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]=='X'){
                count_1++;
            }
            else if(board[i][j]=='O'){
                count_2++;
            }            
        }
    }

    if(count_1+count_2==9){
        return 3;
    }


    return 0;
}

//function that clears the board for a new game
void clear(char board[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j]=' ';
        }
    }
}




    