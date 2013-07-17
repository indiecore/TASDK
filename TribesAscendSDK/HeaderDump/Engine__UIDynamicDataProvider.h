#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDynamicDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDynamicDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDynamicDataProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDynamicDataProvider : public UIPropertyDataProvider
	{
	public:
			ADD_OBJECT( Object, DataSource )
			ADD_OBJECT( ScriptClass, DataClass )
			bool BindProviderInstance( class Object* DataSourceInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.BindProviderInstance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )( params + 0 ) = DataSourceInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnbindProviderInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.UnbindProviderInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ProviderInstanceBound( class Object* DataSourceInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.ProviderInstanceBound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )( params + 0 ) = DataSourceInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProviderInstanceUnbound( class Object* DataSourceInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.ProviderInstanceUnbound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )( params + 0 ) = DataSourceInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsValidDataSourceClass( ScriptClass* PotentialDataSourceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.IsValidDataSourceClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = PotentialDataSourceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Object* GetDataSource(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.GetDataSource" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Object** )( params + function->return_val_offset() );
			}

			bool CleanupDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicDataProvider.CleanupDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
