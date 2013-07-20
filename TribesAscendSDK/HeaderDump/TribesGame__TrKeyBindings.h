#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrKeyBindings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrKeyBindings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrKeyBindings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrKeyBindings : public GFxObject
	{
	public:
			ADD_VAR( ::StrProperty, m_EscapeKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_FriendsHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_SettingsHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_MainMenuHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ClassSelectKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TeamSelectKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TalkReplyKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ChatHotkey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TalkKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TeamTalkKeybind, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_ScoreboardKeybind, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetCurrentBind( byte Key )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.GetCurrentBind" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Key;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > SaveKeyBind( int Index, ScriptArray< wchar_t > KeyName, bool bStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.SaveKeyBind" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KeyName;
				*( bool* )( params + 16 ) = bStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, m_EnterKeybind, 0xFFFFFFFF )
			ADD_OBJECT( PlayerInput, m_EngineInput )
			ADD_OBJECT( GFxObject, m_KeyBindingsList )
			ADD_VAR( ::IntProperty, m_KeyBindingsCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bGotInputKey, 0x1 )
			void FlushSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.FlushSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSettingById( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ClearSettingById" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSettingByValue( ScriptArray< wchar_t > StrValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ClearSettingByValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = StrValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StoreSetting( int SettingId, ScriptArray< wchar_t > KeyBind )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.StoreSetting" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = SettingId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KeyBind;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ReadSetting( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ReadSetting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void CaptureNextKey(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.CaptureNextKey" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetDefaultKeyBindings( class PlayerInput* pInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ResetDefaultKeyBindings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerInput** )params = pInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetDefaultSpectatorBindings( class TrPlayerInput_Spectator* pInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ResetDefaultSpectatorBindings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerInput_Spectator** )params = pInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadBindings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ReadBindings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddBinding( ScriptArray< wchar_t > Command, ScriptArray< wchar_t > KeyName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.AddBinding" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( ScriptArray< wchar_t >* )( params + 12 ) = KeyName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyKeyBinding( int Index, ScriptArray< wchar_t > val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ApplyKeyBinding" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > SavePlayerKeyBind( int Index, ScriptArray< wchar_t > KeyName, bool bStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.SavePlayerKeyBind" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KeyName;
				*( bool* )( params + 16 ) = bStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > SaveSpectatorKeyBind( int Index, ScriptArray< wchar_t > KeyName, bool bStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.SaveSpectatorKeyBind" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KeyName;
				*( bool* )( params + 16 ) = bStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void UnbindPlayerCommand( class PlayerInput* pInput, ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.UnbindPlayerCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerInput** )params = pInput;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnbindSpectatorCommand( class TrPlayerInput_Spectator* pInput, ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.UnbindSpectatorCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class TrPlayerInput_Spectator** )params = pInput;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetCurrentBinding( class PlayerInput* pInput, ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.GetCurrentBinding" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerInput** )params = pInput;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetCommandName( byte Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.GetCommandName" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ApplyDefaultSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.ApplyDefaultSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerInput* GetPlayerInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.GetPlayerInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerInput** )( params + function->return_val_offset() );
			}

			class TrPlayerInput_Spectator* GetSpectatorInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.GetSpectatorInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrPlayerInput_Spectator** )( params + function->return_val_offset() );
			}

			void UpdateRuntimePlayer( class PlayerInput* EngineInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.UpdateRuntimePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerInput** )params = EngineInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRuntimeSpectator( class TrPlayerInput_Spectator* SpecInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.UpdateRuntimeSpectator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerInput_Spectator** )params = SpecInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveInterceptKeys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrKeyBindings.SaveInterceptKeys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
