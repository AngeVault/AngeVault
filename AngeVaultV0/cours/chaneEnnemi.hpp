#pragma once
#include <iostream>s

struct Ennemi {
	std::string name;
	int hp;
	int dmg;
};

struct EnnemiNode {
	Ennemi ennemi;
	EnnemiNode* next = nullptr;
};

void addEnnemi(EnnemiNode*& first, const std::string& name, int hp, int dmg) {
	EnnemiNode* newNode = new EnnemiNode;
	newNode->ennemi.name = name;
	newNode->ennemi.hp = hp;
	newNode->ennemi.dmg = dmg;
	newNode->next = first;
	first = newNode;
	std::cout << "Ennemi ajoute : " << name << std::endl;
}

void drawAllEnnemis(EnnemiNode*& first) {
	std::cout << "======= Ennemis ======= " << std::endl;
	EnnemiNode* current = first;
	while (current != nullptr) {
		std::cout << "Nom : " << current->ennemi.name << ", HP : " << current->ennemi.hp << ", DMG : " << current->ennemi.dmg << std::endl;
		current = current->next;
	}
}

void totalEnnemisHp(EnnemiNode*& first) {
	int totalHp = 0;
	EnnemiNode* current = first;
	while (current != nullptr) {
		totalHp += current->ennemi.hp;
		current = current->next;
	}
	std::cout << "Total HP des ennemis : " << totalHp << std::endl;
}

void removeLastEnnemi(EnnemiNode*& first) {
	if (first == nullptr) {
		std::cout << "Liste vide" << std::endl;
		return;
	}
	if (first->next == nullptr) {
		std::cout << "Ennemi supprime : " << first->ennemi.name << std::endl;
		delete first;
		first = nullptr;
		return;
	}
	EnnemiNode* current = first;
	while (current->next->next != nullptr) {
		current = current->next;
	}
	std::cout << "Ennemi supprime : " << current->next->ennemi.name << std::endl;
	delete current->next;
	current->next = nullptr;
}

void removeAllEnnemis(EnnemiNode*& first) {
	while (first != nullptr) {
		removeLastEnnemi(first);
	}
	std::cout << "Tous les ennemis ont ete supprimes" << std::endl;
}

int testEnnemi() {
	EnnemiNode* first = nullptr;
	addEnnemi(first, "ZipZapZoop", 30, 5);
	addEnnemi(first, "Orc", 50, 10);
	addEnnemi(first, "Clement", 200, 25);
	drawAllEnnemis(first);
	totalEnnemisHp(first);
	removeLastEnnemi(first);
	drawAllEnnemis(first);
	totalEnnemisHp(first);
	removeAllEnnemis(first);
	drawAllEnnemis(first);
	return 0;
}

int testEnnemiVector() {
	std::vector<Ennemi> ennemis;
	ennemis.push_back({ "ZipZapZoop", 30, 5 });
	ennemis.push_back({ "Orc", 50, 10 });
	ennemis.push_back({ "Clement", 200, 25 });
	std::cout << "======= Ennemis ======= " << std::endl;
	for (const auto& ennemi : ennemis) {
		std::cout << "Nom : " << ennemi.name << ", HP : " << ennemi.hp << ", DMG : " << ennemi.dmg << std::endl;
	}
	int totalHp = 0;
	for (const auto& ennemi : ennemis) {
		totalHp += ennemi.hp;
	}
	std::cout << "Total HP des ennemis : " << totalHp << std::endl;
	return 0;
}

// quelles parties du programme ont disparu lorsque vous êtes passé au vector ?
// la creation des fonction pour add ou remoove