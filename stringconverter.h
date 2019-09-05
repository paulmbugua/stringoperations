#include <stdlib.h>
#include <string>
#include <codecvt>
#include <locale>
#include <atlbase.h>
#include <atlstr.h>
#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")
namespace stringconv {
	using convert_t = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_t, wchar_t> strconverter;

	char* stringTochararray(std::string s) {
		const size_t len = (strlen(s.c_str()) + 1) * 2;
		char* result = new char[len];
		strcpy_s(result, len, s.c_str());
		return result;
	}

	wchar_t* stringTowchar_tarray(std::string s) {
		const size_t len = strlen(s.c_str()) + 1;
		size_t con = 0;
		wchar_t* result = new wchar_t[len];
		mbstowcs_s(&con, result, len, s.c_str(), _TRUNCATE);
		return result;
	}

	_bstr_t stringTo_bstr_t(std::string s) {
		_bstr_t result(s.c_str());
		return result;
	}

	CComBSTR stringToCComBSTR(std::string s) {
		CComBSTR result(s.c_str());
		return result;
	}

	CStringA stringToCStringA(std::string s) {
		CStringA result(s.c_str());
		return result;
	}

	CStringW stringToCStringW(std::string s) {
		CStringW result(s.c_str());
		return result;
	}

	std::string chararrayTostring(char* c) {
		std::string result(c);
		return result;
	}

	std::string wstringTostring(std::wstring wstr)
	{
		return strconverter.to_bytes(wstr);
	}

	std::wstring stringTowstring(std::string str)
	{
		return strconverter.from_bytes(str);
	}

	double stringTodouble(std::string d) {
		return std::stod(d);
	}

	int stringToint(std::string i) {
		return std::stoi(i);
	}

	long stringTolong(std::string l) {
		return std::stol(l);
	}

	long long stringTolonglong(std::string ll) {
		return std::stoll(ll);
	}

	float stringTofloat(std::string f) {
		return std::stof(f);
	}

	long double stringTolongdouble(std::string ld) {
		return std::stold(ld);
	}

	int  stringhexToint(std::string sh) {
		return std::stoi(sh, 0, 16);
	}

	int  stringoctToint(std::string so) {
		return std::stoi(so, 0, 8);
	}

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> wchar_to_utf8;
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> utf16_to_utf8;

	std::string wstringToutf8string(std::wstring w) {
		return wchar_to_utf8.to_bytes(w);
	}

	std::wstring utf8stringTowstring(std::string utf8) {
		return wchar_to_utf8.from_bytes(utf8);
	}

	std::string u16stringToutf8string(std::u16string u16) {
		return utf16_to_utf8.to_bytes(u16);
	}

	std::u16string utf8stringTou16string(std::string utf8) {
		return utf16_to_utf8.from_bytes(utf8);
	}

	char* wchar_tarrayTochararray(wchar_t* wa) {
		size_t len = wcslen(wa) + 1;
		size_t conv = 0;

		const size_t newsize = len * 2;
		char* result = new char[newsize];

		wcstombs_s(&conv, result, newsize, wa, _TRUNCATE);

		return result;
	}

	_bstr_t  wchar_tarrayTo_bstr_t(wchar_t* wa) {
		_bstr_t bstrt(wa);
		return bstrt;
	}

	BSTR wchar_tarrayToBSTR(wchar_t* wa) {
		CComBSTR result(wa);
		//CW2A result (wchar_tarrayToBSTR(wa)); multibyte
		return result;
	}

	CStringA wchar_tarrayToCStringA(wchar_t* wa) {
		CStringA result(wa);
		return result;
	}

	CStringW wchar_tarrayToCStringW(wchar_t* wa) {
		CStringW result(wa);
		return result;
	}

	std::wstring wchar_tarrayTowstring(wchar_t* wa) {
		std::wstring result(wa);
		return result;
	}

	char* _bstr_tTochararray(_bstr_t b) {
		const size_t len = (b.length() + 1) * 2;
		char* result = new char[len];
		strcpy_s(result, len, (char*)b);
		return result;
	}

	wchar_t* _bstr_tTowchar_tarray(_bstr_t b) {
		const size_t len = b.length();
		wchar_t* result = new wchar_t[len];
		wcscpy_s(result, len, (wchar_t*)b);
		return result;
	}

	CComBSTR _bstr_tToCComBSTR(_bstr_t b) {
		CComBSTR result((char*)b);
		//CW2A printstr(result);
		return result;
	}

	CStringA  _bstr_tToCStringA(_bstr_t b) {
		CStringA result(b.GetBSTR());
		return result;
	}

	CStringW  _bstr_tToCStringW(_bstr_t b) {
		CStringW result(b.GetBSTR());
		return result;
	}

	std::string _bstr_tTostring(_bstr_t b) {
		std::string result((char*)b);
		return result;
	}

	char* CComBSTRTochararray(CComBSTR c) {
		const size_t len = (c.Length() + 1) * 2;
		char* result = new char[len];
		CW2A empstr(c);
		strcpy_s(result, len, empstr);
		return result;
	}

	wchar_t* CComBSTRTowchar_tarray(CComBSTR c) {
		const size_t len = c.Length();
		wchar_t* result = new wchar_t[len];
		wcscpy_s(result, len, c);
		return result;
	}

	_bstr_t CComBSTRTo_bstr_t(CComBSTR c) {
		_bstr_t result(c);
		return result;
	}

	CStringA CComBSTRToCStringA(CComBSTR c) {
		CStringA result(c);
		return result;
	}

	CStringW CComBSTRToCStringW(CComBSTR c) {
		CStringW result(c);
		return result;
	}

	std::wstring CComBSTRTowstring(CComBSTR c) {
		std::wstring result(c);
		return result;
	}

	char* CStringATochararray(CStringA a) {
		const size_t len = (a.GetLength() + 1);
		char* result = new char[len];
		strcpy_s(result, len, a);
		return result;
	}

	char* CStringWTochararray(CStringW w) {
		const size_t len = (w.GetLength() + 1) * 2;
		size_t con = 0;
		char* result = new char[len];
		wcstombs_s(&con, result, len, w, _TRUNCATE);
		return result;
	}

	wchar_t* CStringATowchar_tarray(CStringA a) {
		const size_t len = (a.GetLength() + 1);
		size_t con = 0;
		wchar_t* result = new wchar_t[len];
		mbstowcs_s(&con, result, len, a, _TRUNCATE);
		return result;
	}

	wchar_t* CStringWTowchar_tarray(CStringW w) {
		const size_t len = (w.GetLength() + 1) * 2;
		wchar_t* result = new wchar_t[len];
		wcscpy_s(result, len, w);
		return result;
	}

	_bstr_t CStringATo_bstr_t(CStringA a) {
		_bstr_t result(a);
		return result;
	}

	_bstr_t CStringWTo_bstr_t(CStringW a) {
		_bstr_t result(a);
		return result;
	}

	CComBSTR CStringAToCComBSTR(CStringA a) {
		CComBSTR result(a);
		return result;
	}

	CComBSTR CStringWToCComBSTR(CStringW a) {
		CComBSTR result(a);
		return result;
	}

	std::string CStringATostring(CStringA a) {
		std::string result(a);
		return result;
	}
	std::wstring CStringWtowstring(CStringW w) {
		std::wstring result(w);
		return result;
	}
}