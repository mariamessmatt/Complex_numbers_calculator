
// FCAI - Structured Programming - 2022 - Assignment 2
// Program Name : Complex Number Calculator
// Program Description : this program applies basic operations on two complex numbers
// Author1 :  Mohamed Ashraf Fahim         ID:20210329       Group: A
// Author2 :  Momen Mostafa Mabrouk        ID:20210416       Group: A
// Author3 :  Mariam Esmat Ahmed           ID:20211091       Group: A
// ver2 of Date : 20th March 2022
// section 9,10

#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

// To check if the input is right
float checker(float x)
{
    //if the input includes wrong data type it asks the user to enter another value
    while (cin.fail())
    {
        cout << "Enter a valid number: ";
        cin.clear();
        cin.sync();
        cin >> x;
    }
    return x;
}

// The addition function
void addition(float real_1, float imag_1, float real_2, float imag_2)
{
    int sum_real, sum_imag;
    //the real part and imaginary part are added separately
    sum_real = real_1 + real_2;
    sum_imag = imag_1 + imag_2;

    if (sum_imag >= 0)
    {
        cout << "The result is: " << sum_real << " + " << sum_imag << "i ";
    }
    else
    {
        cout << "The result is: " << sum_real << sum_imag << "i ";
    }
}

// The substraction function
void sub(float real_1, float imag_1, float real_2, float imag_2)
{
    int sum_real, sum_imag;
    //the real part and imaginary part are subtracted separately
    sum_real = real_1 - real_2;
    sum_imag = imag_1 - imag_2;

    if (sum_imag >= 0)
    {
        cout << "The result is: " << sum_real << " + " << sum_imag << "i ";
    }
    else
    {
        cout << "The result is: " << sum_real << sum_imag << "i ";
    }
}

// The multiplication function
void mult(float real_1, float imag_1, float real_2, float imag_2)
{

    /*
    applying the complex numbers multiplication rule:

            (a+bi)(c+di)

            = c(a+bi)+ di(a+bi)
            = ac + bci+ adi + bdi^2      where i^2 = -1
            = ac – bd +(bc+ad)i
    */

    int sum_real, sum_imag;
    sum_real = (real_1 * real_2) - (imag_1 * imag_2);
    sum_imag = (real_1 * imag_2) + (real_2 * imag_1);
    if (sum_imag >= 0)
    {
        cout << "The result is: " << sum_real << " + " << sum_imag << "i ";
    }
    else
    {
        cout << "The result is: " << sum_real << sum_imag << "i ";
    }
}

// The division function
void div(float real_1, float imag_1, float real_2, float imag_2)
{
    /*
     applying the complex numbers division rule:

            (a+bi)/(c+di)

         = ( (a+bi)(c-di) ) ÷ ((a+bi)(c-di) )
         = (ac + bd) + (bc - ad) i  ÷ ( c^2 + d^2 )
         = (ac + bd)/( c^2 + d^2 ) + (bc - ad) i/ ( c^2 + d^2 )

    */

    float sum_real, sum_imag, conj;
    conj = (real_2 * real_2) + (imag_2 * imag_2);
    sum_real = ((real_1 * real_2) + (imag_1 * imag_2)) / conj;
    sum_imag = ((imag_1 * real_2) - (real_1 * imag_2)) / conj;
    if (sum_imag >= 0)
    {
        cout << "The result is: " << sum_real << " + " << sum_imag << "i ";
    }
    else
    {
        cout << "The result is: " << sum_real << sum_imag << "i ";
    }
}


int main()
{
    float  real_1, imag_1, real_2, imag_2;
    int choice;
    //keeps the program running as long as the user didn't choose to exit
    while (true)
    {
        cout << "\nPlease enter the operation you want to do by entering the number of operation\n1-Addition(+)\n2-Substraction(-)\n3-Multiplication(x)\n4-Division(÷)\nto exit press any other key\nYour choice: ";
        cin >> choice;
        if (choice < 1 || choice >4)
        {
            break;
        }
        cout << "Please enter the first number in the form of (a+bi)\na=";
        cin >> real_1;
        real_1 = checker(real_1);
        cout << "b=";
        cin >> imag_1;
        imag_1 = checker(imag_1);
        cout << "Please enter the second number in the form of (c+di)\nc=";
        cin >> real_2;
        real_2 = checker(real_2);
        cout << "d=";
        cin >> imag_2;
        imag_2 = checker(imag_2);
        if (choice == 1)
        {
            addition(real_1, imag_1, real_2, imag_2);
        }
        else if (choice == 2)
        {
            sub(real_1, imag_1, real_2, imag_2);
        }
        else if (choice == 3)
        {
            mult(real_1, imag_1, real_2, imag_2);
        }
        else if (choice == 4)
        {
            if (real_2 == 0 && imag_2 == 0)
            {
                cout << "Please don't enter c and d as zero";
                //rerun the program due to the math error user made
                main();
            }
            div(real_1, imag_1, real_2, imag_2);
        }

        else
        {
            cout << "Please enter a correct number\n";
            main();
        }

    }

    return 0;
}

