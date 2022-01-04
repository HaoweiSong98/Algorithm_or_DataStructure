#include <iostream>

using namespace std;

string get_string(std::string s1, std::string s2, std::string s3){
	s1 += s2 + s3;
	string total_string = "";
	for(int i = 0; i< s1.size();i++){
		bool check = true;
		for(int j = i+1; j< total_string.size(); j++){
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

int check_next(int i){
	i++;
	bool check_ = true;
	string i_s = to_string(i);
	for(int j = 0; j<i_s.size(); j++){
		for(int p = j+1;p<i_s.size();p++){
			if(i_s[j] == i_s[p]){
				int new_n = stoi(i_s);
			
				return check_next(new_n);
			}
	
			}
	}
	return stoi(i_s);
}

int main(int argc, char *argv[]) {
	for(int i=123465078; i< 938291176;i++){
		int a = check_next(i);
			cout<<i<<"---"<<a<<endl;
			
	}
	
}