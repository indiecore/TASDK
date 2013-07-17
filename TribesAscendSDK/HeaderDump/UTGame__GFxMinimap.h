#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxMinimap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxMinimap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxMinimap." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxMinimap : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, IconsFlagCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconsBlueCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconsRedCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, IconsFlagMC )
			ADD_OBJECT( GFxObject, IconsBlueMC )
			ADD_OBJECT( GFxObject, IconsRedMC )
			ADD_OBJECT( GFxObject, MapMC )
			ADD_OBJECT( GFxObject, CompassIcon )
			ADD_OBJECT( GFxObject, PlayerIcon )
			ADD_VAR( ::BoolProperty, bNeedsUpdateData, 0x1 )
			ADD_VAR( ::IntProperty, MapTexSize, 0xFFFFFFFF )
			ADD_OBJECT( UTMapInfo, MapInfo )
			ADD_OBJECT( WorldInfo, ThisWorld )
			ADD_OBJECT( GFxMinimapHud, HUD )
			void Init( class GFxMinimapHud* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxMinimapHud** )( params + 0 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.UpdateData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GenFriendIcons( int N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.GenFriendIcons" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GenEnemyIcons( int N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.GenEnemyIcons" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GenFlagIcons( int N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.GenFlagIcons" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void UpdateIcons( bool bIsRedIconType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.UpdateIcons" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( bool* )( params + 24 ) = bIsRedIconType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Update( float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimap.Update" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
