#include <string>
#include <iostream>
#include "myString.h"

using namespace std;

const char* MyString::print()
{
	return this->m_pStr;
}



std::size_t MyString::len(const char* str) const
{
	std::size_t len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

std::size_t MyString::len() 
{
	std::size_t len = 0;
	while (*m_pStr != '\0')
	{
		len++;
		m_pStr++;
	}
	m_pStr -= len;
	return len;
}

const char* MyString::GetString() const
{
	return this->m_pStr;
}

void MyString::PrintString() const
{
	for (std::size_t i = 0; i < length; i++)
	{
		std::cout << m_pStr[i];
	}
	std::cout << std::endl;
}

MyString& MyString::operator= (const MyString& str)
{
	if (m_pStr != str.m_pStr)
	{
		this->length = str.length;
		delete[] this->m_pStr;
		this->m_pStr = new char[this->length + 1];
		for (std::size_t i = 0; i < this->length; i++)
			this->m_pStr[i] = str.m_pStr[i];
		this->m_pStr[this->length] = '\0';
	}
	return *this;
}

MyString& MyString::operator= (const char* str)
{
	this->length = len(str);
	delete[] this->m_pStr;
	this->m_pStr = new char[this->length + 1];
	for (std::size_t i = 0; i < this->length; i++)
		this->m_pStr[i] = str[i];
	this->m_pStr[this->length] = '\0';
	return *this;
}

void MyString::SetNewString(const char* new_string)
{
	this->length = len(new_string);
	delete[] this->m_pStr;
	this->m_pStr = new char[this->length + 1];
	for (std::size_t i = 0; i < this->length + 1; i++)
		this->m_pStr[i] = new_string[i];
}

MyString& MyString::operator+=(const MyString& str)
{
	MyString tmp = *this;
	delete[] this->m_pStr;
	this->length = tmp.length + str.length;
	std::cout << "new length " << this->length << std::endl;
	this->m_pStr = new char[this->length + 1];
	char* ptmp = this->m_pStr;
	for (std::size_t i = 0; i < tmp.length; i++)
		this->m_pStr[i] = tmp.m_pStr[i];
	for (std::size_t i = 0; i < str.length; i++)
		this->m_pStr[i + tmp.length] = str.m_pStr[i];
	this->m_pStr[this->length + str.length] = '\0';
	return *this;
}



// Определение конструктора.
MyString::MyString() 
{
	std::cout << "Default MyString constructor" << std::endl;
	m_pStr = new char[1];
	*m_pStr = '\0'; 
	length = MyString::len(m_pStr);
}

MyString::MyString(const char* str) 
{ 	
	length = len(str);
	m_pStr = new char[length + 1];
	for (std::size_t i = 0; i < length ; i++)
	{
		m_pStr[i] = *str;
		str++;
	}
	m_pStr[length] = '\0';
}

MyString::MyString(MyString&& str) :m_pStr(str.m_pStr), length(str.length)
{
	str.m_pStr = nullptr;
	str.length = 0;
}

MyString::MyString(const MyString& str)
{
	length = str.length;
	m_pStr = new char[length + 1];
	for (std::size_t i = 0; i < length + 1; i++)
	{
		m_pStr[i] = str.m_pStr[i];
	}
}
// Определение деструктора.
MyString::~MyString() 
{
	std::cout << "destructor\n";
	delete[] m_pStr;
}


