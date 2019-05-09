#include "stdafx.h"
#include "Company.h"

// Statikus tagváltozók inicializálása .cpp fájlban:
// Ide már NEM KELL a static kulcsszó, ide már csak a const KELL!
// Õsosztály
const double Employee::baseSalary = 10000;
// Leszármazottak
const double DivisionManager::divisionManagerSalaryFactor = 1.2;
const double VicePresident::vicePresidentSalaryFactor = 2;
const double President::presidentSalaryFactor = 10;