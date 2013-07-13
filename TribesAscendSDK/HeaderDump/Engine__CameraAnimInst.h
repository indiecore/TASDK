#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraAnimInst." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraAnimInst." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraAnimInst." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraAnimInst : public Object
	{
	public:
			ADD_STRUCT( ::VectorProperty, LastCameraLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPPSettingsAlpha, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PlaySpace, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeSequence, SourceAnimNode )
			ADD_OBJECT( InterpTrackInstMove, MoveInst )
			ADD_OBJECT( InterpTrackMove, MoveTrack )
			ADD_VAR( ::FloatProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentBlendWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransientScaleModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BasePlayScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlayRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBlendingOut, 0x10 )
			ADD_VAR( ::BoolProperty, bBlendingIn, 0x8 )
			ADD_VAR( ::BoolProperty, bAutoReleaseWhenFinished, 0x4 )
			ADD_VAR( ::BoolProperty, bFinished, 0x2 )
			ADD_VAR( ::BoolProperty, bLooping, 0x1 )
			ADD_VAR( ::FloatProperty, CurTime, 0xFFFFFFFF )
			ADD_OBJECT( InterpGroupInst, InterpGroupInst )
			ADD_OBJECT( CameraAnim, CamAnim )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
