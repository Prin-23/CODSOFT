/*
                        TASK 2
                    SIMPLE CALCULATOR
 Develop a calculator program that performs basic arithmetic
 operations such as addition, subtraction, multiplication, and
 division. Allow the user to input two numbers and choose an
 operation to perform
*/

#include<iostream>
using namespace std;
int main()
{
    float num1,num2;
    int choice;
    cout << "Welcome to Simple Calculator\n";
    cout << "Enter the two values: \n";
    cout << "First Number: ";
    cin >> num1;
    cout << "Second Number: ";
    cin >> num2;
    cout << "Enter Your choice: \n";
    cout << "1. '+'\n";
    cout << "2. '-'\n";
    cout << "3. '*'\n";
    cout << "4. '/'\n";
    cout <<"choice:";
    cin >> choice;
    switch (choice)
    {
    case 1: cout << "Addition of the Two Numbers " << num1 << "+" << num2 << "=" << num1+num2;
        break;
    case 2: cout << "Substracion of the Two Numbers " << num1 << "-" << num2 << "=" << num1-num2;
        break;
    case 3: cout << "Multiplication of the Two Numbers " << num1 << "*" << num2 << "=" << num1*num2;
        break;
    case 4: cout << "Division of the Two Numbers " << num1 << "/" << num2 << "=" << num1/num2;
        break;
    
    default: cout << "Your is Wrong!! Try Again!!";
        break;
    }
    return 0;
}