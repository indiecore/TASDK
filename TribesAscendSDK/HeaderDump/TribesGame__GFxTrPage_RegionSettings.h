#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_RegionSettings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_RegionSettings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_RegionSettings." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_RegionSettings : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bFilter, 0x1 )
			ADD_VAR( ::BoolProperty, bForceChoose, 0x4 )
			ADD_VAR( ::BoolProperty, bServer, 0x2 )
			ADD_VAR( ::IntProperty, CurrFilterIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrFilterSite, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrRegion, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
