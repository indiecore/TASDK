#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_GetLocationAndRotation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_GetLocationAndRotation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_GetLocationAndRotation." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_GetLocationAndRotation : public SequenceAction
	{
	public:
			ADD_VAR( ::NameProperty, SocketOrBoneName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Rotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RotationVector, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
