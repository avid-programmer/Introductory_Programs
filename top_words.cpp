#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
	std::ifstream fileStream("read.txt");
	std::string word;
	std::map<std::string, int> wordCount;

	while (fileStream >> word) 
	{
		std::transform(word.begin(), word.end(), word.begin(), 
					   [](unsigned char c) { return std::tolower(c); });
		
		++wordCount[word];
	}	

	std::vector<std::pair<std::string, int>> wordCountVector;
	copy(wordCount.begin(), wordCount.end(), std::back_inserter(wordCountVector));
	std::sort(wordCountVector.begin(), wordCountVector.end(), 
			  [] (std::pair<std::string, int> p1, std::pair<std::string, int> p2)
			  {
			      return p1.second > p2.second;
			  });


	int iter_count = std::min(10, static_cast<int>(wordCountVector.size()));

	if (iter_count) 
	{
		std::cout << "Top 10 words of the file are: " << std::endl;
	}

	for (int i = 0; i < iter_count; ++i)
	{
		std::cout << wordCountVector[i].first << std::endl;
	}
}
