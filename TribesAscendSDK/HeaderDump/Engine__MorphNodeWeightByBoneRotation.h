#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MorphNodeWeightByBoneRotation." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MorphNodeWeightByBoneRotation." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MorphNodeWeightByBoneRotation." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MorphNodeWeightByBoneRotation : public MorphNodeWeightBase
	{
	public:
			ADD_OBJECT( MaterialInstanceConstant, MaterialInstanceConstant )
			ADD_VAR( ::NameProperty, ScalarParameterName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaterialSlotId, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bControlMaterialParameter, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertBoneAxis, 0x1 )
			ADD_VAR( ::ByteProperty, BoneAxis, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NodeWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Angle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
