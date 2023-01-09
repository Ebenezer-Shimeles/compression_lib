#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <cassert>
#include <cmath>

uint32_t* GetFreqsOfChars(const char* str) {
	//This functions gets the frequency of all ascii characters
	uint32_t* freqs = new uint32_t[128]{};
	//acts like a hash-map ;)


	for (int i = 0; i < strlen(str); i++) {
		freqs[str[i]]++;
	}
	return freqs;
}
void PrintFrequencyOfChars(uint32_t *freq) {
	using namespace std;
	cout << "Frequency----------------------------\n";
	for (int i = 0; i < 128; i++) {
		cout << (unsigned char)i<< " 0x" << std::hex << i <<" "  << freq[i] << "\n";
	}
	cout << '\n';

}

void CharToBin( char c, std::string& return_value) {
	//works fine!
	
	for (int i = 7; i>= 0;i--) {
		//assert(i >= 0);
		if (c & int(pow(2, i))) {
			return_value += '1';
		}
		else {
			return_value += '0';
		}
	}
	
	
	
}

uint8_t BinToChar(std::string s) {
	//works fine!
	auto SIZE = s.size();
	
	assert(SIZE == 8); //we need to change from asccii bin to asccii char

	uint8_t return_value = 0;

	for (int i = 0; i < SIZE; i++) {
		const char c = s[SIZE - i - 1];
		//std::cout << "char=>" << c << std::endl;
		assert(c == '0' || c == '1');
		if(c == '1') {

			return_value += int(pow(2, i));
		}
	}
	return return_value;
}

/*
   Remember to Delete:
        the binary strings after using
		the freq table qrray after using
*/
char* HuffmanCompress(const char* str) {
	auto freqs = GetFreqsOfChars(str);
	PrintFrequencyOfChars(freqs);
	//Looks good!

	return  const_cast<char*>(str);
}

int main() {
	using namespace std;
	//cout << HuffmanCompress("Ebenezer Shimeles Went to the grocery to buy water!");
	string s ="";
   CharToBin('1',s );
   cout << s << endl;
   cout << std::hex << (char)BinToChar(s) << endl;
   s = "";
   CharToBin('d', s);
   cout << s << endl;
   cout << BinToChar(s) << endl;
   s = "";
   CharToBin('!', s);
   cout << s << endl;
   cout << BinToChar(s) << endl;
   s = ""; 
   CharToBin('8', s);
   cout << s << endl;
   cout << BinToChar(s) << endl;

   s = "";
   CharToBin('z', s);
   cout << s << endl;
   cout << BinToChar(s) << endl;




}


