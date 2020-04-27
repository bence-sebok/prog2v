#pragma once
#include <iostream>
#include "vector.hpp"
#include "state.hpp"
#include "rule.hpp"

// TODO: template
template<class LABEL_TYPE, class INPUT_TYPE>
class FiniteAutomaton
{
	// Szóköz nélkül a C++98 fordító shift operátornak értelmezné.
	// Egy Vector, amiben a szabályokat tároljuk.
	Vector< Rule<LABEL_TYPE, INPUT_TYPE> > rules;

	// Egy Vector, amiben a véges automata állapotait tároljuk.
	Vector< State<LABEL_TYPE> > states;

	// Rámutatunk az aktuális állapotra. Konstans, hogy tudjunk mutatni
	// a Rule::getNextState() által visszaadott állapotra.
	const State<LABEL_TYPE>* currentState;
public:
	// Megadjuk a kezdő állapotot konstruktorban.
	FiniteAutomaton(State<LABEL_TYPE>& startState) : currentState(&startState)
	{
		// 1. Hozzáadjuk az állapotokhoz a kezdőállapotot.
		addState(startState);
	}

	// Hozzáadhatunk egy új állapotot.
	// Konstans, hogy át tudjunk adni konstanst.
	void addState(const State<LABEL_TYPE>& state)
	{
		// 1. Beszúrjuk a states-be a paraméterként megkapott state-t.
		states.insert(states.size(), state);
	}

	// Hozzáadhatunk új szabályt.
	// Konstans, hogy át tudjunk adni konstanst.
	void addRule(const Rule<LABEL_TYPE, INPUT_TYPE>& rule)
	{
		// 1. Beszúrjuk a rules-ba a paraméterként megkapott rule-t.
		rules.insert(rules.size(), rule);
	}

	// A paraméterként kapott inputon futtatjuk az véges automatát.
	bool run(const Vector<INPUT_TYPE>& input)
	{
		// 1. Végigmegyünk a bemeneten.
		for(unsigned int i = 0; i < input.size(); i++)
        {
            //std::cout << "i = " << i << std::endl;
			// 1.1. Diagnosztikai célból írassuk ki az aktuális állapotot.
			std::cout << "Current state before rule matching: " << *currentState << std::endl;

			// 1.2. Mivel azt is ellenőriznünk kell, hogy van-e egyáltalán illeszkedő (matched) szabály
			// az aktuális állapotra és most következő bemenetre, vegyük úgy alapból, hogy
			// nincs illeszkedés. Ezzel a változóval ellenőrizhető, hogy a véges automata állapotátmenetei
			// hiányosan lettek-e specifikálva vagy sem.
			bool matched = false;

			// 1.3. Menjünk végig az összes szabályon, de korábban is megállhatunk,
			// ha már találtunk illeszkedő szabályt.
            for(unsigned int j = 0; j < rules.size() && matched == false; j++)
            {
				// 1.3.1. Ha van illeszkedés (match) a j. szabállyal:
                if(rules[j].match(*currentState, input[i]) == true)
                {
                    std::cout << "Matched rule!" << std::endl;
                    std::cout << "Current state: " << *currentState << std::endl;
                    std::cout << "Input: " << input[i] << std::endl;
                    std::cout << "Next state: " << rules[j].getNextState() << std::endl;
                    // 1.3.1.1. Az aktuális állapot legyen egyenlő a szabályban tárolt következő lehetséges állapottal.
                    currentState = &rules[j].getNextState();
                    std::cout << "New current state after rule matching: " << *currentState << std::endl << std::endl;
                    // 1.3.1.2. Ne felejtsük el feljegyezni, hogy van illeszkedő szabály (1.2.)
                    matched = true;
                }
            }
			// 1.4. Ha nem volt illeszkedő szabály, tehát a véges automata elakadt, nem tudott továbbmenni, térjünk vissza hamissal.
			if(matched == false)
            {
                return false;
            }
        }
		// 2. Írassuk ki az aktuális állapotot.
		std::cout << "Current state after processing all inputs: " << *currentState << std::endl << std::endl;

		// 3. Térjünk vissza igazzal, ha az aktuális állapot elfogadó volt, különben hamissal.
		return currentState->isAccepting();
	}
};
