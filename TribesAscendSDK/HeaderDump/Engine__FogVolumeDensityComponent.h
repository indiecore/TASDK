#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.FogVolumeDensityComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.FogVolumeDensityComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.FogVolumeDensityComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FogVolumeDensityComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::FloatProperty, StartDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlyAffectsTranslucency, 0x4 )
			ADD_VAR( ::BoolProperty, bAffectsTranslucency, 0x2 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_OBJECT( MaterialInterface, DefaultFogVolumeMaterial )
			ADD_OBJECT( MaterialInterface, FogMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
