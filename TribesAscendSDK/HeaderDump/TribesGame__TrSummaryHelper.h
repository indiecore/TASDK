#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSummaryHelper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSummaryHelper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSummaryHelper." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSummaryHelper : public Object
	{
	public:
			void SortPlayerAwards(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.SortPlayerAwards" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SortMVPAwards(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.SortMVPAwards" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, AWARD_TIER_SIZE, 0xFFFFFFFF )
			int MVPSort( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.MVPSort" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int AwardSort( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.AwardSort" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptClass* GetAwardFromId( int AwardId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetAwardFromId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = AwardId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetTierTitle( int val, ScriptClass* award )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetTierTitle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = val;
				*( ScriptClass** )( params + 4 ) = award;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptClass* GetAccoladeFromId( int AccoladeId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetAccoladeFromId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = AccoladeId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptClass* GetRankFromXP( int XP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetRankFromXP" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = XP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptClass* GetNextRank( ScriptClass* Rank )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetNextRank" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = Rank;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			int GetMinTierValue( int AwardId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetMinTierValue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = AwardId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetTieredWeight( int AwardId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSummaryHelper.GetTieredWeight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = AwardId;
				*( int* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
