#include<iostream>
#include<vector>
using namespace std;

void subs(vector<int> &arr, int index, vector<vector<int>> &res, vector<int> &curr){
    int n = arr.size();
    if (index >= n){
        res.push_back(curr);
        return;
    }
    curr.push_back(arr[index]);
    subs(arr, index+1, res, curr); // take
    curr.pop_back();
    subs(arr, index+1, res, curr); // not take
}

void print(vector<vector<int>> &res){
    for (auto &i : res){
        for (auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> arr = {3, 1, 2};
    int index = 0;
    vector<vector<int>> res;
    vector<int> curr;
    subs(arr, index, res, curr);
    print(res);
}