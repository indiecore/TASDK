#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPlayerReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPlayerReplicationInfo : public PlayerReplicationInfo
	{
	public:
		ADD_VAR(::BoolProperty, bHasFlag, 0x1)
		ADD_VAR(::BoolProperty, bIsFemale, 0x4)
		ADD_OBJECT(Texture, CharPortrait)
		ADD_OBJECT(UTPlayerReplicationInfo, LastKillerPRI)
		ADD_VAR(::IntProperty, spree, 0xFFFFFFFF)
		ADD_OBJECT(UTSquadAI, Squad)
		ADD_VAR(::BoolProperty, bHolding, 0x2)
		ADD_VAR(::IntProperty, MultiKillLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastKillTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OrdersIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OrdersString, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DefaultHudColor'!
		ADD_OBJECT(UTCarriedObject, HasFlag)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
