#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_SetMesh." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_SetMesh." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_SetMesh." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_SetMesh : public SequenceAction
	{
	public:
			ADD_VAR( ::ByteProperty, MeshType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsAllowedToMove, 0x1 )
			ADD_VAR( ::BoolProperty, bAllowDecalsToReattach, 0x2 )
			ADD_OBJECT( StaticMesh, NewStaticMesh )
			ADD_OBJECT( SkeletalMesh, NewSkeletalMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
