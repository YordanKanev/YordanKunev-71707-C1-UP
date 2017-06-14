#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
	String();
	String(const char* data);
	String(const String& other);
	String& operator=(const String&);
	~String();

	char getAt(size_t index);
	void setAt(size_t index, char symbol);


	void concat(const String&);
	void concat(const char* other);

	const char* GetData()const;

	String& operator+=(const String& rhs);
	String& operator-=(const String& rhs);

	bool operator==(const String& rhs);
	bool operator!=(const String& rhs);


	bool operator< (const String& rhs);
	bool operator> (const String& rhs);
	bool operator<=(const String& rhs);
	bool operator>=(const String& rhs);
	friend std::istream& operator >> (std::istream& is, String& obj);
	friend std::ostream& operator<<(std::ostream& os, const String& obj);

private:
	void copy(const String&);
	void copy(const char*);
	void destroy();


	char* data;
	size_t size;
};