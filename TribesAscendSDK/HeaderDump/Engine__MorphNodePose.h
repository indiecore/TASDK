#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.MorphNodePose." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.MorphNodePose." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.MorphNodePose." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MorphNodePose : public MorphNodeBase
	{
	public:
			ADD_VAR( ::FloatProperty, Weight, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MorphName, 0xFFFFFFFF )
			ADD_OBJECT( MorphTarget, Target )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
