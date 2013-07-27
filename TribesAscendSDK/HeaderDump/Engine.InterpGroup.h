#pragma once
#include "Core.Object.h"
#include "Engine.InterpTrack.h"
#include "Engine.AnimSet.h"
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
	class InterpGroup : public Object
	{
	public:
		class InterpEdSelKey
		{
		public:
			ADD_STRUCT(float, UnsnappedPosition, 12)
			ADD_STRUCT(int, KeyIndex, 8)
			ADD_OBJECT(InterpTrack, Track, 4)
			ADD_OBJECT(InterpGroup, Group, 0)
		};
		ADD_STRUCT(ScriptArray<class InterpTrack*>, InterpTracks, 64)
		ADD_STRUCT(ScriptArray<class AnimSet*>, GroupAnimSets, 88)
		ADD_BOOL(bIsSelected, 100, 0x10)
		ADD_BOOL(bIsParented, 100, 0x8)
		ADD_BOOL(bIsFolder, 100, 0x4)
		ADD_BOOL(bVisible, 100, 0x2)
		ADD_BOOL(bCollapsed, 100, 0x1)
		ADD_STRUCT(Object::Color, GroupColor, 84)
		ADD_STRUCT(ScriptName, GroupName, 76)
		ADD_STRUCT(Object::Pointer, VfTable_FInterpEdInputInterface, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
