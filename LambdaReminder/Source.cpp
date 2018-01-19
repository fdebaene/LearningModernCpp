#include <algorithm>  
#include <array>
#include <iostream>


void sortArray(std::array<int,10>& arr) {
	//basic sort without capture([] empty)
	int toCapture = 10;
	std::sort(arr.begin(),arr.end(),
		[](int a, int  b) {
			return (std::abs(a) < std::abs(b));
		} 
	);
	//capture default by reference [&]
	std::sort(arr.begin(), arr.end(),
		[&](int a, int  b) {
			toCapture ++;
			return (std::abs(a) < std::abs(b));
		}
	);
	std::cout << toCapture << std::endl;
	//capture default by copy [=]
	std::sort(arr.begin(), arr.end(),
		[=](int a, int  b) {
		// toCapture += 1; to capture is readOnly
		return (std::abs(a) < std::abs(b));
		}
	);
	//generalized with only a ref
	std::sort(arr.begin(), arr.end(),
		[&newVar =  toCapture](int a, int  b) {
		newVar--;	
		return (std::abs(a) < std::abs(b));
		}
	);
	std::cout << toCapture << std::endl;

}

int main(int argc, char** argv)
{
	
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,0 };
	sortArray(arr);
	std::cin.get();
	return 0;
}