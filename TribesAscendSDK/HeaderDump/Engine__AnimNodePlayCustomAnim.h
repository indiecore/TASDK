#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodePlayCustomAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodePlayCustomAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodePlayCustomAnim." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodePlayCustomAnim : public AnimNodeBlend
	{
	public:
			ADD_VAR( ::FloatProperty, CustomPendingBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsPlayingCustomAnim, 0x1 )
			float PlayCustomAnim( ScriptName AnimName, float Rate, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.PlayCustomAnim" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )( params + 0 ) = AnimName;
				*( float* )( params + 8 ) = Rate;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLooping;
				*( bool* )( params + 24 ) = bOverride;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayCustomAnimByDuration( ScriptName AnimName, float Duration, float BlendInTime, float BlendOutTime, bool bLooping, bool bOverride )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.PlayCustomAnimByDuration" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )( params + 0 ) = AnimName;
				*( float* )( params + 8 ) = Duration;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLooping;
				*( bool* )( params + 24 ) = bOverride;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopCustomAnim( float BlendOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.StopCustomAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = BlendOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCustomAnim( ScriptName AnimName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.SetCustomAnim" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = AnimName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorAnimEndNotification( bool bNewStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.SetActorAnimEndNotification" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class AnimNodeSequence* GetCustomAnimNodeSeq(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.GetCustomAnimNodeSeq" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			void SetRootBoneAxisOption( byte AxisX, byte AxisY, byte AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodePlayCustomAnim.SetRootBoneAxisOption" );
				byte *params = ( byte* )( malloc( 3 ) );
				*( byte* )( params + 0 ) = AxisX;
				*( byte* )( params + 1 ) = AxisY;
				*( byte* )( params + 2 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
