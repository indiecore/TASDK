#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame_TrCTFBlitz." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame_TrCTFBlitz." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame_TrCTFBlitz." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TrCTFBlitz : public TrGame_TRCTF
	{
	public:
			ADD_VAR( ::BoolProperty, m_bRotateBothFlagsOnCapture, 0x1 )
			ADD_OBJECT( TrCTFBase_DiamondSword, DiamondSwordFlagStands )
			ADD_OBJECT( TrCTFBase_BloodEagle, BloodEagleFlagStands )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
