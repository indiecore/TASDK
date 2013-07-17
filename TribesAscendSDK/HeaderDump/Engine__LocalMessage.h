#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LocalMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LocalMessage : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bBeep, 0x10 )
			ADD_VAR( ::FloatProperty, Lifetime, 0xFFFFFFFF )
			void* GetConsoleColor( class PlayerReplicationInfo* RelatedPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetConsoleColor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = RelatedPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bIsSpecial, 0x1 )
			ADD_VAR( ::BoolProperty, bIsUnique, 0x2 )
			ADD_VAR( ::BoolProperty, bCountInstances, 0x20 )
			ADD_VAR( ::BoolProperty, bIsPartiallyUnique, 0x4 )
			bool PartiallyDuplicates( int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.PartiallyDuplicates" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = Switch1;
				*( int* )( params + 4 ) = Switch2;
				*( class Object** )( params + 8 ) = OptionalObject1;
				*( class Object** )( params + 12 ) = OptionalObject2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, FontSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PosY, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsConsoleMessage, 0x8 )
			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = Switch;
				*( bool* )( params + 4 ) = bPRI1HUD;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetColor( int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetColor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI_;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			float GetPos( int Switch, class HUD* myHUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetPos" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = Switch;
				*( class HUD** )( params + 4 ) = myHUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetFontSize( int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetFontSize" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI1;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI2;
				*( class PlayerReplicationInfo** )( params + 12 ) = LocalPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetLifeTime( int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.GetLifeTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool IsConsoleMessage( int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LocalMessage.IsConsoleMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
