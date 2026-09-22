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

int main()
{
	int loop = 1;

	while (loop == 1)
	{
		int exo;
		std::cout << "quel exo : " << std::endl;
		std::cin >> exo;
		if (exo == 1)
		{
			std::cout << "==== exo 1 ====" << std::endl;
			exo1();
			exo = 0;
		}
		else if (exo == 2)
		{
			std::cout << "==== exo 2 ====" << std::endl;
			exo2();
			exo = 0;
		}
		else if (exo == 3)
		{
			std::cout << "il n'y as pas d'exo 3 je me bare je suis pas venue ici pour soufire";
			loop = 0;
		}
		else {
			std::cout << "il n'y as pas d'autre exo je me bare je suis pas venue ici pour soufire";
			loop = 0;
		}
	}
}