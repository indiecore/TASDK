#pragma once
#include "Engine.Scout.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKScout : public Scout
	{
	public:
		ADD_STRUCT(ScriptName, SizePersonFindName, 1296)
		ADD_OBJECT(ScriptClass, PrototypePawnClass, 1292)
		ADD_STRUCT(float, MaxDoubleJumpHeight, 1288)
		ADD_BOOL(bRequiresDoubleJump, 1284, 0x1)
		bool SuggestJumpVelocity(Object::Vector& JumpVelocity, Object::Vector Destination, Object::Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKScout.SuggestJumpVelocity");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = JumpVelocity;
			*(Object::Vector*)&params[12] = Destination;
			*(Object::Vector*)&params[24] = Start;
			*(bool*)&params[36] = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			JumpVelocity = *(Object::Vector*)&params[0];
			return *(bool*)&params[40];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
