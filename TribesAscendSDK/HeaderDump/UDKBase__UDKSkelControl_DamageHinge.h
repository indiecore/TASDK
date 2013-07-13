#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_DamageHinge." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_DamageHinge." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_DamageHinge." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_DamageHinge : public UDKSkelControl_Damage
	{
	public:
			ADD_VAR( ::FloatProperty, SpringStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AVModifier, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PivotAxis, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAngle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
