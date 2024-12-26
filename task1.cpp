/*
                        TASK 1
                NUMBER GUESSING GAME
 Create a program that generates a random number and asks the
 user to guess it. Provide feedback on whether the guess is too
 high or too low until the user guesses the correct number
 */

// rand() 
//<cstdlib>
//starting point or seed
//srand()
//<ctime>
//time(0)

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    //seed random number generator
    srand(time(0));

    //Generate a random number between 1 to 100
    int randomNumber = rand() % 100 + 1;
    
    //Variable to store user's guess
    int userGuess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100.Can you guess it?" << endl;

    // Loop until the user guesses the correct number.

    while(userGuess != randomNumber){
        cout << "Enter your guess: ";
        cin >> userGuess;
        if(userGuess < randomNumber){
            cout << "Too Low! Try Again...\n";
        }else if(userGuess > randomNumber){
            cout << "Too High! Try Again...\n";
        }else{
            cout << "Congratulations! You guessed the correct number: " << randomNumber << "!\n";
        }
    }
    return 0;
}