#include <iostream>
#include <vector>


int main()
{
	int numbers[] {3,2,1};
	std::vector<int> vNumbers(numbers, numbers + sizeof(numbers) / sizeof(int) );
	std::vector<int> vCurrentSubseq;
	std::vector<int> vSubseq;

	for (unsigned int i = 1; i < vNumbers.size(); ++i)
	{
		if(vNumbers[i - 1] < vNumbers[i])
		{
			if(vCurrentSubseq.empty())
			{
				vCurrentSubseq.push_back(vNumbers[i -1] );
			}
			vCurrentSubseq.push_back(vNumbers[i]);

			if(vSubseq.size() <= vCurrentSubseq.size())
			{
				vSubseq = vCurrentSubseq;
			}
		}
		else
		{
			if(vSubseq.size() <= vCurrentSubseq.size())
			{
				vSubseq = vCurrentSubseq;
				vCurrentSubseq.clear();
			}

		}


	}

	for(unsigned int i = 0; i < vSubseq.size(); ++i)
	{
		std::cout << vSubseq[i] << " ";
	}

	return 0;
}
