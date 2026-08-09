

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>;


constexpr double BOLTZMANN_CONSTANT = 1.380649e-23; // J/K (exact, SI 2019 definition)
constexpr double EV_TO_JOULES = 1.602176634e-19;

double calculateBF(double E_eV, double T_kelvin) {
	double E_joules = E_eV * EV_TO_JOULES;
	double BF = std::exp(-E_joules / (BOLTZMANN_CONSTANT * T_kelvin));
	return BF;
}