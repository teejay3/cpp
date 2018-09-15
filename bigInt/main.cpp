#include "main.h"
#include <iostream>

int main()
{
#if defined (__APPLE__)
	std::locale current_locale("");
	std::locale::global(current_locale);
	std::wcout.imbue(current_locale);
#elif defined (_WIN32) || defined (_WIN64)
	std::locale rus("rus_rus.866");
	std::wcout.imbue(rus);
#endif
#if defined _DEBUG
	std::wcout << L"Debug mode" << std::endl;
#endif

	unsigned char* src = input_array(); 
	print(src, length(src));
	BigInteger* result = convert(src);
	std::cout << "result structure:" << std::endl;
	print(result->p, result->n);

	delete[] result->p;
	result->p = nullptr;
	delete result;
	result = nullptr;
	delete[] src;
	src = nullptr;

#if defined (_DEBUG) && ((_WIN32) || defined (_WIN64))
	std::cout << _CrtDumpMemoryLeaks() << std::endl;
#endif
	return 0;
}
