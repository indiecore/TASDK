#pragma once
#include "Engine.Console.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTConsole : public Console
	{
	public:
		ADD_STRUCT(int, TextCount, 452)
		bool AnyBrowserOpen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44076);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool InputKey(int ControllerId, ScriptName Key, Object::EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44078);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void OutputTextLine(ScriptString* Text, Object::Color OverrideColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44093);
			byte params[16] = { NULL };
			*(ScriptString**)params = Text;
			*(Object::Color*)&params[12] = OverrideColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
