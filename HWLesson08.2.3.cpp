#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculate(string example) {
    vector<string> first_buffer, second_buffer;
    for (int i = 0; i < example.length(); i++) {
        string symbol(1, example[i]);
        if (symbol == "+" || symbol == "-") {
            if (!second_buffer.empty()) {
                first_buffer.push_back(second_buffer.back());
                second_buffer.pop_back();
            }
            second_buffer.push_back(symbol);
        }
        else if (symbol == "*" || symbol == "/") {
            second_buffer.push_back(symbol);
        }
        else if (symbol >= "0" && symbol <= "9") {
            string number = symbol;
            while (example[i + 1] >= '0' && example[i + 1] <= '9') {
                number += example[i + 1];
                i++;
            }
            first_buffer.push_back(number);
        }
        else {
            throw overflow_error("Incorrect expression entered!");
        }
    }
    while (!second_buffer.empty()) {
        first_buffer.push_back(second_buffer.back());
        second_buffer.pop_back();
    }
    for (int i = 0; i < first_buffer.size(); i++) {
        if (first_buffer[i] == "+" || first_buffer[i] == "-" || first_buffer[i] == "*" || first_buffer[i] == "/") {
            int first_variable = stoi(first_buffer[i - 2]);
            int second_variable = stoi(first_buffer[i - 1]);
            if (first_buffer[i] == "+") {
                first_variable = first_variable + second_variable;
            }
            if (first_buffer[i] == "-") {
                first_variable = first_variable - second_variable;
            }
            if (first_buffer[i] == "*") {
                first_variable = first_variable * second_variable;
            }
            if (first_buffer[i] == "/") {
                if (second_variable == 0) {
                    throw exception ("Can't divide by zero!");
                }
                first_variable = first_variable / second_variable;
            }
            first_buffer.erase(first_buffer.begin() + (i - 2), first_buffer.begin() + i + 1);
            first_buffer.insert(first_buffer.begin(), to_string(first_variable));
            i = 0;
        }
    }
    return stoi(first_buffer.back());
}
int main()
{
    try {
        string example;
        cout << "Enter you example:\n";
        cin >> example;
        int result;
        result = calculate(example);
        cout << "Calculation result: " << result << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}