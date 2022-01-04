#include "proj3.hpp"
#include "Wordset.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

// You should not need to change this function.
void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;
	//int i = 0;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		//i++;
		while( ss >> word )
		{
			words.insert( word );
			//std::cout << word << ' ' << i << std::endl;
		}
	}

}

void recursiveSolver(std::map<std::string, std::set<std::string>>& mapping, std::string s, const WordSet & words, std::map<std::string, std::string>& parent)
{
	std::set<std::string> adj;
	for (int i = 0; i < s.size(); i++)
	{
		std::string copy = s; 
		for (int j = 0; j < 26; j++)
		{
			copy[i] = j  + 'a';
			if (copy != s)
			{
				if (words.contains(copy))
				{
					adj.insert(copy);
					parent[copy] = "9";
				}
			}
		}
	}
	mapping[s] = adj;

	for (auto i = adj.begin(); i != adj.end(); i++)
	{
		if (mapping.count(*i) == 0)
		{
			recursiveSolver(mapping, *i, words, parent);
		}
	}
}


std::string convert(std::string s1, std::string s2, const WordSet & words)
{
	std::map<std::string, std::string> parent; //map shows parent node
	std::map<std::string, std::set<std::string>> mapping; //Graph map
	recursiveSolver(mapping, s1, words, parent);

	std::queue<std::string> frontierQueue; //Queue
	std::set<std::string> visited; //Visited Set
	std::string current;

	//BFS
	frontierQueue.push(s1);
	visited.insert(s1);

	while (frontierQueue.empty() != true)
	{
		current = frontierQueue.front();
		frontierQueue.pop();

		for (auto i = mapping[current].begin(); i != mapping[current].end(); i++)
		{
			if (visited.count(*i) == 0)
			{
				frontierQueue.push(*i);
				visited.insert(*i);
				parent[*i] = current;
			}
		}
	}

	//Showing Result
	std::string result = s2;
	current = s2;
	while (current != s1)
	{
		result = parent[current] + " --> " + result;
		current = parent[current];
	}

	return result;

}
