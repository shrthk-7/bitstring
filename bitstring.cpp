// basic implementation of bitset using arrays
// might be useful as bitsets cannot be dynamically allocated during runtime

// testing / error handling / documentation PRs will be highly appreciated

#include<iostream>
#include<stdint.h>
#include<bitset>
#include<cstring>

using std::bitset;
using std::cout;

class bitstring {
	private:
		uint8_t *bit_array;
		int length;

	public:
	// constructor
		bitstring(size_t size) {
			length = size / 8 + 1;
			bit_array = new uint8_t(length);
			memset(bit_array, 0, length);
		}

	// destructor
		~bitstring(){
			delete[] bit_array;
		}

	// setting the i'th bit
		void set(int i, bool value = true) {
			int index = i / 8;
			int n = i % 8;
			if(value == true)
				bit_array[index] |= 1 << n;
			else
				bit_array[index] &= !(1 << n);
		}

	// accessing the i'th bit
		int get(int i) {
			int index = i / 8;
			int n = i % 8;
			int bit = (bit_array[index] >> n) & 1U;
			return bit;
		}

	// toggling the i'th bit
		void toggle(int i) {
			int index = i / 8;
			int n = i % 8;
			bit_array[index] ^= 1 << n;
		}

	// accessing the i'th bit
		int operator [](int i) {
			return get(i);
		} 

	// viewing the bit_array
		void show() {
			for(int i=length-1; i>-1; i--){
				cout << bitset<8>(bit_array[i]);
			}
			cout << '\n';
		}

	// resetting the entire bitstring
		void reset() {
			for(int i=0; i<length; i++){
				bit_array[i] = 0;
			}
		}
};

int main() {
	// initializing bit_array of size 20:  
	bitstring b = bitstring(20);

	// setting 4th and 5th  bit to true:
	b.set(4, true); 
	// b.set(4) also valid
	b.set(3);

	// viewing the entire bitstring: 
	b.show();

	// toggling the 4th bit
	b.toggle(3);

	// accessing the 4th and 5th bit:
	cout << "Bit 4 : " << b[3] << ", Bit 5 : " << b[4]; 
	// b.get(4) also valid

	// resetting the bitstring:
	b.reset();
}