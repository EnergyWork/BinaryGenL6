#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <climits>
using namespace std;				

bool digitCheck(int d, bitset<7> bits) {
	vector<vector<bool>> masBits = {
	{ 1, 1, 1, 0, 1, 1, 1 },
	{ 0, 1, 0, 0, 1, 0, 0 },
	{ 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 1, 0, 1, 1, 0, 1 },
	{ 0, 1, 0, 1, 1, 1, 0 },
	{ 1, 1, 0, 1, 0, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1 },
	{ 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 1, 1, 1, 1 },
	};
	for (int j = bits.size() - 1; j >= 0; j--) {
		if (bits[j] != masBits[d][j]) {
			return false;
		}
	}
	return true;
}
									
int isDigit(bitset<7> bits) {	

	if (digitCheck(0, bits))
		return 0;
	else if (digitCheck(1, bits))
		return 1;
	else if (digitCheck(2, bits))
		return 2;
	else if (digitCheck(3, bits))
		return 3;
	else if (digitCheck(4, bits))
		return 4;
	else if (digitCheck(5, bits))
		return 5;
	else if (digitCheck(6, bits))
		return 6;
	else if (digitCheck(7, bits))
		return 7;
	else if (digitCheck(8, bits))
		return 8;
	else if (digitCheck(9, bits))
		return 9;
	else 
		return -1;
}

void main() {
	ofstream fout("fileL6.txt");
	for (uint16_t i = 0; i < pow(2, 7); i++) {
		bitset<7> bitvec = bitset<7>(i);
		for (int j = bitvec.size() - 1; j >= 0; j--) {
			fout << bitvec[j] << ' ';
		}
		fout << isDigit(bitvec) << endl;
	}
}