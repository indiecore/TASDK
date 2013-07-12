#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKAnimBlendByHoverboardTilt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKAnimBlendByHoverboardTilt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKAnimBlendByHoverboardTilt." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByHoverboardTilt : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::NameProperty, UpperBodyName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TiltYScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TiltDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TiltScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, UpVector, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
