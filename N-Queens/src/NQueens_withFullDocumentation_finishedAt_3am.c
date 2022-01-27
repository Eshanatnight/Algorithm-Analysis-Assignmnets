#include <stdio.h>
#include <stdbool.h>

int count = 1;

void printBoard(int board[][10], int n)
{
    printf("Solution %d:\n", count++);
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
             if(board[row][col] == 1)
                printf("\tQ");
            else
                printf("\t-");
        }
        printf("\n");
    }
    
}

bool isSafe(int board[][10], int row, int col, int n)
{
    //column checking
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }
    
    // diagonal checking
    
    //left diagonal checking
    int diag_x = row; //diagonal x coordinate
    int diag_y = col; //diagonal y coordinate
    
    while(diag_x >= 0 && diag_y >= 0)
    {
        if(board[diag_x][diag_y] == 1)
            return false;
        diag_x--;
        diag_y--;
    }
    
    // right diagonal checking
    diag_x = row; //diagonal x coordinate
    diag_y = col; //diagonal y coordinate
    
    while(diag_x >= 0 && diag_y < n)
    {
        if(board[diag_x][diag_y] == 1)
            return false;
        diag_x--;
        diag_y++;
    }
    
    return true; // position safe!
}


bool solveNQueens(int board[][10], int row, int n)
{
    //base case
    // succesfully placed all queens in n rows (0,....,n-1)
    if (row == n)
    {
        // IMPORTANT: Dead code for printing the board! Only reason the dead code is kept is
        // IMPORTANT: cause it took me like a day to figure this trick and I am to happy that i figured it out
        // IMPORTANT: and am low-key I am scared that if i delete this commented out code it would break the 
        // IMPORTANT: program even though it makes no sence. Please deal with it..
        // IMPORTANT: Thank You.
        /*
        //print the board
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                if(board[x][y] == 1)
                    printf("\tQ");
                else
                    printf("\t-");
            }
            printf("\n");
        }
        
        // comment this for only one solution
        return true;
        
        // uncomment this line for all possible solutions the recursive case will be 
        // called and keep on finding the possible solutions untill false is returned
        printf("\n\n");
        */  
        
        printBoard(board, n);
    }
    
    //recursive case
    for(int j = 0; j < n; j++)
    {
        //check if i,j position is safe for queen placement
        if(isSafe(board, row, j, n))
        {
            //ASSUMPTION: i,j is a correct position
            // subject to backtracking
            board[row][j] = 1;
            
            bool isNextQueenPossible = solveNQueens(board, row + 1, n);
            if(isNextQueenPossible)
                return true;
                
        //if i,j is not the correct position
        // so backtrack
        board[row][j] = 0;
        
        }
    }
    
    //if queen was not placed even after trying all positions
    return false;
}


int main()
{
    int n;
    scanf("%d", &n);
    int board[10][10] = {0};
    
    solveNQueens(board, 0, 8);
}