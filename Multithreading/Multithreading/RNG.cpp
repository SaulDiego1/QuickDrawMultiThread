#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <random>

#include "RNG.h"

using namespace std;

void RNG::randomNum(int chance)
{
	random_device randomizer; //This will create a true random number as opposed to a seed that will be pseudorandom.
	uniform_int_distribution<int> range(0, chance); //This will make a range for the random value. This is set between 0 and the value of chance.
	currentNum = range(randomizer); //We will generate a random number between 0 and whatever value chance is.
}