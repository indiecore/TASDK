#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVideoSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVideoSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVideoSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVideoSettings : public GFxObject
	{
	public:
			int GetCurrentSettingValue( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetCurrentSettingValue" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_Cached_Resolution, 0xFFFFFFFF )
			int GetSmoothFramerateValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetSmoothFramerateValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void GetAllowedResolutions(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetAllowedResolutions" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyVideoSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.ApplyVideoSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeScreenType( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.ChangeScreenType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeResolution( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.ChangeResolution" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeShadowDetail( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.ChangeShadowDetail" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeTextureDetail( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.ChangeTextureDetail" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetResolutions(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetResolutions" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVSync( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.SetVSync" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMotionBlur( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.SetMotionBlur" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadVideoSettings( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.LoadVideoSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, m_VideoSettingsCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_VideoSettingsList )
			void AddVideoSettingToList( ScriptArray< wchar_t > SettingName, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.AddVideoSettingToList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = SettingName;
				*( int* )( params + 12 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadVideoResolutions( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.LoadVideoResolutions" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadResolutions( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.LoadResolutions" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, m_ResolutionCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_ResolutionList )
			void AddResolutionToList( ScriptArray< wchar_t > Resolution )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.AddResolutionToList" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Resolution;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetSettingNameFromType( byte Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetSettingNameFromType" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			byte GetSettingTypeFromName( ScriptArray< wchar_t > val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.GetSettingTypeFromName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void CacheVideoSetting( int Index, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.CacheVideoSetting" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( int* )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, m_Cached_ShadowDetail, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_TextureDetail, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_ScreenType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_MotionBlur, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_VerticalSync, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_SmoothFramerate, 0xFFFFFFFF )
			void SetSmoothFramerateValue( int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVideoSettings.SetSmoothFramerateValue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
