#pragma once
#include "Core__Object.h"
#include "Engine__Texture2D.h"
#include "Engine__PrefabSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Prefab." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Prefab." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Prefab : public Object
	{
	public:
		ADD_OBJECT(Texture2D, PrefabPreview)
		ADD_OBJECT(PrefabSequence, PrefabSequence)
		ADD_VAR(::IntProperty, PrefabVersion, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
