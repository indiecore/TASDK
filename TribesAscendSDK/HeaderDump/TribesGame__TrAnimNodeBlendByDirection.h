#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAnimNodeBlendByDirection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAnimNodeBlendByDirection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAnimNodeBlendByDirection." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByDirection : public AnimNodeSequenceBlendBase
	{
	public:
			ADD_OBJECT( TrPawn, m_TrPawn )
			ADD_VAR( ::BoolProperty, m_bForwardLeftCorrection, 0x2 )
			ADD_VAR( ::BoolProperty, m_bInterpolateWeights, 0x1 )
			ADD_VAR( ::FloatProperty, m_fDirAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBlendSpeed, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
