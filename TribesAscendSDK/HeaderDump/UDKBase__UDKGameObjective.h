#pragma once
#include "Engine__NavigationPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKGameObjective." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKGameObjective : public NavigationPoint
	{
	public:
		ADD_VAR(::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_OBJECT(Texture2D, IconHudTexture)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bUnderAttack, 0x2)
		ADD_VAR(::BoolProperty, bAllowOnlyShootable, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
