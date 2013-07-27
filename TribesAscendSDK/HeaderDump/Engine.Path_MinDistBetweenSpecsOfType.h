#pragma once
#include "Engine.PathConstraint.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Path_MinDistBetweenSpecsOfType : public PathConstraint
	{
	public:
		ADD_OBJECT(ScriptClass, ReachSpecClass, 84)
		ADD_STRUCT(Vector, InitLocation, 72)
		ADD_STRUCT(float, MinDistBetweenSpecTypes, 68)
		bool EnforceMinDist(class Pawn* P, float InMinDist, ScriptClass* InSpecClass, Vector LastLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23976);
			byte params[28] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = InMinDist;
			*(ScriptClass**)&params[8] = InSpecClass;
			*(Vector*)&params[12] = LastLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23983);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
