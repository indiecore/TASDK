#pragma once
#include "Core.Object.QWord.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.UniqueNetId." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UniqueNetId
	{
	public:
		ADD_STRUCT(::QWordProperty, Uid, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
