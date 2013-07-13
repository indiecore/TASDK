#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpTrackInstProperty." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpTrackInstProperty." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpTrackInstProperty." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrackInstProperty : public InterpTrackInst
	{
	public:
			ADD_OBJECT( Object, PropertyOuterObjectInst )
			ADD_OBJECT( Function, PropertyUpdateCallback )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
