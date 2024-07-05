#include <bits/stdc++.h>
using namespace std;
#define ll long long


void sx(vector<long long>& arr, long long left, long long right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        sx(arr, left, j);
    }
    if (i < right) {
        sx(arr, i, right);
    }
}



int main (){
    long long n; cin >> n;
    ll a[n];
    vector<long long> se;
    long long k; cin >> k;
    vector<ll> v;
    ll mp[1000];
    for (long long i=0; i<n; i++){
        cin >> a[i];
        se.push_back(a[i]);
        mp[a[i]]++;
    }
    sx(se,0,se.size()-1);
       	for(vector<long long>::iterator it=se.begin(); it!=se.end(); it++){
           v.push_back(*it);
		   if(v.size()==k) break;
		   mp[*it]--;
	}
   if(v.size()<k){
   	for(vector<long long>::iterator it=se.begin(); it!=se.end(); it++){
		while(mp[*it]>=1){
			v.push_back(*it);
			mp[*it]--;
			if(v.size()==k){
				break;
			}
		}
		if(v.size()==k) break;
   }

}


   sx(v,0,v.size()-1);
   for(long long i=0; i<v.size(); i++){
   	cout << v[i] << " ";
   }
}
