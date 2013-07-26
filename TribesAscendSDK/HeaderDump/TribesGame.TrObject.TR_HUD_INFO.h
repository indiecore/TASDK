#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.TR_HUD_INFO." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrObject.TR_HUD_INFO." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TR_HUD_INFO
	{
	public:
		ADD_STRUCT(::VectorProperty, vScreenLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fAlphaLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fLastSeenTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fLastUnseenTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsTarget, 0x1)
		ADD_VAR(::StrProperty, sName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nMaxHealth, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnemy, 0x1)
		ADD_VAR(::BoolProperty, bDrawStat, 0x2)
		ADD_VAR(::BoolProperty, bDrawHealth, 0x4)
		ADD_VAR(::FloatProperty, fDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, eOverlayType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nActorId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
