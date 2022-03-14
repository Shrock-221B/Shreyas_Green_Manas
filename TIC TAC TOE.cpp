#include <iostream>//c++ libraries importing
#include <stdlib.h>
using namespace std;



char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};//Declaring Array of size 3*3 for spaces

//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;


void Board_Design(){//This function is for the Structure and Design Of the game


  
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  " <<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<"\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}


void player_turn(){//This Function takes input from players and updates the game 
    if(turn == 'X'){
        cout<<"\nPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\nPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0;
	break;
        case 2: row=0; column=1;
	break;
        case 3: row=0; column=2;
	break;
        case 4: row=1; column=0; 
	break;
        case 5: row=1; column=1;
	break;
        case 6: row=1; column=2;
	break;
        case 7: row=2; column=0; 
	break;
        case 8: row=2; column=1; 
	break;
        case 9: row=2; column=2;
	break;
        default:
            cout<<"Check your Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another!!nn";
        player_turn();
    }
   
    Board_Design();
}


bool gameover(){//This Function Checks If Game is Won or Not
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])//This checks same for adjacent horizontal and vertical
    return false;


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])//Diagnally checking is they are same or not
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}


int main()//This is Main method
{
    cout<<"T I C K -- T A C -- T O E -- G A M E";
    cout<<"\nFOR 2 PLAYERS\n";
    while(gameover()){//While Loop Till game is over
        Board_Design();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"nnCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"nnCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"nnGAME DRAW!!!nn";
} 

