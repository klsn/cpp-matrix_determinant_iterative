#include <bits/stdc++.h>
using namespace std;
int main() {
	double ans=1, temp;
	int ansLog=0, n, tempInt;
	cin >> n;
	vector<vector<double>> matrix (n, vector<double>(n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin >> matrix.at(i).at(j);
		}

	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
				temp = matrix.at(j).at(i) / matrix.at(i).at(i);
			for (int k=i;k<n;k++){  
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


	for (int i=0;i<n;i++) {
		ans *= matrix.at(i).at(i);
		if (ans != 0){
			tempInt = log(abs(ans))/log(10);
			if (tempInt !=0){
				ansLog += tempInt;
				ans/= pow(10,tempInt);
			}
		}

	}		
	cout << ans <<" \\times 10^ "<< ansLog <<endl;

}
