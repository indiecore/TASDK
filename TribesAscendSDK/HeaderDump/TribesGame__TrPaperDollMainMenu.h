#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPaperDollMainMenu." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPaperDollMainMenu." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPaperDollMainMenu." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
			ADD_VAR( ::ByteProperty, m_OldContentDataType, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rZeroedRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFullCharacterLightingContrastFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bWasLastMeshSwapRequestMainMenuContentScene, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEditorMode, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetDevicePaperDollInfo( ScriptClass* WeaponClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.GetDevicePaperDollInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = WeaponClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetMainMesh( void* NewInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.SetMainMesh" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )params = NewInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCharacterMeshContentDataClassLoaded( ScriptClass* Skin3PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.OnCharacterMeshContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin3PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDeviceContentDataClassLoaded( ScriptClass* DeviceContentDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.OnDeviceContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceContentDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TryUpdatingPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.TryUpdatingPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponOnlyMesh( ScriptClass* WeaponClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.SetWeaponOnlyMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = WeaponClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFamilyInfo( ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.SetFamilyInfo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = NewFamilyInfoClass;
				*( ScriptClass** )( params + 4 ) = DeviceClass;
				*( ScriptClass** )( params + 8 ) = skinClass;
				*( int* )( params + 12 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMainMeshInfo( class TrMainMenuMeshInfo* NewMainMeshInfo, byte ContentDataType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.SetMainMeshInfo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TrMainMenuMeshInfo** )params = NewMainMeshInfo;
				*( byte* )( params + 4 ) = ContentDataType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateAndAttachParticleSystems(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.CreateAndAttachParticleSystems" );
				byte *params = ( byte* )( malloc( 16 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachAndDestroyMeshAttachments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.DetachAndDestroyMeshAttachments" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSpinning( bool bShouldSpin, bool bReset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.SetSpinning" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bShouldSpin;
				*( bool* )( params + 4 ) = bReset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EmptyChildrenMeshes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.EmptyChildrenMeshes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddChildrenMeshes( class TrMainMenuMeshInfo* Parent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDollMainMenu.AddChildrenMeshes" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrMainMenuMeshInfo** )params = Parent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
