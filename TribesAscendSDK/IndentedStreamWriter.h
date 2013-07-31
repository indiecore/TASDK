#pragma once
#include <fstream>

class IndentedStreamWriter
{
private:
	std::ofstream innerStream;
	char currentIndent[64];
	bool curIndented;
	int indent;

public:
	IndentedStreamWriter::IndentedStreamWriter(const char* fileName)
	{
		indent = 0;
		curIndented = false;
		memset(&currentIndent, '\0', 64);
		this->innerStream.open(fileName, std::ios::trunc);
	}
	~IndentedStreamWriter()
	{
		this->Close();
	}
	
	int GetIndent() { return indent; }
	void SetIndent(int indent_) 
	{
		if (indent != indent_)
		{
			indent = indent_;
			memset(&currentIndent, '\t', indent);
			currentIndent[indent] = '\0';
		}
	}
	__declspec(property(put=SetIndent, get=GetIndent)) int Indent;
	
	void Close()
	{
		this->Flush();
		this->innerStream.close();
	}
	void Flush()
	{
		this->innerStream.flush();
	}

	void Write(const char* message, ...);
	void WriteLine(const char* message, ...);
};