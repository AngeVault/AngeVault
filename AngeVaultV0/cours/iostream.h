#pragma once
#include <iostream>

void exo1()
{
	int health;
	int damage;
	std::cout << "Enter Player health" << std::endl;
	std::cin >> health;
	std::cout << "enter les damage" << std::endl;
	std::cin >> damage;
	health -= damage;
	std::cout << "vie restantante :" << damage << std::endl;
	if (health <= 0)
	{
		std::cout << "vous êtes mort" << std::endl;
	}
	return;
}

void exo2()
{
	char name[20];
	int pv;
	int dmg;
	int def;

	std::cout << "enter nom player :" << std::endl;
	std::cin >> name;
	std::cout << "enter pv player :" << std::endl;
	std::cin >> pv;
	std::cout << "enter degat player :" << std::endl;
	std::cin >> dmg;
	std::cout << "enter def player :" << std::endl;
	std::cin >> def;

	std::cout << " ===== PLAYER ===" << std::endl
		<< "name : " << name << std::endl
		<< "pv : " << pv << std::endl
		<< "dmg : " << dmg << std::endl
		<< "def : " << def << std::endl
		<< " ===============" << std::endl;
}