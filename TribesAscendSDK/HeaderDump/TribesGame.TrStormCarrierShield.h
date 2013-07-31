#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.DynamicSMActor.h"
#include "TribesGame.TrStormCore.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrStormCarrierShield : public DynamicSMActor
	{
	public:
		ADD_OBJECT(TrStormCore, m_AssociatedCarrierCore, 536)
		ADD_BOOL(m_bAreShieldsUp, 532, 0x1)
		void OnShieldsDestroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112740);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112741);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
