#include <iostream>
#include <cstdlib>
#include <string.h>
#include <Windows.h>
//To use threads we will include the thread library into this program.
#include <thread>

#include "RNG.h"
#include "Shoot.h"

//These are global variables to use anywhere in this file.
bool enemy1Loop = true; //This bool will control the loop.
bool enemy1shoot; //This bool will control if the timing was correct.
bool enemy2Loop = true;
bool enemy2shoot;
bool enemy3Loop = true;
bool enemy3shoot;

int main()
{
	//Intro
	std::cout << "\t\tWelcome to" << endl;
	std::cout << "\t***Sharp Shooter Multithreader***" << endl;
	std::cout << "\nIn this game you are a wandering cowboy. You've been searching night and day for an oasis." << endl;
	std::cout << "Luckily for you, you manage to reach a small town that has a bar where you can get a drink." << endl;
	std::cout << "Unfortunately the local refused service to you." << endl;
	std::cout << "In order to quench your thirst you challenge the Shariff to a shoot off." << endl;
	std::cout << "The winner drinks. The loser swims with fishes." << endl;
	std::cout << "When you're ready to begin press enter. May luck be with you." << endl;
	std::cin.get(); //This will wait for a response to begin the program.

	//Act 1
	std::thread ShariffDuel(quickDraw, &enemy1Loop, &enemy1shoot); //This is the thread that will run until it is over.
	std::cin.get(); //Since we are using a seperate thread, we can give an input while this is running.
	if (enemy1shoot == true) //If our timing is correct then we will get a win.
	{
		std::cout << "You Win!" << std::endl;
		enemy1Loop = false; //This ends the loop.
	}
	else if (enemy1shoot == false) //If the timing is poor then we lose.
	{
		std::cout << "You shot too early!" << std::endl;
		enemy1Loop = false; //This ends the loop.
		std::cout << "The shariff hit his target on the dot! You!" << std::endl;
		std::cout << "\t\t***Game Over***" << std::endl;
		ShariffDuel.join(); //This will wait for the thread. 
		return 0;
	} 
	ShariffDuel.join(); //Making a thread without this may cause errors.

	//Act 2
	std::cout << "You walk to the bar and get a refreshing drink." << std::endl;
	std::cout << "\n***New Day***" << std::endl;
	std::cout << "\nGoing back to wandering the country you find yourself in front of camp filled with bandits!" << std::endl;
	std::cout << "You decide that you can use some pocket change and challenged the leader to a duel." << std::endl;
	std::cout << "When you're ready to begin press enter. May luck be with you." << endl;
	std::cin.get();
	enemy1Loop = true;
	std::thread banditDuel(quickDraw, &enemy1Loop, &enemy1shoot); //I make a new thread in the same way as the previous.
	std::cin.get(); //we will aim to press enter at the right time.
	if (enemy1shoot == true) //Win condition
	{
		std::cout << "You Win!" << std::endl;
		enemy1Loop = false;
	}
	else if (enemy1shoot == false) //Lose condition
	{
		std::cout << "You shot too early!" << std::endl;
		enemy1Loop = false;
		std::cout << "The bandit hit his target on the dot! You!" << std::endl;
		std::cout << "\t\t***Game Over***" << std::endl;
		banditDuel.join(); //End the game and the thread.
		return 0;
	}
	banditDuel.join();

	//Act 3
	std::cout << "\nThe rest of the bandits flee and you're made a wealthy cowboy!" << std::endl;
	std::cout << "However, you have also become infamous and now have a target on your back." << std::endl;
	std::cout << "Three mercenaries come to defeat you. This time you must challenge them all." << std::endl;
	std::cout << "When you're ready to begin press enter. May luck be with you." << endl;
	std::cin.get();
	enemy1Loop = true;

	//For this final act we will have three threads multitasking and working at the same time.
	std::thread enemy1Duel(quickDraw, &enemy1Loop, &enemy1shoot);
	std::thread enemy2Duel(quickDraw, &enemy2Loop, &enemy2shoot);
	std::thread enemy3Duel(quickDraw, &enemy3Loop, &enemy3shoot);
	//To hit each one we give the player three shots to do so.
	std::cin.get();
	std::cin.get();
	std::cin.get();

	//This condition is made exclusively for the first enemy.
	if (enemy1shoot == true)
	{
		std::cout << "Yahtzee! You took one down!" << std::endl;
		enemy1Loop = false;
	}
	else if (enemy1shoot == false)
	{
		std::cout << "You shot too early!" << std::endl;
		//To avoid every other loop playing while the game is over we will shut them all off.
		enemy1Loop = false;
		enemy2Loop = false;
		enemy3Loop = false;
		std::cout << "Your epic tale ends here. Not every mercenary was gunned." << std::endl;
		std::cout << "\t\t***Game Over***" << std::endl;
		//We also need to add a join for every thread to avoid errors.
		enemy1Duel.join();
		enemy2Duel.join();
		enemy3Duel.join();
		return 0; //This ends the program with 0 errors.
	}

	//Enemy 2 conditions.
	if (enemy2shoot == true)
	{
		std::cout << "Yahtzee! You took one down!" << std::endl;
		enemy2Loop = false;
	}
	else if (enemy2shoot == false)
	{
		std::cout << "You shot too early!" << std::endl;
		enemy1Loop = false;
		enemy2Loop = false;
		enemy3Loop = false;
		std::cout << "Your epic tale ends here. Not every mercenary was gunned." << std::endl;
		std::cout << "\t\t***Game Over***" << std::endl;
		enemy1Duel.join();
		enemy2Duel.join();
		enemy3Duel.join();
		return 0;
	}

	//Enemy 3 conditions.
	if (enemy3shoot == true)
	{
		std::cout << "Yahtzee! You took one down!" << std::endl;
		enemy3Loop = false;
	}
	else if (enemy3shoot == false)
	{
		std::cout << "You shot too early!" << std::endl;
		enemy1Loop = false;
		enemy2Loop = false;
		enemy3Loop = false;
		std::cout << "Your epic tale ends here. Not every mercenary was gunned." << std::endl;
		std::cout << "\t\t***Game Over***" << std::endl;
		enemy1Duel.join();
		enemy2Duel.join();
		enemy3Duel.join();
		return 0;
	}
	//If we win then the threads will end with these join().
	enemy1Duel.join();
	enemy2Duel.join();
	enemy3Duel.join();

	//The end
	std::cout << "You walk away into legend." << std::endl;
	std::cout << "\t\t***You Win!***" << std::endl;
}
