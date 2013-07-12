#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.CoverLink." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.CoverLink." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.CoverLink." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CoverLink : public NavigationPoint
	{
	public:
			ADD_VAR( ::BoolProperty, bClaimAllSlots, 0x4 )
			ADD_VAR( ::BoolProperty, bCircular, 0x20 )
			ADD_VAR( ::BoolProperty, bDisabled, 0x2 )
			ADD_VAR( ::BoolProperty, bFractureOnTouch, 0x200 )
			ADD_VAR( ::BoolProperty, GLOBAL_bUseSlotMarkers, 0x1 )
			ADD_VAR( ::BoolProperty, bAutoSort, 0x8 )
			ADD_VAR( ::BoolProperty, bAutoAdjust, 0x10 )
			ADD_VAR( ::BoolProperty, bLooped, 0x40 )
			ADD_VAR( ::BoolProperty, bPlayerOnly, 0x80 )
			ADD_VAR( ::BoolProperty, bDynamicCover, 0x100 )
			ADD_VAR( ::BoolProperty, bDebug_FireLinks, 0x400 )
			ADD_VAR( ::BoolProperty, bDebug_ExposedLinks, 0x800 )
			ADD_VAR( ::BoolProperty, bDebug_CoverGen, 0x1000 )
			ADD_VAR( ::BoolProperty, bDoAutoSlotDensityFixup, 0x2000 )
			ADD_VAR( ::FloatProperty, LeanTraceDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InvalidateDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFireLinkDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CircularOrigin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CircularRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AlignDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoCoverSlotInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidHeight, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StandingLeanOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CrouchLeanOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PopupOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SlipDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DangerScale, 0xFFFFFFFF )
			ADD_OBJECT( CoverLink, NextCoverLink )
			ADD_VAR( ::ByteProperty, LocationDescription, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
