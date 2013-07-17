#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CheatManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CheatManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CheatManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CheatManager : public Object
	{
	public:
			ADD_VAR( ::StrProperty, OwnCamera, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ViewingFrom, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, DebugCameraControllerClass )
			ADD_OBJECT( DebugCameraController, DebugCameraControllerRef )
			void FXPlay( ScriptClass* aClass, ScriptArray< wchar_t > FXAnimPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.FXPlay" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = aClass;
				*( ScriptArray< wchar_t >* )( params + 4 ) = FXAnimPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FXStop( ScriptClass* aClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.FXStop" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = aClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DebugAI( ScriptName Category )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.DebugAI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = Category;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EditAIByTrace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.EditAIByTrace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DebugPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.DebugPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ListDynamicActors(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ListDynamicActors" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FreezeFrame( float Delay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.FreezeFrame" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Delay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WriteToLog( ScriptArray< wchar_t > Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.WriteToLog" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillViewedActor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.KillViewedActor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Teleport(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Teleport" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeSize( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ChangeSize" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndPath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.EndPath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Amphibious(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Amphibious" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Fly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Fly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Walk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Walk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Ghost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Ghost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.AllAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void God(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.God" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Slomo( float T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Slomo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetJumpZ( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.SetJumpZ" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetGravity( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.SetGravity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSpeed( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.SetSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillAll( ScriptClass* aClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.KillAll" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = aClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillAllPawns( ScriptClass* aClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.KillAllPawns" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = aClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillPawns(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.KillPawns" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Avatar( ScriptName ClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Avatar" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Summon( ScriptArray< wchar_t > ClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Summon" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Weapon* GiveWeapon( ScriptArray< wchar_t > WeaponClassStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.GiveWeapon" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = WeaponClassStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Weapon** )( params + function->return_val_offset() );
			}

			void PlayersOnly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.PlayersOnly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyFractures( float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.DestroyFractures" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FractureAllMeshes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.FractureAllMeshes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FractureAllMeshesToMaximizeMemoryUsage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.FractureAllMeshesToMaximizeMemoryUsage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RememberSpot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.RememberSpot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewSelf( bool bQuiet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ViewSelf" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bQuiet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewPlayer( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ViewPlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewActor( ScriptName ActorName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ViewActor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ActorName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewBot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ViewBot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewClass( ScriptClass* aClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.ViewClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = aClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Loaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.Loaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllWeapons(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.AllWeapons" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLevelStreamingStatus( ScriptName PackageName, bool bShouldBeLoaded, bool bShouldBeVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.SetLevelStreamingStatus" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = PackageName;
				*( bool* )( params + 8 ) = bShouldBeLoaded;
				*( bool* )( params + 12 ) = bShouldBeVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableDebugCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.EnableDebugCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitCheatManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.InitCheatManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogPlaySoundCalls( bool bShouldLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.LogPlaySoundCalls" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bShouldLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogParticleActivateSystemCalls( bool bShouldLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.LogParticleActivateSystemCalls" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bShouldLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VerifyNavMeshObjects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.VerifyNavMeshObjects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawUnsupportingEdges( ScriptArray< wchar_t > PawnClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.DrawUnsupportingEdges" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PawnClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrintNavMeshObstacles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.PrintNavMeshObstacles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpCoverStats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CheatManager.DumpCoverStats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
