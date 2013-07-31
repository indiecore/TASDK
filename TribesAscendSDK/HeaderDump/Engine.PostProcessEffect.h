#pragma once
#include "Core.Object.h"
#include "Engine.Scene.h"
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
	class PostProcessEffect : public Object
	{
	public:
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, SceneDPG, 96)
		ADD_STRUCT(int, InDrawY, 92)
		ADD_STRUCT(int, OutDrawY, 88)
		ADD_STRUCT(int, DrawHeight, 84)
		ADD_STRUCT(int, DrawWidth, 80)
		ADD_STRUCT(int, NodePosX, 76)
		ADD_STRUCT(int, NodePosY, 72)
		ADD_STRUCT(ScriptName, EffectName, 64)
		ADD_BOOL(bAffectsLightingOnly, 60, 0x8)
		ADD_BOOL(bUseWorldSettings, 60, 0x4)
		ADD_BOOL(bShowInGame, 60, 0x2)
		ADD_BOOL(bShowInEditor, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
