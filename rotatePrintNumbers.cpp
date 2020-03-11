#include <iostream>
#include <vector>
using namespace std;

/*
1 
27 2 
26 28 3 
25 45 29 4 
24 44 46 30 5 
23 43 54 47 31 6 
22 42 53 55 48 32 7 
21 41 52 51 50 49 33 8 
20 40 39 38 37 36 35 34 9 
19 18 17 16 15 14 13 12 11 10 
*/

void func(int n) {
	vector< vector<int> > mat;
	for (int i = 0; i < n; ++i) {
		mat.push_back(vector<int>(i+1));
	}
	int a = 0;
	int b = n-1;
	int l = 0;
	int row, col;
	int num = 1;
	int count = (1+n) * n / 2;
	while (1) {
		row = a; col = l;
		while (row <= b) {
			mat[row++][col++] = num++;
		}
		++a;
		if (num > count) {
			break;
		}
		row = b; col -= 2;
		while (col >= l) {
			mat[row][col--] = num++;
		}
		--b;
		if (num > count) {		
			break;
		}
		row = b; col = l;
		while (row >= a) {
			mat[row--][col] = num++;
		}
		++l; ++a;
		if (num > count) {
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i+1; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	func(10);
	return 0;
}
