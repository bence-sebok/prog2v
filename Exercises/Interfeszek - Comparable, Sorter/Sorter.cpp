#include "Sorter.h"

void Sorter::bubbleSort(Comparable** pItems, unsigned itemCount)
{
	for (unsigned j = itemCount; j>0; j--)
	{
		for (unsigned i = 1; i<j; i++)
		{
			if (*pItems[i] < *pItems[i - 1])
			{
				Comparable* tmp = pItems[i];
				pItems[i] = pItems[i - 1];
				pItems[i - 1] = tmp;
			}
		}
	}
}

