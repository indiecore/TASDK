#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTCTFBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTCTFBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTCTFBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTCTFBase : public UTGameObjective
	{
	public:
			ADD_OBJECT( MaterialInstanceConstant, MIC_FlagBaseColor )
			ADD_OBJECT( MaterialInstanceConstant, FlagBaseMaterial )
			ADD_VAR( ::FloatProperty, BaseExitTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NearBaseRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF )
			ADD_OBJECT( UTCarriedObject, myFlag )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
