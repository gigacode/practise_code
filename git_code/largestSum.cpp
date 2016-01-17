#include<iostream>
#include<utility>
#include<vector>

using namespace std;

void largestSum(const vector<int>& arr) {
    int maxSum = 0;
    pair<int, int> maxInt;
    int sum = 0;
    int start = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > maxSum) {
            maxSum = sum;
            maxInt = make_pair(start, i);
        } 
        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
     }
     cout << "Sum: " << maxSum << "; [" << maxInt.first << ": " << maxInt.second << "]" << endl;
}

int main(int argc, char** argv) {
    vector<int> arr = {2, -8, 3, -2, 4, -10};
    largestSum(arr);
}

