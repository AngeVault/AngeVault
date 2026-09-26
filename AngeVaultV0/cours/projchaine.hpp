#pragma once
#include <iostream>

struct ProjNodle {
	int dmg;
	ProjNodle* next = nullptr;
};

struct Proj {
	int nbProj = 0;
	ProjNodle* begin;
};


void enter()
{
	std::cout << "appuyer sur entrer pour continuer" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

void addFront(int score, ProjNodle*& first)
{
	ProjNodle* newNode = new ProjNodle;
	newNode->dmg = score;
	newNode->next = first;
	first = newNode;
	std::cout << "score ajoute : " << score << std::endl;
}

void addBack(int score, ProjNodle*& first)
{
	ProjNodle* newNode = new ProjNodle;
	newNode->dmg = score;
	newNode->next = nullptr;
	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		ProjNodle* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	std::cout << "score ajoute : " << score << std::endl;
}

void size(ProjNodle*& first)
{
	int count = 0;
	ProjNodle* current = first;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	std::cout << "taille de la liste : " << count << std::endl;
}

int findBestScore(ProjNodle*& first)
{
	if (first == nullptr)
	{
		std::cout << "liste vide" << std::endl;
		return -1;
	}
	int bestScore = first->dmg;
	ProjNodle* current = first->next;
	while (current != nullptr)
	{
		if (current->dmg > bestScore)
		{
			bestScore = current->dmg;
		}
		current = current->next;
	}
	std::cout << "meilleur score : " << bestScore << std::endl;
	return bestScore;
}

void remooveScore(int score, ProjNodle*& first)
{
	if (first == nullptr)
	{
		std::cout << "liste vide" << std::endl;
		return;
	}
	if (first->dmg == score)
	{
		ProjNodle* temp = first;
		first = first->next;
		delete temp;
		std::cout << "score supprime : " << score << std::endl;
		return;
	}
	ProjNodle* current = first;
	while (current->next != nullptr)
	{
		if (current->next->dmg == score)
		{
			ProjNodle* temp = current->next;
			current->next = current->next->next;
			delete temp;
			std::cout << "score supprime : " << score << std::endl;
			return;
		}
		current = current->next;
	}
	std::cout << "score non trouve" << std::endl;
}

void drawAll(ProjNodle*& first)
{
	std::cout << "======= Draw All liste ======= " << std::endl;
	ProjNodle* current = first;
	while (current != nullptr)
	{
		std::cout << "score : " << current->dmg << std::endl;
		current = current->next;
	}
}

ProjNodle* findScore(int score, ProjNodle*& first)
{
	ProjNodle* current = first;
	while (current != nullptr)
	{
		if (current->dmg == score)
		{
			std::cout << "score trouve : " << current->dmg << std::endl;
			return current;
		}
		current = current->next;
	}
	std::cout << "score non trouve" << std::endl;
}

ProjNodle* remooveFirst(ProjNodle*& first)
{
	if (first == nullptr)
	{
		std::cout << "liste vide" << std::endl;
		return nullptr;
	}
	ProjNodle* temp = first;
	first = first->next;
	std::cout << "score supprime : " << temp->dmg << std::endl;
	delete temp;
	return first;
}

void remooveAll(ProjNodle*& first)
{
	while (first != nullptr)
	{
		remooveFirst(first);
	}
	std::cout << "liste vide" << std::endl;
}

void addProj(Proj& projs)
{
	ProjNodle* newNode = new ProjNodle;
	newNode->dmg = 10;
	newNode->next = projs.begin;
	projs.begin = newNode;
	projs.nbProj++;
}

void removeProj(Proj& projs)
{
	if (projs.begin == nullptr)
	{
		std::cout << "liste vide" << std::endl;
		return;
	}
	ProjNodle* temp = projs.begin;
	projs.begin = projs.begin->next;
	delete temp;
	projs.nbProj--;
}

void testProj()
{
	Proj projs;
	addProj(projs);
	addProj(projs);
	addProj(projs);
	addProj(projs);
	addProj(projs);
	addProj(projs);

	std::cout << "nombre de projectiles : " << projs.nbProj << std::endl;

	removeProj(projs);
	removeProj(projs);

	std::cout << "nombre de projectiles : " << projs.nbProj << std::endl;

}

/*Question 1
Pourquoi avons-nous besoin d'un pointeur next ?
pour acceder au prochaine element de la liste
Question 2
Pourquoi le premier élément de la liste doit-il être
conservé dans une variable particulière ?
afin de pouvoir acceder a la liste et de ne pas perdre le premier element de la liste car .next pointesur le prochaine element de la liste
Question 3
Que représente :
nullptr
que le poiteur est null qu'il est pas initialiser et qu'il ne pointe sur rien
Question 4
Que se passe-t-il si vous oubliez de supprimer un élément
créé avec new ?
fuite de memoire car l'element n'est pas supprimer de la memoire et donc il reste dans la memoire et prend de la place inutilement
Question 5
Pourquoi devons-nous sauvegarder next avant de faire :
delete current;
afin de ne pas perdre la reference du prochain element de la liste et donc de ne pas perdre l'acces a la suite de la liste
dans une liste chaînée ?*/