#include <vector>
#include <limits>
#include <type_traits>
#include <algorithm>
#include <iostream>

using std::vector;


template<typename T>
void countingSort(vector<T>& unsorted, const T minValue, const T maxValue)
{
	// define count space
	const T COUNT_SPACE_SIZE = maxValue - minValue + 1;
	std::vector<T> countSpace(COUNT_SPACE_SIZE, 0);

	// count number of T occurances using T as an index
	for (T& i : unsorted)
		countSpace[i - minValue]++;

	// sort by looking at all non zero counts and transfering 
	// their index to unsorted array	
	size_t j = 0;
	for (T i = 0; i < COUNT_SPACE_SIZE && j < unsorted.size(); ++i)
	{
		while (countSpace[i]-- > 0)
			unsorted[j++] = i + minValue;
	}
}

template<typename T>
void countingSort(vector<T>& unsorted)
{
	static_assert(std::is_integral<T>::value, "Counting sort only works with integer values.");

	// find the max and min values in the unsorted array to calculate count space size
	T minValue = std::numeric_limits<T>::max(), maxValue = std::numeric_limits<T>::min();
	for (const T n : unsorted)
	{
		minValue = std::min(minValue, n);
		maxValue = std::max(maxValue, n);
	}

	// sort
	countingSort(unsorted, minValue, maxValue);
}

template<typename T>
void print(const vector<T>& nums)
{
	for (auto c : nums)
		std::cout << c << " ";
	std::cout << "\n";
}

int main(int argc, char** argv)
{
	vector<int> numbers {-4, 2, 2, 4, 1, 6, 9, 100};
	std::cout << "Unsorted: ";
	print(numbers);

	countingSort(numbers);
	std::cout << "Sorted: ";
	print(numbers);

	return 0;
}
