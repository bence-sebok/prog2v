#include "stdafx.h"
#include "Company.h"

// Statikus tagv�ltoz�k inicializ�l�sa .cpp f�jlban:
// Ide m�r NEM KELL a static kulcssz�, ide m�r csak a const KELL!
// �soszt�ly
const double Employee::baseSalary = 10000;
// Lesz�rmazottak
const double DivisionManager::divisionManagerSalaryFactor = 1.2;
const double VicePresident::vicePresidentSalaryFactor = 2;
const double President::presidentSalaryFactor = 10;