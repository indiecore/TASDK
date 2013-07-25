#pragma once
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNotify." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNotify : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'NotifyColor'!
	};
}
#undef ADD_STRUCT
