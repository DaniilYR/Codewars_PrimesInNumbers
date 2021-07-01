#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

std::string factors(int lst){

	std::vector<int> d;// = {2,2,2,2,5,2,7,11,7};
	std::vector<int>::iterator it;
	std::map<int, int> division;
	std::map<int, int>::iterator itMap = division.begin();
	
	int divider = 2;
	while (lst > 1) {
        if (lst % divider == 0) {
            //cout << divider << endl;
            d.push_back(divider);
            lst = lst / divider;
        }
        else {
            divider = divider + 1;
      
        }
    }
		
	std::sort(d.begin(), d.end());
	for(auto &it : d){
		if(division.find(it) != division.end()){
			division[it]++;
		}
		else
			division.insert({it, 1});
	}
	std::string ans = "";
	for(auto elem : division){
		if(elem.second > 1){
			ans += ("(" + std::to_string(elem.first) + "**" + std::to_string(elem.second) + ")");
		}
		else
			ans += "(" + std::to_string(elem.first) + ")";
	}
	
	return ans;
}

int main(){

	//int n = 86240;
	int n = 7919;
	std::string ans = factors(n);
	std::cout << ans << std::endl;
}
