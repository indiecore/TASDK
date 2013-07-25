#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PostProcessEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PostProcessEffect : public Object
	{
	public:
		ADD_VAR(::ByteProperty, SceneDPG, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InDrawY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OutDrawY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosY, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EffectName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAffectsLightingOnly, 0x8)
		ADD_VAR(::BoolProperty, bUseWorldSettings, 0x4)
		ADD_VAR(::BoolProperty, bShowInGame, 0x2)
		ADD_VAR(::BoolProperty, bShowInEditor, 0x1)
	};
}
#undef ADD_VAR
