#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DOFAndBloomEffect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DOFAndBloomEffect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DOFAndBloomEffect." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DOFAndBloomEffect : public DOFEffect
	{
	public:
			ADD_VAR( ::BoolProperty, bEnableDepthOfFieldHQ, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableReferenceDOF, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableSeparateBloom, 0x1 )
			ADD_VAR( ::FloatProperty, BlurBloomKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SceneMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomScreenBlendThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BloomScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
