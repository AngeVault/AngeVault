#include <iostream>

typedef struct Player {
	int pv;
	float def;
	float dmg;
}Player;

// exo 1 é((
// le programe renvoie 20 et 20

//exo 2 : 
void swap(int& a,  int& b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}

void refExo2()
{
	int a;
	int b;

	std::cout << "valeur de a : " << std::endl;
	std::cin >> a;
	std::cout << "valeur de b : " << std::endl;
	std::cin >> b;

	swap(a, b);
	std::cout << "valeur de a : "  << a << std::endl;
	std::cout << "valeur de b : " << b << std::endl;
}

// exo 3 : 

void heal(Player& player, int heal = 10)
{
	player.pv += heal;
	return;
}

void exo3() 
{
	int pv;
	std::cout << "quel sont les pv du joueur : " << std::endl;
	std::cin >> pv;
	int healAmmount;
	std::cout << "quel sont les pv que vous voulez rendre au joueur : " << std::endl;
	std::cin >> healAmmount;

	Player player{ pv,10,30 };
	heal(player, healAmmount);
	std::cout << "health " << player.pv << std::endl;
	return;
}

// exo 4

void printPlayer(const Player& player)
{
	std::cout << " === stat === \n"
		<< "\t pv : " << player.pv << "\n"
		<< "\t def : " << player.def << "\n"
		<< "\t dmg : " << player.dmg << std::endl;
	return;
}

void exo4() 
{
	Player player;
	std::cout << "quel sont les pv du joueur : " << std::endl;
	std::cin >> player.pv;
	std::cout << "quel sont la def du joueur : " << std::endl;
	std::cin >> player.def;
	std::cout << "quel sont les dmg du joueur : " << std::endl;
	std::cin >> player.dmg;

	printPlayer(player);
	return;
}

// exo 5 

int calculateDamage(const Player& player, const float def = 10.f)
{
	if ((player.dmg - def) <= 0.f)
		return 0;
	return player.dmg - def;
}

void exo5()
{
	Player player;
	float def;
	std::cout << "quel sont les dmg du joueur : " << std::endl;
	std::cin >> player.dmg;
	std::cout << "quel est la def de l'adversaire : " << std::endl;
	std::cin >> def;


	int calc = calculateDamage(player, player.def);
	std::cout << "return :  " << calc << std::endl;


	return;
}