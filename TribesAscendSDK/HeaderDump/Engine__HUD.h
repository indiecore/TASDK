#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.HUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.HUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.HUD." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class HUD : public Actor
	{
	public:
			ADD_OBJECT( Canvas, Canvas )
			bool ShouldDisplayDebug( ScriptName DebugType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ShouldDisplayDebug" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = DebugType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, RatioY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RatioX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RenderDelta, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHUDRenderTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConsoleMessagePosY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConsoleMessagePosX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxHUDAreaMessageCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MessageFontOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConsoleFontSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConsoleMessageCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HudCanvasScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowOverlays, 0x40 )
			ADD_VAR( ::BoolProperty, bMessageBeep, 0x20 )
			ADD_VAR( ::BoolProperty, bShowBadConnectionAlert, 0x10 )
			ADD_VAR( ::BoolProperty, bShowDebugInfo, 0x8 )
			ADD_VAR( ::BoolProperty, bShowScores, 0x4 )
			ADD_VAR( ::BoolProperty, bShowHUD, 0x2 )
			ADD_VAR( ::BoolProperty, bLostFocusPaused, 0x1 )
			ADD_OBJECT( PlayerController, PlayerOwner )
			void Draw3DLine( Vector Start, Vector End, void* LineColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.Draw3DLine" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				*( void** )( params + 24 ) = LineColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Draw2DLine( int X1, int Y1, int X2, int Y2, void* LineColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.Draw2DLine" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = X1;
				*( int* )( params + 4 ) = Y1;
				*( int* )( params + 8 ) = X2;
				*( int* )( params + 12 ) = Y2;
				*( void** )( params + 16 ) = LineColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawActorOverlays( Vector ViewPoint, Rotator ViewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawActorOverlays" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = ViewPoint;
				*( Rotator* )( params + 12 ) = ViewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemovePostRenderedActor( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.RemovePostRenderedActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPostRenderedActor( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.AddPostRenderedActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ToggleHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ShowHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowScores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ShowScores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShowScores( bool bNewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.SetShowScores" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowDebug( ScriptName DebugType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ShowDebug" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = DebugType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowDebugInfo( float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ShowDebugInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = out_YL;
				*( float* )( params + 4 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )params;
				out_YPos = *( float* )( params + 4 );
			}

			void DrawRoute( class Pawn* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawRoute" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreCalcValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.PreCalcValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.PostRender" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayBadConnectionAlert(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DisplayBadConnectionAlert" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMessage( void* &M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.ClearMessage" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				M = *( void** )params;
			}

			void Message( class PlayerReplicationInfo* PRI, ScriptArray< wchar_t > msg, ScriptName MsgType, float Lifetime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.Message" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				*( ScriptName* )( params + 16 ) = MsgType;
				*( float* )( params + 24 ) = Lifetime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayConsoleMessages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DisplayConsoleMessages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddConsoleMessage( ScriptArray< wchar_t > M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.AddConsoleMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = M;
				*( ScriptClass** )( params + 12 ) = InMessageClass;
				*( class PlayerReplicationInfo** )( params + 16 ) = PRI;
				*( float* )( params + 20 ) = Lifetime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LocalizedMessage( ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, ScriptArray< wchar_t > CriticalString, int Switch, float Position, float Lifetime, int FontSize, void* DrawColor, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.LocalizedMessage" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptClass** )params = InMessageClass;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI_;
				*( ScriptArray< wchar_t >* )( params + 12 ) = CriticalString;
				*( int* )( params + 24 ) = Switch;
				*( float* )( params + 28 ) = Position;
				*( float* )( params + 32 ) = Lifetime;
				*( int* )( params + 36 ) = FontSize;
				*( void** )( params + 40 ) = DrawColor;
				*( class Object** )( params + 44 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddLocalizedMessage( int Index, ScriptClass* InMessageClass, ScriptArray< wchar_t > CriticalString, int Switch, float Position, float Lifetime, int FontSize, void* DrawColor, int MessageCount, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.AddLocalizedMessage" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( int* )params = Index;
				*( ScriptClass** )( params + 4 ) = InMessageClass;
				*( ScriptArray< wchar_t >* )( params + 8 ) = CriticalString;
				*( int* )( params + 20 ) = Switch;
				*( float* )( params + 24 ) = Position;
				*( float* )( params + 28 ) = Lifetime;
				*( int* )( params + 32 ) = FontSize;
				*( void** )( params + 36 ) = DrawColor;
				*( int* )( params + 40 ) = MessageCount;
				*( class Object** )( params + 44 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetScreenCoords( float PosY, float &ScreenX, float &ScreenY, void* &InMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.GetScreenCoords" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( float* )params = PosY;
				*( float* )( params + 4 ) = ScreenX;
				*( float* )( params + 8 ) = ScreenY;
				*( void** )( params + 12 ) = InMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ScreenX = *( float* )( params + 4 );
				ScreenY = *( float* )( params + 8 );
				InMessage = *( void** )( params + 12 );
			}

			void DrawMessage( int I, float PosY, float &DX, float &DY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = I;
				*( float* )( params + 4 ) = PosY;
				*( float* )( params + 8 ) = DX;
				*( float* )( params + 12 ) = DY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DX = *( float* )( params + 8 );
				DY = *( float* )( params + 12 );
			}

			void DrawMessageText( void* LocalMessage, float ScreenX, float ScreenY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawMessageText" );
				byte *params = ( byte* )( malloc( 72 ) );
				*( void** )params = LocalMessage;
				*( float* )( params + 64 ) = ScreenX;
				*( float* )( params + 68 ) = ScreenY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayLocalMessages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DisplayLocalMessages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayKismetMessages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DisplayKismetMessages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawText( ScriptArray< wchar_t > Text, void* Position, class Font* TextFont, void* FontScale, void* TextColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.DrawText" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				*( void** )( params + 12 ) = Position;
				*( class Font** )( params + 20 ) = TextFont;
				*( void** )( params + 24 ) = FontScale;
				*( void** )( params + 32 ) = TextColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Font* GetFontSizeIndex( int FontSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.GetFontSizeIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FontSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Font** )( params + function->return_val_offset() );
			}

			void PlayerOwnerDied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.PlayerOwnerDied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLostFocusPause( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.HUD.OnLostFocusPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
