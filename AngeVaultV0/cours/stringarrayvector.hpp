#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>

// exo 1 :
void allexo1()
{
	int* us = new int;
	std::cout << "un nombre : " << std::endl;
	std::cin >> *us;
	std::cout << "nombre = " << *us << " memoire = " << us << std::endl;
	*us = 10;
	std::cout << "nombre = " << *us << std::endl;
	delete us;
	us = nullptr;
}

// exo 2 

int moyenne(int* tab, int nb)
{
	int mid = 0;
	for (int i = 0; i < nb; i++)
	{
		mid += tab[i];
	}
	return mid / nb;
}

void allexo2()
{
	std::cout << "combien de scores vous souhaite saisir :" << std::endl;
	int us;
	std::cin >> us;
	int* tab = new int[us];
	for (int i = 0; i < us; i++)
	{
		std::cout << " sorce " << i << " : " << std::endl;
		std::cin >> tab[i];
	}
	std::cout << " moyenne : " << moyenne(tab, us);

	delete[] tab;
	tab = nullptr;
}

// exo 3 listeChainee.h

// exo 4

/*
1. Que devient la mémoire initialement
allouée pour a ?
elle fuite
2. Que devient la mémoire de b ?
elle est supprimé 
3. Le programme contient-il une fuite
mémoire ?
oui 
4. Que pourrait-il se passer si nous
utilisions b après delete a ?
une erreur car la memoire aloué a b as été delete
*/

// exo 5 
struct VProj
{
	int dmg;
};

void allexo5()
{
	std::vector<VProj> tab;

	tab.push_back({ 10 });
	tab.push_back({ 20 });
	tab.push_back({ 30 });
	tab.push_back({ 40 });

	tab.pop_back();
}
/*
quelle solution choisiriez-vous pour un véritable
projet ?
le vector
Pourquoi ?
plus simple 
*/

// exo 6

/*
n étudiant affirme :
« Maintenant qu'on a appris std::vector,
on n'a plus besoin de savoir faire une
liste chaînée. »
Êtes-vous d'accord ?
non
car en fonction des circonstance une liste chainé peut nous servire niveau optimisation et controle pure la liste chaînée  
mais le vecteur est plus simple d'utilisation et evite les erreurs technique 


Donnez au moins deux arguments techniques
pour défendre votre réponse.
*/