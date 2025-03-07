#include <bits/stdc++.h>

using namespace std;

vector<int> taoLPS(const vector<int> &A){
    int n = A.size();
    vector<int> LPS(n,0);
    int kt = 0;
    int i = 1;
while(i<n){
    if(A[i]==A[kt]){
        kt++;
        LPS[i]=kt;
        i++;
    }else {
        if(kt!=0){
            kt = LPS[kt-1];
        }
        else{
            LPS[i]=0;
            i++;
        }
    }
}
return LPS;
}

vector<int> findKMP(const vector<int> &A, const vector<int> &B){
    int n = A.size();
    int m = B.size();
int i = 0, j = 0;
vector<int> vitri;
vector<int> LPS = taoLPS(A);
while(i<m){
    if(B[i]==A[j]){
        i++;
        j++;
    }
    if(j == n){
        vitri.push_back(i-j);
        j = LPS[j-1];
    }
    else if(i<m&&A[j]!=B[i]){
        if(j!=0){
            j = LPS[j-1];
        }
        else i++;
    }
}
return vitri;
}

int main(){
cout<<"Nhap n, m: ";
    int n; cin>>n;
    int m; cin>>m;
vector<int> A(n),B(m);
cout<<"Nhap A";
for(int &x:A){
    cin>>x;
}
cout<<"Nhap B";
for(int &x:B){
    cin>>x;
}
vector<int> vitri = findKMP(A,B);
cout<<"So lan "<<vitri.size()<<endl;
for(int x : vitri){
    cout<<x<<" ";
}
}
