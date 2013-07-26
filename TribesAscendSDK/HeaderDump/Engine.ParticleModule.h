#pragma once
#include "Core.Object.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModule." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModule." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModule : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, ModuleEditorColor, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LODValidity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequiresLoopingNotification, 0x400)
		ADD_VAR(::BoolProperty, bSupportsRandomSeed, 0x200)
		ADD_VAR(::BoolProperty, LODDuplicate, 0x100)
		ADD_VAR(::BoolProperty, bEditable, 0x80)
		ADD_VAR(::BoolProperty, bEnabled, 0x40)
		ADD_VAR(::BoolProperty, bSupported3DDrawMode, 0x20)
		ADD_VAR(::BoolProperty, b3DDrawMode, 0x10)
		ADD_VAR(::BoolProperty, bCurvesAsColor, 0x8)
		ADD_VAR(::BoolProperty, bFinalUpdateModule, 0x4)
		ADD_VAR(::BoolProperty, bUpdateModule, 0x2)
		ADD_VAR(::BoolProperty, bSpawnModule, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
