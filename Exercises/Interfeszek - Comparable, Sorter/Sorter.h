// #pragma once
#ifndef SORTER_H
#define SORTER_H

#include "Comparable.h"

class Sorter {
public:
    static void bubbleSort(Comparable** pItems, unsigned itemCount);
};

#endif // SORTER_H
