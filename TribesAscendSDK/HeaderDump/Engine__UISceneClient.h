#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UISceneClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UISceneClient : public UIRoot
	{
	public:
			ADD_VAR( ::BoolProperty, bEnablePostProcess, 0x1 )
			ADD_OBJECT( PostProcessChain, UIScenePostProcess )
			ADD_OBJECT( DataStoreClient, DataStoreManager )
			bool IsUIActive( int Flags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UISceneClient.IsUIActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Flags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetCanvasToScreen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UISceneClient.GetCanvasToScreen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetInverseCanvasToScreen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UISceneClient.GetInverseCanvasToScreen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void InitializeSceneClient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UISceneClient.InitializeSceneClient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
