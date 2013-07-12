#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.LocalPlayer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.LocalPlayer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.LocalPlayer." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LocalPlayer : public Player
	{
	public:
			ADD_VAR( ::IntProperty, ControllerId, 0xFFFFFFFF )
			ADD_OBJECT( GameViewportClient, ViewportClient )
			ADD_OBJECT( TranslationContext, TagContext )
			ADD_VAR( ::BoolProperty, bSentSplitJoin, 0x2 )
			ADD_VAR( ::BoolProperty, bWantToResetToMapDefaultPP, 0x1 )
			ADD_VAR( ::StrProperty, LastMap, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AspectRatioAxisConstraint, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastViewLocation, 0xFFFFFFFF )
			ADD_OBJECT( PostProcessChain, PlayerPostProcess )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
