#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKGameObjective." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKGameObjective : public NavigationPoint
	{
	public:
			ADD_VAR( ::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, IconHudTexture )
			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUnderAttack, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowOnlyShootable, 0x1 )
			void ObjectiveChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.ObjectiveChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetBestViewTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.GetBestViewTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool BotNearObjective( class AIController* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.BotNearObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TriggerFlagEvent( ScriptName EventType, class Controller* EventInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.TriggerFlagEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = EventType;
				*( class Controller** )( params + 8 ) = EventInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHUDLocation( Vector NewHUDLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.SetHUDLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewHUDLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawIcon( class Canvas* Canvas, Vector IconLocation, float IconWidth, float IconAlpha, class UDKPlayerController* PlayerOwner, void* DrawColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.DrawIcon" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Canvas** )params = Canvas;
				*( Vector* )( params + 4 ) = IconLocation;
				*( float* )( params + 16 ) = IconWidth;
				*( float* )( params + 20 ) = IconAlpha;
				*( class UDKPlayerController** )( params + 24 ) = PlayerOwner;
				*( void** )( params + 28 ) = DrawColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKGameObjective.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
