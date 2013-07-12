#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.NxForceFieldRadial." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.NxForceFieldRadial." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.NxForceFieldRadial." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxForceFieldRadial : public NxForceField
	{
	public:
			ADD_VAR( ::ByteProperty, ForceFalloff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SelfRotationStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceStrength, 0xFFFFFFFF )
			ADD_OBJECT( ForceFieldShape, Shape )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
