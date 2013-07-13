#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraShake." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraShake : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bSingleInstance, 0x1 )
			ADD_VAR( ::BoolProperty, bRandomAnimSegment, 0x2 )
			ADD_VAR( ::FloatProperty, OscillationDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OscillationBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OscillationBlendOutTime, 0xFFFFFFFF )
			ADD_OBJECT( CameraAnim, Anim )
			ADD_VAR( ::FloatProperty, AnimPlayRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RandomAnimSegmentDuration, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
