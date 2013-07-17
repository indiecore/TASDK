#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Player." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Player." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Player." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Player : public Object
	{
	public:
			ADD_VAR( ::IntProperty, CurrentNetSpeed, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, Actor )
			ADD_VAR( ::FloatProperty, PP_ShadowsMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PP_MidTonesMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PP_HighlightsMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PP_DesaturationMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConfiguredLanSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConfiguredInternetSpeed, 0xFFFFFFFF )
			void SwitchController( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Player.SwitchController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
