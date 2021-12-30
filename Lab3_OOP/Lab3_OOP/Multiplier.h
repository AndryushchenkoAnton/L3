#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator {
public:
    double calculate() override;
    void logToFile(const string& filename) override;
    void logToScreen() override;
};