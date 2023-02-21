#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileWasNotOpenedExeption : public exception {
public:
    FileWasNotOpenedExeption(const char* msg) : exception(msg) {};
    string PrintMsg() {
        return message;
    }
private:
    string message = "File with this name not found!\n";
};

void ReadFile(ifstream &fin) {
    cout << "Reading date from file";
    cout << "\n------------------------------------------------------\n";
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << "\n------------------------------------------------------\n";
    cout << "Reading data from file completed\n";
    fin.close();
    cout << "File was closed\n";
}

void OpenFile(const string filename, ifstream &fin) {
    cout << "Attempt to open the file\n";
    fin.open(filename);
    if (!fin.is_open()) {
        throw FileWasNotOpenedExeption("Error!\n");
    }
    cout << "File open\n";
}

int main()
{
    string filename;
    cout << "Enter the name of the file you want to open:\n";
    cin >> filename;
    try {
        ifstream fin;
        OpenFile(filename, fin);
        ReadFile(fin);
    }
    catch (FileWasNotOpenedExeption& ex) {
        cout << ex.what() << ex.PrintMsg() << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}