#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKSkelControl_HoverboardVibration." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKSkelControl_HoverboardVibration." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKSkelControl_HoverboardVibration." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_HoverboardVibration : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::FloatProperty, VibInput, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VibMaxAmplitude, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VibTurnAmpScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VibSpeedAmpScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VibFrequency, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
