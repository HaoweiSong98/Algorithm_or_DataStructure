#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <map>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping);
void all_result(int start_i, int num_char, int all_num[10],std::vector<std::string> & total, int result[],std::vector<int> check_sheet);
void changeSheet(int sheet_in, std::vector<int> & check_sheet, int step_in);
std::string get_string(std::string s1, std::string s2, std::string s3);
bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping);
int char_int(char the_char);


#endif