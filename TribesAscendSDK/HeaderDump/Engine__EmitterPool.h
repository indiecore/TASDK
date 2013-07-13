#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.EmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.EmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.EmitterPool." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class EmitterPool : public Actor
	{
	public:
			ADD_VAR( ::IntProperty, IdealMaterialInstanceConstants, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IdealStaticMeshComponents, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SMC_MIC_CurrentReductionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SMC_MIC_ReductionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLogPoolOverflowList, 0x2 )
			ADD_VAR( ::BoolProperty, bLogPoolOverflow, 0x1 )
			ADD_VAR( ::IntProperty, MaxActiveEffects, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
