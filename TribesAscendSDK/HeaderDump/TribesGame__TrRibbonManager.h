#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrRibbonManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrRibbonManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrRibbonManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRibbonManager : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bDirty, 0x1 )
			ADD_VAR( ::BoolProperty, bHaveUnlocks, 0x2 )
			ADD_VAR( ::BoolProperty, bOnlyUnlocks, 0x4 )
			ADD_VAR( ::BoolProperty, bHaveUpgrades, 0x8 )
			ADD_VAR( ::BoolProperty, bOnlyUpgrades, 0x10 )
			ADD_VAR( ::IntProperty, PreviousGold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviousXP, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
