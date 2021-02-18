#include <vector>

std::vector<int> Merge(std::vector<int> sort1, std::vector<int> sort2)
{
	int size1 = sort1.size();
	int size2 = sort2.size();
	std::vector<int> res;

	for (auto ix = 0, jx = 0; ix < size1 && jx < size2; ++ix, ++jx)
	{
		if (sort1[ix] < sort2[jx])
		{
			res.push_back(sort1[ix]);
			--jx;
		}

		if (sort1[ix] > sort2[jx])
		{
			res.push_back(sort2[jx]);
			--ix;
		}

		if (sort1[ix] == sort2[jx])
		{
			res.push_back(sort1[ix]);
		}
	}
	
	return res;
}

int main()
{
	std::vector<int> vec1 = { 1,6,10,16,19 };
	std::vector<int> vec2 = { 2,3,5,11,15,17,20 };
	Merge(vec1, vec2);
}