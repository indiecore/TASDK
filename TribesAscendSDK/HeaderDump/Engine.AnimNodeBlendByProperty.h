#pragma once
#include "Engine.AnimNodeBlendList.h"
#include "Core.Object.h"
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
	class AnimNodeBlendByProperty : public AnimNodeBlendList
	{
	public:
		ADD_STRUCT(float, BlendToChild2Time, 328)
		ADD_STRUCT(float, BlendToChild1Time, 324)
		ADD_STRUCT(float, FloatPropMax, 320)
		ADD_STRUCT(float, FloatPropMin, 316)
		ADD_STRUCT(float, BlendTime, 312)
		ADD_OBJECT(Actor, CachedOwner, 308)
		ADD_STRUCT(Object::Pointer, CachedByteProperty, 304)
		ADD_STRUCT(Object::Pointer, CachedBoolProperty, 300)
		ADD_STRUCT(Object::Pointer, CachedFloatProperty, 296)
		ADD_STRUCT(ScriptName, CachedPropertyName, 288)
		ADD_BOOL(bSynchronizeNodesInEditor, 284, 0x8)
		ADD_BOOL(bUseSpecificBlendTimes, 284, 0x4)
		ADD_BOOL(bForceUpdate, 284, 0x2)
		ADD_BOOL(bUseOwnersBase, 284, 0x1)
		ADD_STRUCT(ScriptName, PropertyName, 276)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
