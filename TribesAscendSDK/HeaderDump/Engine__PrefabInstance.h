#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PrefabInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PrefabInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PrefabInstance." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PrefabInstance : public Actor
	{
	public:
			ADD_VAR( ::IntProperty, PI_LicenseePackageVersion, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PI_PackageVersion, 0xFFFFFFFF )
			ADD_OBJECT( PrefabSequence, SequenceInstance )
			ADD_VAR( ::IntProperty, TemplateVersion, 0xFFFFFFFF )
			ADD_OBJECT( Prefab, TemplatePrefab )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
