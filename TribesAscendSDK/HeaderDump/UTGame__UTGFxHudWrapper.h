#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGFxHudWrapper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGFxHudWrapper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGFxHudWrapper." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGFxHudWrapper : public UTHUDBase
	{
	public:
			ADD_OBJECT( ScriptClass, MinimapHUDClass )
			ADD_OBJECT( GFxProjectedUI, InventoryMovie )
			ADD_OBJECT( GFxMinimapHud, HudMovie )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMovies(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.RemoveMovies" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateHUDMovie(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.CreateHUDMovie" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLocalPlayerOwnerIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.GetLocalPlayerOwnerIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetVisible( bool bNewVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.SetVisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayHit( Vector HitDir, int Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.DisplayHit" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitDir;
				*( int* )( params + 12 ) = Damage;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseOtherMenus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.CloseOtherMenus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResolutionChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.ResolutionChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.PostRender" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.DrawHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LocalizedMessage( ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, ScriptArray< wchar_t > CriticalString, int Switch, float Position, float Lifetime, int FontSize, void* DrawColor, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.LocalizedMessage" );
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

			void AddConsoleMessage( ScriptArray< wchar_t > M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.AddConsoleMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = M;
				*( ScriptClass** )( params + 12 ) = InMessageClass;
				*( class PlayerReplicationInfo** )( params + 16 ) = PRI;
				*( float* )( params + 20 ) = Lifetime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompleteCloseInventory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.CompleteCloseInventory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompleteCloseTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxHudWrapper.CompleteCloseTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
