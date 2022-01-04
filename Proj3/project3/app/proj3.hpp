#ifndef ___PROJECT_3_HPP
#define ___PROJECT_3_HPP

#include <string>
#include <set>
#include <map>
#include "Wordset.hpp"

void loadWordsIntoTable(WordSet & words, std::istream & in);

void recursiveSolver(std::map<std::string, std::set<std::string>>& mapping, std::string s, const WordSet & words, std::map<std::string, std::string>& parent);

std::string convert(std::string s1, std::string s2, const WordSet & words);



#endif
