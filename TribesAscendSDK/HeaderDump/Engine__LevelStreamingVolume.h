#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.LevelStreamingVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.LevelStreamingVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.LevelStreamingVolume." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LevelStreamingVolume : public Volume
	{
	public:
			ADD_VAR( ::FloatProperty, TestVolumeDistance, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Usage, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StreamingUsage, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTestDistanceToVolume, 0x4 )
			ADD_VAR( ::BoolProperty, bDisabled, 0x2 )
			ADD_VAR( ::BoolProperty, bEditorPreVisOnly, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
