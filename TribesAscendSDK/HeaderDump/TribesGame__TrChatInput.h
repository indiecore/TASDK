#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrChatInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrChatInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrChatInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrChatInput : public Interaction
	{
	public:
			ADD_VAR( ::BoolProperty, bEnableUI, 0x4 )
			ADD_VAR( ::BoolProperty, bCtrl, 0x2 )
			ADD_VAR( ::BoolProperty, bCaptureKeyInput, 0x1 )
			ADD_VAR( ::StrProperty, ChannelStr, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TypedStrPos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TypedStr, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DefaultTexture_White )
			ADD_OBJECT( Texture2D, DefaultTexture_Black )
			ADD_OBJECT( LocalPlayer, ConsoleTargetPlayer )
			void Initialized(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.Initialized" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInputText( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.SetInputText" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCursorPos( int Position )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.SetCursorPos" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Position;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsoleCommand( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartTyping( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.StartTyping" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender_Console( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.PostRender_Console" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )params = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InputKey( int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.InputKey" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )params = ControllerId;
				*( ScriptName* )( params + 4 ) = Key;
				*( byte* )( params + 12 ) = Event;
				*( float* )( params + 16 ) = AmountDepressed;
				*( bool* )( params + 20 ) = bGamepad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InputChar( int ControllerId, ScriptArray< wchar_t > Unicode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.InputChar" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = ControllerId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Unicode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FlushPlayerInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.FlushPlayerInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ProcessControlKey( ScriptName Key, byte Event )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.ProcessControlKey" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )params = Key;
				*( byte* )( params + 8 ) = Event;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AppendInputText( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrChatInput.AppendInputText" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
