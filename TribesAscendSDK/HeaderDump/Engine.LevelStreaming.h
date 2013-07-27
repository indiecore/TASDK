#pragma once
#include "Engine.Level.h"
#include "Engine.LevelGridVolume.h"
#include "Core.Object.h"
#include "Engine.LevelStreamingVolume.h"
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
	class LevelStreaming : public Object
	{
	public:
		ADD_STRUCT(ScriptName, PackageName, 60)
		ADD_BOOL(bHasLoadRequestPending, 96, 0x2)
		ADD_BOOL(bShouldBeLoaded, 96, 0x80)
		ADD_BOOL(bShouldBeVisible, 96, 0x100)
		ADD_BOOL(bShouldBlockOnLoad, 96, 0x200)
		ADD_STRUCT(ScriptArray<class LevelStreamingVolume*>, EditorStreamingVolumes, 104)
		ADD_STRUCT(ScriptArray<ScriptString*>, Keywords, 124)
		ADD_STRUCT(int, GridPosition, 140)
		ADD_OBJECT(LevelGridVolume, EditorGridVolume, 136)
		ADD_STRUCT(float, LastVolumeUnloadRequestTime, 120)
		ADD_STRUCT(float, MinTimeBetweenVolumeUnloadRequests, 116)
		ADD_STRUCT(Object::Color, DrawColor, 100)
		ADD_BOOL(bIsRequestingUnloadAndRemoval, 96, 0x800)
		ADD_BOOL(bDrawOnLevelStatusMap, 96, 0x400)
		ADD_BOOL(bIsFullyStatic, 96, 0x40)
		ADD_BOOL(bLocked, 96, 0x20)
		ADD_BOOL(bBoundingBoxVisible, 96, 0x10)
		ADD_BOOL(bShouldBeVisibleInEditor, 96, 0x8)
		ADD_BOOL(bHasUnloadRequestPending, 96, 0x4)
		ADD_BOOL(bIsVisible, 96, 0x1)
		ADD_STRUCT(Object::Vector, OldOffset, 84)
		ADD_STRUCT(Object::Vector, Offset, 72)
		ADD_OBJECT(Level, LoadedLevel, 68)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
