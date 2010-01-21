# include <iostream>
using namespace std;

const int size = 11;
const int asize = 13;

int main () {
	int pos, res;
	long sum[asize*asize], all[asize*asize];
	
	for (int i=0; i<asize*asize; i++)
		sum[i]=all[i]=0;
	
	while (cin >> pos >> res) {
		sum[pos]+=res;
		all[pos]++;
		
		int x = size + 1 - pos % asize;
		int y = size + 1 - pos / asize;

		pos = y*asize + x;

		sum[pos]+=res;
		all[pos]++;
	}
	
	for (int pos=0; pos<asize*asize; pos++) {
		if (all[pos] == 0) cout << "5." << endl;
		else cout << (float)sum[pos]/(float)all[pos] << endl;
	}
	cout << endl;
}


