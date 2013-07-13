#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlHandlebars." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlHandlebars." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlHandlebars." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlHandlebars : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::IntProperty, SteerWheelBoneIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInvertRotation, 0x1 )
			ADD_VAR( ::NameProperty, WheelBoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, HandlebarRotateAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WheelRollAxis, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
