#pragma once
#include "TribesGame.TrProj_Tracer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObjectPool.TracerCacheInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrObjectPool.TracerCacheInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TracerCacheInfo
	{
	public:
		ADD_OBJECT(TrProj_Tracer, List)
		ADD_VAR(::IntProperty, ListIdx, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, TracerClass)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
