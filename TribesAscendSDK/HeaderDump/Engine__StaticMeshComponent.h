#pragma once
#include "Engine__MeshComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.StaticMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.StaticMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.StaticMeshComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StaticMeshComponent : public MeshComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightmassPrimitiveSettings' for the property named 'LightmassSettings'!
		ADD_VAR(::IntProperty, VertexPositionVersionNumber, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeverBecomeDynamic, 0x1)
		ADD_VAR(::ByteProperty, SimpleLightmapModificationFunction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ForcedLodModel, 0xFFFFFFFF)
		ADD_OBJECT(Texture, SimpleLightmapModificationTexture)
		ADD_VAR(::BoolProperty, bUseSimpleLightmapModifications, 0x8)
		ADD_VAR(::BoolProperty, bCanHighlightSelectedSections, 0x4)
		ADD_VAR(::BoolProperty, bForceStaticDecals, 0x2)
		ADD_VAR(::BoolProperty, bUseSubDivisions, 0x1)
		ADD_VAR(::IntProperty, SubDivisionStepSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OverriddenLODMaxRange, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OverriddenLightMapRes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OverriddenLightMapResolution, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverrideLightMapRes, 0x4)
		ADD_VAR(::BoolProperty, bOverrideLightMapResolution, 0x2)
		ADD_VAR(::BoolProperty, bIgnoreInstanceForTextureStreaming, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WireframeColor'!
		ADD_OBJECT(StaticMesh, StaticMesh)
		ADD_VAR(::IntProperty, PreviousLODLevel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
