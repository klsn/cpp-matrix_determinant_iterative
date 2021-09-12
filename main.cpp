#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<double>> matrix (n, vector<double>(n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin >> matrix.at(i).at(j);
		}
	double temp;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
				temp = matrix.at(j).at(i) / matrix.at(i).at(i);
			for (int k=i;k<n;k++){  // 0 1 0  
				matrix.at(j).at(k) -= matrix.at(i).at(k) * temp;
				}
			}
		}


	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cout << matrix.at(i).at(j) << ' ';
		}
	cout <<endl;
	}


	double ans=1;
	for (int i=0;i<n;i++) {
		ans *= matrix.at(i).at(i);
	
	cout << ans <<endl;
}
}
