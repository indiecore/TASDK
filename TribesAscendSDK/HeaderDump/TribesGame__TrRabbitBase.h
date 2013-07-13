#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrRabbitBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrRabbitBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrRabbitBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRabbitBase : public UTGameObjective
	{
	public:
			ADD_OBJECT( TrAnimNodeBlendList, m_OpenCloseBlendList )
			ADD_OBJECT( MaterialInstanceConstant, MIC_FlagBaseColor )
			ADD_OBJECT( MaterialInstanceConstant, FlagBaseMaterial )
			ADD_VAR( ::FloatProperty, BaseExitTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NearBaseRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF )
			ADD_OBJECT( TrFlagRabbit, myFlag )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
