#include <iostream>
#include <vector>

using namespace std;


void find_path(std::vector< std::vector<int> > & friends, int start_i, int end_i,vector<bool> check_sheet, vector<int> the_path,vector< vector<int> > & total_result){
	if(start_i!=end_i){
		the_path.push_back(start_i);
		check_sheet[start_i] = false;
		for(int i=0; i<friends[start_i].size();i++){
			if(check_sheet[friends[start_i][i]] == true){
				for(int j=0; j<friends[start_i].size();j++){
					if(j != i) check_sheet[friends[start_i][j]] = false;
				}
				find_path(friends, friends[start_i][i], end_i, check_sheet, the_path, total_result);
				check_sheet[friends[start_i][i]] = false;
				for(int j=0; j<friends[start_i].size();j++){
					if(j != i) check_sheet[friends[start_i][j]] = true;
				}
			}
			if(i == friends[start_i].size()-1 && check_sheet[friends[start_i][i]] == false){
				the_path.pop_back();
				return;
			}
		
		}
	}
	else{
		the_path.push_back(end_i);
		bool check_state = true;
		for(int i = 1; i<the_path.size();i++){
			if(the_path[i]<the_path[i-1]){
				check_state = false;
			} 
		}
		if(check_state == true){
			total_result[end_i].push_back(the_path.size()-1);
		} 
	}
	
}



int main(int argc, char *argv[]) {
	vector< vector<int> > g1(8);// = {{1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6}};
	g1[0].push_back(1);
	g1[0].push_back(2);
	//g1[0].push_back(4);
	g1[1].push_back(0);
	g1[1].push_back(3);
	g1[2].push_back(0);
	g1[2].push_back(3);
	g1[3].push_back(1);
	g1[3].push_back(2);
	//g1[3].push_back(5);
//	g1[3].push_back(7);
	//g1[4].push_back(0);
	//g1[4].push_back(5);
	//g1[4].push_back(6);
	//g1[5].push_back(3);
//	g1[5].push_back(4);
//	g1[6].push_back(4);
//	g1[6].push_back(7);
//	g1[7].push_back(3);
//	g1[7].push_back(6);
	//for(int i=0;i<8;i++){
	//	for(int j = 0;j<g1[i].size();j++){
	//		cout<<g1[i][j];
	//	}
	//	cout<<endl;
	//}
	vector<bool> check_sheet(g1.size(),true);
	vector< vector<int> > total_result(g1.size());
	vector<int> the_path;
	for(int i=0;i<g1.size();i++){
		find_path(g1,0,i,check_sheet,the_path,total_result);
		for(int j = 0; j<g1.size();j++){
		   check_sheet[j] = true;
		}
	
	}
	for(int i=0;i<g1.size();i++){
		for(int j = 0;j<g1[i].size();j++){
			std::cout<< total_result[i][j];
			
		}
		std::cout<<std::endl;
	   
	}
	//find_path(g1, 0, 3, check_sheet, the_path, total_result);
	//cout<<total_result[3][0]<<endl;
	//cout<<total_result[3][1]<<endl;
	//cout<<total_result[5][2]<<endl;
	//cout<<total_result[3].size();
	//cout<<total_result[6][1]<<endl;
	//cout<<total_result[6][2]<<endl;
}