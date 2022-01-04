#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>



void dfs(int start_i, int num_char, int all_num[10],vector<string> & total, int result[],vector<bool> check_sheet)
{

	if(start_i!= num_char) //需要k个数，当step=k+1时返回 
	{
		for(int i=0;i<10;i++) //有n个数供选择 
		{
			if(check_sheet[i]==true)
			{
				result[start_i]=all_num[i];
				check_sheet[i]=false;
				dfs(start_i+1,num_char,all_num,total,result,check_sheet);
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
int main()
{
	vector<string> total;
	int i;
	int all_num[10];
	int result[10];
	int num_char = 5;
	vector<bool> check_sheet;
	for(int i = 0; i < 10; i++){
		check_sheet.push_back(true);
	}
	for(int i=0;i<10;i++){
		all_num[i]=i;
	}

	dfs(0,num_char,all_num,total,result,check_sheet);

	for(int l = 0; l< total.size();l++){
		cout<<total[l]<<endl;
	}
	
	return 0;
}
