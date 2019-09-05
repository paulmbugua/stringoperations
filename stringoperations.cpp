#include <iostream>
#include "stringconverter.h"

int main() {
	CStringW a = "Test";
	std::wstring b = stringconv::CStringWtowstring(a);
	std::wcout << b;
	return 0;
}