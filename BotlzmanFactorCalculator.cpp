// BotlzmanFactorCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CalcBF.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
	// User enters a temperature in Kelvin and an energy in eV then gets the Boltzmann Factor 
    std::cout << "Welcome to the Boltzmann Factor Caculcator!\n";

	double TfromUser;
	double EfromUser;
	double AF;


	std::cout << "Select a temperature (in Kelvin) for the effect you would like to study.";
	std::cin >> TfromUser;
	std::cout << "OK, you selected " << TfromUser;

	std::cout << "Select an energy for the effect you would like to study. \n (NOTE: you must use Electron-volts (eV) or the results will not be accurate)";
	std::cin >> EfromUser;
	std::cout << "OK, you selected " << EfromUser;

	AF = calculateBF(EfromUser, TfromUser);

	std::cout << "Boltzmann Factor: " << AF ;

	return 0;
}


