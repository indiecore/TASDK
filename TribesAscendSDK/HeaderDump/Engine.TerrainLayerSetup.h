#pragma once
#include "Core.Object.h"
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
	class TerrainLayerSetup : public Object
	{
	public:
		class FilterLimit
		{
		public:
			ADD_STRUCT(float, NoiseAmount, 12)
			ADD_STRUCT(float, NoiseScale, 8)
			ADD_STRUCT(float, Base, 4)
			ADD_BOOL(Enabled, 0, 0x1)
		};
		class TerrainFilteredMaterial
		{
		public:
			ADD_OBJECT(TerrainMaterial, Material, 80)
			ADD_STRUCT(float, Alpha, 76)
			ADD_STRUCT(TerrainLayerSetup::FilterLimit, MaxSlope, 60)
			ADD_STRUCT(TerrainLayerSetup::FilterLimit, MinSlope, 44)
			ADD_STRUCT(TerrainLayerSetup::FilterLimit, MaxHeight, 28)
			ADD_STRUCT(TerrainLayerSetup::FilterLimit, MinHeight, 12)
			ADD_STRUCT(float, NoisePercent, 8)
			ADD_STRUCT(float, NoiseScale, 4)
			ADD_BOOL(UseNoise, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<TerrainLayerSetup::TerrainFilteredMaterial>, Materials, 60)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TerrainLayerSetup.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
