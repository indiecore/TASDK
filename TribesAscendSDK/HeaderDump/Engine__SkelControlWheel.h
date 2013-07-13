#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlWheel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlWheel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlWheel." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlWheel : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::BoolProperty, bInvertWheelSteering, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertWheelRoll, 0x1 )
			ADD_VAR( ::FloatProperty, WheelSteering, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WheelSteeringAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WheelRollAxis, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WheelRoll, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WheelMaxRenderDisplacement, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WheelDisplacement, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
