#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_AttachToActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_AttachToActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_AttachToActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_AttachToActor : public SequenceAction
	{
	public:
			ADD_VAR( ::BoolProperty, bDetach, 0x1 )
			ADD_VAR( ::BoolProperty, bHardAttach, 0x2 )
			ADD_VAR( ::BoolProperty, bUseRelativeOffset, 0x4 )
			ADD_VAR( ::BoolProperty, bUseRelativeRotation, 0x8 )
			ADD_STRUCT( ::RotatorProperty, RelativeRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RelativeOffset, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
