#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Divisor : public ExpressionEvaluator, public IShuffle {
public:
    double calculate() override;
    void logToFile(const string& filename) override;
    void logToScreen() override;
    void shuffle() override;
    void shuffle(size_t i, size_t j) override;
};