#include<iostream>
#include<bitset>
using  namespace std;
const int N = 1e5 + 10;

bitset<N>Prime;//Intially Initialised with 0.

void Prime_Seive() {

	for (int i = 3; i * i <= N; i += 2) {
		if (Prime[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				Prime[j] = 1;
			}
		}
	}


	cout << 2 << " ";
	for (int i = 3; i <= N; i += 2) {
		if (Prime[i] == 0) {
			cout << i << " ";
		}
	}

}

int main() {
	Prime_Seive();
}