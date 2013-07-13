#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpGroupInstAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpGroupInstAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpGroupInstAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpGroupInstAI : public InterpGroupInst
	{
	public:
			ADD_VAR( ::BoolProperty, bSavedNoEncroachCheck, 0x1 )
			ADD_VAR( ::ByteProperty, SavedPhysics, 0xFFFFFFFF )
			ADD_OBJECT( InterpGroupAI, AIGroup )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
