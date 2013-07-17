#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGameObjective." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameObjective : public UDKGameObjective
	{
	public:
			bool UsedBy( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.UsedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bAllowRemoteUse, 0x2 )
			class Actor* GetAutoObjectiveActor( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetAutoObjectiveActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class UTCarriedObject* GetFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTCarriedObject** )( params + function->return_val_offset() );
			}

			bool Shootable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.Shootable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MaxBeaconDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinimapIconScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighlightSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxHighlightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighlightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraViewDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSensorRange, 0xFFFFFFFF )
			ADD_OBJECT( Material, HudMaterial )
			ADD_VAR( ::FloatProperty, IconExtentY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconExtentX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconPosY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconPosX, 0xFFFFFFFF )
			ADD_OBJECT( UTGameObjective, NextObjective )
			ADD_VAR( ::IntProperty, Score, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseRadius, 0xFFFFFFFF )
			ADD_OBJECT( Volume, MyBaseVolume )
			ADD_VAR( ::StrProperty, ObjectiveName, 0xFFFFFFFF )
			ADD_OBJECT( UTDefensePoint, DefensePoints )
			ADD_OBJECT( UTSquadAI, DefenseSquad )
			ADD_VAR( ::ByteProperty, DefensePriority, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StartTeam, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bScriptRenderAdditionalMinimap, 0x200 )
			ADD_VAR( ::BoolProperty, bHasLocationSpeech, 0x100 )
			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x80 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x40 )
			ADD_VAR( ::BoolProperty, bIsDisabled, 0x20 )
			ADD_VAR( ::BoolProperty, bIsConstructing, 0x10 )
			ADD_VAR( ::BoolProperty, bHasSensor, 0x8 )
			ADD_VAR( ::BoolProperty, bFirstObjective, 0x4 )
			ADD_VAR( ::BoolProperty, bAlreadyRendered, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsStandalone(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.IsStandalone" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetHUDOffset( class PlayerController* PC, class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetHUDOffset" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			int GetLocationMessageIndex( class UTBot* B, class Pawn* StatusPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetLocationMessageIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Pawn** )( params + 4 ) = StatusPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class SoundNodeWave* GetLocationSpeechFor( class PlayerController* PC, int LocationSpeechOffset, int MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetLocationSpeechFor" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( int* )( params + 4 ) = LocationSpeechOffset;
				*( int* )( params + 8 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTeamStaticMesh( class UTTeamStaticMesh* SMesh )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.AddTeamStaticMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTTeamStaticMesh** )( params + 0 ) = SMesh;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeamStaticMeshes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.UpdateTeamStaticMeshes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTGameObjective* FindNearestFriendlyNode( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.FindNearestFriendlyNode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HighlightOnMinimap( int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.HighlightOnMinimap" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderMinimap( class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.RenderMinimap" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTMapInfo** )( params + 0 ) = MP;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( class UTPlayerController** )( params + 8 ) = PlayerOwner;
				*( float* )( params + 12 ) = ColorPercent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderExtraDetails( class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent, bool bSelected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.RenderExtraDetails" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UTMapInfo** )( params + 0 ) = MP;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( class UTPlayerController** )( params + 8 ) = PlayerOwner;
				*( float* )( params + 12 ) = ColorPercent;
				*( bool* )( params + 16 ) = bSelected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMapSelection( class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.DrawMapSelection" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTMapInfo** )( params + 0 ) = MP;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( class UTPlayerController** )( params + 8 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsCritical(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.IsCritical" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsNeutral(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.IsNeutral" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.IsActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TellBotHowToHeal( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.TellBotHowToHeal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TeamLink( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.TeamLink" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedsHealing(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.NeedsHealing" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanDoubleJump( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.CanDoubleJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BotNearObjective( class AIController* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.BotNearObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NearObjective( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.NearObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool TellBotHowToDisable( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.TellBotHowToDisable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetNumDefenders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.GetNumDefenders" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool BetterObjectiveThan( class UTGameObjective* Best, byte DesiredTeamNum, byte RequesterTeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.BetterObjectiveThan" );
				byte *params = ( byte* )( malloc( 6 ) );
				*( class UTGameObjective** )( params + 0 ) = Best;
				*( byte* )( params + 4 ) = DesiredTeamNum;
				*( byte* )( params + 5 ) = RequesterTeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.ClientReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddScorer( class UTPlayerReplicationInfo* PRI, float Pct )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.AddScorer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = PRI;
				*( float* )( params + 4 ) = Pct;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShareScore( int TotalScore, ScriptArray< wchar_t > EventDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.ShareScore" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = TotalScore;
				*( ScriptArray< wchar_t >* )( params + 4 ) = EventDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTeam( byte TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.SetTeam" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindGoodEndView( class PlayerController* PC, Rotator &GoodRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.FindGoodEndView" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( Rotator* )( params + 4 ) = GoodRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				GoodRotation = *( Rotator* )( params + 4 );
			}

			bool TeleportTo( class UTPawn* Traveler )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.TeleportTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = Traveler;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ValidSpawnPointFor( byte TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.ValidSpawnPointFor" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetAlarm( bool bNowOn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.SetAlarm" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNowOn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TriggerFlagEvent( ScriptName EventType, class Controller* EventInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.TriggerFlagEvent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = EventType;
				*( class Controller** )( params + 8 ) = EventInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MarkShootSpotsFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.MarkShootSpotsFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReachedParkingSpot( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.ReachedParkingSpot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FlagUpdated( bool bFlagHome )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.FlagUpdated" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bFlagHome;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFlagComesHome(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.OnFlagComesHome" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFlagTaken(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameObjective.OnFlagTaken" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
