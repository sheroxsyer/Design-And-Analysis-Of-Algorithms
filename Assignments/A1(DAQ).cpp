#include <iostream>
#include <stack>
using namespace std;
int FinalNumber = 0;

int Multiply(int a, int b); 

int main()
{
    // variable to store the two number that we will multiply
    int a;
    int b;

    
    cout << "Enter the numbers you want to multiply." << endl;
    cout << "First Number: ";
    cin >> a;
    cout << endl
         << "Second Number: ";
    cin >> b;

    // Calling function
    cout << "Answer = " << Multiply(a, b);
}

int Multiply(int a, int b)
{
    int save = b; // storing the second parameter in save variable

    // Creating two stacks, one for each variable
    stack<int> stack1;
    stack<int> stack2;

    // inserting the digits of first number in stack1
    while (a != 0)
    {
        int d = a % 10;
        stack1.push(d);
        a = a / 10;
    }

    // inserting 0 in first place of number incase the number of digits is odd
    if ((stack1.size() % 2) != 0)
    {
        stack1.push(0);
    }

    // This while loop will do the whole multiplication process. In each iteration we will multiply the first two digits of the first number with the second number
    while (!stack1.empty())
    {
        int num;
        save = b;

        // storing the first two digits of first number in num variable
        num = (stack1.top()) * 10;
        stack1.pop();

        num += stack1.top();
        stack1.pop();

        // storing the digits of second variable in the stack
        while (save != 0)
        {
            int c = save % 10;
            stack2.push(c);
            save = save / 10;
        }

        // inserting 0 in first place of number incase the number of digits is odd
        if ((stack2.size() % 2) != 0)
        {
            stack2.push(0);
        }

        // In this loop we will multiply the two digits of first number with each pair of second number
        while (!stack2.empty())
        {
            int num1;
            int factor = 1;

            num1 = (stack2.top()) * 10;
            stack2.pop();

            num1 += stack2.top();
            stack2.pop();

            // calculating the number of zeros that we will have to put at the end of the digit
            for (int i = 0; i < (stack1.size() + stack2.size()); i++)
            {
                factor *= 10;
            }

            int answer = (num * num1) * factor;

            // adding the answer of each interation int the FinalNumber variable that we will return
            FinalNumber += answer;
        }
    }

    // returning the final answer
    return FinalNumber;
}