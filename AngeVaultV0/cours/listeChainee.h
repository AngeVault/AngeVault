#pragma once
#include <iostream>
typedef struct ScoreNodle ScoreNodle;

struct  ScoreNodle {
	int score;
	ScoreNodle* next = nullptr;
};

void enter()
{
	std::cout << "appuyer sur entrer pour continuer" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

void addFront(int score, ScoreNodle*& first)
{
	ScoreNodle* newNode = new ScoreNodle;
	newNode->score = score;
	newNode->next = first;
	first = newNode;
	std::cout << "score ajoute : " << score << std::endl;
}

void drawAll(ScoreNodle*& first)
{
	std::cout << "======= Draw All liste ======= " << std::endl;
	ScoreNodle* current = first;
	while (current != nullptr)
	{
		std::cout << "score : " << current->score << std::endl;
		current = current->next;
	}
}

ScoreNodle* findScore(int score, ScoreNodle*& first)
{
	ScoreNodle* current = first;
	while (current != nullptr)
	{
		if (current->score == score)
		{
			std::cout << "score trouve : " << current->score << std::endl;
			return current;
		}
		current = current->next;
	}
	std::cout << "score non trouve" << std::endl;
}

ScoreNodle* remooveFirst(ScoreNodle*& first)
{
	if (first == nullptr)
	{
		std::cout << "liste vide" << std::endl;
		return nullptr;
	}
	ScoreNodle* temp = first;
	first = first->next;
	std::cout << "score supprime : " << temp->score << std::endl;
	delete temp;
	return first;
}

void remooveAll(ScoreNodle*& first)
{
	while (first != nullptr)
	{
		remooveFirst(first);
	}
	std::cout << "liste vide" << std::endl;
}

void testListe()
{
	ScoreNodle* first = nullptr;
	addFront(10, first);
	addFront(20, first);
	addFront(30, first);

	drawAll(first);
	enter();

	findScore(20, first);
	enter();

	remooveFirst(first);

	drawAll(first);
	enter();

	remooveAll(first);

	drawAll(first);
	enter();
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