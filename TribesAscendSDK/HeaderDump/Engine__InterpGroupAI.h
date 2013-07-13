#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpGroupAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpGroupAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpGroupAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpGroupAI : public InterpGroup
	{
	public:
			ADD_VAR( ::BoolProperty, bNoEncroachmentCheck, 0x2 )
			ADD_VAR( ::BoolProperty, SnapToRootBoneLocationWhenFinished, 0x1 )
			ADD_OBJECT( Actor, StageMarkActor )
			ADD_OBJECT( Pawn, PreviewPawn )
			ADD_VAR( ::NameProperty, StageMarkGroup, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
