#include "Multiplier.h"
#include <fstream>
#include <iostream>

double Multiplier::calculate() {
    double answer = 1;
    for (int i = 0; i < operandsCount; i++) {
        answer *= operands[i];
    }
    return answer;
}

void Multiplier::logToFile(const string& filename) {
    ofstream fout(filename, ios::app);
    fout << "\tMultiplier:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    for (size_t i = 0; i < operandsCount; i++) {
        if (i == (operandsCount - 1)) {
            if (operands[i] >= 0)
                fout << operands[i];
            else
                fout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                fout << operands[i] << " * ";
            else
                fout << "(" << operands[i] << ")" << " * ";
        }
    }
    fout << " < Total: " << operandsCount << " >" << endl;
    fout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}

void Multiplier::logToScreen() {
    cout << "\tMultiplier:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    for (size_t i = 0; i < operandsCount; i++) {
        if (i == (operandsCount - 1)) {
            if (operands[i] >= 0)
                cout << operands[i];
            else
                cout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                cout << operands[i] << " * ";
            else
                cout << "(" << operands[i] << ")" << " * ";
        }
    }
    cout << " < Total: " << operandsCount << " >" << endl;
    cout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}