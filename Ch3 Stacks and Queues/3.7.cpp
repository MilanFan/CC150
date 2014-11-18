/*
 * 3.7.cpp
 *
 * An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out" basis.
 * People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they
 * can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type).
 * They cannot select which specific animal they would like. Create the data structures to maintain this
 * system and implement operations such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may use
 * the built-in LinkedList data structure.
 *
 *  Created on: Nov 18, 2014
 *      Author: Milan Fan
 */

#include <iostream>
#include <queue>
using namespace std;

class Animal {
private:
	int order;
	char type;

public:

	Animal(int o, char t) : order(o), type(t) {};
	Animal() : order(0), type('U') {};

	int getOrder() {
		return order;
	}

	char getType() {
		return type;
	}

	bool isOlderThan(Animal a) {
		return this->order < a.getOrder();
	}
};

class AnimalQueue {
	queue<Animal> dog, cat;
	int order = 0;

public:
	void enqueue(char c)
	{
		if (c == 'd' || c == 'D')
			dog.push(Animal(++order, 'D'));
		else if (c == 'c' || c == 'C')
			cat.push(Animal(++order, 'C'));
		else
			cout << "Unknown animal.";
	}

	Animal dequeueDog()
	{
		if (dog.empty()) {
			cout << "No more dogs." << endl;
			return Animal();
		}
		Animal d = dog.front();
		dog.pop();
		return d;
	}

	Animal dequeueCat()
	{
		if (cat.empty()) {
			cout << "No more cats." << endl;
			return Animal();
		}
		Animal c = cat.front();
		cat.pop();
		return c;

	}

	Animal dequeueAny()
	{
		if (dog.empty() && cat.empty()) {
			cout << "No more animals." << endl;
			return Animal();
		}
		if (dog.empty() || cat.front().isOlderThan(dog.front()))
			return dequeueCat();
		return dequeueDog();
	}
};

int main()
{
	AnimalQueue aq;
	int cmd;
	char c;
	Animal a;

	while (true) {
		cin >> cmd;
		if (cmd < 1 || cmd > 4) break;
		switch (cmd) {
		case 1:
			cin >> c;
			aq.enqueue(c);
			cout << "enqueue:\t" << c << endl;
			break;
		case 2:
			cout << "dequeueAny: ";
			a = aq.dequeueAny();
			if (a.getOrder() > 0) cout << a.getType() << endl;
			break;
		case 3:
			cout << "dequeueDog: ";
			a = aq.dequeueDog();
			if (a.getOrder() > 0) cout << a.getType() << endl;
			break;
		case 4:
			cout << "dequeueCat: ";
			a = aq.dequeueCat();
			if (a.getOrder() > 0) cout << a.getType() << endl;
			break;
		default:
			break;
		}
	}
	cout << "End" << endl;

	return 0;
}

