﻿#include <iostream>
using namespace std;
#include "ILoggable.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"
#include "Multiplier.h"
#include "Divisor.h"
//Задание 1. 
//Написать в ООП - стиле код программы, позволяющей работать с арифметическими выражениями разного вида, оперирующими вещественными числами : вычислять результат выражения, выводить запись выражения на консоль и в файл лога.Например, для вычисления выражений вида(10 + 4 + 2 + 3 + 7 + 1) и(1 + 2.5) будет использоваться класс Summator, выражений вида(2 * 3 * 7 * 1) – класс Multiplier, и т.д.
//В коде необходимо отразить следующее :
//Создать интерфейс ILoggable с 2 методами(функционал логирования) :
   // Запись лога всего выражения на консоль :
//void logToScreen()
//Добавление записи лога всего выражения в файл лога :
//void logToFile(const std::string & filename).
//Создать абстрактный класс ExpressionEvaluator, реализующий интерфейс ILoggable и предоставляющий чисто виртуальный метод double calculate() для вычисления результата произвольного выражения.Количество операндов должно храниться в отдельном члене класса.Сами операнды х1, х2, х3 и т.д.должны храниться в члене данного класса – массиве, в куче(динамической памяти).
//Класс ExpressionEvaluator должен предоставлять два конструктора и виртуальный деструктор.В конструкторе без параметров выделять память под 20 операндов и инициализировать их нулями, в конструкторе с параметром n – выделять память под n элементов и инициализировать нулями.Также необходимо реализовать 2 метода, позволяющие присвоить операндам конкретные значения :
//Присвоить значение value одному операнду на позиции pos :
//void setOperand(size_t pos, double value)
//Заполнить сразу группу из n операндов массивом значений ops :
//void setOperands(double ops[], size_t n)
//В деструкторе должна освобождаться память, выделенная в конструкторе.
//Создать два подкласса класса ExpressionEvaluator, работающих со стандартными выражениями, в соответствии с вариантом, из четырех возможных :
//Summator – сумма всех операндов(х1 + х2 + х3 + х4 + ...)
//Subtractor – разность всех операндов(х1 – х2 – х3 – х4 – ...)
//Multiplier – произведение всех операндов(х1* х2* х3* х4 * ...)
//Divisor – частное всех операндов(х1 / х2 / х3 / х4 / ...), но если хоть один
//операнд равен 0, то результату выражения присвоить также 0.
//Создать подкласс CustomExpressionEvaluator, работающий со специфическими выражениями, вид которых приведен в варианте.
//Подклассы ExpressionEvaluator, для которых порядок следования операндов важен, должны также реализовывать интерфейс IShuffle.Данный интерфейс объявляет 2 перегруженных метода(функционал перемешивания операндов) :
  //  Произвольно перемешать операнды :
//void shuffle()
//Перемешать операнды, находящиеся на позициях i и j :
//void shuffle(size_t i, size_t j)
//В функции main() необходимо продемонстрировать работу созданных классов :
//• Создать массив из трех указателей на класс обработки арифметических выражений.
//• В соответствии с вариантом, создать в куче три объекта конкретных подклассов обработки арифметических выражений и установить на них указатели; присвоить их операндам значения двумя способами(поэлементным и групповым).
//• Продемонстрировать полиморфизм : организовать проход в цикле по указателям и вывести лог выражения на консоль и в файл(в консоли отобразить еще и сам результат выражения).
//• Организовать цикл по указателям, в теле которого средствами С++ проверить, реализует ли текущий объект интерфейс IShuffle.Если да, то вызвать один из методов shuffle() этого объекта и отобразить на экране запись выражения после перемешивания операндов, а также вычислить и отобразить результат нового выражения.
//Ниже приведена желательная структура проекта(например, для случая, когда нужно использовать классы Summator и Multiplier) :
   // Примечание.Отрицательные операнды при выводе записи выражения на экран и в файл должны автоматически браться в скобки(подробнее см.приложение В).
/*Вариант 5
Вид выражения CustomExpression : result = x1 + x2 * x3 + x4 * х5 + ...
Порядок создания и инициализации объектов подклассов :
Divisor: 4 операнда, присвоить поэлементно 150, -3, 10, –2.5.
CustomExpressionEvaluator : 5 операндов, присвоить группой 5, 16, -3, 10, 12.
Multiplier : 5 операндов, присвоить группой 1.5, 4, -2.5 - 8, -15.
Метод shuffle() – отсортировать все операнды в порядке возрастания.
Метод shuffle(size_t i, size_t j) – если хотя бы один из i - ого и j - ого операндов
имеет дробную часть, поменять их местами, иначе – не менять.
Формат вывода :
5 + 16 * (-3) + 10 * 12 < Total 5 >
< Result 77 */

int main() {

    double C[] = { 5, 16, -3, 10, 12 }; 
    double S[] = { 1.5, 4, -2.5, 8, -15 }; 

    string filename = "log.txt";
    ExpressionEvaluator* examplesObjects[3];

    examplesObjects[0] = new CustomExpressionEvaluator(); 
    examplesObjects[0]->setOperands(C, 5); 

    examplesObjects[1] = new Multiplier();
    examplesObjects[1]->setOperands(S, 5);

    examplesObjects[2] = new Divisor(); 
    examplesObjects[2]->setOperand(0, 150); 
    examplesObjects[2]->setOperand(1, -3); 
    examplesObjects[2]->setOperand(2, 10);
    examplesObjects[2]->setOperand(3, -2.5);

    for (size_t i = 0; i < 3; i++) {
        examplesObjects[i]->logToFile(filename); 
        examplesObjects[i]->logToScreen(); 
    }

    cout << "\n\nShuffle\n" << endl;
    for (size_t i = 0; i < 3; i++) {

        CustomExpressionEvaluator* customExpression = dynamic_cast<CustomExpressionEvaluator*>(examplesObjects[i]);
        if (customExpression) {
            customExpression->shuffle(); 
            customExpression->logToScreen();
        }

        Divisor* divisor = dynamic_cast<Divisor*>(examplesObjects[i]);
        if (divisor) {
            divisor->shuffle();
            divisor->shuffle(0, 1);
            divisor->logToScreen(); 
        }
    }

    system("pause");
    return 0;
}