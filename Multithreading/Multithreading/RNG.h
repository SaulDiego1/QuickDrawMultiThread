#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class RNG //This RNG class doean't inherit from anything making it a base class as well.
{
public:
	void randomNum(int chance); //This will make a random number and has a parameter for the chances of the random number.
	int currentNum; //This will hold the random number.
};