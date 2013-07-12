#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAnimNodeBlendByPhysics." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAnimNodeBlendByPhysics." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAnimNodeBlendByPhysics." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByPhysics : public TrAnimNodeBlendList
	{
	public:
			ADD_VAR( ::BoolProperty, m_bDirectUnspecifiedPhysicsThroughChild0, 0x1 )
			ADD_VAR( ::IntProperty, m_CurrentPhysicsChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CurrentPhysics, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_LastPhysics, 0xFFFFFFFF )
			ADD_OBJECT( TrPawn, m_TrPawn )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
