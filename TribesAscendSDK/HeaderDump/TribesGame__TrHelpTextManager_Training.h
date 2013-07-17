#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrHelpTextManager_Training." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrHelpTextManager_Training." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrHelpTextManager_Training." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrHelpTextManager_Training : public TrHelpTextManager
	{
	public:
			ADD_VAR( ::StrProperty, m_TrainingHelpTextExample1, 0xFFFFFFFF )
			void InitHelpTextManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.InitHelpTextManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTypesToRemoveOnTimers( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.UpdateTypesToRemoveOnTimers" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckDestroy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.CheckDestroy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RequestHelpText( byte RequestedType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.RequestHelpText" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = RequestedType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RemoveHelpText( byte TypeToRemove, float Time, bool bDoNotSuppress )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.RemoveHelpText" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = TypeToRemove;
				*( float* )( params + 4 ) = Time;
				*( bool* )( params + 8 ) = bDoNotSuppress;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RequestHelpText_Training( byte RequestedType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.RequestHelpText_Training" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = RequestedType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, m_CurrentHelpTextTrainingType, 0xFFFFFFFF )
			void UpdateHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHelpTextManager_Training.UpdateHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, m_TrainingHelpTextExample1MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextExample2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextExample2MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiMessage1, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSki1MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiMessage2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSki2MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiMessage3, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSki3MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiMessage4, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSki4MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiMessage5, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSki5MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdvMessage1, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdv1MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdvMessage2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdv2MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdvMessage3, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdv3MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdvMessage4, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdv4MenuTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdvMessage5, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_TrainingHelpTextSkiAdv5MenuTitle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
