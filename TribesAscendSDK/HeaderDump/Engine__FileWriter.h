#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FileWriter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FileWriter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FileWriter : public Info
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ArchivePtr'!
		ADD_VAR(::StrProperty, Filename, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FileType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFlushEachWrite, 0x1)
		ADD_VAR(::BoolProperty, bWantsAsyncWrites, 0x2)
		// Here lies the not-yet-implemented method 'OpenFile'
		// Here lies the not-yet-implemented method 'CloseFile'
		// Here lies the not-yet-implemented method 'Logf'
		// Here lies the not-yet-implemented method 'Destroyed'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
