#pragma once
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LightFunction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LightFunction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LightFunction." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LightFunction : public Object
	{
	public:
		ADD_VAR(::FloatProperty, DisabledBrightness, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scale, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, SourceMaterial)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
