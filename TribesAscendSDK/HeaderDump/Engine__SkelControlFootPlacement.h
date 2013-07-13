#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkelControlFootPlacement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkelControlFootPlacement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkelControlFootPlacement." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlFootPlacement : public SkelControlLimb
	{
	public:
			ADD_VAR( ::FloatProperty, MaxFootOrientAdjust, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDownAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxUpAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlyEnableForUpAdjustment, 0x4 )
			ADD_VAR( ::BoolProperty, bOrientFootToGround, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertFootUpAxis, 0x1 )
			ADD_STRUCT( ::RotatorProperty, FootRotOffset, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FootUpAxis, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FootOffset, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
