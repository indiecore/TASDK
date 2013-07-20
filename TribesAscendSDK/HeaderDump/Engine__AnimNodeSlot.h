#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeSlot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeSlot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeSlot." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeSlot : public AnimNodeBlendBase
	{
	public:
			ADD_OBJECT( AnimNodeSynch, SynchNode )
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TargetChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CustomChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PendingBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAdditiveAnimationsOverrideSource, 0x8 )
			ADD_VAR( ::BoolProperty, bSkipBlendWhenNotRendered, 0x4 )
			ADD_VAR( ::BoolProperty, bEarlyAnimEndNotify, 0x2 )
			ADD_VAR( ::BoolProperty, bIsPlayingCustomAnim, 0x1 )
			float PlayCustomAnim( ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride, float StartTime, float EndTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.PlayCustomAnim" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )params = AnimName;
				*( float* )( params + 8 ) = Rate;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLooping;
				*( bool* )( params + 24 ) = bOverride;
				*( float* )( params + 28 ) = StartTime;
				*( float* )( params + 32 ) = EndTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool PlayCustomAnimByDuration( ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.PlayCustomAnimByDuration" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )params = AnimName;
				*( float* )( params + 8 ) = Duration;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLooping;
				*( bool* )( params + 24 ) = bOverride;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetPlayedAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.GetPlayedAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void StopCustomAnim( float BlendOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.StopCustomAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = BlendOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCustomAnim( ScriptName AnimName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.SetCustomAnim" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = AnimName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorAnimEndNotification( bool bNewStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.SetActorAnimEndNotification" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class AnimNodeSequence* GetCustomAnimNodeSeq(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.GetCustomAnimNodeSeq" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			void SetRootBoneAxisOption( byte AxisX, byte AxisY, byte AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.SetRootBoneAxisOption" );
				byte *params = ( byte* )( malloc( 3 ) );
				*( byte* )params = AxisX;
				*( byte* )( params + 1 ) = AxisY;
				*( byte* )( params + 2 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRootBoneRotationOption( byte AxisX, byte AxisY, byte AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.SetRootBoneRotationOption" );
				byte *params = ( byte* )( malloc( 3 ) );
				*( byte* )params = AxisX;
				*( byte* )( params + 1 ) = AxisY;
				*( byte* )( params + 2 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddToSynchGroup( ScriptName GroupName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeSlot.AddToSynchGroup" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = GroupName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
