#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_Deproject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqAct_Deproject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqAct_Deproject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_Deproject : public SequenceAction
	{
	public:
		ADD_STRUCT(::VectorProperty, HitNormal, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_OBJECT(Object, HitObject)
		ADD_VAR(::FloatProperty, TraceDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScreenY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScreenX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
