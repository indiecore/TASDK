#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxMinimap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.GFxMinimap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxMinimap." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMinimap : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, IconsFlagCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconsBlueCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconsRedCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, IconsFlagMC)
		ADD_OBJECT(GFxObject, IconsBlueMC)
		ADD_OBJECT(GFxObject, IconsRedMC)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'IconMatrix'!
		ADD_OBJECT(GFxObject, MapMC)
		ADD_OBJECT(GFxObject, CompassIcon)
		ADD_OBJECT(GFxObject, PlayerIcon)
		ADD_VAR(::BoolProperty, bNeedsUpdateData, 0x1)
		ADD_VAR(::IntProperty, MapTexSize, 0xFFFFFFFF)
		ADD_OBJECT(UTMapInfo, MapInfo)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GFxMinimapHud, HUD)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
