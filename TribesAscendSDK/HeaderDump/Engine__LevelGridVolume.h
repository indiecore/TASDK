#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.LevelGridVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.LevelGridVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.LevelGridVolume." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LevelGridVolume : public Volume
	{
	public:
			ADD_VAR( ::FloatProperty, KeepLoadedRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LoadingDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Subdivisions, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CellShape, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LevelGridVolumeName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
