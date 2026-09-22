#include "iostream.h"
#include "refConstFonc.h"
#include "listeChainee.h"
#include <iostream>

typedef enum Cours {
	IOSTREAM = 1,
	REFCONSTFONC = 2,
	LISTECHAINEE = 3
}Cours;



int main()
{
	int loop = 1;

	int cours = 0;

	while (loop == 1)
	{
		std::cout << "quel cours : \n" 
			<< "iostream : 1 \n"
			<< "refConstFonc : 2"<< std::endl;
		std::cin >> cours;

		if (cours == IOSTREAM)
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
				cours = 0;
			}
			else {
				std::cout << "il n'y as pas d'autre exo je me bare je suis pas venue ici pour soufire";
				cours = 0;
			}
		}
		else if (cours == REFCONSTFONC)
		{
			int exo;
			std::cout << "quel exo : " << std::endl;
			std::cin >> exo;

			if (exo == 1)
			{
				std::cout << "20 et 20 " << std::endl;
				exo = 0;
			}
			else if (exo == 2)
			{
				refExo2();
				exo = 0;
			}
			else if (exo == 3)
			{
				exo3();
				exo = 0;
			}
			else if (exo == 4)
			{
				exo4();
				exo = 0;
			}
			else if (exo == 5)
			{
				exo5();
				exo = 0;
			}
			else 
			{
				cours = 0;
			}
		}
		else if (cours == LISTECHAINEE)
		{
			testListe();
			cours = 0;
		}
		else
		{
			loop = 0;
		}
	}
}