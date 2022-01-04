#include <map>
#include <string>
#include "proj0.hpp"
#include <math.h>
using namespace std;


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
