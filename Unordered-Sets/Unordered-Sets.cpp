#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


/*
	All operations on un-ordered sets take O(1) on average.

	Traditional, ordered sets maintain a balanced tree structure
	which leads allows sets to maintain order.

	Set operations = O(log n)
	Un-ordered set operations = O(1)
*/
class unorderedSetOperations
{
public:

	static void unorderedSetFindKey(std::unordered_set<std::string> x, std::string key)
	{
		if (x.find(key) == x.end())
		{
			std::cout << key << " not found" << "\n\n";
		}
		else
		{
			std::cout << "Found " << key << "\n\n";
		}
	}

	static void unorderedSetIterate(std::unordered_set<std::string> x)
	{
		std::unordered_set<std::string>::iterator itr;

		for (itr = x.begin(); itr != x.end(); itr++)
		{
			std::cout << (*itr) << "\n";
		}

		std::cout << "\n";
	}

	static void unorderedSetFindDupes(std::vector<int> v, int n)
	{
		std::unordered_set<int> src;
		std::unordered_set<int> dest;
		
		for (int i = 0; i < n; i++)
		{
			if (src.find(v[i]) == src.end())
			{
				src.insert(v[i]);
			}
			else
			{
				dest.insert(v[i]);
			}
		}

		std::cout << "Dupes: ";
		std::unordered_set<int>::iterator itr;

		for (itr = dest.begin(); itr != dest.end(); itr++)
		{
			std::cout << *itr << " ";
		}
	}
};



int main()
{
	std::unordered_set<std::string> stringSet;

	stringSet.insert("foo");
	stringSet.insert("Bar");

	unorderedSetOperations::unorderedSetFindKey(stringSet, "test");
	unorderedSetOperations::unorderedSetFindKey(stringSet, "foo");

	unorderedSetOperations::unorderedSetIterate(stringSet);

	std::vector<int> vctr = { 6,7,3,5,7,4,9,5,8,9,1,4,3 };
	int n = vctr.size();

	unorderedSetOperations::unorderedSetFindDupes(vctr, n);

	return 0;
}