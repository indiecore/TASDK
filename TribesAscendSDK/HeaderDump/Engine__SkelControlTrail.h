#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlTrail." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlTrail : public SkelControlBase
	{
	public:
			ADD_VAR( ::FloatProperty, ThisTimstep, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FakeVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StretchLimit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TrailRelaxation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHadValidStrength, 0x8 )
			ADD_VAR( ::BoolProperty, bActorSpaceFakeVel, 0x4 )
			ADD_VAR( ::BoolProperty, bLimitStretch, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertChainBoneAxis, 0x1 )
			ADD_VAR( ::ByteProperty, ChainBoneAxis, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ChainLength, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
