#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_Badges." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_Badges." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_Badges." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Badges : public GFxTrPage
	{
	public:
			ADD_VAR( ::IntProperty, ActiveType, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialAction( class GFxTrAction* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.SpecialAction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrAction** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int TakeAction( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.TakeAction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ShowModel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.ShowModel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int TakeFocus( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.TakeFocus" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void FillData( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* FillProfile(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillProfile" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void FillCombatType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillCombatType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillObjectiveType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillObjectiveType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillVehicleType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillVehicleType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillTacticalType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillTacticalType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillSingleType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillSingleType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillReferralType( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillReferralType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillBadge( class GFxObject* Obj, int Count, int badgeIndex, bool bSkiBadge, bool bSingle, bool bReferralBadge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.FillBadge" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class GFxObject** )params = Obj;
				*( int* )( params + 4 ) = Count;
				*( int* )( params + 8 ) = badgeIndex;
				*( bool* )( params + 12 ) = bSkiBadge;
				*( bool* )( params + 16 ) = bSingle;
				*( bool* )( params + 20 ) = bReferralBadge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHighestBadgeIndex( int ActivityId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.GetHighestBadgeIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActivityId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetHighestSkiBadgeIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.GetHighestSkiBadgeIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ProfileUp( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.ProfileUp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProfileDown( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_Badges.ProfileDown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
