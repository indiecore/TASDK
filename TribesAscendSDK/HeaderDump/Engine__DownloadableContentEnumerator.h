#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DownloadableContentEnumerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DownloadableContentEnumerator : public Object
	{
	public:
		ADD_VAR(::StrProperty, DLCRootDir, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnFindDLCComplete'
		// Here lies the not-yet-implemented method 'FindDLC'
		// Here lies the not-yet-implemented method 'AddFindDLCDelegate'
		// Here lies the not-yet-implemented method 'ClearFindDLCDelegate'
		// Here lies the not-yet-implemented method 'DeleteDLC'
		// Here lies the not-yet-implemented method 'InstallAllDLC'
		// Here lies the not-yet-implemented method 'InstallDLC'
		// Here lies the not-yet-implemented method 'TriggerFindDLCDelegates'
	};
}
#undef ADD_VAR
