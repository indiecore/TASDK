#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ParticleModuleTrailSource." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ParticleModuleTrailSource." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ParticleModuleTrailSource." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleTrailSource : public ParticleModuleTrailBase
	{
	public:
			ADD_VAR( ::IntProperty, SourceOffsetCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInheritRotation, 0x2 )
			ADD_VAR( ::BoolProperty, bLockSourceStength, 0x1 )
			ADD_VAR( ::NameProperty, SourceName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SelectionMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SourceMethod, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
