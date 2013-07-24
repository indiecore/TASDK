#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKForcedDirectionVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKForcedDirectionVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKForcedDirectionVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(::VectorProperty, ArrowDirection, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bBlockSpectators, 0x8)
		ADD_VAR(::BoolProperty, bBlockPawns, 0x4)
		ADD_VAR(::BoolProperty, bDenyExit, 0x2)
		ADD_VAR(::BoolProperty, bIgnoreHoverboards, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
