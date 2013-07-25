#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Pawn.h"
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
		ADD_STRUCT(::VectorProperty, InitLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDistBetweenSpecTypes, 0xFFFFFFFF)
		bool EnforceMinDist(class Pawn* P, float InMinDist, ScriptClass* InSpecClass, Vector LastLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_MinDistBetweenSpecsOfType.EnforceMinDist");
			byte* params = (byte*)malloc(28);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = InMinDist;
			*(ScriptClass**)(params + 8) = InSpecClass;
			*(Vector*)(params + 12) = LastLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_MinDistBetweenSpecsOfType.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
