#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxMoviePlayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxMoviePlayer : public Object
	{
	public:
			void OnFocusLost( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.OnFocusLost" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusGained( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.OnFocusGained" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsoleCommand( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerController* GetPC(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetPC" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			class LocalPlayer* GetLP(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetLP" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class LocalPlayer** )( params + function->return_val_offset() );
			}

			void Init( class LocalPlayer* LocPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = LocPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, LocalPlayerOwnerIndex, 0xFFFFFFFF )
			void SetWidgetPathBinding( class GFxObject* WidgetToBind, ScriptName Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetWidgetPathBinding" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class GFxObject** )( params + 0 ) = WidgetToBind;
				*( ScriptName* )( params + 4 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SwfMovie, MovieInfo )
			ADD_VAR( ::BoolProperty, bAutoPlay, 0x80 )
			void Advance( float Time )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.Advance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Time;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostWidgetInit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.PostWidgetInit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetUnloaded( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.WidgetUnloaded" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GFxObject* ActionScriptObject( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptObject" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > ActionScriptString( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			float ActionScriptFloat( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int ActionScriptInt( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptInt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ActionScriptVoid( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptVoid" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* Invoke( ScriptArray< wchar_t > method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.Invoke" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void ActionScriptSetFunction( class GFxObject* Object, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ActionScriptSetFunction" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GFxObject** )( params + 0 ) = Object;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* CreateArray(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.CreateArray" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* CreateObject( ScriptArray< wchar_t > ASClass, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.CreateObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ASClass;
				*( ScriptClass** )( params + 12 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool SetVariableStringArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableStringArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetVariableFloatArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableFloatArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetVariableIntArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableIntArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetVariableArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVariableStringArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableStringArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVariableFloatArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableFloatArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVariableIntArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableIntArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVariableArray( ScriptArray< wchar_t > Path, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableArray" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetVariableObject( ScriptArray< wchar_t > Path, class GFxObject* Object )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( class GFxObject** )( params + 12 ) = Object;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVariableString( ScriptArray< wchar_t > Path, ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableString" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( ScriptArray< wchar_t >* )( params + 12 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVariableNumber( ScriptArray< wchar_t > Path, float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableNumber" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( float* )( params + 12 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVariableBool( ScriptArray< wchar_t > Path, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariableBool" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( bool* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVariable( ScriptArray< wchar_t > Path, void* Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetVariable" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( void** )( params + 12 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* GetVariableObject( ScriptArray< wchar_t > Path, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				*( ScriptClass** )( params + 12 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetVariableString( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			float GetVariableNumber( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableNumber" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool GetVariableBool( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariableBool" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetVariable( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVariable" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool FilterButtonInput( int ControllerId, ScriptName ButtonName, byte InputEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.FilterButtonInput" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptName* )( params + 4 ) = ButtonName;
				*( byte* )( params + 12 ) = InputEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FlushPlayerInput( bool capturekeysonly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.FlushPlayerInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = capturekeysonly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFocusIgnoreKeys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ClearFocusIgnoreKeys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFocusIgnoreKey( ScriptName Key )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.AddFocusIgnoreKey" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = Key;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCaptureKeys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ClearCaptureKeys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCaptureKey( ScriptName Key )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.AddCaptureKey" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = Key;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovieCanReceiveInput( bool bCanReceiveInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bCanReceiveInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovieCanReceiveFocus( bool bCanReceiveFocus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bCanReceiveFocus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPerspective3D( void* &matPersp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetPerspective3D" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )( params + 0 ) = matPersp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				matPersp = *( void** )( params + 0 );
			}

			void SetView3D( void* &matView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetView3D" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )( params + 0 ) = matView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				matView = *( void** )( params + 0 );
			}

			void GetVisibleFrameRect( float &x0, float &y0, float &X1, float &Y1 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetVisibleFrameRect" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = x0;
				*( float* )( params + 4 ) = y0;
				*( float* )( params + 8 ) = X1;
				*( float* )( params + 12 ) = Y1;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				x0 = *( float* )( params + 0 );
				y0 = *( float* )( params + 4 );
				X1 = *( float* )( params + 8 );
				Y1 = *( float* )( params + 12 );
			}

			void SetAlignment( byte A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetAlignment" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewScaleMode( byte SM )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetViewScaleMode" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = SM;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewport( int X, int Y, int Width, int Height )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetViewport" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = X;
				*( int* )( params + 4 ) = Y;
				*( int* )( params + 8 ) = Width;
				*( int* )( params + 12 ) = Height;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameViewportClient* GetGameViewportClient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.GetGameViewportClient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameViewportClient** )( params + function->return_val_offset() );
			}

			void SetPriority( byte NewPriority )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetPriority" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = NewPriority;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PublishDataStoreValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.PublishDataStoreValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshDataStoreBindings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.RefreshDataStoreBindings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetExternalTexture( ScriptArray< wchar_t > Resource, class Texture* Texture )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetExternalTexture" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Resource;
				*( class Texture** )( params + 12 ) = Texture;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetExternalInterface( class Object* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetExternalInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )( params + 0 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetForceSmoothAnimation( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetForceSmoothAnimation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( Object, ExternalInterface )
			void SetTimingMode( byte Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetTimingMode" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovieInfo( class SwfMovie* Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetMovieInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SwfMovie** )( params + 0 ) = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConditionalClearPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.ConditionalClearPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClose(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.OnClose" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bPauseGameWhileActive, 0x100 )
			void Close( bool Unload )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.Close" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = Unload;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPause( bool bPausePlayback )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.SetPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPausePlayback;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPostAdvance( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.OnPostAdvance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostAdvance( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.PostAdvance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Start( bool StartPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxMoviePlayer.Start" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = StartPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, NextASUObject, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bMovieIsOpen, 0x1 )
			ADD_VAR( ::BoolProperty, bDisplayWithHudOff, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableGammaCorrection, 0x4 )
			ADD_VAR( ::BoolProperty, bWidgetsInitializedThisFrame, 0x8 )
			ADD_VAR( ::BoolProperty, bLogUnhandedWidgetInitializations, 0x10 )
			ADD_VAR( ::BoolProperty, bAllowInput, 0x20 )
			ADD_VAR( ::BoolProperty, bAllowFocus, 0x40 )
			ADD_VAR( ::BoolProperty, bCloseOnLevelChange, 0x200 )
			ADD_VAR( ::BoolProperty, bOnlyOwnerFocusable, 0x400 )
			ADD_VAR( ::BoolProperty, bDiscardNonOwnerInput, 0x800 )
			ADD_VAR( ::BoolProperty, bCaptureInput, 0x1000 )
			ADD_VAR( ::BoolProperty, bIgnoreMouseInput, 0x2000 )
			ADD_VAR( ::BoolProperty, bForceSmoothAnimation, 0x4000 )
			ADD_OBJECT( TextureRenderTarget2D, RenderTexture )
			ADD_VAR( ::ByteProperty, TimingMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RenderTextureMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Priority, 0xFFFFFFFF )
			ADD_OBJECT( GFxDataStoreSubscriber, DataStoreSubscriber )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
