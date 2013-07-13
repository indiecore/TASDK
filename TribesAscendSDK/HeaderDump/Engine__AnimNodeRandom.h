#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeRandom." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeRandom." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeRandom." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeRandom : public AnimNodeBlendList
	{
	public:
			ADD_VAR( ::BoolProperty, bPickedPendingChildIndex, 0x1 )
			ADD_VAR( ::IntProperty, PendingChildIndex, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeSequence, PlayingSeqNode )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
