// CalBF_Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "CalcBF.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::string;

struct TestCase {
    double E_eV;
    double T_kelvin;
    double expected;
    string label;
};

bool nearlyEqual(double a, double b, double relTolerance = 1.0E-4) {
    return std::fabs(a - b) <= relTolerance * std::fabs(b);
}

int main()
{
    std::vector<TestCase> tests = {
        {0.026, 300,  3.657794e-01, "room-temp sanity check"},
        {0.10,  300,  2.089652e-02, "shallow trap level"},
        {0.50,  300,  3.984462e-09, "mid-level defect trap"},
        {1.10,  300,  3.317518e-19, "silicon bandgap, 300K"},
        {1.10,  1000, 2.859196e-06, "silicon bandgap, 1000K"},
        {0.05,  77,   5.338469e-04, "LN2 temp"},
        {2.00,  500,  6.932458e-21, "strong thermal barrier"},
        {0.30,  600,  3.020723e-03, "diffusion activation energy"},
        {0.01,  4,    2.515096e-13, "cryogenic regime"},
        {0.80,  1500, 2.051721e-03, "combustion / high-temp catalysis"},
    };

    int passed = 0;
    int failed = 0;

    for (const auto& t : tests) { //'auto' means let the compiler figure out the type automatically. Since tests holds TestCase objects, auto deduces to TestCase
        double result = calculateBF(t.E_eV, t.T_kelvin);
        bool ok = nearlyEqual(result, t.expected);

        std::cout << (ok ? "[PASS] " : "[FAIL] ") << t.label << " | got=" << result << " expected=" << t.expected << std::endl;
        ok ? passed++ : failed++;
    }

    std::cout << "\n" << passed << " passed, " << failed << " failed." << std::endl;
    return failed == 0 ? 0 : 1;  // non-zero exit code signals failure to CI/scripts


    
}


