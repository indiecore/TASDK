#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_HugGround." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_HugGround." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_HugGround." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_HugGround : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxTranslationPerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZDistFromParentBone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, XYDistFromParentBone, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOppositeFromParent, 0x1 )
			ADD_VAR( ::NameProperty, ParentBone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredGroundDist, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
