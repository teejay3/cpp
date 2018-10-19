#pragma once
class MyString
{
public:
    char* m_pStr;	//строка-член класса
	size_t length;
public:
	~MyString();
	MyString();
	explicit MyString(const char* str);
	MyString(const MyString& str);
	MyString(MyString&& str);
	const char* print();
	size_t len(const char* str) const;
	size_t len();
	void PrintString() const;
	const char* GetString() const;
	MyString& operator= (const MyString& str);
	MyString& MyString::operator= (const char* str);
	void SetNewString(const char* new_string);
	MyString& operator+=(const MyString& str);
	
};
