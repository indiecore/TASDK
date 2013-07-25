#pragma once
#include "Engine__GameEngine.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlatformCommon.TgGameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TgGameEngine : public GameEngine
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pEventMarshal'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pOutgoingMarshal'!
	};
}
#undef ADD_STRUCT
