#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAudioSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAudioSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAudioSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAudioSettings : public GFxObject
	{
	public:
			int GetCurrentSettingValue( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.GetCurrentSettingValue" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_nVolumeMaster, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeMusic, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeVoice, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeVGS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeEffects, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_SettingsList )
			ADD_VAR( ::IntProperty, m_SettingsCount, 0xFFFFFFFF )
			void FlushSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.FlushSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StoreSetting( int SettingId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.StoreSetting" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = SettingId;
				*( int* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int ReadSetting( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.ReadSetting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ReadSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.ReadSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeAudioVolumes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.InitializeAudioVolumes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadAudioSettings( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.LoadAudioSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyAudioSetting( int Type, int val, bool bStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.ApplyAudioSetting" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Type;
				*( int* )( params + 4 ) = val;
				*( bool* )( params + 8 ) = bStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddSettingToList( ScriptArray< wchar_t > SettingName, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.AddSettingToList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = SettingName;
				*( int* )( params + 12 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMasterVolume( float NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetMasterVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEffectsVolume( float NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetEffectsVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMusicVolume( float NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetMusicVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVGSVolume( float NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetVGSVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVoiceVolume( float NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetVoiceVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetBassBoost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.GetBassBoost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetBassBoost( bool NewBassBoost )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.SetBassBoost" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = NewBassBoost;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetSettingNameFromType( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAudioSettings.GetSettingNameFromType" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
