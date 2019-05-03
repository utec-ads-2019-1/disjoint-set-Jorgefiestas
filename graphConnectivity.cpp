#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int T;

char find(unordered_map<char, char> &ds, char idx){
    while(idx != ds[idx]){
        ds[idx] = ds[ds[idx]];
        idx = ds[idx];
    }
    return idx;
}

void join(unordered_map<char, char> &ds, char a, char b){
    char rootA = find(ds, a);
    char rootB = find(ds, b);
    ds[rootA] = rootB;
}

int solve(){
    char n;
    cin>>n;
    unordered_map<char, char> ds;
    for(char c = 'A'; c <= n; c++)
       ds[c] = c;
    string edge;
    cin.ignore();
    while(true){
        getline(cin, edge);
        if(edge.empty()) break;
        join(ds, edge[0], edge[1]);
    }
    unordered_set<char> s;
    for(char c = 'A'; c <= n; c++)
        s.insert(find(ds, c));
    return s.size();
}

int main(){
	cin>>T;
    for(int i = 0; i<T; i++){
        cout<<solve()<<endl;
        if(i != T-1) cout<<endl;
    }
    return 0;
}
