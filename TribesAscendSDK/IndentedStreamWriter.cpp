#include "TASDK.h"
#include "IndentedStreamWriter.h"
#include <fstream>
#include <string>
#include <cstdio>

void IndentedStreamWriter::Write(const char* message, ...)
{
	char buffer[2048] = { NULL };
	
	va_list lst;
	
	va_start(lst, message);
	vsprintf_s(buffer, message, lst);
	va_end(lst);

	if (!this->curIndented)
	{
		this->innerStream << &this->currentIndent;
		this->curIndented = true;
	}
	this->innerStream << buffer;
}
void IndentedStreamWriter::WriteLine(const char* message, ...)
{
	char buffer[2048] = { NULL };
	
	va_list lst;
	
	va_start(lst, message);
	vsprintf_s(buffer, message, lst);
	va_end(lst);
	
	if (!this->curIndented)
	{
		this->innerStream << &this->currentIndent;
		this->curIndented = true;
	}
	this->innerStream << buffer;
	this->innerStream << "\n";
	this->curIndented = false;
}