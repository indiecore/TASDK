#include "TASDK.h"
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

ofstream log_file;

extern const char *kLogName;

void InitLogging()
{
	log_file.open( kLogName, ios::out );
	log_file.close();
}

void OutputLog( const char * message, ... )
{
	log_file.open( kLogName, ios::app );

	char buffer[ 512 ] = { NULL };
	
	va_list lst;
	
	va_start( lst, message );
	vsprintf_s( buffer, message, lst );
	va_end( lst );

	log_file << buffer;

	log_file.flush();
	log_file.close();
}

void InitLoggingTo( const char *log_name )
{
	log_file.open( log_name, ios::out );
	log_file.close();
}

void OutputLogTo( const char *log_name, const char * message, ... )
{
	log_file.open( log_name, ios::app );

	char buffer[ 512 ] = { NULL };
	
	va_list lst;
	
	va_start( lst, message );
	vsprintf_s( buffer, message, lst );
	va_end( lst );

	log_file << buffer;

	log_file.flush();
	log_file.close();
}