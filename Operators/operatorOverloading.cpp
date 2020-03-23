/*
A lenti operátor használata:
Vector<int> egeszek;
// egeszek tároló feltöltése elemekkel
Vector<int> nagyobb_egeszek = 5 * egeszek; // SORREND!!!
*/
template <typename T>
Vector<T>& operator* (T scalar, const Vector<T>& vector)
{
	Vector<T> v = vector;
	int vectorSize = v.size();
	for (int i = 0; i < vectorSize; i++)
	{
		v[i] = scalar * v[i];
	}
	return v;
} 

/* T típussal szemben támasztott követelmények
- operator*
- operator=
- másoló konstruktor
*/