#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKHUD." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKHUD." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKHUD." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKHUD : public MobileHUD
	{
	public:
			ADD_OBJECT( Font, BindTextFont )
			ADD_OBJECT( Font, ConsoleIconFont )
			ADD_VAR( ::FloatProperty, PulseMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PulseSplit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PulseDuration, 0xFFFFFFFF )
			ADD_OBJECT( Font, GlowFonts )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
