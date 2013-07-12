#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ApexDestructibleAsset." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ApexDestructibleAsset." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ApexDestructibleAsset." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ApexDestructibleAsset : public ApexAsset
	{
	public:
			ADD_VAR( ::StrProperty, DustEmitterName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CrumbleEmitterName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDynamic, 0x2 )
			ADD_VAR( ::BoolProperty, bHasUniqueAssetMaterialNames, 0x1 )
			ADD_OBJECT( PhysicalMaterial, DefaultPhysMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
