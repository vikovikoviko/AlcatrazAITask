#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "SortedList.h"
using namespace std;
#define PROBABILITY_OF_RETURNING_MEDIAN 5 //1 in X chance of returning the median
int main()
{
	/* initialize random seed: */
	srand(time(NULL));

	SortedList *data = data->getInstance();

	cout << "Input number N and limit L:\nN - number of operations\nL - range of numbers added\n";
	unsigned int N, L;
	cin >> N >> L;
	for (unsigned int i = 0;i < N;i++)
	{
		bool is_new_number = rand() % PROBABILITY_OF_RETURNING_MEDIAN;//false (0) - return median, true(1,2,3) - add new number
		if (!is_new_number)
		{
			cout << "The median is:";
			cout << data->returnMedian();
			cout << endl;
		}
		else
		{
			int number_to_add = rand() % (2 * L + 1) - L;//generats random number between -L and L
			cout <<"New number to the data: " << number_to_add << endl;
			data->addNewNumber(number_to_add);
		}
	}
	return 0;
}