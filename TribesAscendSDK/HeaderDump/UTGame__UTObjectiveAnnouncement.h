#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTObjectiveAnnouncement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTObjectiveAnnouncement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTObjectiveAnnouncement." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTObjectiveAnnouncement : public UTObjectiveSpecificMessage
	{
	public:
			void* GetObjectiveAnnouncement( byte MessageIndex, class Object* Objective, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTObjectiveAnnouncement.GetObjectiveAnnouncement" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = MessageIndex;
				*( class Object** )( params + 4 ) = Objective;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool ShouldBeRemoved( class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTObjectiveAnnouncement.ShouldBeRemoved" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTQueuedAnnouncement** )( params + 0 ) = MyAnnouncement;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHUDDisplay( class PlayerController* P, int Switch, ScriptArray< wchar_t > Text, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTObjectiveAnnouncement.SetHUDDisplay" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Text;
				*( class PlayerReplicationInfo** )( params + 20 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 24 ) = RelatedPRI_;
				*( class Object** )( params + 28 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
