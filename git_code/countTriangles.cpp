//Count the number of triangles that can be formed from n integers
#include <iostream>
#include <vector>

using namespace std;

int getPairCountWithGreaterSum(const vector<int>& arr, int key, int first, int last)
{
    int count = 0; 
    int i = first;
    int j = last;
    while ( i < j) {
        if ((arr[i] + arr[j]) > key) {
            count += j - i;
            j--;
            continue; 
        }
        i++;
    }
    return count;
}



void triangleCount(vector<int> arr,int *count ) {
    sort(arr.begin(), arr.end());
    *count = 0;
    for(int i = arr.size() - 1; i >= 2; i--) {
        int key = arr.at(i);
        *count += getPairCountWithGreaterSum(arr, key, 0, i-1);
    }

}

int main(int argc, char**argv)
{
    
    int count;
    triangleCount({10, 21, 22, 100, 101, 200, 300}, &count);
    cout << "No of triangles: " << count;
}
