#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGameObjectiveUpgrade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGameObjectiveUpgrade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGameObjectiveUpgrade." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGameObjectiveUpgrade : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, m_fNewValue, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nmClassPropertyName, 0xFFFFFFFF )
			ADD_OBJECT( TrGameObjective, m_Owner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
