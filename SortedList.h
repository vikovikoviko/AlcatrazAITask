#pragma once
#include <vector>
using namespace std;
class SortedList
{
private:
	vector<double> data;
	static SortedList* instance;//singleton design pattern
	// Private constructor so that no objects can be created.
	SortedList() {}
	void sortTheLastElement()
	{
		int position = data.size() - 1;
		while (position >= 1 and data[position] < data[position - 1])
		{
			swap(data[position], data[position - 1]);
			position--;
		}
	}
public:
	static SortedList* getInstance() {
		if (!instance)
			instance = new SortedList;
		return instance;
	}
	void addNewNumber(double new_number)
	{
		data.push_back(new_number);
		sortTheLastElement();
	}
	double returnMedian()const 
	{
		if (data.size() == 0)
		{
			return 0;
		}
		if (data.size() % 2 == 1)
		{
			return data[data.size() / 2];
		}
		//else
		return (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2;
	}
};
//Initialize pointer to zero so that it can be initialized in first call to getInstance
SortedList* SortedList::instance = 0;