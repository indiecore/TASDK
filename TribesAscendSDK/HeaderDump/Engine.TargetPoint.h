#pragma once
#include "Engine.Keypoint.h"
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TargetPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TargetPoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TargetPoint : public Keypoint
	{
	public:
		ADD_VAR(::IntProperty, SpawnRefCount, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, SpawnSpriteTexture)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
