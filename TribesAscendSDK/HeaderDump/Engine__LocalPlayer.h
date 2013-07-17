#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LocalPlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LocalPlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LocalPlayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LocalPlayer : public Player
	{
	public:
			ADD_VAR( ::IntProperty, ControllerId, 0xFFFFFFFF )
			ADD_OBJECT( GameViewportClient, ViewportClient )
			bool SpawnPlayActor( ScriptArray< wchar_t > URL, ScriptArray< wchar_t > &OutError )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.SpawnPlayActor" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				*( ScriptArray< wchar_t >* )( params + 12 ) = OutError;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SendSplitJoin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.SendSplitJoin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( TranslationContext, TagContext )
			ADD_VAR( ::BoolProperty, bSentSplitJoin, 0x2 )
			ADD_VAR( ::BoolProperty, bWantToResetToMapDefaultPP, 0x1 )
			ADD_VAR( ::StrProperty, LastMap, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AspectRatioAxisConstraint, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastViewLocation, 0xFFFFFFFF )
			ADD_OBJECT( PostProcessChain, PlayerPostProcess )
			bool GetActorVisibility( class Actor* TestActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.GetActorVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = TestActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OverridePostProcessSettings( void* OverrideSettings, float BlendInTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.OverridePostProcessSettings" );
				byte *params = ( byte* )( malloc( 224 ) );
				*( void** )( params + 0 ) = OverrideSettings;
				*( float* )( params + 220 ) = BlendInTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPostProcessSettingsOverride( float BlendOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.ClearPostProcessSettingsOverride" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = BlendOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetControllerId( int NewControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.SetControllerId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = NewControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TranslationContext* GetTranslationContext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.GetTranslationContext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TranslationContext** )( params + function->return_val_offset() );
			}

			bool InsertPostProcessingChain( class PostProcessChain* InChain, int InIndex, bool bInClone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.InsertPostProcessingChain" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class PostProcessChain** )( params + 0 ) = InChain;
				*( int* )( params + 4 ) = InIndex;
				*( bool* )( params + 8 ) = bInClone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemovePostProcessingChain( int InIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.RemovePostProcessingChain" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveAllPostProcessingChains(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.RemoveAllPostProcessingChains" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class PostProcessChain* GetPostProcessChain( int InIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.GetPostProcessChain" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PostProcessChain** )( params + function->return_val_offset() );
			}

			void TouchPlayerPostProcessChain(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.TouchPlayerPostProcessChain" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeProject( void* RelativeScreenPos, Vector &WorldOrigin, Vector &WorldDirection )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.DeProject" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = RelativeScreenPos;
				*( Vector* )( params + 8 ) = WorldOrigin;
				*( Vector* )( params + 20 ) = WorldDirection;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				WorldOrigin = *( Vector* )( params + 8 );
				WorldDirection = *( Vector* )( params + 20 );
			}

			void* GetUniqueNetId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.GetUniqueNetId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetNickname(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalPlayer.GetNickname" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
