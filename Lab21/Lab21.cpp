#include <iostream>
#include<vector>

using namespace std;

void zd1() {

	int pr = 1, i1 = 0, j1 = 0;

	int m;

	cout << "Enter size matrix : ";

	cin >> m;

	vector< vector<int> > A(m, vector<int>(m));

	cout << "Enter elements of matrix : ";

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {

			cin >> A[i][j];

		}

	}

	if (m == 1) {
		cout << A[0][0];
		return;
	}

	int v = m / 2;

	int c = 1, ogr1_i = m - 1, ogr2_j = m - 1, ogr3_i = 0, ogr4_j = 1;
	bool fl = true;

	while (i1 != v || j1 != v) {

		if (c > 4) {
			c = 1;
		}

		if (c == 1) {

			for (i1 = i1; i1 <= ogr1_i; i1++) {
				if (!fl) {
					fl = true;
					continue;
				}
				cout << A[i1][j1] << " ";
			}

			fl = false;
			ogr1_i--;
			i1--;
		}

		if (c == 2) {

			for (j1 = j1; j1 <= ogr2_j; j1++) {
				if (!fl) {
					fl = true;
					continue;
				}
				cout << A[i1][j1] << " ";
			}

			fl = false;
			ogr2_j--;
			j1--;
		}

		if (c == 3) {

			for (i1 = i1; i1 >= ogr3_i; i1--) {
				if (!fl) {
					fl = true;
					continue;
				}
				cout << A[i1][j1] << " ";
			}

			fl = false;
			ogr3_i++;
			i1++;
		}

		if (c == 4) {


			for (j1 = j1; j1 >= ogr4_j; j1--) {
				if (!fl) {
					fl = true;
					continue;
				}
				cout << A[i1][j1] << " ";
			}

			fl = false;
			ogr4_j++;
			j1++;
		}

		c++;
		//cout << "\n" << i1 << " " << j1 << endl;;
	}
}

void zd2() {

	int m, n, k, sum = 0, mn = 1;

	cout << "Enter size matrix (n , m) : ";

	cin >> m >> n;

	cout << "Enter k : ";

	cin >> k;

	k--;

	vector< vector<int> > A(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	for (int j = 0; j < n; j++) {

		sum += A[k][j];
		mn *= A[k][j];

	}

	cout << "Sum = " << sum << "  Multiplication : " << mn;

}

void zd3() {

	int m, n, k, mi_mp = 1e8, mi_n;

	cout << "Enter size matrix (n , m) : ";

	cin >> m >> n;


	vector< vector<int> > A(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	int mp = 1;
	for (int j = 0; j < n; j++) {

		for (int i = 0; i < m; i++) {
			mp *= A[i][j];
		}

		if (mp <= mi_mp) {
			mi_mp = mp;
			mi_n = j + 1;
		}

		mp = 1;

	}

	cout << "Min number = " << mi_n << " multiplication = " << mi_mp << endl;

}

void zd4() {

	int m, n;

	cout << "Enter size matrix (m , n) : ";

	cin >> m >> n;


	vector< vector<int> > A(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	int sr = 0, ans = 0;

	for (int j = 0; j < n; j++) {

		sr = 0, ans = 0;

		for (int i = 0; i < m; i++) {

			sr += A[i][j];

		}

		sr /= m;


		for (int i = 0; i < m; i++) {

			if (A[i][j] > sr)
				ans++;

		}

		cout << j + 1 << " stolb : " << ans << endl;

	}

}

void zd5() {

	int m, n;

	cout << "Enter size matrix (m , n) : ";

	cin >> m >> n;


	vector< vector<int> > A(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	for (int j = 0; j < n; j++) {

		bool fl = true;

		for (int i = 0; i < m; i++) {

			if (A[i][j] % 2 == 0) {

				fl = false;
				break;

			}

		}

		if (fl) {

			cout << j + 1;
			return;

		}

	}

}

int main() {

	int t;

	while (true) {

		cout << "Enter number job or zero for exit : ";

		cin >> t;

		switch (t)
		{
		case 1:
			zd1();
			break;
		case 2 :
			zd2();
			break;
		case 3:
			zd3();
			break;
		case 4:
			zd4();
			break;
		case 5:
			zd5();
			break;
		case 0:
			return 0;
		default:
			break;
		}

		cout << endl;
	}

	return 0;
}