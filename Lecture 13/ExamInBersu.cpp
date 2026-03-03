#include<iostream>
using namespace std;
#define int long long
int n, m;
int t[200001] {0};
int freq[101] {0};



int32_t main() {


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	int Total = 0;

	for (int i = 0; i < n; i++) {
		int ET = Total - m + t[i];
		int Removed = 0;

		if (ET > 0) {

			for (int j = 100; j >= 1; j--) {

				if (freq[j] > 0) {

					//Current Freq ka contribution batao;
					int contri = freq[j] * j;

					if (contri >= ET) {
						//Current Current ki kuch freq ko remove karke mera kaam hojaayega

						//Ceil value :

						// (ET / j);//Ceil value of this.
						//ceil(ET/j)-->same baat hain.

						Removed += ((ET + j - 1) / j);//isse kaam hojayega
						break;
					}

					//If reached here that means current freq ke saaare students hatao and
					//aur students remove karne ke liye dhundo.
					Removed += freq[j];
					ET -= contri;
				}
			}
		}

		freq[t[i]]++;
		Total += t[i];
		cout << Removed << " ";
	}
}




// Extra Time : 100

// mujhe 40 value vale kitne student remvoe karne hain.

// (100/40)--->remainder bach jata 20.

// ceil of (100/40)