#pragma once
#include "Engine.Interaction.h"
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
	class Input : public Interaction
	{
	public:
		struct KeyBind
		{
		public:
			ADD_BOOL(bIgnoreAlt, 20, 0x20)
			ADD_BOOL(bIgnoreShift, 20, 0x10)
			ADD_BOOL(bIgnoreCtrl, 20, 0x8)
			ADD_BOOL(Alt, 20, 0x4)
			ADD_BOOL(Shift, 20, 0x2)
			ADD_BOOL(Control, 20, 0x1)
			ADD_STRUCT(ScriptString*, Command, 8)
			ADD_STRUCT(ScriptName, Name, 0)
		};
		ADD_STRUCT(ScriptArray<Input::KeyBind>, Bindings, 108)
		ADD_STRUCT(ScriptArray<ScriptName>, PressedKeys, 120)
		ADD_STRUCT(ScriptArray<Object::Pointer>, AxisArray, 204)
		ADD_STRUCT(float, CurrentDeltaTime, 140)
		ADD_STRUCT(float, CurrentDelta, 136)
		ADD_STRUCT(Object::EInputEvent, CurrentEvent, 132)
		void ResetInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13920);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetBind(ScriptName& Key)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13921);
			byte params[20] = { NULL };
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Key = *(ScriptName*)params;
			return *(ScriptString**)&params[8];
		}
		ScriptString* GetBindNameFromCommandScript(ScriptString*& KeyCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13924);
			byte params[24] = { NULL };
			*(ScriptString**)params = KeyCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			KeyCommand = *(ScriptString**)params;
			return *(ScriptString**)&params[12];
		}
		void SetBind(ScriptName& BindName, ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13927);
			byte params[20] = { NULL };
			*(ScriptName*)params = BindName;
			*(ScriptString**)&params[8] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BindName = *(ScriptName*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
