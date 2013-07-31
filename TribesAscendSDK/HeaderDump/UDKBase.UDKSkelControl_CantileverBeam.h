#pragma once
#include "Engine.SkelControlLookAt.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_CantileverBeam : public SkelControlLookAt
	{
	public:
		ADD_STRUCT(float, PercentBeamVelocityTransfer, 364)
		ADD_STRUCT(float, SpringDamping, 360)
		ADD_STRUCT(float, SpringStiffness, 356)
		ADD_STRUCT(Vector, Velocity, 344)
		ADD_STRUCT(Vector, InitialWorldSpaceGoalOffset, 332)
		ADD_STRUCT(Vector, WorldSpaceGoal, 320)
		Vector EntireBeamVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35332);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
	};
}
#undef ADD_STRUCT
