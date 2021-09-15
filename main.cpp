#include <bits/stdc++.h>
using namespace std;


// if matirx[i][i] == 0; find a row such that !=0 and swap it.
bool swapRows (vector<vector<double>> &matrix, int &i, int &n, double &ans) {
	for (int j=i+1;j<n;j++) {
		if (matrix.at(j).at(i) !=0) {
			vector<double> temp = matrix.at(j);
			matrix.at(j) = matrix.at(i);
			matrix.at(i) = temp;
			ans *= -1; // when swapping any 2 rows, det*=-1.
			return false;
		}
	}
	return true;
}

int main() {
	double ans=1, temp;
	int ansLog=0, n, tempInt;
	cin >> n; // size of matrix.
	vector<vector<double>> matrix (n, vector<double>(n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin >> matrix.at(i).at(j);
		} // input till here.

	for (int i=0;i<n-1;i++){ // row reduction.
		if ( matrix.at(i).at(i) == 0) 
			if ( swapRows(matrix, i, n, ans) ) { // returned true means det is 0
				cout << 0 <<" \\times 10^ "<< 0 <<endl;
				return 0;
			}
		for (int j=i+1;j<n;j++){
				temp = matrix.at(j).at(i) / matrix.at(i).at(i);
			for (int k=i;k<n;k++){  
				matrix.at(j).at(k) -= matrix.at(i).at(k) * temp;
				}
			}
		}

/* output for debug.
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cout << matrix.at(i).at(j) << ' ';
		}
	cout <<endl;
	}
*/


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
	return 0;
}
