#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GFxUI.GFxAction_Invoke." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GFxUI.GFxAction_Invoke." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GFxUI.GFxAction_Invoke." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxAction_Invoke : public SequenceAction
	{
	public:
			ADD_VAR( ::StrProperty, MethodName, 0xFFFFFFFF )
			ADD_OBJECT( GFxMoviePlayer, Movie )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
