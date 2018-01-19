#include <utility>
#include <iostream>

void isDetectValueType(int&& rvalue)
{
	std::cout << "input was a rvalue" << std::endl;
}
void isDetectValueType(int& lvalue)
{
	std::cout << "input was a lvalue" << std::endl;
}
int generateRValue() { return 0; }
template <typename T>
void doStuff(T&& param)//universal reference
{
	isDetectValueType(param);//lvalue because param is a lvalue ( even if it was initialized by a rvalue)
	isDetectValueType(std::forward<T>(param) ); //std::forward convert cast param  to rvalue T if was initialize by a rvalue, lvalue otherwise
}

int main(int argc, char** argv)
{
	doStuff(generateRValue());

	int&& a =generateRValue();  // no type detection with && => rvalue
	auto&& b = generateRValue(); //type detection with && => universal value
	std::cin.get();
	return 0;
}