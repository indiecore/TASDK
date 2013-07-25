#pragma once
#include "Engine__Actor.h"
#include "Engine__Prefab.h"
#include "Engine__PrefabSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PrefabInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PrefabInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PrefabInstance : public Actor
	{
	public:
		ADD_VAR(::IntProperty, PI_LicenseePackageVersion, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PI_PackageVersion, 0xFFFFFFFF)
		ADD_OBJECT(PrefabSequence, SequenceInstance)
		ADD_VAR(::IntProperty, TemplateVersion, 0xFFFFFFFF)
		ADD_OBJECT(Prefab, TemplatePrefab)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
