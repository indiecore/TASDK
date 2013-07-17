#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxMinimapHud." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxMinimapHud." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxMinimapHud." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxMinimapHud : public GFxMoviePlayer
	{
	public:
			ADD_VAR( ::BoolProperty, bIsTeamHUD, 0x1 )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NormalZoomf, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurZoomf, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDrawWeaponCrosshairs, 0x2 )
			ADD_OBJECT( UTGameReplicationInfo, GRI )
			ADD_OBJECT( UTPlayerReplicationInfo, LastFlagCarrier )
			ADD_OBJECT( UTPlayerReplicationInfo, LastEnemy )
			ADD_VAR( ::ByteProperty, LastFlagHome, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastAmmoCount, 0xFFFFFFFF )
			ADD_OBJECT( UTWeapon, LastWeapon )
			ADD_OBJECT( UTVehicle, LastVehicle )
			ADD_OBJECT( GFxObject, MultiKillMC )
			ADD_OBJECT( GFxObject, MultiKillMsg_TF )
			ADD_OBJECT( GFxObject, MultiKillN_TF )
			ADD_OBJECT( GFxObject, HitLocMC )
			ADD_OBJECT( GFxObject, CreditsAndStreaksMC )
			ADD_OBJECT( GFxObject, OffhandsAndFlagMC )
			ADD_OBJECT( GFxObject, EnemyNameTF )
			ADD_OBJECT( GFxObject, CenterTextTF )
			ADD_OBJECT( GFxObject, CenterTextMC )
			ADD_OBJECT( GFxObject, TimeTF )
			ADD_OBJECT( GFxObject, TeamStatsMC )
			ADD_OBJECT( GFxObject, PlayerStatsMC )
			ADD_VAR( ::IntProperty, NumMessages, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MessageHeight, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, LogMC )
			ADD_VAR( ::FloatProperty, MinZoomf, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxZoomf, 0xFFFFFFFF )
			ADD_OBJECT( GFxMinimap, Minimap )
			ADD_OBJECT( WorldInfo, ThisWorld )
			void registerMiniMapView( class GFxMinimap* MC, float R )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.registerMiniMapView" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GFxMinimap** )( params + 0 ) = MC;
				*( float* )( params + 4 ) = R;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAmmoCountTF( class Weapon* Wep, ScriptArray< wchar_t > Ammo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.SetAmmoCountTF" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )( params + 0 ) = Wep;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Ammo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* CreateMessageRow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.CreateMessageRow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* InitMessageRow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.InitMessageRow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void Init( class LocalPlayer* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadHeEn( void* &Info, ScriptArray< wchar_t > Base )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.LoadHeEn" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 0 ) = Info;
				*( ScriptArray< wchar_t >* )( params + 36 ) = Base;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Info = *( void** )( params + 0 );
			}

			void UpdateHealth( void* &Info, float NewHealth, float HealthMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.UpdateHealth" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( void** )( params + 0 ) = Info;
				*( float* )( params + 36 ) = NewHealth;
				*( float* )( params + 40 ) = HealthMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Info = *( void** )( params + 0 );
			}

			void UpdateEnergy( void* &Info, float NewEnergy, float EnergyMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.UpdateEnergy" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( void** )( params + 0 ) = Info;
				*( float* )( params + 36 ) = NewEnergy;
				*( float* )( params + 40 ) = EnergyMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Info = *( void** )( params + 0 );
			}

			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ClearStats( bool clearScores )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.ClearStats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = clearScores;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.RemoveMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMessage( ScriptArray< wchar_t > Type, ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.AddMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Type;
				*( ScriptArray< wchar_t >* )( params + 12 ) = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameHUD( class UTPlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.UpdateGameHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TickHud( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.TickHud" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleCrosshair( bool bToggle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.ToggleCrosshair" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bToggle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MinimapZoomOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.MinimapZoomOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MinimapZoomIn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.MinimapZoomIn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayHit( Vector HitDir, int Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.DisplayHit" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = HitDir;
				*( int* )( params + 12 ) = Damage;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMultiKill( int N, ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.ShowMultiKill" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = N;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCenterText( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.SetCenterText" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetRank( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.GetRank" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void AddDeathMessage( class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Killed, ScriptClass* Dmg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxMinimapHud.AddDeathMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Killer;
				*( class PlayerReplicationInfo** )( params + 4 ) = Killed;
				*( ScriptClass** )( params + 8 ) = Dmg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
