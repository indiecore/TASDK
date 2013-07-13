#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeBlendDirectional." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeBlendDirectional." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeBlendDirectional." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeBlendDirectional : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::BoolProperty, bUseAcceleration, 0x1 )
			ADD_STRUCT( ::RotatorProperty, RotationOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SingleAnimAtOrAboveLOD, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirDegreesPerSecond, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
