#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrMapInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrMapInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrMapInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrMapInfo : public UDKMapInfo
	{
	public:
			ADD_VAR( ::NameProperty, m_DefaultPhysicalMaterialName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_WeatherEffect )
			ADD_OBJECT( TrMapMusicInfo, m_MapMusicInfo )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
