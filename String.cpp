#include "stdafx.h"
#include "String.h"

void String::copy(const char* otherData)
{
	if (otherData != nullptr)
	{
		int len = strlen(otherData);
		if (len > 0)
		{
			data = new char[len + 1];
			size = len;
			strcpy(data, otherData);
		}
		else
		{
			data = new char[1];
			size = 0;
			*data = '\0';
		}
	}
	else
	{
		data = new char[1];
		size = 0;
		*data = '\0';
	}
}

void String::copy(const String& other)
{
	const char* otherData = other.GetData();
	copy(otherData);
}

void String::destroy()
{
	delete[] data;
}

String::String() : data(nullptr)
{
	copy("");
}

String::String(const char* data)
{
	copy(data);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

String::~String()
{
	destroy();
}

char String::getAt(size_t index)
{
	return this->data[index];
}

void String::setAt(size_t index, char symbol)
{
	this->data[index] = symbol;
}

void String::concat(const char* other)
{
	for (size_t i = 0; other[i] != '\0'; i++)
	{

	}
}