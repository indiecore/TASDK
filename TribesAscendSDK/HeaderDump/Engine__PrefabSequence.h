#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PrefabSequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PrefabSequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PrefabSequence." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PrefabSequence : public Sequence
	{
	public:
			ADD_OBJECT( PrefabInstance, OwnerPrefab )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
