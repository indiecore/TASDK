#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ParticleSystem." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ParticleSystem." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ParticleSystem." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleSystem : public Object
	{
	public:
			ADD_VAR( ::ByteProperty, SystemUpdateMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LODMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OcclusionBoundsMethod, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UpdateTime_FPS, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UpdateTime_Delta, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WarmupTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, ThumbnailAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ThumbnailDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ThumbnailWarmup, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLit, 0x1 )
			ADD_VAR( ::BoolProperty, bOrientZAxisTowardCamera, 0x2 )
			ADD_VAR( ::BoolProperty, bRegenerateLODDuplicate, 0x4 )
			ADD_VAR( ::BoolProperty, bUseFixedRelativeBoundingBox, 0x8 )
			ADD_VAR( ::BoolProperty, bShouldResetPeakCounts, 0x10 )
			ADD_VAR( ::BoolProperty, bHasPhysics, 0x20 )
			ADD_VAR( ::BoolProperty, bUseRealtimeThumbnail, 0x40 )
			ADD_VAR( ::BoolProperty, ThumbnailImageOutOfDate, 0x80 )
			ADD_VAR( ::BoolProperty, bSkipSpawnCountCheck, 0x100 )
			ADD_VAR( ::BoolProperty, bUseDelayRange, 0x200 )
			ADD_VAR( ::BoolProperty, bUseMobilePointSprites, 0x400 )
			ADD_OBJECT( InterpCurveEdSetup, CurveEdSetup )
			ADD_VAR( ::FloatProperty, LODDistanceCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EditorLODSetting, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SecondsBeforeInactive, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FloorMesh, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FloorPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, FloorRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FloorScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FloorScale3D, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, ThumbnailImage )
			ADD_VAR( ::FloatProperty, Delay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DelayLow, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MacroUVPosition, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MacroUVRadius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
