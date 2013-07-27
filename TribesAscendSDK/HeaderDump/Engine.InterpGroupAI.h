#pragma once
#include "Engine.Pawn.h"
#include "Engine.InterpGroup.h"
#include "Engine.Actor.h"
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
	class InterpGroupAI : public InterpGroup
	{
	public:
		ADD_BOOL(bNoEncroachmentCheck, 124, 0x2)
		ADD_BOOL(SnapToRootBoneLocationWhenFinished, 124, 0x1)
		ADD_OBJECT(Actor, StageMarkActor, 120)
		ADD_OBJECT(Pawn, PreviewPawn, 116)
		ADD_STRUCT(ScriptName, StageMarkGroup, 108)
		ADD_OBJECT(ScriptClass, PreviewPawnClass, 104)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
