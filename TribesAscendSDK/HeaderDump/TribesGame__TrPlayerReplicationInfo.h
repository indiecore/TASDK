#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPlayerReplicationInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPlayerReplicationInfo : public UTPlayerReplicationInfo
	{
	public:
			ScriptClass* GetPlayerRank(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetPlayerRank" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptClass* GetCurrentClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCurrentClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptClass* GetEquipDevice( ScriptClass* FamilyInfo, byte equipSlot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetEquipDevice" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( byte* )( params + 4 ) = equipSlot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_nCreditsEarned, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nKills, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nAssists, 0xFFFFFFFF )
			int GetRankIcon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetRankIcon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, r_nArenaSpawnsLeft, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsCrossedOffArenaList, 0x8 )
			class TrValueModifier* GetCurrentValueModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCurrentValueModifier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrValueModifier** )( params + function->return_val_offset() );
			}

			byte GetEquipPointByWeaponId( int WeaponId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetEquipPointByWeaponId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = WeaponId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte GetArmorType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetArmorType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ScriptClass* GetCurrentSkinClass( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCurrentSkinClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			class SkeletalMesh* GetGibMesh( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetGibMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			class SkeletalMesh* Get3PSkin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.Get3PSkin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			class SkeletalMesh* GetBodyMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetBodyMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Actor, m_LockedTarget )
			ADD_VAR( ::BoolProperty, c_bIsBuddyToLocalPlayer, 0x2 )
			ADD_VAR( ::BoolProperty, c_bIsMutualBuddiesWithLocalPlayer, 0x4 )
			ADD_VAR( ::BoolProperty, r_bIsLastManStanding, 0x10 )
			class SkeletalMesh* GetHandsMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetHandsMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			class ParticleSystem* GetSkiThrust( ScriptClass* FamilyInfo, class ParticleSystem* DefaultSystem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetSkiThrust" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( class ParticleSystem** )( params + 4 ) = DefaultSystem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			int GetJetpackSocketCount( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocketCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class ParticleSystem* GetJetpackThrust( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetJetpackThrust" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			ScriptName GetJetpackSocket( ScriptClass* FamilyInfo, int Socket )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocket" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( int* )( params + 4 ) = Socket;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			class ParticleSystem* GetJetpackTrail( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetJetpackTrail" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_nFreeCredits, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrentCredits, 0xFFFFFFFF )
			bool RequestLoadoutChange( ScriptClass* FamilyInfo, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.RequestLoadoutChange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, r_VoiceClass )
			ADD_VAR( ::IntProperty, m_nRabbitRank, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPlayerIconIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_bSkinId, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, c_Cached1PSkin )
			ADD_OBJECT( ScriptClass, c_Cached3PSkin )
			ADD_OBJECT( TrValueModifier, m_ValueModifier )
			ADD_VAR( ::FloatProperty, c_fRedFlagTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, c_fRedFlagPingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, c_fRedFlagPingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, c_fCurrentPingMS, 0xFFFFFFFF )
			ADD_OBJECT( TrInventoryHelper, InvHelper )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::ByteProperty, m_ArmorType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDevUpgrades, 0x1 )
			ADD_VAR( ::IntProperty, m_nPlayerClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nBaseXP, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nBaseGP, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRankIconIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRankNum, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_PendingBaseClass )
			ADD_OBJECT( ScriptClass, m_CurrentBaseClass )
			ADD_OBJECT( ScriptClass, m_Rank )
			ADD_VAR( ::IntProperty, m_PendingLoadout, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_CurrentLoadout, 0xFFFFFFFF )
			bool VerifyCharacter( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.VerifyCharacter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetCharacterEquip( int ClassId, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquip" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetCharacterEquipLocal( int ClassId, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquipLocal" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetUpgradeLevel( int ClassId, int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevel" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetUpgradeLevelLocal( int ClassId, int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevelLocal" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdatePing( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.UpdatePing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterBuddy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.RegisterBuddy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* Load1PData( ScriptArray< wchar_t > ContentPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.Load1PData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = ContentPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterPlayerWithSession(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.RegisterPlayerWithSession" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateValueModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.UpdateValueModifier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPlayerTeam( class TeamInfo* NewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetPlayerTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TeamInfo** )params = NewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwapToPendingCharClass( bool bIsRespawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SwapToPendingCharClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsRespawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool VerifyAndLoadCharacter( ScriptClass* FamilyInfo, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.VerifyAndLoadCharacter" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSelectedLoadout(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetSelectedLoadout" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool ShouldVisitStation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.ShouldVisitStation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ResolveDefaultEquip( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.ResolveDefaultEquip" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActiveEquip( byte EquipId, int ItemId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetActiveEquip" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = EquipId;
				*( int* )( params + 4 ) = ItemId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementKills( bool bEnemyKill )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.IncrementKills" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnemyKill;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckMultiKill(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.CheckMultiKill" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetPlayerClassId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetPlayerClassId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptClass* GetPendingClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetPendingClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetCurrentClassAbb(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCurrentClassAbb" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int GetPlayerRankNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetPlayerRankNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetBaseGP(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetBaseGP" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetBaseXP(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetBaseXP" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetPlayerGP( int GP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetPlayerGP" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = GP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPlayerXP( int XP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetPlayerXP" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = XP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetRankFromXP( int XP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetRankFromXP" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = XP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ScriptClass* GetPerkFromId( int PerkId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetPerkFromId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PerkId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void SetFlag( class UTCarriedObject* NewFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTCarriedObject** )params = NewFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerReplicationInfo* Duplicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.Duplicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			void CopyProperties( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.CopyProperties" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCached3PSkin( ScriptClass* NewCachedSkin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.SetCached3PSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = NewCachedSkin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetCurrentVoiceClass( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.GetCurrentVoiceClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void UpdateCachedSkin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.UpdateCachedSkin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void On3PSkinContentLoaded( ScriptClass* Skin3PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.On3PSkinContentLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin3PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void On1PSkinContentLoaded( ScriptClass* Skin1PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.On1PSkinContentLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin1PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Update1PMesh( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.Update1PMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPingRedFlagged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.OnPingRedFlagged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerPingRedFlag( float CurrentPingMS )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerReplicationInfo.ServerPingRedFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = CurrentPingMS;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
