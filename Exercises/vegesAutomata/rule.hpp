#pragma once
#include "state.hpp"

// TODO: template
template<class LABEL_TYPE, class INPUT_TYPE>
class Rule
{
	// Ha referencia lenne, nem lehetne operator=-t írni úgy, hogy a Vector-ban ne pointereket tároljunk.
	// Ami ugyan jó megoldás lenne, csak kicsit bonyolultabb.
	// Konstans, hogy tudjunk mutatni a konstans konstruktor paraméterre.
	const State<LABEL_TYPE>* state;

	INPUT_TYPE input; // A bemeneti szekvencia egy eleme.

	const State<LABEL_TYPE>* nextState; // A következő állapot, ahova ugorhatunk.
public:
	// TODO: Ide jön egy konstruktor
	Rule(const State<LABEL_TYPE>& state = State<LABEL_TYPE>(), const INPUT_TYPE& input = INPUT_TYPE(), const State<LABEL_TYPE>& nextState = State<LABEL_TYPE>()):
	    state(&state), input(input), nextState(&nextState) {}

	// Akkor találunk egyezést a szabállyal, ha a megadott jelenlegi állapot
	// megegyezik a tárolt állapottal, valamint a most érkezett bemeneti elem
	// megegyezik a tárolt inputtal.
	bool match(const State <LABEL_TYPE>& currentState, const INPUT_TYPE& currentInput)
	{
		// 1. Visszatérés igenne, ha matchel, ellenkező esetben hamissal.
		return (currentState == *state && currentInput == input);
	}

	// Visszaadjuk a következő állapotot. Konstanst ad vissza,
	// hogy semmiképp se tudjuk módosítani a nextState-t.
	const State<LABEL_TYPE>& getNextState() const
	{
		// 1. Visszatérés
		return *nextState; // pointer --> dereferálás --> objektum
	}

	// Megjegyzés: most megelégszünk az alapértelmezett operator=-vel
	// (ami egyébként kell a Vector dinamikus adatkezelése miatt).
};
