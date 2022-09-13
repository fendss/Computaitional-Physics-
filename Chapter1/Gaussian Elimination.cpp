/**************************************************
 * Topic:Gaussian Elimination
 * Videos:
 * https://www.bilibili.com/video/BV1By4y1J7UA?spm_id_from=333.337.search-card.all.click&vd_source=6bd34378b818dc9b604e8d6828a5edfd
 * https://www.youtube.com/watch?v=RgnWMBpQPXk
 * date:2022-09-13
 */

#include<bits/stdc++.h>
using namespace std;


vector<double> guass_elimination(vector<vector<double>> &mat) {
	
	int row = mat.size() - 1, col = mat[0].size() - 1;
	vector<double> solution(row+1);
	
	//making the current main diagonal elements larger than the elements in the same column below
	for (int i = 1; i < row; i++) {
		for (int j = i + 1; j <= row; j++) {
			if (abs(mat[i][i]) < abs(mat[j][i]))
				swap(mat[i], mat[j]);
		}
	}
	/************************ Something looks like this *********************
	 *  A1  b1  c1  d1  s1
	 *  a2  B2  c2  d2  s2
	 *  a3  b3  C3  d3  s3
	 *  a4  b4  c4  D4  s4
	 */

	// performing gauss elimination
	for (int i = 1; i < row; i++) {
		for (int j = i+1; j <= row; j++) {
			double times = -1.0 * (mat[j][i] / mat[i][i]);
			for (int k = i; k <= col; k++) {
				mat[j][k] += times * mat[i][k];
			}
		}
	}
	
	/************************ Something looks like this *********************
	 *  A1  b1  c1  d1  s1
	 *  0   B2  c2  d2  s2
	 *  0   0   C3  d3  s3
	 *  0   0   0  D4   s4
	 */
	
	//solve the equation one by one
	for (int i = row; i >= 1; i--) {
		solution[i] = mat[i][col];
		for (int j = i + 1; j < col; j++) {
			if(i!=j) solution[i] -= solution[j] * mat[i][j];
		}
		solution[i] /= mat[i][i];
	}
		
	return solution;
}

	
int main() {
	int row; // numbers of the equations
	cin >> row;
	int col = row + 1; // size of the equations
		
		
	vector<vector<double>> mat(row + 1, vector<double>(col + 1)); // 1-inded
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> mat[i][j];
		}
	}
		
	vector<double> solutions = guass_elimination(mat);
	cout << "Solutions is:" << endl;
	for (int i = 1; i < solutions.size(); i++) {
		cout << "x" << i << " = " << solutions[i] << endl;
	}
	return 0;
}
