#pragma once
#include "Core.Object.h"
#include "GameFramework.MobileMenuObject.h"
#include "Engine.Font.h"
#include "Engine.Canvas.h"
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
	class MobileMenuLabel : public MobileMenuObject
	{
	public:
		ADD_BOOL(bAutoSize, 164, 0x1)
		ADD_STRUCT(float, TextYScale, 160)
		ADD_STRUCT(float, TextXScale, 156)
		ADD_STRUCT(Object::Color, TouchedColor, 152)
		ADD_STRUCT(Object::Color, TextColor, 148)
		ADD_OBJECT(Font, TextFont, 144)
		ADD_STRUCT(ScriptString*, Caption, 132)
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuLabel.RenderObject");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
