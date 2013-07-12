#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_SetLocation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_SetLocation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_SetLocation." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_SetLocation : public SeqAct_SetSequenceVariable
	{
	public:
			ADD_OBJECT( Object, Target )
			ADD_STRUCT( ::RotatorProperty, RotationValue, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LocationValue, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSetRotation, 0x2 )
			ADD_VAR( ::BoolProperty, bSetLocation, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
