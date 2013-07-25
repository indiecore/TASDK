#pragma once
#include "Engine__SequenceVariable.h"
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqVar_Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqVar_Object." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqVar_Object : public SequenceVariable
	{
	public:
		ADD_STRUCT(::VectorProperty, ActorLocation, 0xFFFFFFFF
		ADD_OBJECT(Object, ObjValue)
		// Here lies the not-yet-implemented method 'GetObjectValue'
		// Here lies the not-yet-implemented method 'SetObjectValue'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
