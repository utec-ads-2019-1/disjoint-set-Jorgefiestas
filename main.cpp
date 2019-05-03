#include <iostream>
#include <vector>

using namespace std;
int test[16][2] = {{1, 2}, {3, 4}, {3, 5}, {1, 7}, {3, 6}, {8, 9}, {1, 8}, {3, 10}, {3, 11}, {3, 12}, {3, 13}, {14, 15}, {16, 1}, {14, 16}, {1, 3}, {1, 14}};

int find(vector<int> &ds, int idx){
    while(idx != ds[idx]){
        ds[idx] = ds[ds[idx]];
        idx = ds[idx];
    }
    return idx;
}

void joinRandom(vector<int> &ds, int a, int b){
    int rootA = find(ds, a);
    int rootB = find(ds, b);
    ds[rootA] = rootB;
}

void joinRanked(vector<int> &ds, vector<int> &rank, int a, int b){
    int rootA = find(ds, a);
    int rootB = find(ds, b);
    if(rank[rootA] > rank[rootB])
        ds[b] = rootA;
    else if(rank[rootA] < rank[rootB])
        ds[rootA] = rootB;
    else
        ds[rootB] = rootA, rank[rootA]++;
}

void joinSize(vector<int> &ds, vector<int> &size, int a, int b){
    int rootA = find(ds, a);
    int rootB = find(ds, b);
    if(size[rootA] > size[rootB])
        ds[rootB] = rootA, size[rootA] += size[rootB];
    else
        ds[rootA] = rootB, size[rootB] += size[rootA];
}

int main(){
    vector<int> ds(16), rank(16, 0), size(16, 1);

    //Random Union-Find
    for(int i = 0; i<ds.size(); i++)
        ds[i] = i;
    
    for(int i = 0; i<16; i++)
        joinRandom(ds, test[i][0] - 1, test[i][1] - 1);

    for(int i = 0; i<ds.size(); i++)
        cout<<find(ds, i)<<" ";
    cout<<endl;
    
    //Ranked Union-Find
    for(int i = 0; i<ds.size(); i++)
        ds[i] = i;
    
    for(int i = 0; i<16; i++)
        joinRanked(ds, rank, test[i][0] - 1, test[i][1] - 1);

    for(int i = 0; i<ds.size(); i++)
        cout<<find(ds, i)<<" ";
    cout<<endl;

    //Size Union-Find
    for(int i = 0; i<ds.size(); i++)
        ds[i] = i;
    
    for(int i = 0; i<16; i++)
        joinRanked(ds, size, test[i][0] - 1, test[i][1] - 1);

    for(int i = 0; i<ds.size(); i++)
        cout<<find(ds, i)<<" ";
    cout<<endl;

    return 0;
}
