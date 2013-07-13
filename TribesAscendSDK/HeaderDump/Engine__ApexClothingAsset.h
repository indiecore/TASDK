#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ApexClothingAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ApexClothingAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ApexClothingAsset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ApexClothingAsset : public ApexAsset
	{
	public:
			ADD_VAR( ::FloatProperty, LodWeightsBenefitsBias, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LodWeightsBias, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LodWeightsDistanceWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LodWeightsMaxDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ContinuousDistanceThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ContinuousRotationThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDistanceBlendTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, UVChannelForTangentUpdate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRecomputeNormals, 0x8 )
			ADD_VAR( ::BoolProperty, bSlowStart, 0x4 )
			ADD_VAR( ::BoolProperty, bFallbackSkinning, 0x2 )
			ADD_VAR( ::BoolProperty, bUseHardwareCloth, 0x1 )
			ADD_OBJECT( ApexGenericAsset, ApexClothingLibrary )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
