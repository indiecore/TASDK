#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDeviceContentData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDeviceContentData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDeviceContentData." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeviceContentData : public Object
	{
	public:
			ADD_OBJECT( AnimSet, m_PaperDollAnimSet )
			ADD_OBJECT( AnimTree, m_AnimTreeTemplate1p )
			ADD_OBJECT( PhysicsAsset, m_PhysicsAsset1p )
			ADD_OBJECT( SkeletalMesh, m_SkeletalMesh1p )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
