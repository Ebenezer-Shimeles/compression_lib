#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <cassert>
#include <cmath>
#include <exception>
#include <sstream>


#define MAX_HEAP_MAX_SIZE 100

template<class T>
class MaxHeap {
	
private:  
	uint32_t current_max_size;
	uint32_t size = 0;
	
	T *elems;
	void Resize() {
		current_max_size *= 2;
		auto tmp = new T[current_max_size];
		for (uint32_t i = 0; i < size; i++) {
			tmp[i] = elems[i];
		}
		delete[]elems;
		elems = tmp;
	}
	void Swap(T& one, T& two) {
		//std::cout << "Swapping " << one << " and " << two << " with size = " << size<< '\n';
		auto tmp = one;
		one = two;
		two = tmp;
	}
	void init(uint32_t size) {
		current_max_size = size;
		elems = new T[current_max_size];
	}
	uint32_t ParrentIndex(uint32_t index) {
		//std::cout << elems[index] << "'s parent is " << elems[index / 2] <<'\n';
		return index / 2;
	}
	uint32_t LeftIndex(uint32_t index) {
		return index * 2;
	}
	uint32_t RightIndex(uint32_t index) {
		return index * 2 + 1;
	}
public:
	void PrintHeap() {
		using namespace std;
		cout << "Heap::";
		for (int i = 0; i < size; i++) {
			cout << elems[i] << "\n";
		}
		cout << endl;
	}
	void ShiftUp(uint32_t index) {
		assert(index < size); //DO NOT SHIFT FROM ABOVE
		if (size == 1) return; // A man is a boss of his house.
		uint32_t parrent_index = ParrentIndex(index);

		while (elems[index] > elems[parrent_index]) {
			//std::cout << "Before swap:\n";
		//	PrintHeap();
			Swap(elems[index], elems[parrent_index]);
			//std::cout << "After swap:\n";
			//PrintHeap();
			index = parrent_index;
		    parrent_index = ParrentIndex(index);
			
		}
		//Works fine!

	}

	void ShiftDown(uint32_t index) {
		//there is something fishy here!
		if (size <= 1) {
			return; //do nothing here
		}
		uint32_t left_index = LeftIndex(index);
		uint32_t right_index = RightIndex(index);

		uint32_t swap_index = index;
		while (left_index < size && right_index < size) {
			if (elems[swap_index] < elems[left_index]) {
				swap_index = left_index;
			}
			if (elems[swap_index] < elems[right_index]) {
				swap_index = right_index;
			}
			if (swap_index == index) break;
			//std::cout << "P swap\n";
			Swap(elems[swap_index], elems[index]);
			index = swap_index;
			left_index = LeftIndex(index);
			right_index = RightIndex(index);
		}

	}
	T Pop() {
		if (size == 0) {
			throw std::logic_error("Error Max Heap is Empty! :(");
		}
		//std::cout << "\nPOP::" << this << "\n"; //TODO:: just for testing delete latter please!
		T max = elems[0]; //Max Heap so ...
		Swap(elems[0], elems[size-1]);
		
	
		size--; //forget the max
		//works fine up to here
		ShiftDown(0);
		return max;
	}



	void Insert(T item) {
		//std::cout << "Inserting " << item << " into max heap\n";
		if (current_max_size == size) {
			Resize();
		}
		elems[size++] = item;
		//std::cout << "Inserted element at last: ";
		//PrintHeap();
		//Works perfectly!
		ShiftUp(size-1);
		
	}
	T Max() const
	{
		if (size == 0) {
			throw std::logic_error("Error Max Heap is empty!");
		}
		return elems[0];
	}
	T Min() const {
		//Wrong function change this please!
		if (size == 0) {
			throw std::logic_error("Error max heap is empty!");
		}
		return elems[size - 1];
	}

	bool IsEmpty() const {
		return size == 0;
	}

	~MaxHeap() {
		std::cout << "Max heap deleted :(!\n";
		delete elems;
	}

	uint32_t Size() const {
		return size;
	}
	uint32_t MaxSize() const {
		return current_max_size;
	}
	
	MaxHeap() {
		init(MAX_HEAP_MAX_SIZE);
	}


	MaxHeap(uint32_t size) {
		init(size);
	}

	void ToString(std::string& str) {
		for (uint32_t i = 0; i < size; i++) {
			//std::cout << elems[i] << ", ";
		//	str += std::to_string(elems[i]); //assuming we will only use this for int
			str += ", ";
		}
	}

};
template<typename T>
std::ostream& operator << (std::ostream & o, MaxHeap<T>* m) {
	std::string t;
	m->ToString(t);
	return o << t;
}


class HuffmanTreeNode {
public:
	int freq;
	char character;
	HuffmanTreeNode *left, *right;

	HuffmanTreeNode() {} //Le'Mode
	HuffmanTreeNode(char c, int f, HuffmanTreeNode* l, HuffmanTreeNode* r) {
		character = c;
		freq = f;
		left = l;
		r = right;
	}

	bool operator >(HuffmanTreeNode other) {
		std::cout << "Comp callled!!!!!!!!!!\n";
		return this->freq > other.freq;
	}
	bool operator >(HuffmanTreeNode *other) {
		std::cout << "Comp callled!!!!!!!!!!\n";
		return this->freq > other->freq;
	}
	bool operator <(HuffmanTreeNode other) {
		return this->freq < other.freq;
	}
	bool operator <(HuffmanTreeNode* other) {
		return this->freq < other->freq;
	}
	////////////////////////////////////

	bool operator >=(HuffmanTreeNode other) {
		return this->freq >= other.freq;
	}
	bool operator >=(HuffmanTreeNode* other) {
		return this->freq >= other->freq;
	}
	bool operator <=(HuffmanTreeNode other) {
		return this->freq <= other.freq;
	}
	bool operator <=(HuffmanTreeNode* other) {
		return this->freq <= other->freq;
	}

	void ToString(std::string & s) {
		s = "freq:";
		s += std::to_string(freq);
		s += " character: ";
		s += character;
	}

};

std::ostream& operator<<(std::ostream& o, HuffmanTreeNode node) {
	std::string s;
	node.ToString(s);
	return o << s;
}
std::ostream& operator<<(std::ostream& o, HuffmanTreeNode* node) {
	std::string s;
	node->ToString(s);
	return o << s;
}

uint32_t* GetFreqsOfChars(const char* str) {
	//This functions gets the frequency of all ascii characters
	uint32_t* freqs = new uint32_t[128]{};
	//acts like a hash-map ;)


	for (int i = 0; i < strlen(str); i++) {
		assert(str[i] < pow(2, 7));
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
	auto m = new MaxHeap<HuffmanTreeNode>();

	for (short i = 0; i < 128; i++) {
		if(freqs[i]) m->Insert(
			 HuffmanTreeNode( (char)i, freqs[i], nullptr, nullptr)
		);
	}
	std::cout << "\nFinal heap :\n";
	m->PrintHeap();
	std::cout << "\n";
	return  const_cast<char*>(str);
}

int main() {
	using namespace std;
	cout << HuffmanCompress("Hello this is good");
	//cout << HuffmanCompress("Ebenezer Shimeles Went to the grocery to buy water!");
	//{
	//	auto m = new MaxHeap<int>(1);
	//	m->Insert(10);
	//	m->Insert(20);
	//	m->Insert(200);
	//	m->Insert(2);
	//	m->Insert(10000);
	//	m->Insert(-1);
	//	m->Insert(100);
	//	m->Insert(30);
	//	m->Insert(1000000);

	//	cout << "\n\n\n\n\n" <<  m <<endl<<endl<<endl;

	//	

	//	//cout << "Min " << m->Min() << " Max " << m->Max() << endl;
	//	cout << "Size is " << m->Size() <<endl;
	//	int s = m->Size();
	//	for (int i = 0; i < s; i++) {
	//		cout << "i:" << i  << " E:" << m->Pop()  << " size is " << m->Size() << ", ";
	//	 
	//    }
	//	cout << "\nFinal Size is " << m->Size() << endl;
	//	//delete m;
	//}


}


