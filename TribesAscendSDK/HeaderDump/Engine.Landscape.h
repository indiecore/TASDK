#pragma once
#include "Engine.Info.h"
#include "Core.Object.h"
#include "Engine.EngineTypes.h"
#include "Engine.Material.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Landscape : public Info
	{
	public:
		struct LandscapeLayerInfo
		{
		public:
			ADD_OBJECT(MaterialInstanceConstant, ThumbnailMIC, 16)
			ADD_BOOL(bNoWeightBlend, 12, 0x1)
			ADD_STRUCT(float, Hardness, 8)
			ADD_STRUCT(ScriptName, LayerName, 0)
		};
		struct LandscapeWeightmapUsage
		{
		};
		ADD_STRUCT(ScriptArray<ScriptName>, LayerNames, 484)
		ADD_STRUCT(ScriptArray<Landscape::LandscapeLayerInfo>, LayerInfos, 496)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, LandscapeComponents, 604)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, CollisionComponents, 616)
		ADD_STRUCT(int, NumSubsections, 820)
		ADD_STRUCT(int, SubsectionSizeQuads, 816)
		ADD_STRUCT(int, ComponentSizeQuads, 812)
		ADD_STRUCT(Object::Pointer, DataInterface, 808)
		ADD_STRUCT(float, StreamingDistanceMultiplier, 600)
		ADD_STRUCT(int, StaticLightingResolution, 596)
		ADD_STRUCT(EngineTypes::LightmassPrimitiveSettings, LightmassSettings, 568)
		ADD_STRUCT(int, MaxLODLevel, 480)
		ADD_OBJECT(Material, LandscapeMaterial, 476)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
