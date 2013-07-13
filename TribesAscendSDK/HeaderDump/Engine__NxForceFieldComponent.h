#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NxForceFieldComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NxForceFieldComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NxForceFieldComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxForceFieldComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDestroyWhenInactive, 0x2 )
			ADD_VAR( ::BoolProperty, bForceActive, 0x1 )
			ADD_VAR( ::IntProperty, ExcludeChannel, 0xFFFFFFFF )
			ADD_OBJECT( ForceFieldShape, Shape )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
