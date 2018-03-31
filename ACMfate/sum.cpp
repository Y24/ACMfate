#include<iostream>
#include<cstdlib>
long cy(int n, int q) {
	long N = 1;
	while (q-- > 0)
		N *= n;
	return N;
};
unsigned long long sumall(int , int );
void copy(int **, int **,int, int);
void increase(int **, int **,int, int);
using namespace std;
int main() {
	int time;
	cin >> time;
	for (int i = 0; i < time; i++) {
		int n, q;
		cin >> n >> q;
		cout << "Case #" << i+1 << ": " << sumall(n, q) % 1000000007<<endl;
	}
	system("pause");
	return 0;
}
void copy(int **a, int **b,int n, int q) {
	for (int i = 0; i < cy(n, q); i++)
		for (int j = 0; j < n; j++)
			b[i][j] = a[i][j];
}
void increase(int **a, int **b, int n, int q) {
	for (int i = 0; i < cy(n, q); i++) {
		int j = i * n;
		for (int sign = 0; sign < n; sign++,j++) {
			for (int z = 0; z < n; z++) {
				a[j][0] = b[i][sign];
				if (z == sign)
					a[j][z] = b[i][0];
				else
					a[j][z] = b[i][z];
			}
		}
	}
}
unsigned long long sumall(int n, int q) {
	long long N = cy(n, q);
	unsigned long long sum = 0;
	int **a = new int*[N];
	int **bak = new int*[N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[n];
		bak[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
			a[0][i] = i;
	for (int times = 0; times < q; times++) {
		copy(a,bak,n,times);
		increase(a, bak,n, times);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < n; j++) 
			cout << a[i][j]<<" ";
		cout << endl;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < n; j++)
			for (int z = j + 1; z < n; z++)
				if (a[i][z] < a[i][j])
					sum++;
	for (int i = 0; i < N; i++) {
		delete[] a[i];
		delete[] bak[i];
	}
	delete[] a;
	delete[] bak;
	return sum;
}