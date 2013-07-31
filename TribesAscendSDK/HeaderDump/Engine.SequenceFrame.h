#pragma once
#include "Engine.Texture2D.h"
#include "Engine.SequenceObject.h"
#include "Engine.Material.h"
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
	class SequenceFrame : public SequenceObject
	{
	public:
		ADD_OBJECT(Material, FillMaterial, 168)
		ADD_OBJECT(Texture2D, FillTexture, 164)
		ADD_STRUCT(Object::Color, FillColor, 160)
		ADD_STRUCT(Object::Color, BorderColor, 156)
		ADD_BOOL(bTileFill, 152, 0x4)
		ADD_BOOL(bFilled, 152, 0x2)
		ADD_BOOL(bDrawBox, 152, 0x1)
		ADD_STRUCT(int, BorderWidth, 148)
		ADD_STRUCT(int, SizeY, 144)
		ADD_STRUCT(int, SizeX, 140)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
