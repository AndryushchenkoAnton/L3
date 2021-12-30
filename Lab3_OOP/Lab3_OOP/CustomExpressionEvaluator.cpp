#include "CustomExpressionEvaluator.h"
#include <fstream> // for using file input/output
#include <iostream>

double CustomExpressionEvaluator::calculate() {
    double answer = 0;
    answer += operands[0];
    for (size_t i = 1; i < operandsCount-1; i+=2) {
        answer += operands[i] * operands[i+1];
    }
    return answer;
}

void CustomExpressionEvaluator::logToScreen() {
    cout << "\tCustomExpressionEvaluator:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    for (size_t i = 0; i < operandsCount-1; i++) {
        if (i == 0) {
            if (operands[i] > 0)
                cout << operands[i] << " + ";
            else
                cout << "(" << operands[i] << ")" << " + ";
        }
        else if (i == operandsCount - 2) {
            if (operands[i] > 0)
                cout << operands[i] << "*" << operands[i+1];
            else
                cout << "(" << operands[i] << ")" << "*" << operands[i + 1];
        }
        else {
            if (operands[i] > 0)
                cout << operands[i] << "*" << operands[i+1] << " + ";
            else
                cout << "(" << operands[i] << ")" << "*" << operands[i + 1] << " + ";
        }
    }
    cout << " < Total: " << operandsCount << " >" << endl;
    cout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}

void CustomExpressionEvaluator::logToFile(const string& filename) {
    ofstream fout(filename);
    fout << "\tCustomExpressionEvaluator:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    for (size_t i = 0; i < operandsCount - 1; i++) {
        if (i == 0) {
            if (operands[i] > 0)
                fout << operands[i] << " + ";
            else
                fout << "(" << operands[i] << ")" << " + ";
        }
        else if (i == operandsCount - 2) {
            if (operands[i] > 0)
                fout << operands[i] << "*" << operands[i + 1];
            else
                fout << "(" << operands[i] << ")" << "*" << operands[i + 1];
        }
        else {
            if (operands[i] > 0)
                fout << operands[i] << "*" << operands[i + 1] << " + ";
            else
                fout << "(" << operands[i] << ")" << "*" << operands[i + 1] << " + ";
        }
    }
    fout << " <Total: " << operandsCount << " >" << endl;
    fout << "\n < Result: " << calculate() << " >" << "\n" << endl;
}

void CustomExpressionEvaluator::shuffle() {
    double temp; // временная переменная для обмена элементов местами

   // Сортировка массива пузырьком
    for (int i = 0; i < sizeof(operands) - 1; i++) {
        for (int j = 0; j < sizeof(operands) - i - 1; j++) {
            if (operands[j] > operands[j + 1]) {
                // меняем элементы местами
                temp = operands[j];
                operands[j] = operands[j + 1];
                operands[j + 1] = temp;
            }
        }
    }

}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
    if (operands[i] - int(operands[i]) == 0 || operands[j] - int(operands[j]) == 0)
    {
        double temp = operands[i];
        operands[i] = operands[j];
        operands[j] = temp;
    }
}