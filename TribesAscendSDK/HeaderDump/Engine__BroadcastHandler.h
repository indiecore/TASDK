#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.BroadcastHandler." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.BroadcastHandler." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.BroadcastHandler." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class BroadcastHandler : public Info
	{
	public:
			ADD_VAR( ::BoolProperty, bMuteSpectators, 0x1 )
			ADD_VAR( ::IntProperty, SentText, 0xFFFFFFFF )
			void UpdateSentText(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.UpdateSentText" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowsBroadcast( class Actor* broadcaster, int InLen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.AllowsBroadcast" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = broadcaster;
				*( int* )( params + 4 ) = InLen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BroadcastText( class PlayerReplicationInfo* SenderPRI, class PlayerController* Receiver, ScriptArray< wchar_t > msg, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.BroadcastText" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class PlayerReplicationInfo** )params = SenderPRI;
				*( class PlayerController** )( params + 4 ) = Receiver;
				*( ScriptArray< wchar_t >* )( params + 8 ) = msg;
				*( ScriptName* )( params + 20 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastLocalized( class Actor* Sender, class PlayerController* Receiver, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.BroadcastLocalized" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = Sender;
				*( class PlayerController** )( params + 4 ) = Receiver;
				*( ScriptClass** )( params + 8 ) = Message;
				*( int* )( params + 12 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 20 ) = RelatedPRI_;
				*( class Object** )( params + 24 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Broadcast( class Actor* Sender, ScriptArray< wchar_t > msg, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.Broadcast" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )params = Sender;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				*( ScriptName* )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastTeam( class Controller* Sender, ScriptArray< wchar_t > msg, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.BroadcastTeam" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Controller** )params = Sender;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				*( ScriptName* )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllowBroadcastLocalized( class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.AllowBroadcastLocalized" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )params = Sender;
				*( ScriptClass** )( params + 4 ) = Message;
				*( int* )( params + 8 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI_;
				*( class Object** )( params + 20 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllowBroadcastLocalizedTeam( int TeamIndex, class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.BroadcastHandler.AllowBroadcastLocalizedTeam" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = TeamIndex;
				*( class Actor** )( params + 4 ) = Sender;
				*( ScriptClass** )( params + 8 ) = Message;
				*( int* )( params + 12 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 20 ) = RelatedPRI_;
				*( class Object** )( params + 24 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
