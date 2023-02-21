#include <iostream>
using namespace std;

double divide(double number) {
    if (number == 0) {
        throw exception("You entered 0. You cannot divide by zero!");
    }
    int value = 1024;
    double rezult = (double)value / number;
    return rezult;
}

int main()
{
    double number;
    cout << "Enter the number: ";
    cin >> number;
    try {
        cout << "The result of dividing 1024 by the entered number: \n" << divide(number) << endl;
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}