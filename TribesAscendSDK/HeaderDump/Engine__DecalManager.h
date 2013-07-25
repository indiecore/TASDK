#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DecalManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DecalManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DecalManager : public Actor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'DecalBlendRange'!
		ADD_VAR(::FloatProperty, DecalDepthBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxActiveDecals, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AreDynamicDecalsEnabled'
		// Here lies the not-yet-implemented method 'DecalFinished'
		// Here lies the not-yet-implemented method 'CanSpawnDecals'
		// Here lies the not-yet-implemented method 'SetDecalParameters'
		// Here lies the not-yet-implemented method 'GetPooledComponent'
		// Here lies the not-yet-implemented method 'SpawnDecal'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
