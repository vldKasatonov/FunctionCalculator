#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

double calculateY(double x, int n) {
    double y;
    double sum;
    if (x <= 0) {
        y = 0;
        for (int i = 2; i <= n - 1; i++) {
            y += x / i;
        }
    }
    else {
        y = 0;
        for (int i = 0; i <= n - 1; i++) {
            sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += i / (j + x);
            }
            y += sum;
        }
    }
    return y;
}

void checkValidInput() {
    if (cin.fail()) {
        throw "Invalid data has been entered";
    }
}

void checkValidParams(double a, double b, double h, int n) {
    if (a >= b) {
        throw "Variable 'a' must be less than variable 'b'";
    }

    if (h <= 0) {
        throw "Variable 'h' must be a positive number";
    }

    if (n < 3) {
        throw "Variable 'n' must not be less than 3";
    }
}

void readData(double& a, double& b, double& h, int& n, char& isEntryToFile) {
    cout << "Enter the first element of the interval 'x', a:" << endl;
    cin >> a;
    checkValidInput();

    cout << "Enter the last element of the interval 'x' (b>a), b:" << endl;
    cin >> b;
    checkValidInput();

    cout << "Enter the 'x' increment step (h>0), h:" << endl;
    cin >> h;
    checkValidInput();

    cout << "Enter the integer index of the last element of the sum (n>=3), n:" << endl;
    cin >> n;
    checkValidInput();

    cout << "Do you want to enter the results of the calculations into a file?\n   If yes, enter '+':" << endl;
    cin >> isEntryToFile;
    checkValidInput();
}

void entryToFile(string outputString, string pathToFile) {
    ofstream fout(pathToFile, ios::app);
    if (!fout.is_open()) {
        throw "Failed to open the file for writing";
    }
    fout << outputString;
    fout.close();
}

int main(){
    double a, b, h, y;
    int n;
    char isEntryToFile;
    ostringstream outputStringStream;
    string outputString;
    string pathToFile = R"(C:\KhPI\CppProject\FSE\LabProject\FunctionCalculator\Results\valueOfXAndY.txt)";
    try {
        readData(a, b, h, n, isEntryToFile);
        checkValidParams(a, b, h, n);
        for (double x = a; x <= b; x += h) {
            y = calculateY(x, n);
            outputStringStream << "When n = " << n << " and x" << " = " << x << ": y" << " = " << y << endl;
        }
        outputString = outputStringStream.str();
        cout << outputString;
        outputStringStream << "======================================\n";
        outputString = outputStringStream.str();
        if (isEntryToFile == '+') {
            entryToFile(outputString, pathToFile);
        }
    }
    catch (const char* e) {
        cerr << "Error: " << e << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unknown error!" << endl;
        return 2;
    }
    return 0;
}