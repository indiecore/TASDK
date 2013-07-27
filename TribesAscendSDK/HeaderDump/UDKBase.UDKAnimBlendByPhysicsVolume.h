#pragma once
#include "UDKBase.UDKAnimBlendBase.h"
#include "Engine.PhysicsVolume.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByPhysicsVolume : public UDKAnimBlendBase
	{
	public:
		class PhysicsVolumeParams
		{
		public:
			ADD_STRUCT(float, MaxGravity, 12)
			ADD_STRUCT(float, MinGravity, 8)
			ADD_BOOL(bCheckGravity, 4, 0x2)
			ADD_BOOL(bWaterVolume, 4, 0x1)
			ADD_STRUCT(int, ChildIndex, 0)
		};
		ADD_STRUCT(ScriptArray<UDKAnimBlendByPhysicsVolume::PhysicsVolumeParams>, PhysicsParamList, 296)
		ADD_OBJECT(PhysicsVolume, LastPhysicsVolume, 308)
		void PhysicsVolumeChanged(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByPhysicsVolume.PhysicsVolumeChanged");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
