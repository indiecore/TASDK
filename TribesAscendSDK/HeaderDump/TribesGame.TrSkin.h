#pragma once
#include "Core.Object.h"
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
	class TrSkin : public Object
	{
	public:
		class SkinStruct
		{
		public:
			ADD_STRUCT(int, skinId, 0)
			ADD_STRUCT(ScriptString*, SkinContentPath3p, 16)
			ADD_STRUCT(ScriptString*, SkinContentPath1p, 4)
			ADD_OBJECT(ParticleSystem, JetpackThrustTemplate, 36)
			ADD_OBJECT(ParticleSystem, JetpackRibbonTemplate, 32)
			ADD_OBJECT(ParticleSystem, SkiThrustTemplate, 28)
			ADD_STRUCT(ScriptArray<ScriptName>, JetpackThrustEffectSockets, 40)
		};
		class VehicleSkinStruct
		{
		public:
			ADD_OBJECT(AnimSet, SeatAnimSet, 4)
			ADD_OBJECT(ScriptClass, VehicleClass, 0)
		};
		ADD_STRUCT(ScriptString*, ItemName, 64)
		ADD_STRUCT(ScriptString*, InfoPanelDescription, 76)
		ADD_STRUCT(int, TranslucencySortPriority, 88)
		ADD_STRUCT(ScriptArray<TrSkin::SkinStruct>, Skins, 96)
		ADD_STRUCT(int, ItemId, 60)
		ADD_OBJECT(ScriptClass, SkinMeleeDevice, 92)
		ADD_STRUCT(ScriptArray<TrSkin::VehicleSkinStruct>, VehicleSkins, 108)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
