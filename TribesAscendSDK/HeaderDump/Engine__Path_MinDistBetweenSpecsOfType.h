#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Path_MinDistBetweenSpecsOfType." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Path_MinDistBetweenSpecsOfType : public PathConstraint
	{
	public:
		ADD_OBJECT(ScriptClass, ReachSpecClass)
		ADD_STRUCT(::VectorProperty, InitLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MinDistBetweenSpecTypes, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'EnforceMinDist'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
