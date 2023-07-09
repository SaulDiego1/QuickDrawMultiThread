#include <iostream>
#include <cstdlib>
#include <string.h>
#include <Windows.h>
#include <thread>

#include "RNG.h" //This allows for the use of the random feature.
#include "Shoot.h" //This connects to the shoot header.

RNG randomizer{}; //This randomizer is used to have the thread give a random outcome.

int sleepPace = 500;
void quickDraw(bool* loop, bool* shoot) //We will take in pointers as parameters to create conditions on it.
{
	std::cout << "Start!" << std::endl;
	while (*loop == true)
	{
		randomizer.randomNum(100); //The odds of a random number is between 0 and 100.
		if (randomizer.currentNum > 25) //If we roll anything higher than 25 then we print "wait".
		{
			std::cout << "Wait." << std::endl;
			*shoot = false; //The timing for shoot is set to false meaning it would be bad to shoot at this time.
			sleepPace = 500; //The pace is at half a second.
		}
		if (randomizer.currentNum <= 25) //The good response plays if the random number is at 25 or lower.
		{
			std::cout << "Now!" << std::endl;
			*shoot = true;//Shooting now is the good response that we want.
			sleepPace = 750; //The pace is now at x0.75 speed.
		}
		Sleep(sleepPace);//This sleep will wait based on what the sleepPace's value is.
	}
}