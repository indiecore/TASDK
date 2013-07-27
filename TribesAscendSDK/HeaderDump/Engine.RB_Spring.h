#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class RB_Spring : public ActorComponent
	{
	public:
		ADD_STRUCT(float, DampMaxForce, 164)
		ADD_STRUCT(float, DampSaturateVel, 160)
		ADD_STRUCT(Object::InterpCurveFloat, SpringMaxForceTimeScale, 144)
		ADD_STRUCT(float, MaxForceMassRatio, 140)
		ADD_STRUCT(float, SpringMaxForce, 136)
		ADD_STRUCT(float, SpringSaturateDist, 132)
		ADD_STRUCT(float, MinBodyMass, 128)
		ADD_STRUCT(float, TimeSinceActivation, 124)
		ADD_STRUCT(Object::Pointer, SpringData, 120)
		ADD_BOOL(bEnableForceMassRatio, 116, 0x2)
		ADD_BOOL(bInHardware, 116, 0x1)
		ADD_STRUCT(int, SceneIndex, 112)
		ADD_STRUCT(ScriptName, BoneName2, 104)
		ADD_STRUCT(ScriptName, BoneName1, 92)
		void SetComponents(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent1, ScriptName InBoneName1, Object::Vector Position1, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent2, ScriptName InBoneName2, Object::Vector Position2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Spring.SetComponents");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = InComponent1;
			*(ScriptName*)&params[4] = InBoneName1;
			*(Object::Vector*)&params[12] = Position1;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[24] = InComponent2;
			*(ScriptName*)&params[28] = InBoneName2;
			*(Object::Vector*)&params[36] = Position2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Spring.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
