#pragma once
#include "Engine.SeqVar_Object.h"
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
	class SeqVar_Player : public SeqVar_Object
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, Players, 176)
		ADD_STRUCT(int, PlayerIdx, 192)
		ADD_BOOL(bAllPlayers, 188, 0x1)
		void UpdatePlayersList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_Player.UpdatePlayersList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Object* GetObjectValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_Player.GetObjectValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
