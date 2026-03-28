#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(49);
    v.push_back(67);
    for(int x: v){
        cout << x << " ";  // Add space separator
    }
    cout << endl;
    cout << v[0] << endl;
    return 0;
}