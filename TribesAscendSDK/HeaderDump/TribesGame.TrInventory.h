#pragma once
#include "UTGame.UTInventory.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrInventory : public UTInventory
	{
	public:
		ADD_STRUCT(float, m_fMaxPickupSpeed, 556)
		void DropFrom(Object::Vector StartLocation, Object::Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventory.DropFrom");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartLocation;
			*(Object::Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
