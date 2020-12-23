#include "Functions.h"
#include <cmath>

using namespace std;

//  4. В машинному слові запрограмуйте функцію перестановки місцями 
//     парних бітів з непарними.Результат перевірте.

struct Word
{
	unsigned int _k;
	struct Word4
	{
		unsigned _bit : 1;
		unsigned _bit_next : 1;
	} _word;
};

inline unsigned int Fourth(const Word& word)
{
	
}