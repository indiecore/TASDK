#include <Windows.h>
#include <Psapi.h>

MODULEINFO GetModuleInfo( char *module_name )
{
	MODULEINFO info = { NULL };
	HMODULE module = GetModuleHandle( module_name );

	if( module )
	{
		GetModuleInformation( GetCurrentProcess(), module, &info, sizeof ( MODULEINFO ) );
	}

	return info;
}

uintptr_t FindPattern( void *start_address, uintptr_t file_size, const byte *pattern, const char *mask )
{
	uintptr_t pos = 0;
	int search_len = strlen( mask ) - 1;

	for( uintptr_t ret_address = ( uintptr_t )( start_address ); ret_address < ( uintptr_t )( start_address ) + file_size; ret_address++ )
	{
		if( *( byte* )ret_address == pattern[ pos ] || mask[ pos ] == '?' )
		{
			if( mask[ pos + 1 ] == '\0' )
			{
				return ret_address - search_len;
			}
					
			pos++;
		} 
		else
		{
			pos = 0;
		}		
	}

	return NULL;
}