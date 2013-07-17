#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrScene_PlayerSummary." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrScene_PlayerSummary." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrScene_PlayerSummary." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrScene_PlayerSummary : public GFxTrScene
	{
	public:
			ADD_VAR( ::BoolProperty, bSummaryReady, 0x4 )
			ADD_VAR( ::BoolProperty, bSummaryTweened, 0x8 )
			ADD_VAR( ::BoolProperty, bSummaryXPTweened, 0x10 )
			ADD_VAR( ::BoolProperty, bFirstWin, 0x2 )
			ADD_VAR( ::BoolProperty, bUseSNS, 0x1 )
			ADD_OBJECT( TrSummaryHelper, SummaryHelper )
			ADD_VAR( ::IntProperty, EarnedBadgeValue, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPBoost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPVIP, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPPerf, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPBase, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RankGained, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RankBase, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TopPlayedClass, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Credits, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Assists, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Deaths, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Kills, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerID, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, AccoladeDataList )
			ADD_OBJECT( GFxObject, AwardDataList )
			ADD_OBJECT( GFxObject, MiscDataList )
			ADD_VAR( ::IntProperty, AccoladeDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AwardDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MiscDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SkillClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AWARD_TIER_SIZE, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSummary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.ClearSummary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearEarnedBadgeValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.ClearEarnedBadgeValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SummaryReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.SummaryReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadXPData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.LoadXPData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPlayerStatsData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerStatsData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPlayerAccoladeData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerAccoladeData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPlayerMiscData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerMiscData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddAward( int AwardId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.AddAward" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = AwardId;
				*( int* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddBadge( void* Badge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.AddBadge" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( void** )( params + 0 ) = Badge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddAccolade( int AccoladeId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.AddAccolade" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = AccoladeId;
				*( int* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMiscData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.AddMiscData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetFlagGrabCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.GetFlagGrabCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetFlagReturnCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_PlayerSummary.GetFlagReturnCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
