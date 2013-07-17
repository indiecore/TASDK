#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_CameraLookAt." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_CameraLookAt." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_CameraLookAt." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_CameraLookAt : public SequenceAction
	{
	public:
			ADD_VAR( ::FloatProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TotalTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TextDisplay, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, FocusBoneName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCheckLineOfSight, 0x800 )
			ADD_VAR( ::BoolProperty, bUsedTimer, 0x400 )
			ADD_VAR( ::BoolProperty, bDisableInput, 0x200 )
			ADD_VAR( ::BoolProperty, bLeaveCameraRotation, 0x100 )
			ADD_VAR( ::BoolProperty, bToggleGodMode, 0x80 )
			ADD_VAR( ::BoolProperty, bRotatePlayerWithCamera, 0x40 )
			ADD_VAR( ::BoolProperty, bAffectHead, 0x20 )
			ADD_VAR( ::BoolProperty, bIgnoreTrace, 0x10 )
			ADD_VAR( ::BoolProperty, bTurnInPlace, 0x8 )
			ADD_VAR( ::BoolProperty, bAdjustCamera, 0x4 )
			ADD_VAR( ::BoolProperty, bAlwaysFocus, 0x2 )
			ADD_VAR( ::BoolProperty, bAffectCamera, 0x1 )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_CameraLookAt.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
