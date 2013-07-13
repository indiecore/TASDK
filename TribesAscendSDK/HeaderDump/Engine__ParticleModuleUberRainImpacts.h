#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleUberRainImpacts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleUberRainImpacts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleUberRainImpacts." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleUberRainImpacts : public ParticleModuleUberBase
	{
	public:
			ADD_VAR( ::ByteProperty, PC_HeightAxis, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRadialVelocity, 0x2000 )
			ADD_VAR( ::BoolProperty, bVelocity, 0x1000 )
			ADD_VAR( ::BoolProperty, bSurfaceOnly, 0x800 )
			ADD_VAR( ::BoolProperty, bNegative_Z, 0x400 )
			ADD_VAR( ::BoolProperty, bNegative_Y, 0x200 )
			ADD_VAR( ::BoolProperty, bNegative_X, 0x100 )
			ADD_VAR( ::BoolProperty, bPositive_Z, 0x80 )
			ADD_VAR( ::BoolProperty, bPositive_Y, 0x40 )
			ADD_VAR( ::BoolProperty, bPositive_X, 0x20 )
			ADD_VAR( ::BoolProperty, bIsUsingCylinder, 0x10 )
			ADD_VAR( ::BoolProperty, MultiplyZ, 0x8 )
			ADD_VAR( ::BoolProperty, MultiplyY, 0x4 )
			ADD_VAR( ::BoolProperty, MultiplyX, 0x2 )
			ADD_VAR( ::BoolProperty, bInheritParent, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
