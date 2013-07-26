#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrObject.TrTakeEffectInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrObject.TrTakeEffectInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTakeEffectInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, EffectForm)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
