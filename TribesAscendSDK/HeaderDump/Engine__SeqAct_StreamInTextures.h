#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_StreamInTextures." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_StreamInTextures." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_StreamInTextures." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_StreamInTextures : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::IntProperty, SelectedCinematicTextureGroups, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Seconds, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bStreamingActive, 0x2 )
			ADD_VAR( ::BoolProperty, bLocationBased, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
