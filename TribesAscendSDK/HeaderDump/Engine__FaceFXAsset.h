#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FaceFXAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FaceFXAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FaceFXAsset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FaceFXAsset : public Object
	{
	public:
			ADD_VAR( ::IntProperty, NumLoadErrors, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, DefaultSkelMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
