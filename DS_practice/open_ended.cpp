#include <iostream>
using namespace std;

int main(void)
{
    int ch, num_1, num_2;
    int num1, num2;
    // num_1 = int(num1 + 0.5);
    // num_2 = int(num2 + 0.5);

    // num_1 = (((int)(num1 + 32768.5)) - 32768);
    // num_2 = (((int)(num2 + 32768.5)) - 32768);

    // if (num1 > 0)
    // {
    //     num_1 = (int)(num1 + 0.5);
    // }
    // else
    // {
    //     num_1 = (int)(num1 - 0.5);
    // }

    // if (num2 > 0)
    // {
    //     num_2 = (int)(num2 + 0.5);
    // }
    // else
    // {
    //     num_2 = (int)(num2 - 0.5);
    // }

    cout << "\nEnter two operands: ";
    cin >> num1 >> num2;

    while (1)
    {
        cout << "\n====SIMPLE CALCULATOR====";
        cout << "\n1. Addition ( + )\n2. Subtraction ( - )\n3. Multiplication ( * )\n4. Division ( / )\n5. Modulo ( % )\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 4:
            cout << "Result: " << num1 / num2 << endl;
            break;
        case 5:
            cout << "Result: " << num1 % num2 << endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Error! Invalid Input";
        }
    }
}