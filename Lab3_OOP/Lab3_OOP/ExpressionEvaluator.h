#pragma once
using namespace std;
#include <iostream>
#include <fstream> // for using file input/output
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable {
public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual double calculate() = 0;
	void setOperand(size_t n, double value);
	void setOperands(double* ops, size_t n);
	~ExpressionEvaluator();

protected:
	int operandsCount;
	double* operands;
};