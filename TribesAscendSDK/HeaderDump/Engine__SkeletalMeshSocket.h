#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SkeletalMeshSocket." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SkeletalMeshSocket." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SkeletalMeshSocket." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkeletalMeshSocket : public Object
	{
	public:
			ADD_OBJECT( StaticMesh, PreviewStaticMesh )
			ADD_OBJECT( SkeletalMesh, PreviewSkelMesh )
			ADD_STRUCT( ::VectorProperty, RelativeScale, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, RelativeRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RelativeLocation, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
