#pragma once
#include "Engine.Actor.h"
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
	class ActorFactory : public Object
	{
	public:
		ADD_BOOL(bShowInEditorQuickMenu, 88, 0x2)
		ADD_BOOL(bPlaceable, 88, 0x1)
		ADD_OBJECT(ScriptClass, NewActorClass, 84)
		ADD_STRUCT(int, AlternateMenuPriority, 80)
		ADD_STRUCT(int, MenuPriority, 76)
		ADD_STRUCT(ScriptString*, MenuName, 64)
		ADD_OBJECT(ScriptClass, GameplayActorClass, 60)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorFactory.PostCreateActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
