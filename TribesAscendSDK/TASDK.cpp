#include <Windows.h>

#include "TASDK.h"
#include "Sigscans.h"

extern void ModInit();
DWORD WINAPI Init( LPVOID lpThreadParameter )
{
	InitLogging();

	MODULEINFO module_info = GetModuleInfo( "TribesAscend.exe" );

	ScriptArray< ScriptObject* > *new_object_array;
	new_object_array = *( ScriptArray< ScriptObject* >** )( FindPattern( module_info.lpBaseOfDll, module_info.SizeOfImage, kSigObjects, kMaskObjects ) + 1 );
	ScriptObject::set_object_array( new_object_array );

	ScriptArray< ScriptNameEntry* > *new_name_array;
	new_name_array = *( ScriptArray< ScriptNameEntry* >** )( FindPattern( module_info.lpBaseOfDll, module_info.SizeOfImage, kSigNames, kMaskNames ) + 2 );
	ScriptName::set_name_array( new_name_array );

	script_hooks::native_array = *( NativeFunction** )( FindPattern( module_info.lpBaseOfDll, module_info.SizeOfImage, kSigNatives, kMaskNatives ) + 3 );
	script_hooks::cleanup_stack = ( CleanupStack )( FindPattern( module_info.lpBaseOfDll, module_info.SizeOfImage, kSigCleanupStack, kMaskCleanupStack ) );

	//for( int i = 0; i < 4096; i++ )
	//{
	//	if( ( uintptr_t )( script_hooks::native_array[ i ] ) != 0x4A46E0 ) OutputLog( "native %i is 0x%X\n", i, script_hooks::native_array[ i ] );
	//}

	script_hooks::SetupHooks();
	ModInit();

	return 0;
};

bool WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
	if( dwReason == DLL_PROCESS_ATTACH )
	{
		CreateThread( NULL, 0, Init, NULL, 0, NULL );

		return true;
	}
	return false;
}