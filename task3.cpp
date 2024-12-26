/*
                        TASK 3
                     TIC-TAC-TOE GAME
 Build a simple console-based Tic-Tac-Toe game that
 allows two players to play against each other
 Game Board: Create a 3x3 grid as the game board.
 Players: Assign "X" and "O" to two players.
 Display Board: Show the current state of the board.
 Player Input: Prompt the current player to enter their move.
 Update Board: Update the game board with the player's move.
 Check for Win: Check if the current player has won.
 Check for Draw: Determine if the game is a draw.
 Switch Players: Alternate turns between "X" and "O" players.
 Display Result: Show the result of the game (win, draw, or ongoing).
 Play Again: Ask if the players want to play another game.
 */
#include<iostream>
#include<cstring>
using namespace std;


//function to display the game board
void displayBoard(char board[3][3])
{
   cout << "\n";
   //this loop show the row of matrix
   for(int i=0; i<3; i++)
   {
      cout << "\t\t\t";
      //this loop show the col of matrix
      for(int j=0; j<3; j++)
      {
         cout << " " << board[i][j];
         if(j<2)
         cout << " |";
      }
      if(i<2)
      cout << "\n\t\t\t---+---+---\n";
   }
   cout << "\n";
}

//function to check if a player has won
bool checkwin(char board[3][3],char player)
{
   //check rows and columns
   for(int i=0; i<3; i++)
   {
      if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player) )
      {
         return true;
      }
   }
   //check diagonals also
   if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player) )
   {
      return true;
   }
   return false;
}

//function to check if the game is a draw

bool checkDraw(char board[3][3])
{
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         if(board[i][j] != 'X' && board[i][j] != 'O')
         {
            return false;
         }
      }
   }
   return true;
}
//function to reset the gameboard
void resetBoard(char board[3][3])
{
   char num = '1';
   for(int i=0; i<3; i++)
   {
      for(int j=0; j<3; j++)
      {
         board[i][j] = num++;
      }
   }
}
int main()
{
   // This is our 3x3 matrix or board of tic - tac - toe game
   char board[3][3];
   char currentPlayer = 'X';
   bool gameOver = false;
   char playAgain;
   do{
      resetBoard(board);
      gameOver = false;
      cout << "\n\t\tWelcome to Tic-Tac-Toe!\n";
      displayBoard(board);
      while(!gameOver)
      {
         int move;
         cout << "\n\t\tPlayer " << currentPlayer << ", Enter your move(1-9):";
         cin >> move;

         //convert move to board coordinates
         int row = (move - 1)/3;
         int col = (move - 1)%3;

         //check if the move is valid

         if(move < 1 || move > 9 || board[row][col] == 'X'||board[row][col] == 'O')
         {
            cout << "\n\t\tInvalid move!! Try Again...\n";
         }
         else{
            //update board with the current player's move
            board[row][col] = currentPlayer;
            displayBoard(board);

            //check for win or draw
            if(checkwin(board,currentPlayer))
            {
               cout << "\n\t\tPlayer " << currentPlayer << " wins!\n";
               gameOver = true;
            }else if(checkDraw(board))
            {
               cout << "\n\t\tIt's a Draw!\n";
               gameOver = true;
            }else{
               //switch players
               //Here we use ternary operators
               currentPlayer = (currentPlayer == 'X')?'O':'X';
            }
         }
      }
      //Ask if the Players want to play again
      cout << "\n\t\tDo You want to Play Again?(y/n):";
      cin >> playAgain;
   }while(playAgain == 'y' || playAgain == 'Y');
   cout << "\n\t\tThanks for playing Tic-Tac-Toe!!\n";
   return 0;
}