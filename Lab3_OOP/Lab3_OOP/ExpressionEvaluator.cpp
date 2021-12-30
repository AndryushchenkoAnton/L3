#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() {
	operandsCount = 20;
	operands = new double[operandsCount];
	for (size_t i = 0; i < operandsCount; i++) {
		operands[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	operandsCount = n;
	operands = new double[operandsCount];
	for (size_t i = 0; i < operandsCount; i++) {
		operands[i] = 0;
	}
}

void ExpressionEvaluator::setOperand(size_t n, double value) {
	operands[n] = value;
}
void ExpressionEvaluator::setOperands(double* ops, size_t n) {
	for (size_t i = 0; i < n; i++) {
		operands[i] = ops[i];
	}
}

ExpressionEvaluator:: ~ExpressionEvaluator() {
	delete[] operands;
	operandsCount = 0;
}