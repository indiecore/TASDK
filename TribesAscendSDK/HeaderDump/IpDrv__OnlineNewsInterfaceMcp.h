#pragma once
#include "IpDrv__MCPBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineNewsInterfaceMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineNewsInterfaceMcp : public MCPBase
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsTicking, 0x1)
		// Here lies the not-yet-implemented method 'OnReadNewsCompleted'
		// Here lies the not-yet-implemented method 'ReadNews'
		// Here lies the not-yet-implemented method 'AddReadNewsCompletedDelegate'
		// Here lies the not-yet-implemented method 'ClearReadNewsCompletedDelegate'
		// Here lies the not-yet-implemented method 'GetNews'
	};
}
#undef ADD_VAR
