#pragma once
#include "Engine.InterpTrack.h"
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
	class InterpTrackBoolProp : public InterpTrack
	{
	public:
		struct BoolTrackKey
		{
		public:
			ADD_BOOL(Value, 4, 0x1)
			ADD_STRUCT(float, Time, 0)
		};
		ADD_STRUCT(ScriptArray<InterpTrackBoolProp::BoolTrackKey>, BoolTrack, 128)
		ADD_STRUCT(ScriptName, PropertyName, 140)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
