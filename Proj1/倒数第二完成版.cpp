#include "proj1.hpp"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	string s123 = get_string(s1,s2,s3);
	for(int i = 0;i<s123.size();i++){
		mapping[s123[i]] = 0;
	}
	int string_numi = s123.size();
	int start_i = 0;
	int all_num[10];
	for(int i=0;i<10;i++){
		all_num[i]=i;
	}
	int result[10];
	vector<bool> check_sheet;
	for(int i = 0; i<10;i++){
		check_sheet.push_back(true);
	}
	vector<string> total;
	all_result(start_i, string_numi,all_num,total,result,check_sheet);
	for(int check_total = 0; check_total < total.size();check_total++){
		for(int wordnum = 0; wordnum < s123.size();wordnum++){
			mapping[s123[wordnum]] = char_int(total[check_total][wordnum]);
		}
		if (verifySolution(s1,s2,s3,mapping) == true){
			return true;
		}
		if(check_total == total.size()-1){
			return false;
		}
	}
	return false;
	
}

void all_result(int start_i, int num_char, int all_num[10],vector<string> & total, int result[],vector<bool> check_sheet)
{

	if(start_i!= num_char) 
	{
		for(int i=0;i<10;i++) 
		{
			if(check_sheet[i]==true)
			{
				result[start_i]=all_num[i];
				check_sheet[i]=false;
				all_result(start_i+1,num_char,all_num,total,result,check_sheet);
				check_sheet[i]=true;
			}
		}
	}
	else{
		string new_wor = "";
		for(int i = 0; i < num_char; i++){
			new_wor += to_string(result[i]);
		}
		total.push_back(new_wor);
	}
}

string get_string(std::string s1, std::string s2, std::string s3){
	s1 += s2 + s3;
	string total_string = "";
	for(int i = 0; i< s1.size();i++){
		bool check = true;
		for(int j = 0; j< total_string.size(); j++){
			if(s1[i] == total_string[j]){
				check = false;
			}
		}
		if(check){
			total_string += s1[i];
		}
		
	}
	return total_string;

}


bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{
  int s1_num = 0;
  int s2_num = 0;
  int s3_num = 0;
  int s1_check = 0;
  int s2_check = 0;
  int s3_check = 0;

  for(int i = s1.size()-1; i >= 0; i--){
    if (mapping.count(s1[i]) == 0){
      return false;
    }
    
    s1_num += mapping.at(s1[i]) * pow(10,s1_check);
    s1_check++;

  }
   for(int i =s2.size()-1; i >= 0; i--){
    if (mapping.count(s2[i]) == 0){
      return false;
    }
   
    s2_num += mapping.at(s2[i]) * pow(10,s2_check);
      
    
    s2_check++;

  }
   for(int i =s3.size()-1; i >= 0; i--){
    if (mapping.count(s3[i]) == 0){
      return false;
    }
    s3_num += mapping.at(s3[i]) * pow(10,s3_check);
   
    s3_check++;

   }
   if (s1_num + s2_num == s3_num){
     return true;}
    return false; // FYI, this stub is not a correct solution.
}

int char_int(char the_char){
	if(the_char=='0'){
		return 0;
	}
	else if(the_char == '1'){
		return 1;
	}
	else if(the_char == '2'){
		return 2;
	}
	else if(the_char == '3'){
		return 3;
	}
	else if(the_char == '4'){
		return 4;
	}
	else if(the_char == '5'){
		return 5;
	}
	else if(the_char == '6'){
		return 6;
	}
	else if(the_char == '7'){
		return 7;
	}
	else if(the_char == '8'){
		return 8;
	}
	else{
		return 9;
	}
}