#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.SeqEvent_MobileMotion." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.SeqEvent_MobileMotion." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.SeqEvent_MobileMotion." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileMotion : public SeqEvent_MobileBase
	{
	public:
			ADD_VAR( ::FloatProperty, DeltaYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeltaPitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeltaRoll, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Yaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Pitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Roll, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
