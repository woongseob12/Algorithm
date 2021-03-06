#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    map<string, int> m;
    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        m[s] = i;
    }

    vector<string> pass(N);
    for(int i = 0 ; i < N ; i++){
        cin >> pass[i];
    }

    int cnt = 0; 
    for(int i = 0 ; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(m[pass[i]] > m[pass[j]]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
