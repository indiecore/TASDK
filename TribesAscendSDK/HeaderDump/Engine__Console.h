#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Console." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Console." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Console." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Console : public Interaction
	{
	public:
			ADD_VAR( ::IntProperty, AutoCompleteIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TypedStrPos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TypedStr, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsRuntimeAutoCompleteUpToDate, 0x40 )
			ADD_VAR( ::BoolProperty, bRequireCtrlToNavigateAutoComplete, 0x20 )
			ADD_VAR( ::BoolProperty, bAutoCompleteLocked, 0x10 )
			ADD_VAR( ::BoolProperty, bEnableUI, 0x8 )
			ADD_VAR( ::BoolProperty, bCtrl, 0x4 )
			ADD_VAR( ::BoolProperty, bCaptureKeyInput, 0x2 )
			ADD_VAR( ::BoolProperty, bNavigatingHistory, 0x1 )
			ADD_VAR( ::StrProperty, History, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryCur, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryBot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryTop, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SBPos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SBHead, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxScrollbackSize, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TypeKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ConsoleKey, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DefaultTexture_White )
			ADD_OBJECT( Texture2D, DefaultTexture_Black )
			ADD_OBJECT( LocalPlayer, ConsoleTargetPlayer )
			void Initialized(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.Initialized" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInputText( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.SetInputText" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCursorPos( int Position )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.SetCursorPos" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Position;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PurgeCommandFromHistory( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.PurgeCommandFromHistory" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsoleCommand( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearOutput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.ClearOutput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OutputTextLine( ScriptArray< wchar_t > Text, void* OverrideColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.OutputTextLine" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				*( void** )( params + 12 ) = OverrideColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OutputText( ScriptArray< wchar_t > Text, void* OverrideColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.OutputText" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				*( void** )( params + 12 ) = OverrideColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartTyping( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.StartTyping" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender_Console( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.PostRender_Console" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InputKey( int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.InputKey" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )( params + 0 ) = ControllerId;
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.InputChar" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Unicode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FlushPlayerInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.FlushPlayerInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ProcessControlKey( ScriptName Key, byte Event )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.ProcessControlKey" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )( params + 0 ) = Key;
				*( byte* )( params + 8 ) = Event;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AppendInputText( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.AppendInputText" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BuildRuntimeAutoCompleteList( bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.BuildRuntimeAutoCompleteList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCompleteIndices(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Console.UpdateCompleteIndices" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
