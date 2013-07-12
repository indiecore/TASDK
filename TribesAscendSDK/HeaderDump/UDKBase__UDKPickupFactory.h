#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKPickupFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKPickupFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKPickupFactory." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKPickupFactory : public PickupFactory
	{
	public:
			ADD_VAR( ::NameProperty, GlowEmissiveParam, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, MIC_VisibilitySecondMaterial )
			ADD_OBJECT( MaterialInstanceConstant, MIC_Visibility )
			ADD_VAR( ::NameProperty, VisibilityParamName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PivotTranslation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, YawRotationRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobBaseOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobTimer, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BaseMaterialParamName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PulseThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BasePulseTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BasePulseRate, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, BaseMaterialInstance )
			ADD_VAR( ::BoolProperty, bDoVisibilityFadeIn, 0x80 )
			ADD_VAR( ::BoolProperty, bUpdatingPickup, 0x40 )
			ADD_VAR( ::BoolProperty, bRotatingPickup, 0x20 )
			ADD_VAR( ::BoolProperty, bRandomStart, 0x10 )
			ADD_VAR( ::BoolProperty, bFloatingPickup, 0x8 )
			ADD_VAR( ::BoolProperty, bIsDisabled, 0x4 )
			ADD_VAR( ::BoolProperty, bPulseBase, 0x2 )
			ADD_VAR( ::BoolProperty, bIsRespawning, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
