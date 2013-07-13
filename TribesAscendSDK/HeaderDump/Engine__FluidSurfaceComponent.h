#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FluidSurfaceComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FluidSurfaceComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FluidSurfaceComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FluidSurfaceComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ForceImpact, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EditorViewPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DetailPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SimulationPosition, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeactivationTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TestRippleAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TestRippleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TestRippleRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TestRippleFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TestRippleSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NormalLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailUpdateRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailHeightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailTravelSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DetailSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DetailResolution, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeactivationDistance, 0xFFFFFFFF )
			ADD_OBJECT( Actor, TargetDetail )
			ADD_VAR( ::FloatProperty, LightingContrast, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceContinuous, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidUpdateRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidHeightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidTravelSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GPUTessellationFactor, 0xFFFFFFFF )
			ADD_OBJECT( Actor, TargetSimulation )
			ADD_VAR( ::FloatProperty, GridSpacingLowRes, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GridSpacing, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SimulationQuadsY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SimulationQuadsX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTestRippleCenterOnDetail, 0x400 )
			ADD_VAR( ::BoolProperty, bTestRipple, 0x200 )
			ADD_VAR( ::BoolProperty, bShowFluidDetail, 0x100 )
			ADD_VAR( ::BoolProperty, bShowFluidSimulation, 0x80 )
			ADD_VAR( ::BoolProperty, bShowDetailPosition, 0x40 )
			ADD_VAR( ::BoolProperty, bShowDetailNormals, 0x20 )
			ADD_VAR( ::BoolProperty, bShowSimulationPosition, 0x10 )
			ADD_VAR( ::BoolProperty, bShowSimulationNormals, 0x8 )
			ADD_VAR( ::BoolProperty, bPause, 0x4 )
			ADD_VAR( ::BoolProperty, EnableDetail, 0x2 )
			ADD_VAR( ::BoolProperty, EnableSimulation, 0x1 )
			ADD_VAR( ::IntProperty, LightMapResolution, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, FluidMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
