#pragma once
#include "Engine.Material.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Actor.TraceHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Actor.TraceHitInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TraceHitInfo
	{
	public:
		ADD_OBJECT(Material, Material)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial)
		ADD_VAR(::IntProperty, Item, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LevelIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
