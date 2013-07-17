#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeSequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeSequence." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeSequence." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeSequence : public AnimNode
	{
	public:
			ADD_OBJECT( AnimSequence, AnimSeq )
			ADD_VAR( ::BoolProperty, bPlaying, 0x1 )
			ADD_VAR( ::FloatProperty, Rate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLooping, 0x2 )
			void SetAnim( ScriptName Sequence )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.SetAnim" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = Sequence;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnim( bool bLoop, float InRate, float StartTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.PlayAnim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bLoop;
				*( float* )( params + 4 ) = InRate;
				*( float* )( params + 8 ) = StartTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.StopAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplayAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.ReplayAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPosition( float NewTime, bool bFireNotifies )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.SetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = NewTime;
				*( bool* )( params + 4 ) = bFireNotifies;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetNormalizedPosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.GetNormalizedPosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FindGroupRelativePosition( float GroupRelativePosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.FindGroupRelativePosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = GroupRelativePosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FindGroupPosition( float GroupRelativePosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.FindGroupPosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = GroupRelativePosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetGroupRelativePosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.GetGroupRelativePosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetGlobalPlayRate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.GetGlobalPlayRate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetAnimPlaybackLength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.GetAnimPlaybackLength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetTimeLeft(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.GetTimeLeft" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetRootBoneAxisOption( byte AxisX, byte AxisY, byte AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.SetRootBoneAxisOption" );
				byte *params = ( byte* )( malloc( 3 ) );
				*( byte* )( params + 0 ) = AxisX;
				*( byte* )( params + 1 ) = AxisY;
				*( byte* )( params + 2 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, AnimSeqName, 0xFFFFFFFF )
			void SetRootBoneRotationOption( byte AxisX, byte AxisY, byte AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSequence.SetRootBoneRotationOption" );
				byte *params = ( byte* )( malloc( 3 ) );
				*( byte* )( params + 0 ) = AxisX;
				*( byte* )( params + 1 ) = AxisY;
				*( byte* )( params + 2 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bCauseActorAnimEnd, 0x4 )
			ADD_VAR( ::BoolProperty, bCauseActorAnimPlay, 0x8 )
			ADD_VAR( ::BoolProperty, bZeroRootRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bZeroRootTranslation, 0x20 )
			ADD_VAR( ::BoolProperty, bDisableWarningWhenAnimNotFound, 0x40 )
			ADD_VAR( ::BoolProperty, bNoNotifies, 0x80 )
			ADD_VAR( ::BoolProperty, bForceRefposeWhenNotPlaying, 0x100 )
			ADD_VAR( ::BoolProperty, bIsIssuingNotifies, 0x200 )
			ADD_VAR( ::BoolProperty, m_bSuppressNotifies, 0x400 )
			ADD_VAR( ::BoolProperty, bForceAlwaysSlave, 0x800 )
			ADD_VAR( ::BoolProperty, bSynchronize, 0x1000 )
			ADD_VAR( ::BoolProperty, bReverseSync, 0x2000 )
			ADD_VAR( ::BoolProperty, bShowTimeLineSlider, 0x4000 )
			ADD_VAR( ::BoolProperty, bLoopCameraAnim, 0x8000 )
			ADD_VAR( ::BoolProperty, bRandomizeCameraAnimLoopStartTime, 0x10000 )
			ADD_VAR( ::BoolProperty, bEditorOnlyAddRefPoseToAdditiveAnimation, 0x20000 )
			ADD_VAR( ::FloatProperty, CurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreviousTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AnimLinkupIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NotifyWeightThreshold, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SynchGroupName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SynchPosOffset, 0xFFFFFFFF )
			ADD_OBJECT( CameraAnim, CameraAnim )
			ADD_OBJECT( CameraAnimInst, ActiveCameraAnimInstance )
			ADD_VAR( ::FloatProperty, CameraAnimScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimPlayRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootBoneOption, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootRotationOption, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
