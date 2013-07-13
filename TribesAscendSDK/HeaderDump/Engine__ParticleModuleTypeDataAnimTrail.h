#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleTypeDataAnimTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleTypeDataAnimTrail." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleTypeDataAnimTrail." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleTypeDataAnimTrail : public ParticleModuleTypeDataBase
	{
	public:
			ADD_VAR( ::FloatProperty, TangentTessellationScalar, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DistanceTessellationStepSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TilingDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRenderTessellation, 0x80 )
			ADD_VAR( ::BoolProperty, bRenderTangents, 0x40 )
			ADD_VAR( ::BoolProperty, bRenderSpawnPoints, 0x20 )
			ADD_VAR( ::BoolProperty, bRenderGeometry, 0x10 )
			ADD_VAR( ::BoolProperty, bTangentRecalculationEveryFrame, 0x8 )
			ADD_VAR( ::BoolProperty, bEnablePreviousTangentRecalculation, 0x4 )
			ADD_VAR( ::BoolProperty, bClipSourceSegement, 0x2 )
			ADD_VAR( ::BoolProperty, bDeadTrailsOnDeactivate, 0x1 )
			ADD_VAR( ::IntProperty, SheetsPerTrail, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ControlEdgeName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
