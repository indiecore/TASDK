#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKSkelControl_LockRotation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKSkelControl_LockRotation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKSkelControl_LockRotation." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_LockRotation : public SkelControlBase
	{
	public:
			ADD_VAR( ::NameProperty, RotationSpaceBoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LockRotationSpace, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, MaxDelta, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LockRotation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLockRoll, 0x4 )
			ADD_VAR( ::BoolProperty, bLockYaw, 0x2 )
			ADD_VAR( ::BoolProperty, bLockPitch, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
