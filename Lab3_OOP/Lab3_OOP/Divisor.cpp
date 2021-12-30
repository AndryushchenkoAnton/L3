#include "Divisor.h"
#include <fstream>
#include <iostream>

double Divisor::calculate() {
    double answer = operands[0];
    for (int i = 1; i < operandsCount; i++) {
        answer /= operands[i];
    }
    return answer;
}

void Divisor::logToFile(const string& filename) {
    ofstream fout(filename, ios::app);
    fout << "\tDivisor:" << endl;

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
                fout << operands[i] << " / ";
            else
                fout << "(" << operands[i] << ")" << " / ";
        }
    }
    fout << " < Total: " << operandsCount << " >" << endl;
    fout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}

void Divisor::logToScreen() {
    cout << "\tDivisor:" << endl;

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
                cout << operands[i] << " / ";
            else
                cout << "(" << operands[i] << ")" << " / ";
        }
    }
    cout << " < Total: " << operandsCount << " >" << endl;
    cout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}

void Divisor::shuffle() {
    double temp;
    if (operands[0] >= 0) operands[0] = -operands[0];
    if (operands[operandsCount - 1] >= 0) operands[operandsCount - 1] = -operands[operandsCount - 1];
    temp = operands[0];
    operands[0] = operands[operandsCount - 1];
    operands[operandsCount - 1] = temp;

}

void Divisor::shuffle(size_t i, size_t j) {
    double temp;
    if (operands[j] >= 0) operands[j] = -operands[j];
    if (operands[i] >= 0) operands[i] = -operands[i];
    temp = operands[j];
    operands[j] = operands[i];
    operands[i] = temp;
}