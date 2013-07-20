#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " OnlineSubsystemMcts.OnlineVoiceInterfaceMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty OnlineSubsystemMcts.OnlineVoiceInterfaceMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty OnlineSubsystemMcts.OnlineVoiceInterfaceMcts." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineVoiceInterfaceMcts : public Object
	{
	public:
			void OnRecognitionComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnRecognitionComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayerTalkingStateChange( void* Player, bool bIsTalking )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnPlayerTalkingStateChange" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = Player;
				*( bool* )( params + 8 ) = bIsTalking;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RegisterLocalTalker( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterLocalTalker" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnregisterLocalTalker( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterLocalTalker" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterRemoteTalker( void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterRemoteTalker" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnregisterRemoteTalker( void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterRemoteTalker" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLocalPlayerTalking( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsLocalPlayerTalking" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsRemotePlayerTalking( void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsRemotePlayerTalking" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsHeadsetPresent( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsHeadsetPresent" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRemoteTalkerPriority( byte LocalUserNum, void* PlayerID, int Priority )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetRemoteTalkerPriority" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				*( int* )( params + 12 ) = Priority;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MuteRemoteTalker( byte LocalUserNum, void* PlayerID, bool bIsSystemWide )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteRemoteTalker" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				*( bool* )( params + 12 ) = bIsSystemWide;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnmuteRemoteTalker( byte LocalUserNum, void* PlayerID, bool bIsSystemWide )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteRemoteTalker" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				*( bool* )( params + 12 ) = bIsSystemWide;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddPlayerTalkingDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddPlayerTalkingDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPlayerTalkingDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearPlayerTalkingDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartNetworkedVoice( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartNetworkedVoice" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopNetworkedVoice( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopNetworkedVoice" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StartSpeechRecognition( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartSpeechRecognition" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StopSpeechRecognition( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopSpeechRecognition" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetRecognitionResults( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.GetRecognitionResults" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddRecognitionCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddRecognitionCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRecognitionCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearRecognitionCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SelectVocabulary( byte LocalUserNum, int VocabularyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SelectVocabulary" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( int* )( params + 4 ) = VocabularyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetSpeechRecognitionObject( byte LocalUserNum, class SpeechRecognition* SpeechRecogObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetSpeechRecognitionObject" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( class SpeechRecognition** )( params + 4 ) = SpeechRecogObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MuteAll( byte LocalUserNum, bool bAllowFriends )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteAll" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( bool* )( params + 4 ) = bAllowFriends;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnmuteAll( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteAll" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
