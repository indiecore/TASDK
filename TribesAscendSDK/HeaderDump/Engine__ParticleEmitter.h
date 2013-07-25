#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleEmitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleEmitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEmitter : public Object
	{
	public:
		ADD_VAR(::IntProperty, InitialAllocationCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PeakActiveParticles, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCookedOut, 0x8)
		ADD_VAR(::BoolProperty, bIsSoloing, 0x4)
		ADD_VAR(::BoolProperty, bCollapsed, 0x2)
		ADD_VAR(::BoolProperty, ConvertedModules, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'EmitterEditorColor'!
		ADD_VAR(::ByteProperty, EmitterRenderMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SubUVDataOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EmitterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
